#include<iostream>
#include<cmath>

int main()
{
	int n;
	std::cin >> n;
	int a[n];
	
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	
	int dp[n];
	//length of minimum longest increasing subsequence is 1. 
	for(int i = 0; i < n; i++)
		dp[i] = 1;
	
	//Compute optimized length of longest increasing subsequence and store in dp[].	
	for(int i = 1; i < n; i++)
		for(int j = 0; j < i; j++)
		{
			if(a[i] > a[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	
	//Find the maximum length of longest increasing subsequence.
	int max = 1;
	for(int i = 0; i < n; i++)
		max = std::max(max, dp[i]);
	
	std::cout << max << std::endl;
}

