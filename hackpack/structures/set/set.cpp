#include <set>
#include <iostream>
//Create a set of int
std::set<int> myset;

//iterator to a set of int
std::set<int>::iterator it;
std::set<int>::reverse_iterator rit;

int main(){

    //insert O(log N) per element or O(1) am per element for _sorted_ elements
    //For a total of O(N log N)  or O(N) for sorted inputs
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

    //iterate the set in forward order O(1) am / O(log N)
    //for a total of O(N) total
    //Note that begin() returns an iterator to the first element
    //whereas that end() returns to a dummy element after the last element
    for(it = myset.begin(); it != myset.end(); it++){
        std::cout << *it << " " ;
    }
    std::cout << std::endl;

    //iterate the set in reverse order )O(1) am / O(log N)
    //for a total of O(N) total
    //Note that rbegin() returns an iterator to the last element
    //whereas that end() returns to a dummy element before the first element
    for(rit = myset.rbegin(); rit != myset.rend(); rit++){
        std::cout << *rit << " " ;
    }
    std::cout << std::endl;

    //Find the first element greater than or equal to the current element in O(log N) time
    //In this case it returns 6
    it = myset.lower_bound(6);
    std::cout << *it << std::endl;
    
    //Find the first element greater than the current element in O(log N) time
    //In this case it returns 7
    it = myset.upper_bound(6);
    std::cout << *it << std::endl;
    
    // Empties the set O(N) time
    myset.clear();

}
