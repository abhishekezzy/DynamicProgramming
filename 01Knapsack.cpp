#include<iostream>
#include<cmath>

int main()
{
	int n, W;
	std::cin >> n >> W;
	int w[n + 1], v[n + 1];
	
	for(int i = 1; i <= n; i++)
		std::cin >> v[i];
		
	for(int i = 1; i <= n; i++)
		std::cin >> w[i];
		
	int dp[n + 1][W + 1];
	
	//No item can be selected if the Total weight is 0. 
	for(int i = 0; i < n; i++)
		dp[i][0] = 0;
	
	//No item can be selected if the no. of items is 0.
	for(int i = 0; i <= W; i++)
		dp[0][i] = 0;
		
	/*
	DP[i][j] is max of:
	1. Value of i'th item plus value obtained by selecting (i-1) items and excluding the weight of i'th item.
	2. Value of (i-1) items by excluding the i'th item. 
	*/
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= W; j++)
		{
			if(j < w[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = std::max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
		}
	
	std::cout << dp[n][W] << std::endl;
	
}

