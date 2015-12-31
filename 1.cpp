//author:@DGideas
//Every setback has a major comeback.
using namespace std;
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<locale>
#include"cs.h"
int main(int argc,char *argv[])
{
	setlocale(LC_ALL, "");
	wstring str=L"十四是十四，四十是四十。十四不是四十，四十不是十四。";
	vector<wstring> split;
	wstring symbol=L"，。！—；【】：《》";
	word_freq L_freq,freq;
	for(int i=0;i<symbol.size();i++)
	{
		for(int j=0;j<str.size();j++)
		{
			if(str[j]==symbol[i])
			{
				str[j]=L' ';
			}
		}
	}
	wstring tmp;
	for(int i=0;i<str.size();i++)
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
		for(int j=0;j<split[i].size();j++)
		{
			tmp=L"";
			for(int h=j;h<split[i].size();h++)
			{
				tmp+=split[i][h];
				if(tmp.size()>1)
				{
					L_freq.add(tmp);
				}
			}
		}
	}
	L_freq.calculate(str.size());
	L_freq.print();
	wcout<<str<<endl;
	return 0;
}
