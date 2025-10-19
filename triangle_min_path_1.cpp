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


	for (int i{ 1 }; i < n; ++i) {
		for (int j{}; j < i + 1; ++j) {
			if (j == 0)
				dp[i][j] += dp[i - 1][j];
			else if (i == j)
				dp[i][j] += dp[i - 1][j - 1];
			else
				dp[i][j] += std::min(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}


	std::cout << *std::min_element(dp.back().begin(), dp.back().end());
}
