#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int const* build_table(const string& s)
{
	int* const table = new int[s.length()];
	fill(table, table + s.length(), 0);
	for(unsigned int str_sz = 1; str_sz <= s.length(); str_sz++)
	{
		if(str_sz == 1) continue;
		for(int curr_len = str_sz - 1; curr_len > 0; curr_len--)
		{
			const string prefix = s.substr(0, curr_len);
			const string suffix = s.substr(str_sz - curr_len, curr_len);
			if(prefix == suffix) { table[str_sz - 1] = curr_len; break; };
		}
	}

	return table;
}

int main(int numberOfArgs, char** args)
{
	unsigned int cases = 0;

	while(!cin.eof())
	{
		unsigned int expected = 0;
		unsigned int matches = 0;

		cases++;
		cout << "Test #" << cases << ":\t";
		string buffer = "", keyword = "", text = "";
		
		getline(cin, buffer);
		expected = atoi(buffer.c_str());

		getline(cin, keyword);
		getline(cin, text);

		int const* const pm_table = build_table(keyword);
		for(unsigned int i = 0; i <= text.length() - keyword.length() && text.length() >= keyword.length(); i++)
		{
			if(text[i] == keyword[0])
			{
				for(unsigned int m = 1; m <= keyword.length(); m++)
				{
					if(m == keyword.length())
					{
						matches++;
						const unsigned int pm_len = m;
						i += pm_len - pm_table[pm_len - 1];
						i--;
						break;
					}
					if(text[i + m] != keyword[m])
					{
						const unsigned int pm_len = m;
						i += pm_len - pm_table[pm_len - 1];
						i--;
						break;
					}
				}
			}
		}
		if(matches == expected) { cout << "Passed." << endl; }
		else{ cout << "Failed. Got " << matches << "; expected " << expected << "." << endl; }
		getline(cin, buffer);
	}

	return 0;
}

