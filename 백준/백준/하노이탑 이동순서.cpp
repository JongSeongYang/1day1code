// 백준 알고리즘 11729번

#include<iostream>
#include<cmath>
using namespace std;

int N;

void hanoi(int n, int start, int tmp, int end)
{
	if (n == 1)
	{
		printf("%d %d\n", start, end);
		return;
	}
	else
	{
		hanoi(n - 1, start, end, tmp);
		printf("%d %d\n", start, end);
		hanoi(n - 1, tmp, start, end);
	}
	return;
}

int main()
{
	cin >> N;
	cout << (int)pow(2, N) - 1 << endl;
	hanoi(N, 1, 2, 3);
	return 0;
}