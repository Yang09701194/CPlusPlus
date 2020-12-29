#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <iostream>
#include <algorithm>


#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define all(v) v.begin(),v.end()
#define mem(v,x) memset(v,x,sizeof(v))
#define ar array
#define N 2000005
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//list of functions: set.insert(val), *(set.find_by_order(order-1)), set.order_of_key(val)

//using namespace __gnu_pbds;
using namespace std;

#include "test.h"

int main() {
	Solution s;
	auto a = s.getSum(-1, 1);
	cout << a << endl;

	int pause;
	cin>> pause;
	return 0;
}

