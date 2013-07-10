#include <iostream>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <map>
#include <utility>

using namespace std;

vector <int> GetPossiblePrimesUsingWheelFactorize(vector <int> & primes, int n);
bool IsPrime(int num, vector <int> & possible_primes);
bool IsDivisibleByAny(int num, vector<int> & list);
int BinarySearch(vector<int> & arr, int key, int low, int high);
long int GetNumUnSuccessfulAttempts(vector <vector <int> > & arr, int n, vector <int> & primes);


int main(int argc, char *argv[]) {

	vector <int> primes, temp;
	vector <long int> answers;
	int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001, 3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 3083, 3089, 3109, 3119, 3121, 3137, 3163};
	for (int i = 0; i < 447; i++) {
		temp.push_back(arr[i]);
		primes.push_back(arr[i]);
		//cout << arr[i] << ",";
	}

	//temp = GetPossiblePrimesUsingWheelFactorize(temp, 3163);
	for (int i = 3167; i < 10000000; i++) {
		if (IsPrime(i, temp)) primes.push_back(i);
	}
	//cout << endl;

	/*for (int i = 0; i < primes.size(); i++) cout << primes[i] << ", ";
	cout << endl << endl << primes.size() << endl;*/
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		vector <vector <int> > arr;
		for (int i = 0; i < n; i++) {
			vector <int> temp_vec;
			int temp;
			for (int j = 0; j < n; j++){
				scanf("%d", &temp);
				temp_vec.push_back(temp);
			}
			arr.push_back(temp_vec);
		}

		//cout << GetNumUnSuccessfulAttempts(arr, n, primes) << endl;
		answers.push_back(GetNumUnSuccessfulAttempts(arr, n, primes));
	}

	for (int i = 0; i < answers.size(); i++) cout << answers[i] << endl;
}


int BinarySearch(vector<int> & arr, int key, int low, int high) {
	if (low == high) {
		if (arr[low] == key) return low;
		else return -1;
	}

	int mid = low + (high - low) / 2;
	if (arr[mid] == key)
		return mid;
	if (key < arr[mid])
		return BinarySearch(arr, key, low, mid);
	else
		return BinarySearch(arr, key, mid + 1, high);
}

long int GetNumUnSuccessfulAttempts(vector <vector <int> > & arr, int n, vector <int> & primes) {
	long int attempts = 0;
	bool flags[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) flags[i][j] = false;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (flags[i][j]) continue;
			int temp = BinarySearch(primes, arr[i][j], 0, primes.size() - 1);
			//cout << "Search Result: of " <<  arr[i][j] << "is " << temp << endl;
			if(temp != -1) attempts += temp;
			else {
				if (arr[i][j] % 2  == 0) {
					//cout << "attempts for " << arr[i][j] << " " << arr[i][j] / 2 << endl;
					attempts += arr[i][j] / 2;
				}
				else {
					//cout << "attempts for " << arr[i][j] << " " << arr[i][j] / 2 + 2 << endl;
					attempts += arr[i][j] / 2 + 2;
				}
				flags[i][j] = true;
				vector <pair <int, int> > stack;
				stack.push_back(make_pair(i, j));
				//cout << endl;
				while (stack.size() > 0) {
					pair <int, int> temp_pair = stack[stack.size() - 1];
					stack.erase(stack.begin() + stack.size() - 1);
					if (BinarySearch(primes, arr[temp_pair.first][temp_pair.second], 0, primes.size() - 1) >= 0) {
						flags[temp_pair.first][temp_pair.second] = false;
						continue;
					}

					//cout << "Pushed pair for : " << arr[i][j] << " " << arr[temp_pair.first][temp_pair.second] << endl;
					if (temp_pair.first + 1 < n && arr[temp_pair.first][temp_pair.second] % 2  == arr[temp_pair.first + 1][temp_pair.second] % 2 && !flags[temp_pair.first + 1][temp_pair.second]) {
						stack.push_back(make_pair(temp_pair.first + 1, temp_pair.second));
						flags[temp_pair.first + 1][temp_pair.second] = true;
					}
					if (temp_pair.first - 1 >= i && arr[temp_pair.first][temp_pair.second] % 2  == arr[temp_pair.first - 1][temp_pair.second] % 2 && !flags[temp_pair.first - 1][temp_pair.second]) {
						stack.push_back(make_pair(temp_pair.first - 1, temp_pair.second));
						flags[temp_pair.first - 1][temp_pair.second] = true;
					}
					if (temp_pair.second + 1 < n && arr[temp_pair.first][temp_pair.second] % 2  == arr[temp_pair.first][temp_pair.second + 1] % 2 && !flags[temp_pair.first][temp_pair.second + 1]) {
						stack.push_back(make_pair(temp_pair.first, temp_pair.second + 1));
						flags[temp_pair.first][temp_pair.second + 1] = true;
					}
					if (temp_pair.second - 1 >= 0 && arr[temp_pair.first][temp_pair.second] % 2  == arr[temp_pair.first][temp_pair.second - 1] % 2 && !flags[temp_pair.first][temp_pair.second - 1]) {
						stack.push_back(make_pair(temp_pair.first, temp_pair.second - 1));
						flags[temp_pair.first][temp_pair.second - 1] = true;
					}
				}
			}
		}
	}

	return attempts;
}


