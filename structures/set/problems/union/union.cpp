#include<set>
#include<iostream>

using namespace std;

int main(){
    int i;
    set<int> s;
    
    //just inserting into the set will find a union because 
    //it must be unique keyed
    while(cin >> i){
        //0 is not a valid input so ignore it
        if(i!=0)s.insert(i);
    }

    int min_dist,a,b, min_a, min_b, min_c;
    auto j = s.begin();

    //the first triple is a good candidate for the solution
    min_a = a = *(j++);
    min_b = b = *(j++);
    min_c = *j;
    min_dist = *j-a;

    //iterate over all triples
    for(;j != s.end(); j++){
        int dist = *j-a;
        if(dist < min_dist){
            //it it is an improvement, update the pair
            min_dist = dist;
            min_a = a;
            min_b = b;
            min_c = *j;
        }
        //update to the next entry
        a=b;
        b=*j;
    }
    //Output the answer
    cout << min_a << " " << min_b << " " << min_c << endl;
}
