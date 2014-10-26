#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int numberOfArgs, char** args)
{
	// Read input.
	string text = "", buffer = "";
	ifstream file(args[1]);
	while(!file.eof())
	{
		getline(file, buffer);
		text += buffer;
	}
	file.close();

	// KMP algorithm to find keyword.
	const string keyword = "pool";
	long match_idx = -1;
	for(unsigned int i = 0; i < text.length(); i++)
	{
		// Consider a possible match
		if(text[i] == keyword[0])
		{
			unsigned int skip = 0;
			bool using_submatch = false;
			unsigned int submatch_idx = 0;
			unsigned int submatch_beg = 0;
			for(unsigned int m = 1; m <= keyword.length() && i + m < text.length(); m++)
			{
				if(m == keyword.length()) { match_idx = i; break; } // Complete match.

				if(!using_submatch && text[i + m] == keyword[0])
				{
//					cout << "Possible submatch: " << text.substr(i + m, 4) << endl;
					using_submatch = true;
					submatch_idx = 1;
					submatch_beg = i + m;
				}
				else
				{
					if(text[i + m] == keyword[submatch_idx]) submatch_idx++;
					if(text[i + m] != keyword[submatch_idx]) using_submatch = false;
				}
				
				if(text[i + m] == keyword[m]) skip++; // Matched character.
				else break; // Mismatch.
				else // Mismatch.
				{
//					cout << "Mismatch occured." << endl;
					// Don't break the loop. Set 'i' to the beginning
					// of the submatch.
					if(using_submatch)
					{
//						cout << "Submatch was in use. Starting matching at index " << i + submatch_idx << " (\'" << text[i + submatch_idx] << "\')." << endl;
//						cout << "The match is quite possibly at index " << submatch_beg << endl;
//						cout << "Testing " << text.substr(submatch_beg, keyword.length()) << endl;
						using_submatch = false;
						m = submatch_idx;
						i += submatch_beg;
					}
					// No possible submatches.
					else break;
				}
			}
			i += (1 + skip);
		}
	}

	if(match_idx == -1) cout << "The agreement does not mention a pool." << endl;
	else
	{
		unsigned int beg = match_idx;
		unsigned int end = match_idx + keyword.length();
		while(text[beg - 2] != '.' && beg > 0) beg--;
		while(text[end] != '.') end++;
		cout << text.substr(beg, end - beg + 1) << endl;
	}

	return 0;
}
