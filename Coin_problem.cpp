#include<iostream>
#include<vector>
#include<limits.h>
int main()
{
	int s;
	std::cin >> s;
	int n;
	std::cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	std::vector <int> min(s+1,INT_MAX - 1000);
	min[0] = 0;
	
	for(int i = 1; i <= s; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[j] <= i && min[i - a[j]] + 1 < min[i])
				min[i] = min[i - a[j]] + 1;
		}
	}
	
	if(min[s] == INT_MAX)
		std:: cout <<"-1";
	else
		std::cout << min[s] << std::endl;
}

