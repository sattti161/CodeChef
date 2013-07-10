#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *arv[]) {
	int t; cin >> t;

	for (int i = 0; i < t; i++) {
		string str; cin >> str;
		map <char, int> mymap;
		for (int j = 0; j < str.size(); j++) {
			if (mymap.find(str[j]) != mymap.end()) mymap[str[j]] ++;
			else mymap[str[j]] = 1;
		}

		int answer = 0;
		for (map <char, int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
			answer += it->second / 2;
			if (it->second % 2 != 0) answer ++;
		}
		cout << answer << endl;
	}
}
