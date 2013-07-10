#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	map <string, string > player_countries;
	map <string, long long int> cum_points, player_points;
	map <string, long long int>::iterator it;

	int n, m; cin >> n >> m;
	string str1, str2, str;
	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2;
		player_countries[str1] = str2;
		cum_points[str2] = 0;
		player_points[str1] = 0;
	}

	for (int i = 0; i < m; i++) {
		cin >> str;	cum_points[player_countries[str]] ++;
		player_points[str] ++;
	}

	long long int max = 0;
	for (it = cum_points.begin(); it != cum_points.end(); it ++) {
		if (it->second > max){
			max = it->second;
			str = it->first;
		}
	}
	cout << str << endl;

	max = 0;
	for (it = player_points.begin(); it != player_points.end(); it ++) {
		if (it->second > max){
			max = it->second;
			str = it->first;
		}
	}

	cout << str << endl;
}