/*
long int GetNumUnSuccessfulAttempts(vector <vector <int> > & arr, int n, vector <int> & primes) {
	long int attempts = 0;
	bool flags[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) flags[i][j] = false;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = BinarySearch(primes, arr[i][j], 0, primes.size() - 1);
			cout << "Search Result: of " <<  arr[i][j] << "is " << temp << endl;
			if(temp != -1) attempts += temp;

			else {
				if ((i - 1 >= 0 && flags[i - 1][j] && arr[i][j] % 2 == arr[i - 1][j] % 2) || (j - 1 >= 0 && flags[i][j - 1] && arr[i][j] % 2 == arr[i][j - 1] % 2) || (j + 1 < n && flags[i][j + 1] && arr[i][j] % 2 == arr[i][j + 1] % 2)) flags[i][j] = true;
				else if (arr[i][j] % 2  == 0) {
					cout << "attempts for " <<  arr[i][j] << "is " << arr[i][j] / 2 << endl;
					attempts += arr[i][j] / 2;
					flags[i][j] = true;

					for (int k = j; k < n && i + 1 < n; k++) {
						if (arr[i + 1][k] / 2 == 0 && arr[i + 1][k] != 2) flags[i + 1][k] = true;
						else break;
					}
					for (int k = j; k >= 0 && i + 1 < n; k--) {
						if (arr[i + 1][k] / 2 == 0 && arr[i + 1][k] != 2) flags[i + 1][k] = true;
						else break;
					}
				}

				else {
					cout << "attempts for " <<  arr[i][j] << "is " << arr[i][j] / 2  + 2 << endl;
					attempts += arr[i][j] / 2 + 2;
					flags[i][j] = true;

					for (int k = j; k < n && i + 1 < n; k++) {
						if (arr[i + 1][k] / 2 != 0 && arr[i + 1][k] != 2) flags[i + 1][k] = true;
						else break;
					}
					for (int k = j; k >= 0 && i + 1 < n; k--) {
						if (arr[i + 1][k] / 2 != 0 && arr[i + 1][k] != 2) flags[i + 1][k] = true;
						else break;
					}
				}
			}
		}
	}

	return attempts;
}

*/
bool IsPrime(int num, vector <int> & possible_primes) {
	//cout << num << endl ;
	int sqr_root = (int) sqrt(possible_primes[possible_primes.size() - 1]) + 1;
	for (int i = 0; i < possible_primes.size() && possible_primes[i] <= sqr_root && possible_primes[i] < num; i++) {
		if (num % possible_primes[i] == 0) return false;
	}

	return true;
}

vector <int> GetPossiblePrimesUsingWheelFactorize(vector <int> & primes, int n) {
	long long int product = 1;
	for (int i = 0; i < primes.size(); i++) product *= primes[i];
	//cout << "product is : " << product << endl;
	vector <int> temp_vec, possible_primes;
	//cout << "value of n is: " << n << endl;
	map <int, bool> pos_map;

	for (int i = 2; i <= product; i++) {
		if (!IsDivisibleByAny(i, primes)) temp_vec.push_back(i);
	}
	/*for (int i = 0; i< temp_vec.size(); i++) cout << temp_vec[i] << " "; cout <<endl; */
	for (int i = 0; i < temp_vec.size(); i++) {
		for (int j = 0; (temp_vec[i] + j * product) <= n; j++) {
			//cout << "at point 1; " << temp_vec[i]+j*product << endl;
			pos_map[temp_vec[i] + j * product] = true;
		}
	}
	//cout << "REACHED POINT\n";
	for (int i = 0; i < primes.size(); i++) pos_map[primes[i]] = true;
	//cout << "REACHED POINT1\n";
	for (int i = 1; 1 + i * product <= n; i++) pos_map[i * product + 1] = true;
	//cout << "REACHED POINT 2\n";
	for (map <int, bool>::iterator it = pos_map.begin(); it != pos_map.end(); it++) {
		//cout << "FINAL POINT: " <<it->first << endl;
		possible_primes.push_back(it->first);
	}

	return possible_primes;
}


/*
vector <int> GetPossiblePrimesUsingWheelFactorize(vector <int> & primes, int n) {
	long long int product = 1;
	for (int i = 0; i < primes.size(); i++) product *= primes[i];
	cout << "product is : " << product << endl;
	vector <int> temp_vec, possible_primes;
	cout << "value of n is: " << n << endl;


	bool non_primes[n];
	for (int i = 0; i < n; i++){
		cout << i << endl;
		non_primes[i] = false;
	}

	non_primes[0] = true;

	for (int i = 2; i <= product; i++) {
		if (IsDivisibleByAny(i, primes)) temp_vec.push_back(i);
	}

	for (int i = 0; i < temp_vec.size(); i++) {
		for (int j = 0; temp_vec[i] + j * product <= n; j++) non_primes[temp_vec[i] - 1 + j * product] = true;
	}

	for (int i = 0; i < primes.size(); i++) non_primes[primes[i] - 1] = false;

	for (int i = 0; i < n; i++) {
		if (!non_primes[i]) possible_primes.push_back(i + 1);
	}

	return possible_primes;
}*/


bool IsDivisibleByAny(int num, vector<int> & list) {
	for (int i = 0; i < list.size(); i++) {
		if (num % list[i] == 0) return true;
	}
	return false;
}




/*
 * vector <int> primes;
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	int n = 10000;
	vector <int> temp = GetPossiblePrimesUsingWheelFactorize(primes, n);
	cout << endl << endl;
	int count  = 0;
	for (int i = 0; i < temp.size(); i++) {
		if (IsPrime(temp[i], temp)) {
			cout <<  temp[i] << ", ";
			count++;
		}
	}
		//cout << temp[i] << " ";
	cout << endl << endl << count << endl;*
 */

/*
long int GetNumUnSuccessfulAttempts(int **arr, int n) {

} */
