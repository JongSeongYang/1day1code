// 백준 알고리즘 14888번

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//최댓값, 최솟값을 int 범위 내에서 가장 작은 수와 큰 수로 설정
int max_result = -2147483647;
int min_result = 2147483647;
int num;
//수열과 연산자를 저장하는 배열
vector<int> A;
vector<int> op;

//연산자를 다 사용했는지 확인하는 함수
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

//중간값을 받아와서 계산후 재귀호출
//함수가 끝나서 돌아오면 원래 중간값으로 바꿔주고 
//연산자수도 원래대로 
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
	//마지막 단계&&모든 연산자를 사용했다면 최대최소 비교 후 저장
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
	//처음 중간값은 수열의 첫번째 원소로 설정
	Solve(A[0], 0);
	cout << max_result << endl;
	cout << min_result << endl;

	return 0;
}