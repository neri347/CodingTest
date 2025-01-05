/// 쿼드압축 후 개수 세기
/// https://school.programmers.co.kr/learn/courses/30/lessons/68936
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
int zeroCount, oneCount;

void DFS(int x, int y, int size)
{
	// 쪼개기 전 압축 시도
	bool isZero = true;
	bool isOne = true;
	for (int i = x; i < x + size; ++i)
	{
		for (int j = y; j < y + size; ++j)
		{
			if (map[i][j] == 0)  isOne = false;
			if (map[i][j] == 1)  isZero = false;
		}
	}

	if (isZero)
	{
		++zeroCount;
		return;
	}

	if (isOne)
	{
		++oneCount;
		return;
	}

	// 압축실패 후 4등분
	int ns = size / 2;
	DFS(x, y, ns);
	DFS(x, y + ns, ns);
	DFS(x + ns, y, ns);
	DFS(x + ns, y + ns, ns);
}

vector<int> solution(vector<vector<int>> arr) {
	map = arr;
	DFS(0, 0, arr.size());
	return { zeroCount, oneCount };
}

int main()
{

	return 0;
}