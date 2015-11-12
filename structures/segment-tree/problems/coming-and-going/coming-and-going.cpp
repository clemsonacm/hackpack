// #ifdef hackpackpp
#include <iostream>
#include <cmath>
using namespace std;
// #endif

// #ifdef hackpackpp
// number of entries in array
// #endif
const unsigned int N = 14;

// #ifdef hackpackpp
// build the segment tree
//
// data   - source array to build segment tree from
// start  - the start index of the array (should be 0)
// end    - the end index of the array (size - 1)
// tree   - the array to hold the segment tree sized appropriately
// st_idx - the current index of the segment tree (should be 0 when first called)
// #endif
int build_segment_tree(int* const data, const unsigned int start, const unsigned int end, int* const tree, const unsigned int st_idx)
{
	// #ifdef hackpackpp
	// if start == end, this is a leaf node and should
	// have the original value from the array here
	// #endif
	if(start == end)
	{
		tree[st_idx] = data[start];
		return data[start];
	}

	// #ifdef hackpackpp
	// recurse into two calls to fill in the tree to the left
	// and right, splitting the array into the new range to be
	// represented by the new call
	// #endif
	const unsigned int mid = start + ((end - start) / 2);
	const int left = build_segment_tree(data, start, mid, tree, (2 * st_idx) + 1);
	const int right = build_segment_tree(data, mid + 1, end, tree, (2 * st_idx) + 2);

	// #ifdef hackpackpp
	// store the greatest value in the array in non-leaf nodes;
	// this can easily be changed to another property by storing
	// the sum, minimum of the subtrees at this node
	// sum:
	//   tree[st_idx] = left + right;
	//
	// minimum:
	//   if(left < right) tree[st_idx] = left;
	//   else tree[st_idx] = right;
	// #endif
	if(left > right) tree[st_idx] = left;
	else tree[st_idx] = right;

	return tree[st_idx];
}

// #ifdef hackpackpp
// update a value in the segment tree
//
// to support range sums, this function would have to be modified to recurse
// down the tree to the leaf node before changing values; after the leaf node
// is updated, the new value should be passed back as a return value and each
// parent should update the sum they have by re-adding the values from the
// two children it has
//
// tree        - the segment tree with values to be updated
// start       - the start index of the _source_ array (should be 0)
// end         - the end index of the _source_ array (size - 1)
// changed_idx - the index of the element that changed
// new_val     - the new value of the element at changed_idx
// st_idx      - the current index of the segment tree (should be 0 when first called)
// #endif
void update_segment_tree(int* const tree, const unsigned int start, const unsigned int end, const unsigned int changed_idx, const int new_val, const unsigned int st_idx)
{
	// #ifdef hackpackpp
	// out of range; should not be counted
	// #endif
	if(changed_idx < start || changed_idx > end)
		return;

	// #ifdef hackpackpp
	// update the value if the new value is greater or if
	// this is the leaf
	// if the tree were storing the range minimum, this would update
	// if(new_val < tree[st_idx] || start == end)
	// #endif
	if(new_val > tree[st_idx] || start == end)
		tree[st_idx] = new_val;

	// #ifdef hackpackpp
	// no need to recurse from leaf
	// #endif
	if(start == end)
		return;
	
	const unsigned int mid = start + ((end - start) / 2);
	update_segment_tree(tree, start, mid, changed_idx, new_val, (2 * st_idx) + 1);
	update_segment_tree(tree, mid + 1, end, changed_idx, new_val, (2 * st_idx) + 2);

	return;
}

// #ifdef hackpackpp
// find the largest value for a range
//
// tree        - the segment tree to query
// start       - the start index of the _source_ array
// end         - the end index of the _source_ array
// range_start - the start index of the query
// range_end   - the end index of the query
// greatest    - the greatest value found so far (set to zero when first calling)
// st_idx      - the current index in the segtree (set to zero when first calling)
// #endif
int query_segment_tree(const int* const tree, const unsigned int start, const unsigned int end, const unsigned int range_start, const unsigned int range_end, int greatest, const unsigned int st_idx)
{
	// #ifdef hackpackpp
	// out of range; do not continue
	// #endif
	if(start > range_end || end < range_start)
		return -2;

	// #ifdef hackpackpp
	// leaf node; the greatest value one can see from here
	// is the value in the leaf node
	// #endif
	if(start == end)
		return tree[st_idx];

	// #ifdef hackpackpp
	// this node can be considered if the values in the original
	// array it represents fit in the query's range
	// #endif
	if(start >= range_start && end <= range_end)
	{
		if(tree[st_idx] > greatest)
			return tree[st_idx];
	}
	else
	{
		const unsigned int mid = start + ((end - start) / 2);
		const int left = query_segment_tree(tree, start, mid, range_start, range_end, greatest, (2 * st_idx) + 1);
		const int right = query_segment_tree(tree, mid + 1, end, range_start, range_end, greatest, (2 * st_idx) + 2);

		// #ifdef hackpackpp
		// use the greater of the two values here;
		// if a summation were desired, one could simply add the values together;
		// for a minimum, simply take the lesser of the two values
		// #endif
		if(left > greatest)
			greatest = left;
		if(right > greatest)
			greatest = right;
	}

	return greatest;
}

#define START_OF_DAY 6

int main()
{
	
	int headcount[N] = { 0 };

	// #ifdef hackpackpp
	// size needed for segtree is 2^{ceil(log2(n)) + 1} - 1
	// #endif
	const unsigned int st_size = pow(2, ceil(log2(N)) + 1) - 1;
	int* segtree = new int[st_size];
	build_segment_tree(headcount, 0, N - 1, segtree, 0);

	unsigned int t1, t2;
	cin >> t1 >> t2;

	unsigned int no_cows;
	cin >> no_cows;

	for(unsigned int i = 0; i < no_cows; i++)
	{
		unsigned int in_barn_times;
		cin >> in_barn_times;

		for(unsigned int j = 0; j < in_barn_times; j++)
		{
			unsigned int start, end;
			cin >> start >> end;
			for(unsigned int k = start; k < end; k++)
			{
				// #ifdef hackpackpp
				// account for times 0 to 5 we don't care about with k - 6
				// #endif
				headcount[k - START_OF_DAY]++;
				update_segment_tree(segtree, 0, N - 1, k - 6, headcount[k - START_OF_DAY], 0);
			}
		}

		// #ifdef hackpackpp
		// print out cow count as data comes in
		// #endif
		const int cows_in_barn = query_segment_tree(segtree, 0, N - 1, t1 - START_OF_DAY, t2 - START_OF_DAY, -1, 0);
		if(cows_in_barn > 0)
			cout << cows_in_barn;
		else
			cout << 0;
		cout << " of " << no_cows << " cows" << endl;
	}

	delete[] segtree;

	return 0;
}
