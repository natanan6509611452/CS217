#include <iostream>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;
int unboundKnapSack(int, vector<pair<int, int>>);
int zeroOneKnapSack(int, vector<pair<int, int>>);

int main() {
	vector<pair<int, int>> items;
	items.push_back(make_pair(6, 20));
	items.push_back(make_pair(2, 8));
	items.push_back(make_pair(4, 12));
	items.push_back(make_pair(3, 13));
	items.push_back(make_pair(11, 35));
	cout << "Unbound: " <<unboundKnapSack(3, items) << endl;
	items.clear();
	
	items.push_back(make_pair(1, 1));
	items.push_back(make_pair(2, 4));
	items.push_back(make_pair(3, 6));
	cout << "0/1: " << zeroOneKnapSack(0, items) << endl;
	cout << "0/1: " << zeroOneKnapSack(1, items) << endl;
	cout << "0/1: " << zeroOneKnapSack(2, items) << endl;
	cout << "0/1: " << zeroOneKnapSack(3, items) << endl;
}

int unboundKnapSack(int capacity, vector<pair<int, int>> items) {
	vector<int> K(items.size());
	for (int i = 0; i <= capacity; i++) {
		K[i] = 0;
		for (auto item : items) {
			if (item.first <= i) {
				K[i] = max(K[i], K[i-(item.first)] + item.second);
			}
		}
	}
	return K[capacity];
}

int zeroOneKnapSack(int capacity, vector<pair<int, int>> items) {
	if (capacity == 0) {
		return 0;
	}
	vector<vector<int>> K;
	for (int i = 0; i <= items.size(); i++) {
		K.push_back(vector<int>(capacity));
	}
	for (int i = 1; i <= capacity; i++) {
		for (int j = 1; j <= items.size(); j++) {
			K[i][j] = K[i][j-1];
			if (items[j-1].first <= i) {
				K[i][j] = max(K[i][j], K[i-items[j-1].first][j-1] + items[j-1].second);
			}
		}
	}
	return K[capacity][capacity];
}