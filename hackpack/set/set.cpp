#include <set>
#include <iostream>
//Create a set of int
std::set<int> myset;

//iterator to a set of int
std::set<int>::iterator it;
std::set<int>::reverse_iterator rit;

int main(){

    //insert O(N log(N)) or O(N) am for sorted inputs
    int key;
    for(key = 0; key < 10; key++){
        myset.insert(key);
    }

    //find O(log N)
    it = myset.find(3);

    //removes 3 in O(1) am post-find time
    myset.erase(it);
    //removes 4 from the set  O(log N) time
    myset.erase(4);

    //iterate the set in forward order O(N log (N))
    for(it = myset.begin(); it != myset.end(); it++){
        std::cout << *it << " " ;
    }
    std::cout << std::endl;

    //iterate the set in reverse order O(N log (N))
    for(rit = myset.rbegin(); rit != myset.rend(); rit++){
        std::cout << *rit << " " ;
    }
    
    // Empties the set O(N) time
    myset.clear();

}
