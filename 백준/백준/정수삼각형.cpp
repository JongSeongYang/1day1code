// 백준 알고리즘 1932번

#include<iostream>
#include<algorithm>
using namespace std;

int arr[500][500];
int dp[501][501] = { 0 };
int N;

//x=높이, y=너비
int solve(int x, int y) {
	//최하단이면 dp에 각 arr에서의 값을 넣어주고 재귀를 종료함
	if (x == N - 1) {
		dp[x][y] = arr[x][y];
		return dp[x][y];
	}
	int& left = dp[x + 1][y];
	int& right = dp[x + 1][y + 1];
	//left 구하기
	if (dp[x + 1][y] == 0)
		left = solve(x + 1, y);
	//right 구하기
	if (dp[x + 1][y + 1] == 0)
		right = solve(x + 1, y + 1);
	//max 계산 및 return
	return dp[x][y] = arr[x][y] + max(left, right);
}
int main()
{
	//입력
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> arr[i][j];
	//계산 및 출력
	cout << solve(0, 0) << endl;
	return 0;
}