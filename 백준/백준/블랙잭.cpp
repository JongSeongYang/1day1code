//블랙잭 2798

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int N, M;
int MIN;
int Add;
int result;
vector<int>card;

//합을 계산하여 최적값을 찾는 함수
void blackJeck(int a, int b, int c)
{
	Add = card[a] + card[b] + card[c];
	if (Add <= M && (M - Add) < MIN)
	{
		MIN = M - Add;
		result = Add;
	}
}
//조합하는 함수
void pick()
{
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			for (int k = j + 1; k < N; k++)
				blackJeck(i, j, k);
}

int main()
{
	//입력
	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		int tmp;
		scanf_s("%d", &tmp);
		card.push_back(tmp);
	}
	MIN = M;
	pick();
	printf("%d", result);
	return 0;
}
