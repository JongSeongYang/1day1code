//������� 2839

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
	//N�� ���� 3���� ������ ������ �� �� �����Ƿ� -1
	if (N < 3) result = -1;
	else
	{
		//f�� �ٿ����� t�� ã�´�
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
		//���� �� �ϳ��� ������ 5�� 3���� �� �� ���� ��� -1
		if (result == 0)
			result = -1;
	}
	cout << result;
	return 0;
}