//无语料库的中文分词，C++实现，标准库
//https://github.com/OpenLP/ChineseSegmentation/wiki
//author:@DGideas
class word_freq
{
	public:
		long long count();
		bool add(wstring);
		void print(double);
		void calculate(long long);
		long long query(wstring);
	private:
		vector<wstring> word;
		vector<double> freq;
		vector<long long> times;
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
class entropy
{
	
};
class entropy_array
{
	public:
		bool addItem(wstring);
		bool addLbhd(wstring,wstring);
		bool addRbhd(wstring,wstring);
	private:
		vector<entropy> etp;
		vector<wstring> etp_key;
};
bool entropy_array::addItem(wstring itemName)
{
	bool status=false;
	for(long long i=0;i<this->etp_key.size();i++)
	{
		if(etp_key[i]==itemName)
		{
			status=true;
			break;
		}
	}
	if(status==true)
	{
		return false;
	}
	entropy etp_i;
	etp.push_back(etp_i);
	etp_key.push_back(itemName);
	return true;
};
