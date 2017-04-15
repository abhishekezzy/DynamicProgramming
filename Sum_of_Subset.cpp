#include<iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int a[n + 1];
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	bool dp[n + 1][k + 1];
	
	for(int i = 0; i < n; i++)
		dp[i][0] = true;
	
	for(int i = 1; i <= k; i++)
		dp[0][i] = false;
		
	for(int i = 1; i <= n; i++ )
	{
		for(int j = 1; j <= k; j++)
		{
			if(a[i] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i]];		
		}
	}
	
	cout << dp[n][k] << endl;
	
}


