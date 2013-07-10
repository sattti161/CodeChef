#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		long long int n, g; cin >> n >> g;
		long long int temp1 = 1, temp2 = 0, answer = 0;
		for (int j = 1; j <= n; j++) {
			answer += temp1 + temp2;
			answer = answer % 1000000007;
		}
		if (g == answer) cout << "CORRECT" << endl;
		else cout << "INCORRECT" << endl;
	}
}
