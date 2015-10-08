#include <set>
#include <iostream>
//Create a set of int
std::set<int> myset;

//iterator to a set of int
std::set<int>::iterator it;
std::set<int>::reverse_iterator rit;

int main(){

    // #ifdef hackpackpp
    //insert O(log N) per element or O(1) am per element for _sorted_ elements
    //For a total of O(N log N)  or O(N) for sorted inputs
    // #endif
    int key;
    for(key = 0; key < 10; key++){
        myset.insert(key);
    }

    //#ifdef hackpackpp
    //find O(log N)
    //#endif
    it = myset.find(3);

    // #ifdef hackpackpp
    //removes 3 in O(1) am post-find time
    // #endif
    myset.erase(it);
    // #ifdef hackpackpp
    //removes 4 from the set  O(log N) time
    // #endif
    myset.erase(4);

    // #ifdef hackpackpp
    //iterate the set in forward order O(1) am / O(log N)
    //for a total of O(N) total
    //Note that begin() returns an iterator to the first element
    //whereas that end() returns to a dummy element after the last element
    // #endif
    for(it = myset.begin(); it != myset.end(); it++){
        std::cout << *it << " " ;
    }
    std::cout << std::endl;

    // #ifdef hackpackpp
    //iterate the set in reverse order )O(1) am / O(log N)
    //for a total of O(N) total
    //Note that rbegin() returns an iterator to the last element
    //whereas that end() returns to a dummy element before the first element
    // #endif
    for(rit = myset.rbegin(); rit != myset.rend(); rit++){
        std::cout << *rit << " " ;
    }
    std::cout << std::endl;

    // #ifdef hackpackpp
    //Find the first element greater than or equal to the current element in O(log N) time
    //In this case it returns 6
    // #endif
    it = myset.lower_bound(6);
    std::cout << *it << std::endl;
    
    // #ifdef hackpackpp
    //Find the first element greater than the current element in O(log N) time
    //In this case it returns 7
    // #endif
    it = myset.upper_bound(6);
    std::cout << *it << std::endl;
    
    // #ifdef hackpackpp
    // Empties the set O(N) time
    // #endif
    myset.clear();

}
