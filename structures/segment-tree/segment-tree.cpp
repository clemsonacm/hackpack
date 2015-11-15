#include <iostream>
#include <cmath>
using namespace std;

// dummy query returns; modify as necessary
#define ST_QUERY_DUMMY_MAX  99999999
#define ST_QUERY_DUMMY_MIN -99999999
#define ST_QUERY_DUMMY_SUM 0

// choose information to store
enum SegmentTreeType { ST_MIN, ST_MAX, ST_SUM };
const SegmentTreeType type = ST_MIN;

// number of entries in array
unsigned int N = 10;

int segment_tree_helper(const int a, const int b)
{
	if(type == ST_MIN)
		return (a < b ? a : b);
	else if(type == ST_MAX)
		return (a > b ? a : b);
	else if(type == ST_SUM)
		return (a + b);
	else
		return -1;
}

int build_segment_tree(int* const data, const unsigned int start, const unsigned int end, int* const tree, const unsigned int st_idx)
{
	if(start == end)
	{
		tree[st_idx] = data[start];
		return data[start];
	}

	const unsigned int mid = start + ((end - start) / 2);
	const int left = build_segment_tree(data, start, mid, tree, (2 * st_idx) + 1);
	const int right = build_segment_tree(data, mid + 1, end, tree, (2 * st_idx) + 2);

	tree[st_idx] = segment_tree_helper(left, right);

	return tree[st_idx];
}

void update_segment_tree(int* const tree, const unsigned int start, const unsigned int end, const unsigned int changed_idx, const int old_val, const int new_val, const unsigned int st_idx)
{
	if(changed_idx < start || changed_idx > end)
		return;

	if(type == ST_MIN)
	{
		if(new_val < tree[st_idx]  || start == end)
			tree[st_idx] = new_val;
	}
	else if(type == ST_MAX)
	{
		if(new_val > tree[st_idx] || start == end)
			tree[st_idx] = new_val;
	}
	else if(type == ST_SUM)
	{
		int delta = new_val - old_val;
		tree[st_idx] += delta;
	}
	

	if(start == end)
		return;
	
	const unsigned int mid = start + ((end - start) / 2);
	update_segment_tree(tree, start, mid, changed_idx, old_val, new_val, (2 * st_idx) + 1);
	update_segment_tree(tree, mid + 1, end, changed_idx, old_val, new_val, (2 * st_idx) + 2);

	return;
}

int query_segment_tree(const int* const tree, const unsigned int start, const unsigned int end, const unsigned int range_start, const unsigned int range_end, int val, const unsigned int st_idx)
{
	if(start > range_end || end < range_start)
	{
		if(type == ST_MIN)
			return ST_QUERY_DUMMY_MAX;
		else if(type == ST_MAX)
			return ST_QUERY_DUMMY_MIN;
		else if(type == ST_SUM)
			return ST_QUERY_DUMMY_SUM;
	}

	if(start == end)
		return tree[st_idx];

	if(type == ST_MIN && (start >= range_start && end <= range_end))
	{
		if(tree[st_idx] < val)
			return tree[st_idx];
	}
	else if(type == ST_MAX && (start >= range_start && end <= range_end))
	{
		if(tree[st_idx] > val)
			return tree[st_idx];
	}
	else if(type == ST_SUM && (start >= range_start && end <= range_end))
	{
		return tree[st_idx];
	}
	else
	{
		const unsigned int mid = start + ((end - start) / 2);
		const int left = query_segment_tree(tree, start, mid, range_start, range_end, val, (2 * st_idx) + 1);
		const int right = query_segment_tree(tree, mid + 1, end, range_start, range_end, val, (2 * st_idx) + 2);
		val = segment_tree_helper(left, right);
	}

	return val;
}

int main()
{
	
	int src_array[N];

	// size needed for segtree is 2^{ceil(log2(n)) + 1} - 1
	const unsigned int st_size = pow(2, ceil(log2(N)) + 1) - 1;
	int* segtree = new int[st_size];
	build_segment_tree(src_array, 0, N - 1, segtree, 0);

	// update value in segtree
	int old = src_array[4];
	src_array[4] = 43;
	update_segment_tree(segtree, 0, N - 1, 4, old, 43, 0);
	old = src_array[2];
	src_array[2] = 21;
	update_segment_tree(segtree, 0, N - 1, 2, old, 21, 0);
	old = src_array[3];
	src_array[3] = 2;
	update_segment_tree(segtree, 0, N - 1, 3, old, 2, 0);
	old = src_array[9];
	src_array[9] = 1;
	update_segment_tree(segtree, 0, N - 1, 9, old, 1, 0);

	// query segtree between indices 0 and 9, inclusive
	int result = query_segment_tree(segtree, 0, N - 1, 0, 9, ST_QUERY_DUMMY_MAX, 0);

	cout << result << endl;

	delete[] segtree;

	return 0;
}
