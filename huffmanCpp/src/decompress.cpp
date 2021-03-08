#include <bits/stdc++.h>
using namespace std;

int main()
{
	unordered_map <string,unsigned char> huff;

	unsigned char huff_char;
	int huff_size;
	char* huff_code;
	char huff_code_char;

	ifstream fin("try.txt",ios::in | ios::binary);

	int padding;
	int map_size;

	fin.read((char*)&padding,sizeof(int));
	fin.read((char*)&map_size,sizeof(int));

	for ( int i = 0 ; i < map_size ; i++ )
	{
		
		fin.read((char*)&huff_char,sizeof(unsigned char));
		fin.read((char*)&huff_size,sizeof(int));

		huff_code = new char[huff_size + 1];
		for ( int j = 0 ; j < huff_size ; j++ )
		{
			fin.read((char*)&huff_code_char,sizeof(char));
			huff_code[j] = huff_code_char;
		}	

		huff_code[huff_size] = '\0';

		huff.insert(make_pair(huff_code,huff_char));

		delete huff_code;

		
	}

	for (auto i = huff.begin(); i != huff.end(); i++) 
	{
		cout<<i->first<<" : "<<i->second<< '\n';
	}

	cout<<"\n\n----------------------\n";


	ofstream fout("../decompression_sample/decompressed.txt");

	char inp;
	char mask = 128;
	char move = 0;
	char one = '1';
	char zero = '0';
	string charecter = "" ;

	//while ( !fin.eof() )
	while(true)
	{
		fin.get(inp);
		//added by adi
		if(fin.eof())break;
		for ( int i = 0 ; i < 8 ; i++ )
		{
			move = inp & mask;
			move = move >> 7;
			inp  = inp << 1;

			charecter.push_back((int)move ? '1' : '0');

			if ( huff.find(charecter) == huff.end() )
				continue;
			else
			{
				cout<<huff[charecter];
				fout<<huff[charecter];
				charecter = "";
			}

		}
		
		
	}
}


