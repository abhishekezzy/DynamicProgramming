#include<iostream>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	long long int dp[n + 1][k + 1];
	
	for(int i = 0; i <= n; i++)
		dp[i][0] = 1; // C(n, 0) = 1
		
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(j > i)
				continue; // k must be greater than n for C(n, k)
			else if(j == i)
				dp[i][j] = 1; // C(n,n) = 1
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]; // C(n, k) = C(n - 1, k) + C(n - 1, k - 1)
		}
	}
	
	cout << dp[n][k] << endl;
}

