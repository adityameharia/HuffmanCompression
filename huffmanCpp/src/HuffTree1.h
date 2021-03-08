#pragma once
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};
Node* getNode(char ch, int freq, Node* left, Node* right);
void encode(Node* root, string str,
			unordered_map<char, string> &huffmanCode);
            string HuffmanTree(string tp);