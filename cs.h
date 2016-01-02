class word_freq
{
		public:
				long long count();
				bool add(wstring);
				void print(double);
				void calculate(long long);
				long long query(wstring);
				vector<wstring> word;
				vector<double> freq;
				vector<long long> times;
};
long long word_freq::count()
{
		return word.size();
}
bool word_freq::add(wstring added_string)
{
		bool status=false;
		for(long long i=0;i<word.size();i++)
		{
				if(word[i]==added_string)
				{
						status=true;
						times[i]++;
				}
		}
		if(status==false)
		{
				word.push_back(added_string);
				freq.push_back(0.0);
				times.push_back(1);
				return true;
		}
		else
		{
				return false;
		}
}
void word_freq::print(double freq_limit_min=0.0)
{
		for(long long i=0;i<word.size();i++)
		{
				if(freq[i]>=freq_limit_min)
				{
						wcout<<L"*"<<word[i]<<L":"<<freq[i]<<L"@"<<times[i]<<endl;
				}
		}
		return;
}
void word_freq::calculate(long long word_total)
{
		for(long long i=0;i<word.size();i++)
		{
				freq[i]=(double)times[i]/(double)word_total;
		}
		return;
}
long long word_freq::query(wstring w)
{
		for(long long i=0;i<word.size();i++)
		{
				if(word[i]==w)
				{
						return times[i];
				}
		}
		return 0;
}
class entropy
{
		public:
				void calculate();
				wstring word;
				vector<wstring> Lbhd;
				vector<wstring> Rbhd;
				double Letp;
				double Retp;
};
void entropy::calculate()
{
	
}
class entropy_array
{
		public:
				long long fndItem(wstring);
				bool addItem(wstring);
				bool addLbhd(wstring,wstring);
				bool addRbhd(wstring,wstring);
		private:
				vector<entropy> etp;
				vector<wstring> etp_key;
};
long long entropy_array::fndItem(wstring itemName)
{
		bool status=false;
		long long location;
		for(long long i=0;i<etp_key.size();i++)
		{
				if(etp_key[i]==itemName)
				{
						status=true;
						location=i;
						break;
				}
		}
		if(status==false)
		{
				return -1;
		}
		else
		{
				return location;
		}
}
bool entropy_array::addItem(wstring itemName)
{
		long long status=fndItem(itemName);
		if(status!=-1)
		{
				return false;
		}
		entropy etp_i;
		etp_i.word=itemName;
		etp.push_back(etp_i);
		etp_key.push_back(itemName);
		return true;
}
bool entropy_array::addLbhd(wstring itemName,wstring Lbhd)
{
		long long status=fndItem(itemName);
		if(status==-1)
		{
				return false;
		}
		etp[status].Lbhd.push_back(Lbhd);
		return true;
}
bool entropy_array::addRbhd(wstring itemName,wstring Rbhd)
{
		long long status=fndItem(itemName);
		if(status==-1)
		{
				return false;
		}
		etp[status].Rbhd.push_back(Rbhd);
		return true;
}
