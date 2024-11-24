#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int RodCut(int rods[], int n) {
   	int r[n+1];
    r[0] = 0;

    for (int i = 1; i <= n; i++) {
    	int q = INT_MIN;
        for (int j = 0; j < i; j++) {
            q = q > (rods[j] + r[i - j - 1]) ? q : (rods[j] + r[i - j - 1]);
        }
        r[i] = q;
    }
    return r[n];
}

int main() {
    int n;
    cout << "Length: ";
    cin >> n;
    int rods[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    cout << "Money: " << RodCut(rods, n);
    return 0;
}