#include <stdio.h>

int main(int argc, char * args[]) {
	int n, q; scanf("%d %d", &n, &q);
	bool coins[n];
	for (int i = 0; i < n; i++) coins[i] = false;

	int c, a, b, count;
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &c, &a, &b);
		if (c) {
			count = 0;
			for (int i = a; i <= b; i++) {
				if (coins[i]) count ++;
			}
			printf("%d\n", count);
		}
		else {
			for (int i = a; i <= b; i++)
				coins[i] = !coins[i];
		}
	}
}
