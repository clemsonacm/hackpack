#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_NODE 10001
int T[MAX_NODE][MAX_NODE];

class concert{
	public:
		int time;
		int id;
		concert(int t, int i): time(t), id(i) {};
};

bool sortOnTime(concert &a, concert &b){return a.time < b.time;}
vector<concert> concerts;
vector<int> sol;

int main(int argc, char *argv[])
{
	//Read in the input
	int N,time,dist;
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> time;
		concert c = concert(time,i);
		concerts.push_back(c);
		for(int j=1; j<=N;j++) {
			cin >> dist;
			T[i][j]=dist;
		}
	}

	//Modify the input to insert a dummy concert so we can start at any concert
	concert c = concert(0,0);
	concerts.push_back(c);
	for(int i=0;i<N;i++){
		T[0][i+1] = concerts[i].time;
		T[i+1][0] = concerts[i].time;
	}

	//Sort all of the concerts based on time
	sort(concerts.begin(), concerts.end(), sortOnTime);
	
	/*	
	//test the matrix
	cout << "  ";
	for(int i=0; i<=N; i++){
		cout << i << " ";
	}
	cout << endl;
	for(int i =0;i<=N;i++) {
		cout << i << " ";
		for(int j =0;j<=N;j++){
			cout << T[i][j] << " " ;
		}
		cout << endl;
	}
	cout << endl;

	cout << "  ";
	for(auto& x: concerts){
		cout << x.id << " ";
	}
	cout << endl;
	for(int i=0; i<=N; i++){
		cout << concerts[i].id << " ";
		for(int j=0; j<=N; j++){
		cout << T[concerts[i].id][concerts[j].id] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/
	
	//Don't forget the base case!
	sol.push_back(0);

	//Solve the Problem
	for (int i = 0; i <= N; i++){
		int m = 0;
		for(int j=1; j < i; j++){
			cout << "(i, j) " << i << " " << j << " " << T[concerts[i].id][concerts[j].id] << endl;
			cout << "arive " << concerts[j].time +T[concerts[i].id][concerts[j].id]<< " " << endl;
			cout << "concert " << concerts[i].time << endl;
			if(concerts[j].time +T[concerts[i].id][concerts[j].id] <= concerts[i].time ){
				cout << "updated" <<endl;
				m = max(sol[j]+1,m);
				cout << "sol[" << j << "] " << sol[j] << endl;
				cout << "m " << m << endl;
			}
		}
		cout << "storing "  << m << " in " << "sol[" << i << "]" << endl << endl;
		sol.push_back(m);
	}	
	cout << "-----sols-------" << endl;
	for(auto x: sol){cout << x << endl;}
	cout << endl;

	//We could have stopped at any concert so check them all
	int m =0;
	for (vector<int>::iterator i = sol.begin(); i != sol.end(); i++) m = max(m,*i);
	cout << m << endl;

}
