#include<set>
#include<iostream>

using namespace std;

int main(){
    int i;
    set<int> s;
    
    //#ifdef hackpackpp
    //just inserting into the set will find a union because 
    //it must be unique keyed
    //#endif
    while(cin >> i){
        //0 is not a valid input so ignore it
        if(i!=0)s.insert(i);
    }

    int min_dist,a,b, min_a, min_b, min_c;
    auto j = s.begin();

    //#ifdef hackpackpp
    //the first triple is a good candidate for the solution
    //#endif
    min_a = a = *(j++);
    min_b = b = *(j++);
    min_c = *j;
    min_dist = *j-a;

    //#ifdef hackpackpp
    //iterate over all triples
    //#endif
    for(;j != s.end(); j++){
        int dist = *j-a;
        if(dist < min_dist){
            //#ifdef hackpackpp
            //it it is an improvement, update the pair
            //#endif
            min_dist = dist;
            min_a = a;
            min_b = b;
            min_c = *j;
        }
        //#ifdef hackpackpp
        //update to the next entry
        //#endif
        a=b;
        b=*j;
    }
    //#ifdef hackpackpp
    //Output the answer
    //#endif
    cout << min_a << " " << min_b << " " << min_c << endl;
}
