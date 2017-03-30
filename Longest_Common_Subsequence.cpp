#include<iostream>
#include<cmath>
#include<stack>
int main()
{
	std::string s1, s2, stemp;
	std:: cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();
	int temp;
	
	if(n < m)
	{
	    temp = n;
	    n = m;
	    m = temp;
	    stemp = s1;
	    s1 = s2;
	    s2 = stemp;
	}
	
	int dp[n + 1][m + 1];
	//Initialization of dp
	
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
		
	for(int i = 0; i <= n; i++)
		dp[0][i] = 0;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	
	std::stack <char> s;
	int i = n, j = m;
	
	//To print the Longest Common Subsequence
	while(i > 0 && j > 0)
	{
		if(s1[i - 1] == s2[j - 1])
		{
			s.push(s1[i - 1]);
			i--;
			j--;
		}
		else if(dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	}
	
	std::cout << dp[n][m] << std::endl;
	
	while(!s.empty())
	{
	
		std::cout << s.top();
		s.pop();
	}
}

