//无语料库的中文分词，C++实现，标准库
//author:@DGideas
class word_freq //词频类，用于存储和统计词频
{
	public:
		long long count(); //统计单词个数
		bool add(wstring); //添加新词
		void print(); //打印词频表中的词
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
long long word_freq::query(wstring w)
{
	for(int i=0;i<this->word.size();i++)
	{
		if(this->word[i]==w)
		{
			return this->times[i];
		}
	}
	return 0;
}
class entropy //信息熵类
{
	public:
		wstring letter; //信息熵计算的字
		double L_bhd_entropy; //左邻字信息熵
		double R_bhd_entropy; //右邻字信息熵
		vector<wstring> L_bhd; //左邻字
		vector<wstring> R_bhd; //右邻字
};
