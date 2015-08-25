


/*
The ideal holiday for many people involves being on the white sand of a sunny 
beach on a tropical island, drinking cocktails under the palm trees and 
swimming, snorkelling and diving in the clear blue waves. The Algorithmic 
Archipelago is the ideal place for such a holiday as it consists of countless
 beautiful islands. Since many tourists spend their holidays (and money) on 
 these islands, you decided to enter the tourism industry and buy an island. 
 The cost of an island is proportional to its area, but the number of tourists 
 that visit an island is proportional to the length of its beaches, i.e., the 
 perimeter of the island. Your task is to select the island where the profit 
 per investment ratio is the highest: where the ratio of the perimeter and the 
 area is maximum. Out of curiosity, you would like the determine the minimum of 
 this ratio aswell.

In the input you are given the map of the archipelago as an n×n matrix. Each 
cell contains either water or land. An island is a connected area of land.

Two cells sharing only a corner are not considered to be neighbours. 
(Therefore, there are 3 islands in the sample input). It can happen that an 
island contains one or more lakes. The perimeter of these lakes also contribute
to the perimeter of the island. It can happen that the lake on an island 
contains further islands. These are considered to be separate islands, and the 
area of these islands does not contribute to the area of the island containing 
them.We assume that there is water in the area outside the map.

//////////////////////
Input 

The input contains several blocks of test cases. Each case begins with a line 
containing a single integer 1 <= n <= 400, the size of the map. This is 
followed by n lines, each containing n characters. Character `.' means water 
and character `X' means land. It can be assumed that the map contains not only 
water. The input is terminated by a test case with n = 0 .

///////////////////////
Output 

For each test case, you have to output a line containing two real numbers, 
separated by a space: the maximum and the minimum of the ratio of the perimeter 
and the area. To avoid rounding problems, we accept solutions with a maximum of
 ±0.001 error.

///////////////////////
Sample Input 

8
....XXXX
.XXX.XXX
XX.XX...
XX...XX.
X.XXX.XX
X.XXX.XX
X....XX.
XXXXXX..
0

///////////////////////
Sample Output 

1.923 1.66613

*/

#include<fstream>
#include<string>
#include<time.h>        
#include<cmath>
#include<stdlib.h>
#include<iostream>

char graph[8][8];
char newval[8]={'0','1','2','3','4','5','6','\0'};
int  mapsize;

using namespace std;

void floodfill4( int Sy,int Sx,char oldval,int k){

  if(graph[Sy][Sx]!= oldval) return;
  graph[Sy][Sx]=newval[k];
  floodfill4( Sy-1, Sx, oldval,k);
  floodfill4( Sy+1, Sx, oldval,k);
  floodfill4( Sy, Sx-1, oldval,k);
  floodfill4( Sy, Sx+1, oldval,k); 
}

int main(){
 
  int y=0;
  ifstream file;
  file.open ("how-many-islands.in");
  string s;
  cout << "\n";
  
  getline(file,s); 
  mapsize   = s[0] - '0';
  getline(file,s);
  char map[mapsize][mapsize];
  
  while(!file.eof()){  
    for(int x=0; x < mapsize ; x++){
	   map[y][x]= s[x];
	 }
	 getline(file,s);
	 y++;
	 if (y == mapsize) break;  
  }
  file.close();
  cout << "\n";  
  
    
  for(int i=0; i < mapsize; i++){
    for(int j=0; j < mapsize ; j++){
	   cout << map[i][j];
	 } cout << "\n";     
  }    
  cout << "\n";
  cout << "\n"; 
  
  for(int i=0; i < mapsize; i++){
    for(int j=0; j < mapsize ; j++){
	   graph[i][j] = map[i][j];
	 }     
  }
  
  char val;   
  char oldval= 'X';
  int k=0;
  for(int i=0; i < mapsize; i++){
    for(int j=0; j < mapsize ; j++){
	   if(graph[i][j] == oldval){
	     floodfill4(i,j,oldval,k);
	     k++;
	   }
	 }
  }      
  /*
  int Beach[mapsize];
  int Area[mapsize];    
  for(int i=0; i < mapsize; i++){
    for(int j=0; j < mapsize ; j++){
	   map[i][j] = graph[i][j];
	   if (graph[i][j] == '0'){
	    Area[0] += 1;
	    Beach[0] = i;
	   }
	   if (graph[i][j] == '1'){
	    Area[1] += 1;
	    Beach[1] = i;
	   }
	   //if (graph[i][j] == '2'){
	   // Area[2] += 1;
	   // Beach[2] = i;
	   //}
	 }
  }  
   int ratio[mapsize];
   ratio[0] = Area[0] / (Area[0] + (2*Beach[0]));
   ratio[1] = Area[1] / (Area[1] + (2*Beach[1]));
   //ratio[2] = Area[2] / (Area[2] + (2*Beach[2]));   
    
   for(int i=0; i < 1; i++){ 
   cout <<  ratio[i] << "  ";
   }cout << "\n";  */
        
  for(int i=0; i < mapsize; i++){
    for(int j=0; j < mapsize ; j++){
	   cout << graph[i][j];
	 } cout << "\n";     
  }    
  cout << "\n";
  cout << "\n"; 
    
  return 0;
}  
