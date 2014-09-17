#include <set>
std::set<type_one> myset;

//iterator
std::set<type_one>::iterator it;

//insert O(N log(N)) or O(N) am for sorted inputs
myset.insert(type_one (value));

//remove O(log N) or O(1) am post-find
myset.erase(it);
myset.erase(key);

//find O(log N)
myset.find(key)
