
// Find maximum possible stolen value from houses

/*

	There are n houses build in a line, each of which contains some value in it.
 A thief is going to steal the maximal value of these houses, but he can’t steal in two adjacent houses 
 because owner of the stolen houses will tell his two neighbour left and right side. What is the maximum stolen value.

*/

#include<bits/stdc++.h>
using namespace std;



// topDown Solution
int solution(vector<int> a, int index, int n){
	if(index >= n){
		return 0;
	}
	else{
		return max(a[index]+solution(a,index+2,n) , solution(a,index+1,n));
	}
}


void bottomUp(vector<int> a, int n){
	int memo[n+2];
	memo[n] = 0;
	memo[n+1] = 0;

	for(int i = n-1; i >= 0; i--){
		memo[i] = max(a[i]+memo[i+2],memo[i+1]);
	}

	
	cout<<"\nmax val "<<memo[0];
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}

	cout<<solution(a,0, n);
	bottomUp(a,n);
}
