// ���� �˰��� 1712��

#include<iostream>
using namespace std;
int A;
int B;
int C;

int main()
{
	cin >> A >> B >> C;
	int result = 1;
	// C-B�� 0���� ������ ������ ���� �� �����Ƿ� result=-1
	if (C - B <= 0)
		result = -1;
	else
		// A/(C-B)���� �������� ������ �� �ִµ�
		// �������� ������ �Ѱ��� �� �Ⱦƾ� �ϹǷ� +1�� ���ش�.
		result = A / (C - B) + 1;
	cout << result;
	return 0;
}