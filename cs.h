//无语料库的中文分词，C++实现，标准库
//author:@DGideas
class word_freq //词频类，用于存储和统计词频；统计词语的凝聚程度
{
	public:
		long long count(); //统计单词个数
		bool add(wstring); //添加新词
		void print(double); //打印词频表中的词
		void calculate(long long); //统计词频方法
		long long query(wstring); //查询词信息
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
	bool status=false;
	for(long long i=0;i<this->word.size();i++)
	{
		if(this->word[i]==added_string)
		{
			status=true;
			this->times[i]++;
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
void word_freq::print(double freq_limit_min=0.0)
{
	for(long long i=0;i<this->word.size();i++)
	{
		if(this->freq[i]>=freq_limit_min)
		{
			wcout<<L"*"<<this->word[i]<<L":"<<this->freq[i]<<L"@"<<this->times[i]<<endl;
		}
	}
	return;
}
void word_freq::calculate(long long word_total)
{
	for(long long i=0;i<this->word.size();i++)
	{
		this->freq[i]=(double)this->times[i]/(double)word_total;
	}
	return;
}
long long word_freq::query(wstring w)
{
	for(long long i=0;i<this->word.size();i++)
	{
		if(this->word[i]==w)
		{
			return this->times[i];
		}
	}
	return 0;
}
class entropy //信息熵类；用于统计词语的自由程度
{
	public:
		entropy()
		{
			wcout<<L"欢迎使用信息熵类！"<<endl;
		}
		vector<wstring> letter; //信息熵计算的字
		vector<double> L_bhd_entropy; //左邻字信息熵
		vector<double> R_bhd_entropy; //右邻字信息熵
		vector<vector<wstring> > L_bhd; //左邻字
		vector<vector<wstring> > R_bhd; //右邻字
};
