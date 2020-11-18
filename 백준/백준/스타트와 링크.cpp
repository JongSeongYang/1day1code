// ���� �˰��� 14889��

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//�������� �ɷ�ġ ǥ���� �迭
int S[20][20];
int N;
//��ũ���� ��ŸƮ���� �ɷ�ġ
int start_s;
int link_s;
int MIN = 2147483647;
//��ũ�� ��Ÿ��
vector<int>s;
vector<int>l;

void solve(int n)
{
	//�ο����� N���϶������� �����ϵ���
	if (n <= N)
	{
		//�� ���� �������� ���� ���� �������� ��� ���� ���� ��
		//�� ���� �ɷ�ġ�� ���� ���
		if ((s.size() + l.size() == N) && (s.size() == l.size()))
		{
			start_s = 0;
			link_s = 0;
			for (int i = 0;i < s.size() - 1;i++)
				for (int j = i;j < s.size();j++)
				{
					start_s += S[s[i]][s[j]];
					start_s += S[s[j]][s[i]];
				}
			for (int i = 0;i < l.size() - 1;i++)
				for (int j = i;j < l.size();j++)
				{
					link_s += S[l[i]][l[j]];
					link_s += S[l[j]][l[i]];
				}
			int tmp = start_s - link_s;
			//�� ���� �ɷ�ġ�� ���� ������ -1 �����ֱ�
			if (tmp < 0) tmp *= -1;
			//�ּ� �ɷ�ġ ����
			MIN = min(tmp, MIN);
		}
		//�� ���� ������ ���� N���� �ƴϸ�
		//���� �Ѹ� �߰��ϸ鼭 ����� Ž��
		else
		{
			s.push_back(n);
			solve(n + 1);
			s.pop_back();
			//��Ʈ��ŷ�ϸ鼭 ���� �� �� �ִ� ��� ��� Ȯ��
			l.push_back(n);
			solve(n + 1);
			l.pop_back();
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			cin >> S[i][j];
	solve(0);
	cout << MIN;
	return 0;
}