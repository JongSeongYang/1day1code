//설탕배달 2839

#include<iostream>
#include<algorithm>
using namespace std;

int N;

int main()
{
	cin >> N;
	int f = N / 5;
	int t;
	int result = 0;
	//N의 값이 3보다 작으면 봉지를 들 수 없으므로 -1
	if (N < 3) result = -1;
	else
	{
		//f를 줄여가며 t를 찾는다
		while (f >= 0)
		{
			t = (N - 5 * f);
			if (t % 3 == 0)
			{
				t = t / 3;
				result = f + t;
				break;
			}
			f--;
		}
		//만약 단 하나의 봉지라도 5와 3으로 될 수 없는 경우 -1
		if (result == 0)
			result = -1;
	}
	cout << result;
	return 0;
}