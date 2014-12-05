#include<iostream>
#include<algorithm>
#include<map>

using namespace std; 

class employee{
    public:
        int id;
        int value; 
        employee(int id,int value): id(id), value(value){};
};

//key is supervisor,
multimap<int, employee> company;
map<int,int> max_present;
map<int,int> max_not_present;

int solve(multimap<int, employee>::iterator r, bool present){
    //No need to check both present and not present because they 
    //are evaluated at the same time
    if(max_present.find(r->first) != max_present.end()){
        return ((present)? max_present[r->first]: max(max_present[r->first],
                    max_not_present[r->first]));
    }

    //Compute the best solution to the subproblem.
    int sum_present=0, sum_not_present=0;
    int supervisor = r->second.id;
    auto subordinates = company.equal_range(supervisor);

    //Base case the employee has no subordinates
    if(subordinates.first == company.end() && subordinates.second == company.end()){
        return ((present)? 0 : r->second.value );
    }
    
    //Otherwise compute the present vs not present sums
    for(auto i = subordinates.first; i!= subordinates.second; i++){
        int not_present = solve(i,true);
        int present = solve(i,false);
        sum_present += present;
        sum_not_present += max(present, not_present);
    }

    //Store off the best results for present vs not present
    max_present[r->second.id] = sum_present;
    max_not_present[r->second.id] = sum_not_present;
    return ((present)? sum_not_present: max(sum_not_present, sum_present));


}

int main(){
    int id, value, supervisor;
    while(cin >> id >> value >> supervisor){
        company.insert(make_pair(supervisor, employee(id, value)));
    }
    cout << max(solve(company.find(0),true) ,solve(company.find(0),false)) << endl;


    /*
    for(auto i: company){
        cout << "[" << i.first << ", " << i.second.id << ", " << i.second.value
            << "]" << endl;
    }
    */
}

