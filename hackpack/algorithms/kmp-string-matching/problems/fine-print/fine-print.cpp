#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<unsigned int> match_idxs;

// Create the partial match table.
int* build_table(string s)
{
	int* table = new int[s.length()]();
	fill(table, table + s.length(), 0);
	for(int str_sz = 1; str_sz <= s.length(); str_sz++)
	{
		if(str_sz == 1) continue;
		for(int curr_len = str_sz - 1; curr_len > 0; curr_len--)
		{
			// Take the first and last 'curr_len' characters.
			string prefix = s.substr(0, curr_len);
			string suffix = s.substr(str_sz - curr_len, curr_len);

			// Keep the length of longest matching prefix and suffix.
			if(prefix == suffix) { table[str_sz - 1] = curr_len; break; }
		}
	}

	return table;
}

int main()
{
	// Read input.
	string text = "", buffer = "";
	while(!cin.eof()) { getline(cin, buffer); text += buffer; }

	// KMP algorithm to find keyword.
	const string keyword = "pool";
	int* pm_table = build_table(keyword);
	for(unsigned int i = 0; i < text.length() - keyword.length(); i++)
	{
		// Consider a possible match
		if(text[i] == keyword[0])
		{
			for(unsigned int m = 1; m <= keyword.length(); m++)
			{
				// Complete match
				if(m == keyword.length()) { match_idxs.push_back(i); break; }

				// Mismatch
				if(text[i + m] != keyword[m])
				{
					// Consult table to see where to start 'i' at.
					const unsigned int pm_len = m + 1;
					i += pm_len - pm_table[pm_len - 1];

					// It will be necessary to negate the next loop's i++.
					i--;
					break;
				}
			}
		}
	}

	if(match_idxs.size() == 0) cout << "The agreement does not mention a pool." << endl;
	else // Pick out the sentence.
	{
		unsigned int beg = match_idxs[0];
		unsigned int end = match_idxs[0] + keyword.length();
		while(text[beg - 2] != '.' && beg > 0) beg--;
		while(text[end] != '.') end++;
		cout << text.substr(beg, end - beg + 1) << endl;
	}

	return 0;
}
