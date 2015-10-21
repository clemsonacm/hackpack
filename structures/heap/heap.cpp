#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

static inline unsigned int parent(unsigned int i){return (floor(i-1)/2);}
static inline unsigned int left(unsigned int i){return (2*i)+1;}
static inline unsigned int right(unsigned int i){return (2*i)+2;}

template <class T>
class binary_heap{
	typedef pair<int, T> heap_element;
	typedef typename vector<heap_element>::iterator heap_iterator;

	vector<heap_element> h;

	public:
	void insert(int key, T value){ // O(log n) time
		h.emplace_back(key, value);
		sift_up(h.size() - 1);
	}

	heap_element remove_min(){ // O(log n) time
		swap(h[h.size() - 1], h[0]);
		heap_element e = h.back();
		h.pop_back();
		sift_down(0);
		return e;
	}

	void decrease_key(int i , int delta){ // O(log n) time
		h[i].first -= delta;
		sift_up(i);
	}

	void delete_element(int i){ // O(log n) time
		swap(h[i], h[h.size() - 1]);
		sift_up(i);
		sift_down(i);
	}

	void sift_up(int i){ // O(log n) time
		while(i != 0 && h[i].first < h[parent(i)].first){
			swap(h[i],h[parent(i)]);
			i = parent(i);
		}
	}

	void sift_down(int i){ // O(log n) time
		while((left(i) < h.size() && h[i].first > h[left(i)].first) || (right(i) < h.size() && h[i].first > h[right(i)].first)){
			if (right(i) >= h.size() || h[left(i)].first < h[right(i)].first) { swap(h[left(i)],h[i]); i = left(i);}
			else { swap(h[right(i)],h[i]); i = right(i);}
		}
	}

	heap_iterator begin(){ // O(1) time
		return h.begin();
	}

	heap_iterator end(){ // O(1) time
		return h.end();
	}

	int size(){ // O(1) time
		return h.size();
	}
	
	void make_heap(vector<heap_element> v){ // O(N) time
		h=v;
		for(int i=v.size() - 1; i>0; i--) sift_down(i);
	}
};

int main() {

	binary_heap<int> h;
	int n;
	while(cin >> n) h.insert(n,0);

	while(h.size() > 0){
		cout << h.remove_min().first << ", ";
	}
	cout << endl;
	

	return 0;
}
