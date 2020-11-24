// 백준 알고리즘 2292번

#include<iostream>
using namespace std;

int N;

int main()
{
	cin >> N;
	//앞뒤 범위를 나타내는 변수
	int forward;
	int back = 1;
	int result = 0;
	if (N == 1) result = 1;
	else {
		forward = 1;
		int i = 2;
		while (1)
		{
			//back의 값이 N보다 커지면 
			//N이 back 과 forward사이에 있는 것이므로 
			//결과값은 i
			if (back >= N) break;
			back = forward + (i * 6) - 6;
			if (N > forward && N <= back)
			{
				result = i;
				break;
			}
			forward = back;
			i++;
		}
	}
	cout << result;
	return 0;
}