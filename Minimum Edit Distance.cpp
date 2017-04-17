#include<iostream>
#include<cmath>
int main()
{
	int t;
	std::cin >> t;
	while(t--)
	{
		//Convert string s1 to s2
		int m, n;
		std::cin >> m >> n;
		std::string s1, s2;
		std::cin >> s1 >> s2;
		
		//int m = s1.length(), n = s2.length();
		int dp[n + 1][m + 1];
		
		for(int i = 0; i <= m; i++)
			dp[0][i] = i;
		
		for(int i = 0; i <= n; i++)
			dp[i][0] = i;
			
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(s2[i - 1] == s1[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = 1 + std::min(dp[i - 1][j - 1], //edit
									std::min(dp[i - 1][j],    //delete
										 dp[i][j - 1])); // add
			}
		}
		
		std::cout << dp[n][m] << std::endl;
	}
}

