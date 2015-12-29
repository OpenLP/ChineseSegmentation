//无语料库的中文分词，C++实现
//author:@DGideas,@sunlanchang
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<locale>
using namespace std;
class word_freq //词频类，用于存储和统计词频
{
	public:
		wstring word; //词
		double freq; //词频
};
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
				str[j]=L' ';
			}
		}
	}
	wstring tmp; //临时字符串
	for(int i=0;i<str.size();i++) //将字符串以空格分隔，存入wstring数组中
	{
		if(str[i]!=L' ')
		{
			tmp+=str[i];
		}
		else
		{
			split.push_back(tmp);
			tmp=L"";
		}
	}
	for(int i=0;i<split.size();i++)
	{
		wcout<<split[i]<<endl;
	}
	return 0;
}
