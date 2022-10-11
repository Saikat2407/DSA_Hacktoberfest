#include <bits/stdc++.h>
using namespace std;
#define el "\n";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n,m,i,tm;
	cin>>t;
	while(t--){
	    cin>>n>>m; i=0;
		int *arr = new int[n];
		set<int> S;
		while(i<n){
		    cin>>tm;
			S.insert(tm);
			i++;
		}
		if((S.size()<m)){
			cout<<"YES"<<el;
		}
		else{
			cout<<"NO"<<el;
		}
	}
	return 0;
}