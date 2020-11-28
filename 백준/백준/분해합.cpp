// 백준 알고리즘 2231번

#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int N;
int M;
int mid = 1;

int main()
{
	scanf_s("%d", &N);

	while (1)
	{
		// 범위별로 앞에서부터 탐색
		if (mid < 10) M = mid + mid;
		else if (10 <= mid && mid < 100) M = mid + mid / 10 + mid % 10;
		else if (100 <= mid && mid < 1000) M = mid + mid / 100 + (mid % 100) / 10 + (mid % 10);
		else if (1000 <= mid && mid < 10000) M = mid + mid / 1000 + (mid % 1000) / 100 + (mid % 100) / 10 + mid % 10;
		else if (10000 <= mid && mid < 100000) M = mid + mid / 10000 + (mid % 10000) / 1000 + (mid % 1000) / 100 + (mid % 100) / 10 + mid % 10;
		else M = mid + mid / 100000 + (mid % 100000) / 10000 + (mid % 10000) / 1000 + (mid % 1000) / 100 + (mid % 100) / 10 + mid % 10;
		// M 과 N이 같다면 반복문 탈출
		if (M == N)
		{
			M = mid;
			break;
		}
		// 값이 N보다 커지면 안되므로 
		// 0 값을 넣고 반복문 종료
		else if (mid >= N)
		{
			M = 0;
			break;
		}
		mid++;
	}
	cout << M;
	return 0;
}
