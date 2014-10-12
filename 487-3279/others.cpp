#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int s[100000] = {0}, l[25] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9}, cnt, flag, t;
char tmp[30];

int main() {
	scanf("%d\n", &t);
	for (int i = 0; i < t; i++) {
		gets(tmp);
		for (int j = 0; tmp[j] != '\0'; j++) {
			if (tmp[j] >= '0' && tmp[j] <= '9')
				s[i] = s[i] * 10 + tmp[j] - '0';
			else if (tmp[j] >= 'A' && tmp[j] <= 'Z')
				s[i] = s[i] * 10 + l[tmp[j] - 'A'];
		}
	}
	sort (s, s + t);
	cnt = flag = 1;
	for (int i = 1; i < t; i++)
	{
		if (s[i] != s[i - 1]) {
			if (cnt > 1) {
				printf("%03d-%04d %d\n", s[i - 1] / 10000, s[i - 1] % 10000, cnt);
				if (flag == 1) flag = 0;
			}
			cnt = 1;
		}
		else
			cnt++;
	}

	if (cnt > 1) {
		printf("%03d-%04d %d\n", s[t - 1] / 10000, s[t - 1] % 10000, cnt);
		if (flag == 1) flag = 0;
	}
	if (flag)
		printf("No duplicates.\n");

	return 0;
}