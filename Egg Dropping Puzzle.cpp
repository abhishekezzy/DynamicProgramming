#include <iostream>
#include<cmath>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int dp[n + 1][k + 1];
	    for(int i = 0; i <= k; i++)
	        dp[0][i] = 0;
	    
	    for(int i = 0; i <= k; i++)
	        dp[1][i] = i;
	        
	    for(int i = 0; i <= n; i++)
	        dp[i][0] = 0;
	   
	    for(int i = 2; i <= n; i++)
	        for(int j = 1; j <= k; j++)
	        {
	            //if(i <= j)
	                dp[i][j] = 100000;
	        }
	    
	    for(int i = 2; i <= n; i++)
	    {
	        for(int j = 1; j <= k; j++)
	        {
	            if(i > j)
	                dp[i][j] = dp[i - 1][j];
	            else
	            {
	                for(int l = 1; l <= j; l++)
	                    dp[i][j] = min(dp[i][j],1 + max(dp[i - 1][l - 1], dp[i][j - l]));
	            }   
	        }
	    }
	    
	    cout << dp[n][k] << endl;
	}
	return 0;
}
