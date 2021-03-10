#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <unordered_map>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

inline bool exists_test0 (const string& name) {
    ifstream f(name.c_str());
    return f.good();
}


std::string get_current_dir() {
   char buff[FILENAME_MAX]; //create string buffer to hold path
   GetCurrentDir( buff, FILENAME_MAX );
   string current_working_dir(buff);
   return current_working_dir;
}


int main(int argc, char** argv)
{	

	string path=argv[1];
	if(exists_test0(path)==0){
		cout<<"file doesnt exist"<<endl;
		exit(0);
	}

	unordered_map <string,unsigned char> huff;

	unsigned char huff_char;
	int huff_size;
	char* huff_code;
	char huff_code_char;

	ifstream fin(path,ios::in | ios::binary);

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


	ofstream fout(argv[2]);

	char inp;
	char mask = 128;
	char move = 0;
	char one = '1';
	char zero = '0';
	string charecter = "" ;
	
	int pos = fin.tellg();       // Save current position
	
	fin.seekg(-1,ios::end);		 // Get to the end of file
	
	int last_byte = fin.tellg(); // Save the number of the last byte
	
	fin.seekg(pos,ios::beg); 	 // Reset

	while(true)
	{
		
		fin.get(inp);
				
		if( fin.tellg() == last_byte + 1 ) 
		{		
			for ( int i = 0 ; i < 8 - padding ; i++ )
			{	
				move = inp & mask;
				move = move >> 7;
				inp  = inp << 1;
	
				charecter.push_back((int)move ? '1' : '0');
	
				if ( huff.find(charecter) == huff.end() )
					continue;
				else
				{
					fout<<huff[charecter];
					charecter = "";
				}	
			}
			
			break;
		}		
		
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
				fout<<huff[charecter];
				charecter = "";
			}	
		}	
	}
}