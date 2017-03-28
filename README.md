# DynamicProgramming

Dynamic Programming is an algorithmic paradigm that solves a given complex problem by breaking it into subproblems and stores the results of subproblems to avoid computing the same results again. Following are the two main properties of a problem that suggest that the given problem can be solved using Dynamic programming:
1) Overlapping Subproblems
2) Optimal Substructure

https://en.wikipedia.org/wiki/Dynamic_programming

### 0/1 Knapsack Problem

Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

Solution:
For every item, you can either include the item in the Knapsack or exclude it. Thus to get the maximum value obtained by selecting out of n items, we need to compute the maximum of the following two values:
1. ( Including the n'th item ) Value of the n'th item plus the maximum value obtained from (n - 1) items and excluding the weight of n'th item. 
2. (Excluding the n'th item) Maximum value obtained from (n - 1) items. 
If weight of the n'th item is greater than total weight, then n'th item is excluded. (Case 2)
