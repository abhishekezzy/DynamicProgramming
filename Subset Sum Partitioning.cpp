#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n;
		int a[n + 1], sum = 0;
		
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		
		if(sum % 2 == 1)
			cout << "NO";
		else
		{
			k = sum / 2;
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
			
			if(dp[n][k])
				cout << "YES";
			else
				cout << "NO";
		}
		cout << endl;
	}
}


