#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		long long int arr[n], min = 10000, answer = 0;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
			if (min > arr[j]) min = arr[j];
		}

		for (int j = 0; j < n; j++) answer += arr[j] - min;
		cout << answer << endl;
	}
}
