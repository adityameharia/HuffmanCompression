#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream fin("./decompression_sample/sample.adi",ios::in | ios::binary);

	const node *root = ?;
	node* curr;


	char inp;
	char mask = 128;
	char move = 0;

	while ( !fin.eof() )
	{
		fin.get(inp);
		cout<<inp<<" ";
		for ( int i = 0 ; i < 8 ; i++ )
		{
			move = inp & mask;
			move = move >> 8;
			inp  = inp << 1;

			cout<<((int)move ? 1 : 0)<<" ";

			if ( move)
				curr = curr->right;
			else
				curr = curr->left;

			if ( curr->next )
			{
				cout<<curr->data;
				curr = root;
			}



		}
		cout<<endl;
		cout<<"-----------------------\n";

	}

}


