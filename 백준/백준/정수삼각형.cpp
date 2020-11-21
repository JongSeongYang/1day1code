// ���� �˰��� 1932��

#include<iostream>
#include<algorithm>
using namespace std;

int arr[500][500];
int dp[501][501] = { 0 };
int N;

//x=����, y=�ʺ�
int solve(int x, int y) {
	//���ϴ��̸� dp�� �� arr������ ���� �־��ְ� ��͸� ������
	if (x == N - 1) {
		dp[x][y] = arr[x][y];
		return dp[x][y];
	}
	int& left = dp[x + 1][y];
	int& right = dp[x + 1][y + 1];
	//left ���ϱ�
	if (dp[x + 1][y] == 0)
		left = solve(x + 1, y);
	//right ���ϱ�
	if (dp[x + 1][y + 1] == 0)
		right = solve(x + 1, y + 1);
	//max ��� �� return
	return dp[x][y] = arr[x][y] + max(left, right);
}
int main()
{
	//�Է�
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> arr[i][j];
	//��� �� ���
	cout << solve(0, 0) << endl;
	return 0;
}