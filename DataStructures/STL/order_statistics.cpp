#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<long, null_type, less<long>, rb_tree_tag, tree_order_statistics_node_update> indexedSet;

int main() {
	indexedSet S;
	for (int i=0; i<=10; i+=2)
		S.insert(i);
		
	/*has 6 elements in S*/
	cout << *S.find_by_order(2) << "\n"; //4
	cout << *S.find_by_order(4) << "\n"; //8
	cout << *S.find_by_order(5) << "\n"; //10
	cout << *S.find_by_order(6) << "\n"; //0
	cout << (S.end() == S.find_by_order(7)) << "\n"; //Yes. The 7th position is end() and does not contain nummber

	cout << S.order_of_key(-1) << "\n";//0
	cout << S.order_of_key(0) << "\n";//0
	cout << S.order_of_key(4) << "\n";//2
	cout << S.order_of_key(20) << "\n";//6
	return 0;
}
