#include<fstream>
#include<string>
#include<time.h>        
#include<cmath>
#include<stdlib.h>
#include<iostream>

int graph[20][50];

using namespace std;

void floodfill4(int Sy,int Sx,int oldnumber,int newnumber){
	 	
  if(graph[Sy][Sx]!= oldnumber) return;
  graph[Sy][Sx] = newnumber;
  floodfill4(Sy-1, Sx, oldnumber,newnumber);
  floodfill4(Sy+1, Sx, oldnumber,newnumber);
  floodfill4(Sy, Sx-1, oldnumber,newnumber);
  floodfill4(Sy, Sx+1, oldnumber,newnumber);
}
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
  int Sx,Sy,Tx,Ty;
  Tx=  3;
  Ty= 18;
  Sx= 24;
  Sy=  9;       
  floodfill4(Sy,Sx,oldnumber,newnumber);  
   
  for(int i=0; i < 20; i++){
    for(int j=0; j < 50; j++){
	   cout << graph[i][j];
	 } cout << "\n";     
  }    
  cout << "\n";
  cout << "\n"; 
  
  return 0;
}  
