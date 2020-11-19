// ���� �˰��� 14888��

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//�ִ�, �ּڰ��� int ���� ������ ���� ���� ���� ū ���� ����
int max_result = -2147483647;
int min_result = 2147483647;
int num;
//������ �����ڸ� �����ϴ� �迭
vector<int> A;
vector<int> op;

//�����ڸ� �� ����ߴ��� Ȯ���ϴ� �Լ�
bool isEmpty()
{
	int empty = 0;
	for (int i = 0; i < 4; i++)
	{
		if (op[i] == 0)
			empty++;
	}
	if (empty == 4)
		return true;
	else
		return false;
}

//�߰����� �޾ƿͼ� ����� ���ȣ��
//�Լ��� ������ ���ƿ��� ���� �߰������� �ٲ��ְ� 
//�����ڼ��� ������� 
void Solve(int result, int level)
{
	int mid_r = result;
	if (op[0] != 0)
	{
		mid_r += A[level + 1];
		op[0]--;
		Solve(mid_r, level + 1);
		mid_r = result;
		op[0]++;
	}
	if (op[1] != 0)
	{
		mid_r -= A[level + 1];
		op[1]--;
		Solve(mid_r, level + 1);
		mid_r = result;
		op[1]++;
	}
	if (op[2] != 0)
	{
		mid_r *= A[level + 1];
		op[2]--;
		Solve(mid_r, level + 1);
		mid_r = result;
		op[2]++;
	}
	if (op[3] != 0)
	{
		mid_r = mid_r / A[level + 1];
		op[3]--;
		Solve(mid_r, level + 1);
		mid_r = result;
		op[3]++;
	}
	//������ �ܰ�&&��� �����ڸ� ����ߴٸ� �ִ��ּ� �� �� ����
	if (isEmpty() && level == num - 1)
	{
		max_result = max(max_result, mid_r);
		min_result = min(min_result, mid_r);
	}
}
int main()
{
	cin >> num;
	int tmp;
	for (int i = 0; i < num; i++)
	{
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> tmp;
		op.push_back(tmp);
	}
	//ó�� �߰����� ������ ù��° ���ҷ� ����
	Solve(A[0], 0);
	cout << max_result << endl;
	cout << min_result << endl;

	return 0;
}