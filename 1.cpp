//无语料库的中文分词，C++实现
//author:@DGideas
using namespace std;
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<locale>
#include"cs.h"
int main(int argc,char *argv[])
{
	setlocale(LC_ALL, ""); //更改字符集为UTF-8
	wstring str=L"十四是十四，四十是四十。十四不是四十，四十不是十四。"; //待分词的字符串
	wstring symbol=L"，。！—；【】：《》"; //特殊符号
	return 0;
}
