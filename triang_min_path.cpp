#include <vector>
#include <iostream>
#include <algorithm>


int main() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int> > dp(n, std::vector<int>(n));
	for (int i{}; i < n; ++i)
		for (int j{}; j < i + 1; ++j)
			std::cin >> dp[i][j];

	for (int i{ n-2 }; i >-1 ; --i) 
		for (int j{}; j < i + 1; ++j)
			dp[i][j] += std::min(dp[i+1][j], dp[i + 1][j+1]);


	std::cout << dp.front().front();
}