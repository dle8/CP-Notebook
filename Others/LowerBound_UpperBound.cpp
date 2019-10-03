// lower_bound returns pointer to the 1st array element whose value >= x
// upper_bound returns pointer to the 1st array element whose value > x
// equal_range returns both the above pointers

// Count the element whose values are x
auto a = lower_bound(array, array + size, x);
auto b = upper_bound(array, array + size, x);
cout << b - a;

auto r = equal_range(array, array + size, x);
cout << r.second - r.first;
