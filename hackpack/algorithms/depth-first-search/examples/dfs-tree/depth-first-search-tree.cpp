#include<time.h>        
#include<cmath>
#include<stdlib.h>
#include<iostream>
#include<fstream>

#include "tree-search.h"

int graph[3][3];

using namespace std;

int main(){

	int y=0,z=0;
  ifstream file;
  file.open ("input.in");
  string s;
  cout << "\n"; 
  while(!file.eof()){  
    getline(file,s);  
    z = 3;
    for(int x=0; x < z ; x++){
	   graph[y][x]= s[x] - '0';
	 }
	 y++;
	 if(y==20) break;  
  }
  file.close();
    
	for(int i=0; i < 3; i++){
	  for(int j=0; j < 3; j++){
	    cout << graph[i][j];
	  } cout << "\n";     
	}    
	cout << "\n";

	/* Build tree from graph */
	BST bst;
	for (int i=1; i < 3; i++){
	  	for(int j=0; j < 3; j++){
	  		bst.insert(graph[i][j]);	
		}
	}
	/* bst traversal: pre-order, in-order, and post-order. */
	bst.preorder_traversal();
	bst.postorder_traversal();
	bst.inorder_traversal();
	  
  	return 0;
}  
