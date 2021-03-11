#pragma once
#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode {

    char data;
 
    unsigned freq;
 
    MinHeapNode *left, *right;
 
    MinHeapNode(char data, unsigned freq)
 
    {
 
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
 
    bool operator()(MinHeapNode* l, MinHeapNode* r)
 
    {
        return (l->freq > r->freq);
    }
};

void findFreq( ifstream& fin , map<unsigned char,int>& huff );
MinHeapNode* HuffmanCodes(map<unsigned char,int>freqtable);
void buildCharacterCodes(MinHeapNode *root, string prepend, string append, map<unsigned char, string> &chararCodes);
unsigned char *getBufferFromFile(string path, long *size) ;
string getBitString(unsigned char *buf, map<unsigned char, string> characCodes, long size, int &padding);
unsigned char* getEncodedBufferFromBitString(string bitstring, vector<unsigned char> &outputBuffer, long& size);
void writeBufferToFile(char *path, unsigned char *buffer, int sz, int flag);
void writeHeader(char* path, map<unsigned char, string> characCodes, int padding) ;
void compress(string path,char* output_path);