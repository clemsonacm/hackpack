#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class concert{
	public:
		int time;
		vector<int> dist;
		concert(): time(), dist() {};
};
bool sortOnTime(concert &a, concert &b){return a.time < b.time;}
vector<concert> concerts;
vector<int> sol;

int main(int argc, char *argv[])
{
	//Read in the input
	int N,time,dist;
	cin >> N;
	for (int i = 0; i < N; i++){
		concert c = concert();
		cin >> time;
		c.time = time;
		for(int j = 0; j < N; j++){
			cin >> dist;
			c.dist.push_back(dist);
		}
		concerts.push_back(c);
	}
	concert c = concert();

	//Modify the input to insert a dummy concert so we can start at any concert
	c.time = 0;
	for (vector<concert>::iterator i = concerts.begin(); i != concerts.end(); i++) 
		c.dist.push_back(i->time);
	concerts.push_back(c);

	//Sort all of the concerts based on time
	sort(concerts.begin(), concerts.end(), sortOnTime);

	//Don't forget the base case!
	sol.push_back(0);

	//Solve the Problem
	for (int i = 1; i <= N; i++){
		int m = 0;
		for(int j=0; j <= N; j++){
			if(concerts[j].time + concerts[j].dist[i] <= concerts[i].time) 
				m = max(sol[j]+1,m);
		}
		sol.push_back(m);
	}	

	//We could have stopped at any concert so check them all
	int m =0;
	for (vector<int>::iterator i = sol.begin(); i != sol.end(); i++) m = max(m,*i);
	cout << m << endl;

}
