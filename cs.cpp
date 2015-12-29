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
		long long count(); //统计单词个数
		bool add(wstring); //添加新词
		void print(); //打印词频表中的词
		void calculate(long long); //统计词频方法
	private:
		vector<wstring> word; //词
		vector<double> freq; //词频
		vector<long long> times; //单词出现次数
};
long long word_freq::count()
{
	return this->word.size();
}
bool word_freq::add(wstring added_string)
{
	bool status=false; //该单词是否已经存在
	for(int i=0;i<this->word.size();i++)
	{
		if(this->word[i]==added_string)
		{
			status=true;
			this->times[i]++; //如果存在，则增加出现次数
		}
	}
	if(status==false)
	{
		this->word.push_back(added_string);
		this->freq.push_back(0.0);
		this->times.push_back(1);
		return true;
	}
	else
	{
		return false;
	}
}
void word_freq::print()
{
	for(int i=0;i<this->word.size();i++)
	{
		wcout<<L"*"<<this->word[i]<<L":"<<this->freq[i]<<L"@"<<this->times[i]<<endl;
	}
	return;
}
void word_freq::calculate(long long word_total)
{
	for(int i=0;i<this->word.size();i++)
	{
		this->freq[i]=(double)this->times[i]/(double)word_total;
	}
	return;
}
int main(int argc,char *argv[])
{
	setlocale(LC_ALL, ""); //更改字符集为UTF-8
	wstring str=L"十四是十四，四十是四十。十四不是四十，四十不是十四。"; //待分词的字符串
	wstring symbol=L"，。！—；【】：《》"; //特殊符号
	vector<wstring> split; //分割后的字符串
	vector<wstring> words; //最后得出的分词结果
	word_freq L_freq,R_freq,freq; //词频统计类:左邻字，右邻字，单字
	//wcout<<str<<endl;
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
	for(long long i=0;i<split.size();i++) //构建左邻字集合
	{
		tmp=L"";
		wstring single_tmp;
		for(long long j=0;j<split[i].size();j++)
		{
			tmp+=split[i][j];
			L_freq.add(tmp);
			single_tmp=split[i][j];
			freq.add(single_tmp);
		}
	}
	L_freq.calculate(str.size());
	L_freq.print();
	freq.calculate(str.size());
	freq.print();
	for(int i=0;i<split.size();i++)
	{
		wcout<<split[i]<<endl;
	}
	return 0;
}
