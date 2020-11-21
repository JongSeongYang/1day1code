// 백준 알고리즘 2748번

#include<iostream>
using namespace std;

int main()
{
	long long P[100];
	int ntest;
	cin >> ntest;
	P[0] = 0;
	P[1] = 1;
	for (int i = 2;i <= ntest;i++)
		P[i] = P[i - 1] + P[i - 2];
	cout << P[ntest] << endl;;
	return 0;
}