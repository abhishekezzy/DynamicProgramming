#include<iostream>
#include<cmath>
int main()
{
	int n, m;
	std::cin >> n >> m;
	long long int a[n + 1], b[m + 1];
	long long int dp[n + 1][m + 1];
	
	for(int i = 1; i <= n; i++)
		std:: cin >> a[i];
		
	for(int j = 1; j <= m; j++)
		std::cin >> b[j];
	
	for(int i = 0; i <= m; i++)
		dp[0][i] = 0;
	
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(j <= i)
				dp[i][j] = std::max(dp[i - 1][j - 1] + a[i] * b[j], dp[i - 1][j]);
			else
				dp[i][j] = dp[i][j - 1];
		}
	
	std::cout << dp[n][m] << std::endl;
}

