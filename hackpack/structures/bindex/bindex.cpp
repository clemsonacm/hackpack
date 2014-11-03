#define array_size 101
int array[array_size];
// Note that indices start at 1; So this array holds 100 elements

// Get sum from elements 1 to k
int get_prefix_sum(int k) {
   int sum=0;
   for(; k; k-=(k&-k))
      sum += array[k-1];
   return sum;
}

// Add n to element k
void add_to_element(int k, int n) {
   for(; k<=array_size; k+=(k&-k))
      array[k-1] += n;
}

// Sum from element a to b
int range_sum(int a, int b) {
   return get_prefix_sum(b) - get_prefix_sum(a-1);
}

// Get element k
int get_element(int k) {
   return range_sum(k,k);
}

// Set element k to value n
void set_element(int k, int n) {
   add_to_element(k, n - get_element(k));
}
