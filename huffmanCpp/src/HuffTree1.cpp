#include "HuffTree1.h"
using namespace std;

// A Tree node

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

// Comparison object to be used to order the heap
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};

// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(Node* root, string str,
			unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

//...........

 string HuffmanTree(string tp)
{
	// Define an unordered_map
	unordered_map<char, int> M;

	// Traverse string str check if
	// current character is present
	// or not
	for (int i = 0; tp[i]; i++) 
	{
		// If the current characters
		// is not found then insert
		// current characters with
		// frequency 1
		if (M.find(tp[i]) == M.end()) 
		{
			M.insert(make_pair(tp[i], 1));
		}

		// Else update the frequency
		else
		{
			M[tp[i]]++;
		}
	}

	// Traverse the map to print the
	// frequency
	for (auto& it : M) {
		cout << it.first << ' ' << it.second << '\n';
	}
    priority_queue<Node*, vector<Node*>, comp> pq;

	// Create a leaf node for each character and add it
	// to the priority queue.
	for (auto pair: M) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
		// Remove the two nodes of highest priority
		// (lowest frequency) from the queue
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();

		// Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	// root stores pointer to root of Huffman Tree
	Node* root = pq.top();

	// traverse the Huffman Tree and store Huffman Codes
	// in a map. Also prints them
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "Huffman Codes are :\n" << '\n';
	for (auto pair: huffmanCode) {
		cout << pair.first << " " << pair.second << '\n';
	}

	

	// print encoded string
	string str = "";
	for (char ch: tp) {
		str += huffmanCode[ch];
	}

	cout << "\nEncoded string is :\n" << str << '\n';
    return str;
 }


// Huffman coding algorithm
int main()
{
	 string tp="hamlet text";
	 HuffmanTree(tp);
	
	/*string tp;
		fstream newfile;
		newfile.open("code.txt",ios::in); //open a file to perform read operation using file object
		if (newfile.is_open()){ //checking whether the file is open
			
			while(getline(newfile, tp)){ //read data from file object and put it into string.
				cout << tp << ""; //print the data of the string
				 
			}
		
			newfile.close(); //close the file object.
				
		}*/
     
	 
   
	return 0;
}