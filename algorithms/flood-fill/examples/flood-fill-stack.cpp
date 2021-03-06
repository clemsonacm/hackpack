#include<time.h>        
#include<cmath>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<fstream>
#include<string>

using namespace std;

typedef pair<int,int> pii;
stack<pii> S;
int graph[20][50]; //global graph

void floodfill(int oldval, int newval){
   while (!S.empty()){
      int i = S.top().first, j = S.top().second;
      S.pop();

      if(graph[i][j] == oldval) {
         graph[i][j] = newval;
         S.push(pii(i-1,j));
         S.push(pii(i+1,j));
         S.push(pii(i,j-1));
         S.push(pii(i,j+1));
}}}

int main(){
  
  int y=0,z=0;
  ifstream file;
  file.open ("input.in");
  string s;
  cout << "\n";
  
  while(!file.eof()){  
    getline(file,s);  
    z = s.length();
    
    for(int x=0; x < z ; x++){
	   graph[y][x]= s[x] - '0';
	 }
	 
	 y++;
	 if(y==20) break;  
  }
  
  file.close();
  cout << "\n";
        
  int oldnumber=2;
  int newnumber=1;
  S.push(pii(9, 24)); 
  floodfill(oldnumber,newnumber);  
    
  for(int i=0; i < 20; i++){
    for(int j=0; j < 50; j++){
	   cout << graph[i][j];
	 } cout << "\n";     
  }    
  cout << "\n";
 
  return 0;
}  
