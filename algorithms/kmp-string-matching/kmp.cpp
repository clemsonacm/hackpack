// build partial match table
int const* build_table(const string& s)
{
	int* const table = new int[s.length()];
	fill(table, table + s.length(), 0);
	for(unsigned int str_sz = 1; str_sz <= s.length(); str_sz++)
	{
		if(str_sz == 1) continue;
		for(int curr_len = str_sz - 1; curr_len > 0; curr_len--)
		{
			string prefix = s.substr(0, curr_len);
			string suffix = s.substr(str_sz - curr_len, curr_len);
			if(prefix == suffix) { table[str_sz - 1] = curr_len; break; }
		}
	}

	return table;
}

int main()
{
	// assign these
	string text;
	string keyword;

	const int* const pm_table = build_table(keyword);
	for(unsigned int i = 0; i <= text.length() - keyword.length() && text.length() >= keyword.length(); i++)
	{
		if(text[i] == keyword[0])
		{
			for(unsigned int m = 1; m <= keyword.length(); m++)
			{
				if(m == keyword.length()) {} // complete match
				else if(text[i + m] != keyword[m])
				{
					i += m - pm_table[m - 1];
					i--;
					break;
				}
			}
		}
	}

	return 0;
}
