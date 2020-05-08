#include <bits/stdc++.h> 
using namespace std; 
bool** dp; 

void display(const vector<int>& v) 
{ 
	for (int i = 0; i < v.size(); ++i) 
		printf("%d ", v[i]); 
	printf("\n"); 
} 

void print_one(int arr[], int i, int sum, vector<int>& p) 
{ 
	if (i == 0 && sum != 0 && dp[0][sum]) 
	{ 
		p.push_back(arr[i]); 
		display(p); 
		return; 
	} 
	if (i == 0 && sum == 0) 
	{ 
		display(p); 
		return; 
	} 
	if (dp[i-1][sum]) 
	{ 
		vector<int> b = p; 
		print_one(arr, i-1, sum, b); 
	} 
	if (sum >= arr[i] && dp[i-1][sum-arr[i]]) 
	{ 
		p.push_back(arr[i]); 
		print_one(arr, i-1, sum-arr[i], p); 
	} 
} 
void print_two(int arr[], int n, int sum) 
{ 
	if (n == 0 || sum < 0) 
	return; 
	dp = new bool*[n]; 
	for (int i=0; i<n; ++i) 
	{ 
		dp[i] = new bool[sum + 1]; 
		dp[i][0] = true; 
	} 

	if (arr[0] <= sum) 
	dp[0][arr[0]] = true; 
	for (int i = 1; i < n; ++i) 
		for (int j = 0; j < sum + 1; ++j) 
			dp[i][j] = (arr[i] <= j) ? dp[i-1][j] || 
									dp[i-1][j-arr[i]] 
									: dp[i - 1][j]; 
	if (dp[n-1][sum] == false) 
	{ 
		printf("There are no subsets with sum %d\n", sum); 
		return; 
	} 

	vector<int> p; 
	print_one(arr, n-1, sum, p); 
} 

int main() 
{ 
	int n,sum;
	cin>>n;
	int arr[n+1];
	for(int i=0;i<n;i++) {
	    cin>>arr[i];
	}
	
	cin>>sum;
	print_two(arr, n, sum); 
	return 0; 
} 
