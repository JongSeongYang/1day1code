// 백준 알고리즘 14889번

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//선수들의 능력치 표현한 배열
int S[20][20];
int N;
//링크팀과 스타트팀의 능력치
int start_s;
int link_s;
int MIN = 2147483647;
//링크팀 스타팀
vector<int>s;
vector<int>l;

void solve(int n)
{
	//인원수가 N명일때까지만 실행하도록
	if (n <= N)
	{
		//두 팀의 선수들의 수가 같고 선수들이 모두 팀에 있을 때
		//두 팀의 능력치를 각각 계산
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
			//두 팀의 능력치의 차가 음수면 -1 곱해주기
			if (tmp < 0) tmp *= -1;
			//최소 능력치 갱신
			MIN = min(tmp, MIN);
		}
		//두 팀의 선수의 합이 N명이 아니면
		//선수 한명씩 추가하면서 모든경우 탐색
		else
		{
			s.push_back(n);
			solve(n + 1);
			s.pop_back();
			//백트래킹하면서 팀이 될 수 있는 모든 경우 확인
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