/// �̷� Ż�� ��ɾ�
/// https://school.programmers.co.kr/learn/courses/30/lessons/150365
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ROW, COLUMN;
int endX, endY;
string ret = "";
string answer = "";
bool findFlag = false;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, -1, 1, 0 };
int ch[4] = { 'd', 'l', 'r', 'u' };

void BackTrack(int curX, int curY, int leftCount)
{
	if (findFlag)
	{
		return;
	}
	// ���� ��ġ�� ���������� �Ÿ� ���. �Ÿ��� ���� Ƚ������ ũ�� �� ��ġ�δ� ������ �� ����.
	int distance = abs(curX - endX) + abs(curY - endY);
	if (distance > leftCount)
	{
		return;
	}
	// ����Ƚ������ ���� ��ġ�� ������ ������ �Ÿ��� ���� �� Ȧ���̸� ���������� ������ �� ����.
	if ((leftCount - distance) % 2 != 0)
	{
		return;
	}

	// ���������� �����߰� ���� Ƚ���� ������ ��θ� ã��
	if (leftCount == 0 && curX == endX && curY == endY)
	{
		answer = ret;
		findFlag = true;
		return;
	}

	// 4���� �˻�
	for (int i = 0; i < 4; ++i)
	{
		int nx = curX + dx[i];
		int ny = curY + dy[i];
		// ���ڿ��� ������ ������ �߰�
		if (nx > 0 && nx <= ROW && ny > 0 && ny <= COLUMN)
		{
			ret += ch[i];
			BackTrack(nx, ny, leftCount - 1);
			ret.pop_back();
		}
	}
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
	ROW = n;
	COLUMN = m;
	endX = r;
	endY = c;

	BackTrack(x, y, k);

	return answer == "" ? "impossible" : answer;
}

int main()
{

	return 0;
}