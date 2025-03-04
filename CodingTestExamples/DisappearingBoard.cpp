/// ������� ����
/// https://school.programmers.co.kr/learn/courses/30/lessons/92345?language=cpp
/// �̴ϸƽ� �˰���
/// �� ���ʿ��� �ִ� ������ �Ǵ� ����, ��� ���ʿ��� �ּ� ������ �Ǵ� ����
/// �׻� A���� ����.
/// ������ ���� Ƚ���� ¦����� ���� ���� ���� �ǹ�, Ȧ����� ���� �̱�� ���� �ǹ�
/// �ش� ������ ����� ���� �� 4��(�����¿�)
/// ���� ��� ����� �� �߿��� ���� �̱�� ��찡 1���̶� �ִٸ� �� ��츦 ����
/// ���� �̱� �� �ִ� ���� �ִµ���, �װ� ���� ���� ���� �ּ��� ������ ���� �����̱� ����
/// ���� ���� ���̶�� �� ���� �� ���� ���� ���� �� ���̰�,
/// ���� �̱�� ���̶�� �� ���� ���� ���� ���� �� ���̴�.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

int DFS(pair<int, int> mine, pair<int, int> yours) // mine = �̹� ������ ����� ��ġ, yours = ���� ������ ����� ��ġ
{
	if (map[mine.first][mine.second] == 0)	return 0; // ���� �������ٸ� 0 ��ȯ
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = mine.first + dx[i];
		int ny = mine.second + dy[i];
		if (nx >= 0 && nx < map.size() && ny >= 0 && ny < map[0].size() && map[nx][ny] == 1)
		{
			map[mine.first][mine.second] = 0;
			int val = DFS(yours, { nx, ny }) + 1;
			map[mine.first][mine.second] = 1;

			// ���ݱ��� ��� �� ���, �̹��� �̰��� �� -> �̰��� �� ��� ����
			if (result % 2 == 0 && val % 2 == 1)
			{
				result = val;
			}
			// ���ݱ��� ����, �̹����� ���� �� -> �ִ��� ���� �����δ�.
			else if (result % 2 == 0 && val % 2 == 0)
			{
				result = max(result, val);
			}
			// ���ݱ��� �̰��, �̹����� �̰��� �� -> �ִ��� ���� �����δ�.
			else if (result % 2 == 1 && val % 2 == 1)
			{
				result = min(result, val);
			}
		}
	}
	return result;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
	map = board;
	return DFS({ aloc[0], aloc[1] }, { bloc[0], bloc[1] });
}

int main()
{
	vector<vector<int>> board = { {1, 1, 1} ,{1, 1, 1},{1, 1, 1} };
	vector<int> aloc = { 1, 0 };
	vector<int> bloc = { 1, 2 };
	cout << solution(board, aloc, bloc);
	return 0;
}