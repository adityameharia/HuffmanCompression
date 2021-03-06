#include <bits/stdc++.h>

using namespace std;

struct Tree {
	int frequency;
	unsigned char charac;
	Tree *left = NULL;
	Tree *right = NULL;
};

void buildCharacterCodes(Tree *root, string prepend, string append, map<unsigned char, string> &chararCodes) {
	prepend = prepend + append;

	if (root->right == NULL && root->left == NULL) {
		chararCodes[root->charac] = prepend;
	}

	if (root->right != NULL) {
		buildCharacterCodes(root->right, prepend, "1", chararCodes);
	}

	if (root->left != NULL) {
		buildCharacterCodes(root->left, prepend, "0", chararCodes);
	}
}

unsigned char *getBufferFromFile(char *path, long *size) {
	unsigned char *source = NULL;
	FILE *fp = fopen("foo.txt", "r");
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

string getBitString(unsigned char *buf, map<unsigned char, string> characCodes, long size, int &padding) {

	string outputString = "";
	for (int i = 0; i < size; i++) {
		outputString = outputString + characCodes[buf[i]];
	}

	long lenOutputString = outputString.length();

	if (lenOutputString % 8 != 0) {
		int val = ((lenOutputString + 1) * 8) - lenOutputString;
		padding = val;

		for (int i = 0; i < val; i++) {
			outputString += "0";
		}
	}

	return outputString;
}

void getEncodedBufferFromBitString(string bitstring, vector<unsigned char> &outputBuffer, long &size) {
	//    bit=(bit<<1)|(arr[i]-'0');
    unsigned char bit=0;
    long checkByte=0;

    for(int i=0;i<size;i++){

        bit=(bit<<1)|(bitstring[i]-'0');

        checkByte++;

        if(checkByte%8==0){
            outputBuffer.push_back(bit);
            bit=0;
        }
    }
}

int main() {

	long bufsize;
	int padding = 0; // the number of bits left which we fill with 0
	vector<unsigned char> outputBuffer;

	map<unsigned char, string> characCodes;

	buildCharacterCodes(root, "", "", characCodes);

	unsigned char *buf = getBufferFromFile(path, &bufsize);

	string bitString = getBitString(buf, characCodes, bufsize, padding);

	getEncodedBufferFromBitString(bitString, outputBuffer, bufsize);
}
