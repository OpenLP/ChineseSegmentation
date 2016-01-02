//author:@DGideas
//Every setback has a major comeback
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
	wstring str=L"这是一段测试文字，之所以叫测试文字，是因为我们在实际生产中，着重对程序代码进行测试。我们认为，只有经过多次测试的代码，才是好代码。";
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
			wstring c_tmp;
			c_tmp=split[i][j];
			freq.add(c_tmp);
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
	freq.calculate(str.size());
	//freq.print();
	wcout<<str<<endl;
	return 0;
}
