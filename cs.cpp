//无语料库的中文分词，C++实现
//author:@DGideas,@sunlanchang
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
	vector<wstring> split; //分割后的字符串
	vector<wstring> words; //最后得出的分词结果
	vector<entropy> eto; //信息熵类
	word_freq L_freq,freq; //词频统计类:左邻字，单字
	for (int i=0;i<symbol.size();i++)//删除标点符号
	{
		for (long long j=0;j<str.size();j++)
		{
			if (symbol[i]==str[j])
			{
				str[j]=L' ';
			}
		}
	}
	wstring tmp; //临时字符串
	for(long long i=0;i<str.size();i++) //将字符串以空格分隔，存入wstring数组中
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
	for(long long i=0;i<split.size();i++) //迭代地构建左邻字集合
	{
		wstring single_tmp;
		for(long long h=0;h<split[i].size();h++)
		{
			tmp=L"";
			for(long long j=h;j<split[i].size();j++)
			{
				tmp+=split[i][j];
				if(tmp.size()>1)
				{
					L_freq.add(tmp);
				}
				single_tmp=split[i][j];
				freq.add(single_tmp);
			}
		}
	}
	L_freq.calculate(str.size());
	L_freq.print();
	freq.calculate(str.size());
	freq.print();
	//计算信息熵
	/*
	for(long long i=0;i<split.size();i++)
	{
		wcout<<split[i]<<endl;
	}*/
	return 0;
}
