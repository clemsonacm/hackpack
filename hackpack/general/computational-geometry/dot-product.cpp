#include<iostream>
#include<vector>

int dot_product(vector<int> v, vector<int> v2) {//Can convert all ints to doubles
	int result=0, length=v.size();
	if(v2.size()<length) length=v2.size();
	for(int c=0; c < length; c++) result += (v[c] * v2[c]);
	return result;
}
