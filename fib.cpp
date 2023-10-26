#include <iostream>
#include <vector>

std::vector<unsigned long long> __cached_fibs;
unsigned long long fib(int n) {
	if (n <= 0) {
		return -1;
	}
	else {
		int s = __cached_fibs.size();
		if (s > n) {
			return __cached_fibs.at(n - 1);
		}
		unsigned long long a = __cached_fibs.at(s - 2), b = __cached_fibs.at(s - 1);
		for (int i = s; i < n; i++) {
			__cached_fibs.push_back(a + b);
		}
		return __cached_fibs.at(__cached_fibs.size() - 1);
	}
}

int main() {
	__cached_fibs.push_back(0uLL);
	__cached_fibs.push_back(1uLL);
	for (int i = 1; i < 100; i++) {
		std::cout << "Fib(" << i << "): " << fib(i) << std::endl;
	}
	return 0;
}