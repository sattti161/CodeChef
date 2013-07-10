#include <iostream>
#include <map>
#include <utility>

using namespace std;

long long int getAmount(long long int n, map <long long int, long long int> & mymap);

int main(int argc, char *argv[]) {
	long long int n;
	map <long long int, long long int> mymap;
	for (long long int i = 0; i <= 4; i++) mymap[i] = i;
	while (cin >> n) cout << getAmount(n, mymap) << endl;
}


long long int getAmount(long long int n, map <long long int, long long int> & mymap) {
	if (mymap.find(n) != mymap.end()) return mymap[n];

	mymap.insert(make_pair(n / 2, getAmount(n / 2, mymap)));
	mymap.insert(make_pair(n / 3, getAmount(n / 3, mymap)));
	mymap.insert(make_pair(n / 4, getAmount(n / 4, mymap)));

	if (n >= (mymap[n / 2] + mymap[n / 3] + mymap[n / 4])) mymap[n] = n;
	else mymap[n] = mymap[n / 2] + mymap[n / 3] + mymap[n / 4];

	return mymap[n];
}
