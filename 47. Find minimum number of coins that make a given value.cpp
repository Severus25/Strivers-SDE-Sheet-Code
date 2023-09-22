// Problem Statement:
// Given a value V, if we want to make a change for V cents, and we have an infinite supply of each of C = { C1, C2, .., Cm} valued coins, 
// what is the minimum number of coins to make the change? If it’s not possible to make a change, print -1.

// Examples:  

// Input: coins[] = {25, 10, 5}, V = 30
// Output: Minimum 2 coins required We can use one coin of 25 cents and one of 5 cents 

// Input: coins[] = {9, 6, 5, 1}, V = 11
// Output: Minimum 2 coins required We can use one coin of 6 cents and 1 coin of 5 cents

// Problem Solution:
// A Dynamic Programming based C++ program to find minimum
// of coins to make a given change V
#include <bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
	// table[i] will be storing the minimum number of coins
	// required for i value. So table[V] will have result
	int table[V + 1];

	// Base case (If given value V is 0)
	table[0] = 0;

	// Initialize all table values as Infinite
	for (int i = 1; i <= V; i++)
		table[i] = INT_MAX;

	// Compute minimum coins required for all
	// values from 1 to V
	for (int i = 1; i <= V; i++) {
		// Go through all coins smaller than i
		for (int j = 0; j < m; j++)
			if (coins[j] <= i) {
				int sub_res = table[i - coins[j]];
				if (sub_res != INT_MAX
					&& sub_res + 1 < table[i])
					table[i] = sub_res + 1;
			}
	}

	if (table[V] == INT_MAX)
		return -1;

	return table[V];
}

// Driver program to test above function
int main()
{
	int coins[] = { 9, 6, 5, 1 };
	int m = sizeof(coins) / sizeof(coins[0]);
	int V = 11;
	cout << "Minimum coins required is "
		<< minCoins(coins, m, V);
	return 0;
}
