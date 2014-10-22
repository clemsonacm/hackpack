#include <map>
std::map<key_type,value_type> mymap;

int main(){
    //insert O(N log(N)) or O(N) am for sorted inputs
    mymap.insert( std::pair<key_type, value_type>(key, value);
    mymap[key] = value;

    //iterator
    std::map<key_type, value_type>::iterator it;

    //remove O(log N) or O(1) am post-find
    mymap.erase(key);
    mymap.erase(it);

    //find O(log N)
    mymap.find(key)
}
