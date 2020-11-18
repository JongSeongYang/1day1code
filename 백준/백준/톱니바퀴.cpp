// ���� �˰��� 14891��

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string circle[4];
int k;
int num;
int direction;
int score = 0;
int flag[4] = { 0 };//ȸ������ Ȯ��

//�� ��Ϲ����� Ž���ϸ鼭 ����Ȯ���ϴ� �Լ�
void findScore()
{
	if (circle[0][0] == '0') score += 0;
	else if (circle[0][0] == '1') score += 1;

	if (circle[1][0] == '0') score += 0;
	else if (circle[1][0] == '1') score += 2;

	if (circle[2][0] == '0') score += 0;
	else if (circle[2][0] == '1') score += 4;

	if (circle[3][0] == '0') score += 0;
	else if (circle[3][0] == '1') score += 8;
}

//��Ϲ����� ������ �Լ�
int change(int n, int d)
{
	//�Լ��� ȣ���� �Ǹ� �ϴ��� ���ư��� ��Ϲ��� �̹Ƿ� 
	flag[n] = 1;
	//���ȣ�� 
	//1���� 4���� ���ʸ� Ȯ�� 2 3���� ���ʴ�Ȯ��
	if (n == 0)
	{
		//3��° Ȩ�� �� ��Ϲ����� 7��° Ȩ�� ���� �ٸ���
		//ȸ������ �ʾ�����
		//ȸ���ϴ� �Լ� ȣ��
		if (circle[n][2] != circle[n + 1][6]) {
			if (flag[n + 1] == 0)
				change(n + 1, -d);
		}
	}
	if (n == 3)
	{
		if (circle[n][6] != circle[n - 1][2]) {
			if (flag[n - 1] == 0)
				change(n - 1, -d);
		}
	}
	if (n == 2 || n == 1)//2�� 3��
	{
		//������ ������
		if (circle[n][2] != circle[n + 1][6]) {
			if (flag[n + 1] == 0)
				change(n + 1, -d);
		}
		//���� ������
		if (circle[n][6] != circle[n - 1][2]) {
			if (flag[n - 1] == 0)
				change(n - 1, -d);
		}
	}
	//������
	char tmp;
	if (d == 1)
	{
		tmp = circle[n][7];
		for (int i = 7;i >= 1;i--)
		{
			circle[n][i] = circle[n][i - 1];
		}
		circle[n][0] = tmp;
	}
	else if (d == -1) {
		tmp = circle[n][0];
		for (int i = 0;i < 7;i++)
		{
			circle[n][i] = circle[n][i + 1];
		}
		circle[n][7] = tmp;
	}
	return 0;
}

int main()
{
	for (int i = 0;i < 4;i++)
		cin >> circle[i];
	cin >> k;
	for (int i = 0;i < k;i++)
	{
		//�ѹ� ȸ���� ������ flag�Լ� �ʱ�ȭ
		//���ο� ȸ���̹Ƿ�
		fill_n(flag, 4, 0);
		cin >> num >> direction;
		change(num - 1, direction);
	}
	findScore();
	cout << score;
	return 0;
}