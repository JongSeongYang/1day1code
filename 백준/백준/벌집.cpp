// ���� �˰��� 2292��

#include<iostream>
using namespace std;

int N;

int main()
{
	cin >> N;
	//�յ� ������ ��Ÿ���� ����
	int forward;
	int back = 1;
	int result = 0;
	if (N == 1) result = 1;
	else {
		forward = 1;
		int i = 2;
		while (1)
		{
			//back�� ���� N���� Ŀ���� 
			//N�� back �� forward���̿� �ִ� ���̹Ƿ� 
			//������� i
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