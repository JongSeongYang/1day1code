// 백준 알고리즘 1712번

#include<iostream>
using namespace std;
int A;
int B;
int C;

int main()
{
	cin >> A >> B >> C;
	int result = 1;
	// C-B가 0보다 작으면 이윤이 남을 수 없으므로 result=-1
	if (C - B <= 0)
		result = -1;
	else
		// A/(C-B)값이 나머지가 존재할 수 있는데
		// 나머지가 있으면 한개를 더 팔아야 하므로 +1을 해준다.
		result = A / (C - B) + 1;
	cout << result;
	return 0;
}