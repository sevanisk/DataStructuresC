#include <iostream>
#include <chrono>

using namespace std;

int main() {

	auto start = chrono::system_clock::now();
	int n = 5000;

	// A
	int sum_a = 0;
	for(int i = 1; i <= n; i++){
		sum_a += 1;
	}
	//sum when--
	// n = 1: 1
	// n = 10: 10
	// n = 50: 50
	// n = 100: 100
	// n = 200: 200


	// B
	int sum_b = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			sum_b += 1;
		}
	}
	//sum when--
	// n = 1: 1
	// n = 10: 55
	// n = 50: 1275
	// n = 100: 5050
	// n = 200: 20100

	//C
	int sum_c = 0;
	for (int i = 1; i <= n; i++){
		for(int j = 1; j <= (i*i); j++){
			for(int k = 1; k <= j; k++){
				sum_c += 1;
			}
		}
	}
	//sum when--
	// n = 1: 1
	// n = 10: 12859
	// n = 50: 32854795
	// n = 100: 1025335640
	// n = 200: overflow

	//cout << "SUM A: " << sum_a << endl;
	//cout << "SUM B: " << sum_b << endl;
	//cout << "SUM C: " << sum_c << endl;

	auto end = chrono::system_clock::now();

	auto elapsed = chrono::duration_cast<std::chrono::microseconds>(end - start);

	cout << elapsed.count() << '\n';
	return 0;
	}