#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>

int main(int n, char** args)
{
	std::ifstream fin(args[1],std::ios::in);
	std::string code="";
	std::string file_name=args[1];

	if(!fin)
		std::cout<<"File not found";
	else
	{
		char ch;
		while(fin.get(ch))
			code.push_back(ch);
		fin.close();
	}

	if(code.length()>0)
	{
		file_name=file_name.erase(file_name.length()-3,3);
		file_name=file_name+"jcv";
		std::ofstream fout;
		fout.open(file_name.c_str(),std::ios::binary);
		std::stringstream ss(code);
		unsigned int int_inp;
		unsigned char ch;
		while(ss>>int_inp)
		{
			ch=(unsigned char)int_inp;
			fout.write((char*)&ch,1);
		}
		ch=EOF;
		fout.write((char*)&ch,1);
		fout.close();
	}
}
