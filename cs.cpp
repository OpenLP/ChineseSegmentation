//无语料库的中文分词，C++实现
//author:@DGideas,@sunlanchang
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<locale>
using namespace std;
int main(int argc,char *argv[])
{
	setlocale(LC_ALL, ""); //更改字符集为UTF-8
	wstring str=L"十四是十四，四十是四十。十四不是四十，四十不是十四。"; //待分词的字符串
	wstring symbol=L"，。！—；【】：《》"; //特殊符号
	vector<wstring> split; //分割后的字符串
	//wcout<<str<<endl;
	for (int i=0;i<symbol.size();i++)//删除标点符号
	{
		for (int j=0;j<str.size();j++)
		{
			if (symbol[i]==str[j])
			{
				str[j] =L' ';
			}
		}
	}
	
	wcout<<str<<endl;
	return 0;
}
