#include <bits/stdc++.h>

using namespace std;

// // struct for the huffman tree
// struct MinHeapNode {
// 	int frequency;
// 	unsigned char charac;
// 	MinHeapNode *left = NULL;
// 	MinHeapNode *right = NULL;
// };

struct MinHeapNode {
 
    // One of the input characters
    char data;
 
    // Frequency of the character
    unsigned freq;
 
    // Left and right child
    MinHeapNode *left, *right;
 
    MinHeapNode(char data, unsigned freq)
 
    {
 
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
 
// For comparison of
// two heap nodes (needed in min heap)
struct compare {
 
    bool operator()(MinHeapNode* l, MinHeapNode* r)
 
    {
        return (l->freq > r->freq);
    }
};

// void printCodes(struct MinHeapNode* root, string str)
// {
 
//     if (!root)
//         return;
 
//     if (root->data != '$')
//         cout << root->data << ": " << str << "\n";
 
//     printCodes(root->left, str + "0");
//     printCodes(root->right, str + "1");
// }
 
// The main function that builds a Huffman MinHeapNode and
// print codes by traversing the built Huffman MinHeapNode
MinHeapNode* HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
 
    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
 
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
 
    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
 
        // Extract the two minimum
        // freq items from min heap
        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();
 
        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '$' is a special value
        // for internal nodes, not used
        top = new MinHeapNode('$', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        minHeap.push(top);
    }

	
 
    // Print Huffman codes using
    // the Huffman tree built above
    // printCodes(minHeap.top(), "");
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

	cout<<outputString<<endl;

	if (lenOutputString % 8 != 0) {
		int val = 8*((lenOutputString/8)+1)-lenOutputString;
		padding = val;
		cout<<val<<endl;
		for (int i = 0; i < val; i++) {
			outputString += "0";
		}
	}
	cout<<outputString<<endl;
	return outputString;
}

// Makes the final encoded string from the bitString using bit manipulation
unsigned char* getEncodedBufferFromBitString(string bitstring, vector<unsigned char> &outputBuffer, long& size) {
	//    bit=(bit<<1)|(arr[i]-'0');
	unsigned char bit = 0;
	long checkByte = 0;
	cout<<"man no"<<endl;
	for (int i = 0; i < size; i++) {
		
		cout<<bitstring[i]<<endl;
		bit = (bit << 1) | (bitstring[i] - '0');
		cout<<bit<<endl;
		checkByte++;

		if (checkByte % 8 == 0) {
			outputBuffer.push_back(bit);
			bit = 0;
		}
	}
	cout<<"bye"<<endl;
	size = outputBuffer.size();
	cout<<size<<endl;
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
		cout<<i->first<<" "<<i->second<<endl;
		writeBufferToFile(path, (unsigned char *)&i->first, 1, 1);
		int len = i->second.size();
		writeBufferToFile(path, (unsigned char *)&len, sizeof(int), 1);
		writeBufferToFile(path, (unsigned char *)i->second.c_str(), len, 1);
	}
}


 

int main() {

	string path="test.txt";
	char* output_path="try.txt";

	long bufsize;						// the file size
	int padding = 0;					// the number of bits left which we fill with 0
	vector<unsigned char> outputBuffer; // encoded buffer after character coding according to the huffman algo

	map<unsigned char, string> characCodes; // map consisting of all the character with their respective huffman codes

	char arr[] = { 'w', 't', 'f'};
    int freq[] = { 1,1,1 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    auto root=HuffmanCodes(arr, freq, size);

	buildCharacterCodes(root, "", "", characCodes);

	unsigned char *buf = getBufferFromFile(path, &bufsize);

	string bitString = getBitString(buf, characCodes, bufsize, padding);

	bufsize=bitString.size();

	cout<<bitString<<endl;
	cout<<bufsize<<endl;

	getEncodedBufferFromBitString(bitString, outputBuffer, bufsize);

	unsigned char* output = outputBuffer.data();

	cout<<"hi"<<endl;
	cout<<outputBuffer.data()<<endl;

	writeHeader(output_path, characCodes, padding);

	cout<<bitString<<endl;

	writeBufferToFile(output_path, output, bufsize, 1);
}
