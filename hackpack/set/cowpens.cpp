#include<algorithm>
#include<iostream>
#include<utility>
#include<set>
#include<vector>
using namespace std;

const long MAXHEIGHT= 1000000;
typedef pair<int,int> pii;
bool SortOnY(pii v1 ,pii v2){return v1.second < v2.second;}
bool SortOnX(pii v1 ,pii v2){return v1.first < v2.first;}
vector<pii> list;
set<pii> myset;

int main (){
    int N,x,y;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        list.push_back(make_pair(x,y));
    }

    //Sort the elements on increasing y values
    sort(list.begin(),list.end(),SortOnY);
//    for(vector<pii>::iterator it = list.begin(); it != list.end(); it++){
//        cout << it->first << ", " << it->second << endl;
//    }
    set<pii>::iterator before, after;
    int leftxbound, rightxbound;
    long area = 0;
    for(vector<pii>::iterator it = list.begin(); it != list.end(); it++){
        myset.insert(*it);
        before = myset.lower_bound(*it);
        after = myset.upper_bound(*it);
        leftxbound = (before != myset.begin()) ? before->first : 0;
        rightxbound = (after != myset.end()) ? after->first : 1000000;
//        cout << "---------------------------" << endl << "leftxbound: " << leftxbound << endl;
//        cout << "rightxbound: " << rightxbound << endl << "current: " << it->first << ", " << it->second << endl;
        area = max(area,  (long)it->second * (long)(rightxbound - leftxbound));
//        cout << it->second * (rightxbound - leftxbound) << endl;
    }
    myset.insert(make_pair(0,0));
    myset.insert(make_pair(1000000,0));
    after = myset.begin();
    for(set<pii>::iterator before = myset.begin(); before != myset.end(); before++){
        after++;
        leftxbound = (before != myset.begin()) ? before->first : 0;
        rightxbound = (after != myset.end()) ? after->first : 1000000;
        area = max(area, (long)(rightxbound - leftxbound) * MAXHEIGHT);
//        cout << "---------------------------" << endl << "leftxbound: " << leftxbound << endl;
//        cout << "rightxbound: " << rightxbound << endl;
//        cout << (rightxbound - leftxbound) * MAXHEIGHT << endl;
    }
//    cout << area << endl;
}
