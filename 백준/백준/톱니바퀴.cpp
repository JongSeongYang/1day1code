// 백준 알고리즘 14891번

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string circle[4];
int k;
int num;
int direction;
int score = 0;
int flag[4] = { 0 };//회전여부 확인

//각 톱니바퀴를 탐색하면서 점수확인하는 함수
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

//톱니바퀴를 돌리는 함수
int change(int n, int d)
{
	//함수가 호출이 되면 일단은 돌아가는 톱니바퀴 이므로 
	flag[n] = 1;
	//재귀호출 
	//1번과 4번은 한쪽만 확인 2 3번은 양쪽다확인
	if (n == 0)
	{
		//3번째 홈과 옆 톱니바퀴의 7번째 홈의 극이 다르면
		//회전하지 않았으면
		//회전하는 함수 호출
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
	if (n == 2 || n == 1)//2번 3번
	{
		//오른쪽 돌리기
		if (circle[n][2] != circle[n + 1][6]) {
			if (flag[n + 1] == 0)
				change(n + 1, -d);
		}
		//왼쪽 돌리기
		if (circle[n][6] != circle[n - 1][2]) {
			if (flag[n - 1] == 0)
				change(n - 1, -d);
		}
	}
	//돌리기
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
		//한번 회전이 끝나면 flag함수 초기화
		//새로운 회전이므로
		fill_n(flag, 4, 0);
		cin >> num >> direction;
		change(num - 1, direction);
	}
	findScore();
	cout << score;
	return 0;
}