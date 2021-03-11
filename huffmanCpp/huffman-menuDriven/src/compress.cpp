#include "../include/compress.h"

using namespace std;


void findFreq( ifstream& fin , map<unsigned char,int>& huff )
{
	char ch;
	
	while ( true )
	{		
		fin.get(ch);
		
		if ( fin.eof() ) break; //Adi your code
		
		if ( huff.find(ch) == huff.end() )
			huff.insert(make_pair(ch,1));
		else
			huff[ch]++;
	}
}
 
// The main function that builds a Huffman MinHeapNode and
MinHeapNode* HuffmanCodes(map<unsigned char,int>freqtable)
{
    struct MinHeapNode *left, *right, *top;
 
    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for(auto i:freqtable){
		 minHeap.push(new MinHeapNode(i.first,i.second));
	}
 
    while (minHeap.size() != 1) {
 
        // Extract the two minimum
        // freq items from min heap
        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();
 
        top = new MinHeapNode('$', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        minHeap.push(top);
    }

	return minHeap.top();
}

// maps the characters with their respective huffman codes
void buildCharacterCodes(MinHeapNode *root, string prepend, string append, map<unsigned char, string> &chararCodes) {
	prepend = prepend + append;

	if (root->right == NULL && root->left == NULL) {
		chararCodes[root->data] = prepend;
	}

	if (root->right != NULL) {
		buildCharacterCodes(root->right, prepend, "1", chararCodes);
	}

	if (root->left != NULL) {
		buildCharacterCodes(root->left, prepend, "0", chararCodes);
	}
}

// Opens file and reads the file into a unsigned char array
unsigned char *getBufferFromFile(string path, long *size) {
	unsigned char *source = NULL;
	FILE *fp = fopen("test.txt", "r");
	if (fp != NULL) {

		if (fseek(fp, 0L, SEEK_END) == 0) {
			/* Get the size of the file. */
			long bufsize = ftell(fp);
			if (bufsize == -1) {
				cout << "Empty File" << endl;
				exit(1);
			}

			*size = bufsize;

			/* Allocate our buffer to that size. */
			source = (unsigned char *)malloc(sizeof(char) * (bufsize + 1));

			/* Go back to the start of the file. */
			if (fseek(fp, 0L, SEEK_SET) != 0) {
				cout << "Empty File" << endl;
				exit(1);
			}

			/* Read the entire file into memory. */
			size_t newLen = fread(source, sizeof(char), bufsize, fp);
			if (ferror(fp) != 0) {
				fputs("Error reading file", stderr);
			} else {
				source[newLen++] = '\0'; /* Just to be safe. */
			}
		}
		fclose(fp);
	}
	return source;
}

// Makes a bitstring according to the given file nd character codes
string getBitString(unsigned char *buf, map<unsigned char, string> characCodes, long size, int &padding) {

	string outputString = "";
	for (int i = 0; i < size; i++) {
		outputString = outputString + characCodes[buf[i]];
	}

	long lenOutputString = outputString.length();

	

	if (lenOutputString % 8 != 0) {
		int val = 8*((lenOutputString/8)+1)-lenOutputString;
		padding = val;
		
		for (int i = 0; i < val; i++) {
			outputString += "0";
		}
	}

	return outputString;
}

// Makes the final encoded string from the bitString using bit manipulation
unsigned char* getEncodedBufferFromBitString(string bitstring, vector<unsigned char> &outputBuffer, long& size) {
	//    bit=(bit<<1)|(arr[i]-'0');
	unsigned char bit = 0;
	long checkByte = 0;
	
	for (int i = 0; i < size; i++) {
		
		
		bit = (bit << 1) | (bitstring[i] - '0');
		
		checkByte++;

		if (checkByte % 8 == 0) {
			outputBuffer.push_back(bit);
			bit = 0;
		}
	}
	
	size = outputBuffer.size();
	
	return outputBuffer.data();
}

//writes given buffer into file
void writeBufferToFile(char *path, unsigned char *buffer, int sz, int flag){
	FILE *fp;
    if(flag==0)
    {
        fp = fopen(path, "wb");
    }

    else{
        fp = fopen(path, "ab");
    }
   
    fwrite(buffer, 1, sz, fp);

    fclose(fp);
}

//writes header,ie padding,size of map,maps in the form of char,leng,string... 
void writeHeader(char* path, map<unsigned char, string> characCodes, int padding) {

	int size = characCodes.size();
	writeBufferToFile(path, (unsigned char *)&padding, sizeof(int), 0);
	writeBufferToFile(path, (unsigned char *)&size, sizeof(int), 1);
	char nullBit = '\0';
	for (map<unsigned char, string>::iterator i = characCodes.begin(); i != characCodes.end(); i++) {
		
		writeBufferToFile(path, (unsigned char *)&i->first, 1, 1);
		int len = i->second.size();
		writeBufferToFile(path, (unsigned char *)&len, sizeof(int), 1);
		writeBufferToFile(path, (unsigned char *)i->second.c_str(), len, 1);
	}
}


 
void compress(string path,char* output_path) {
	long bufsize;						// the file size
	int padding = 0;					// the number of bits left which we fill with 0
	vector<unsigned char> outputBuffer; // encoded buffer after character coding according to the huffman algo

	map<unsigned char, string> characCodes; // map consisting of all the character with their respective huffman codes

	map<unsigned char,int> freqtable; //frequency table

	ifstream fin("test.txt",ios::in | ios::binary);

	findFreq(fin,freqtable);

    auto root=HuffmanCodes(freqtable);

	buildCharacterCodes(root, "", "", characCodes);

	unsigned char *buf = getBufferFromFile(path, &bufsize);

	string bitString = getBitString(buf, characCodes, bufsize, padding);

	bufsize=bitString.size();

	getEncodedBufferFromBitString(bitString, outputBuffer, bufsize);

	unsigned char* output = outputBuffer.data();

	writeHeader(output_path, characCodes, padding);	

	writeBufferToFile(output_path, output, bufsize, 1);
}
