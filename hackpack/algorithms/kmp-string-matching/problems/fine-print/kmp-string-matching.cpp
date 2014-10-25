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
	unsigned int begin_at = 0;
	long loc = -1;
	for(unsigned int i = 0; i < text.length(); i++)
	{
		// Consider a possible match
		if(text[i] == keyword[0])
		{
			begin_at = i;
			for(int j = 0; j < keyword.length() && i + j < text.length(); j++)
			{
				// If the next letter to match does not match the first of
				// the keyword, 'i' can be moved forward.
				if(text[i + j] != keyword[0]) begin_at = i + j;
				if(text[i + j] != keyword[j]) break; // Mismatch occurred.
				if(j == keyword.length() - 1) { loc = i; break; } // Match found.
			}
			if(loc >= 0) break;		// Finish on first match found...
			else i = begin_at;		// or continue from where the prospective matching halted.
		}
	}

	if(loc == -1) cout << "Nothing about a swimming pool." << endl;
	else
	{
		unsigned int beg = loc;
		unsigned int end = loc + keyword.length();
		while(text[beg - 2] != '.') beg--;
		while(text[end] != '.') end++;
		cout << text.substr(beg, end - beg + 1) << endl;
	}

	return 0;
}
