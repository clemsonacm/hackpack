#include <iostream>
#include <cmath>
using namespace std;

// number of entries in array
unsigned int N;

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

	if(left > right) tree[st_idx] = left;
	else tree[st_idx] = right;

	return tree[st_idx];
}

void update_segment_tree(int* const tree, const unsigned int start, const unsigned int end, const unsigned int changed_idx, const int new_val, const unsigned int st_idx)
{
	if(changed_idx < start || changed_idx > end)
		return;

	if(new_val > tree[st_idx] || start == end)
		tree[st_idx] = new_val;

	if(start == end)
		return;
	
	const unsigned int mid = start + ((end - start) / 2);
	update_segment_tree(tree, start, mid, changed_idx, new_val, (2 * st_idx) + 1);
	update_segment_tree(tree, mid + 1, end, changed_idx, new_val, (2 * st_idx) + 2);

	return;
}

int query_segment_tree(const int* const tree, const unsigned int start, const unsigned int end, const unsigned int range_start, const unsigned int range_end, int greatest, const unsigned int st_idx)
{
	if(start > range_end || end < range_start)
		return -2;

	if(start == end)
		return tree[st_idx];

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

		if(left > greatest)
			greatest = left;
		if(right > greatest)
			greatest = right;
	}

	return greatest;
}

int main()
{
	
	int src_array[N];

	// size needed for segtree is 2^{ceil(log2(n)) + 1} - 1
	const unsigned int st_size = pow(2, ceil(log2(N)) + 1) - 1;
	int* segtree = new int[st_size];
	build_segment_tree(src_array, 0, N - 1, segtree, 0);

	// update value in segtree
	src_array[42] = 43;
	update_segment_tree(segtree, 0, N - 1, 42, 43, 0);

	// query segtree between indices 0 and 12, inclusive
	int result = query_segment_tree(segtree, 0, N - 1, 0, 12, -1, 0);

	delete[] segtree;

	return 0;
}
