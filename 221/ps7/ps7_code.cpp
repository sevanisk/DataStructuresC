#include <iostream>
#include <chrono>
#include <vector>
#include<functional>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void quick_sort(int* v, int sz){
	sort(v, v + sz);
}

bool part_a(int* v, int sz, int target){
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			if(i != j && ((v[i] + v[j]) == target)){
				return true;
			}
		}
	}
	return false;
}

bool part_b(int* v, int sz, int target){
	quick_sort(v, sz);
	int left = 0;
	int right = sz-1;
	int sum = v[left] + v[right];
	while(left < right && sum != target){
		if(sum > target){ right--; }
		else if(sum < target){ left++; }
		sum = v[left] + v[right];
	}
	if(sum == target){ return true; }
	return false;
}

int main() {
	//set up with random numbers and target
	int n = 10000000;
	int v[10000000];
	for(int i = 0; i < n-1; i++){
		int num = (rand() % (1000)) + 1;
		v[i] = num;
	}
	int target = (rand() % (2000 - 1)) + 1;

	auto start = chrono::system_clock::now();

	// Part A
	if(part_a(v, n, target)){
		cout << "part a: true" <<endl;
	}
	

	// Part B
	//if(part_b(v, n, target)){
	//   cout << "part b: true" << endl;
	//}

	auto end = chrono::system_clock::now();
	auto elapsed = chrono::duration_cast<std::chrono::microseconds>(end - start);

	cout << elapsed.count() << '\n';
	return 0;
	}