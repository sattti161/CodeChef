#include <iostream>
#include <math.h>

using namespace std;

int GetCount(int n, int sum);

int main(int argc, char *argv[]) {
	int n; cin >> n;
	cout << endl << GetCount(n, (n / 2) + 1) << endl;
}


int GetCount(int n, int sum) {
	if (n == sum) return 1;
	if (n <= 0) return 0;
	if (sum == 0 && n > 0) return pow(2, n);
	return GetCount(n - 1, sum - 1) + GetCount(n - 1, sum);
}
