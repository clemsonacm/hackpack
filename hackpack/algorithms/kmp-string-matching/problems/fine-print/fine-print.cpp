#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Read input.
	string text = "", buffer = "";
	while(!cin.eof()) { getline(cin, buffer); text += buffer; }

	// KMP algorithm to find keyword.
	const string keyword = "pool";
	long match_idx = -1;
	for(unsigned int i = 0; i < text.length(); i++)
	{
		// Consider a possible match
		if(text[i] == keyword[0])
		{
			unsigned int can_skip = 0;
			bool using_submatch = false; // Has a possible submatch been found?
			unsigned int submatch_beg = 0; // The beginning of the submatch
			unsigned int submatch_idx = 0; // Where the submatch is matching

			for(unsigned int m = 1; m <= keyword.length() && i + m < text.length(); m++)
			{
				if(m == keyword.length()) { match_idx = i; break; } // Complete match.

				// Consider submatches
				if(!using_submatch && text[i + m] == keyword[0])
				{
					using_submatch = true;
					submatch_idx = 1;
					submatch_beg = i + m;
				}
				else // Submatch process in progress concurrently.
				{
					if(text[i + m] == keyword[submatch_idx]) submatch_idx++; // Submatched matched character.
					if(text[i + m] != keyword[submatch_idx]) using_submatch = false; // Submatch mismatch.
				}
				
				if(text[i + m] == keyword[m]) can_skip++; // Matched character.
				else // Mismatch.
				{
					if(using_submatch) // Start from submatch
					{
						using_submatch = false;
						m = submatch_idx;
						i += submatch_beg;
					}
					else break;
				}
			}
			i += (1 + can_skip);
		}
	}

	if(match_idx == -1) cout << "The agreement does not mention a pool." << endl;
	else // Pick out the sentence.
	{
		unsigned int beg = match_idx;
		unsigned int end = match_idx + keyword.length();
		while(text[beg - 2] != '.' && beg > 0) beg--;
		while(text[end] != '.') end++;
		cout << text.substr(beg, end - beg + 1) << endl;
	}

	return 0;
}
