/// �Ÿ��α� Ȯ���ϱ�
/// https://school.programmers.co.kr/learn/courses/30/lessons/81302
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// �� �����ڵ���� �Ÿ� ���ϱ�
// �Ÿ��� 2������ ��� ��Ƽ�� �ִ��� üũ
// �Ÿ��� 2�����̰� ��Ƽ�ǵ� ������ 0
// ��� �Ÿ��α� �� ��Ű�� 1

bool IsBlocked(const pair<int, int>& start, const pair<int, int>& end, const vector<string>& places)
{
	if (start.first == end.first)
	{
		int mid = (start.second + end.second) / 2;
		if (places[start.first][mid] != 'X')
		{
			return false;
		}
	}
	else if (start.second == end.second)
	{
		int mid = (start.first + end.first) / 2;
		if (places[mid][start.second] != 'X')
		{
			return false;
		}
	}
	else
	{
		// �ٸ� ����� ���� ���� �ִ� ���
		if (end.first == start.first - 1 && end.second == start.second - 1)
		{
			if (places[start.first][end.second] != 'X' || places[end.first][start.second] != 'X')
			{
				return false;
			}
		}
		// ���� �Ʒ�
		if (end.first == start.first + 1 && end.second == start.second - 1)
		{
			if (places[start.first][end.second] != 'X' || places[end.first][start.second] != 'X')
			{
				return false;
			}
		}
		// ������ ��
		if (end.first == start.first - 1 && end.second == start.second + 1)
		{
			if (places[start.first][end.second] != 'X' || places[end.first][start.second] != 'X')
			{
				return false;
			}
		}
		// ������ �Ʒ�
		else
		{
			if (places[start.first][end.second] != 'X' || places[end.first][start.second] != 'X')
			{
				return false;
			}
		}
	}
	return true;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	// �� �渶�� üũ
	for (int room = 0; room < places.size(); ++room)
	{
		vector<pair<int, int>> pos; // �����ڵ� ��ġ
		for (int r = 0; r < places[room].size(); ++r)
		{
			for (int c = 0; c < places[room][r].size(); ++c)
			{
				if (places[room][r][c] == 'P')
				{
					pos.push_back({ r, c });
				}
			}
		}

		if (pos.size() == 0)
		{
			answer.push_back(1);
			continue;
		}
		// �����ڵ鰣�� �Ÿ� ���ϱ�
		bool flag = true; // �Ÿ��α� �ؼ� ����
		for (int p = 0; p < pos.size() - 1; ++p)
		{
			if (!flag)   break;
			for (int a = p + 1; a < pos.size(); ++a)
			{
				int dist = abs(pos[p].first - pos[a].first) + abs(pos[p].second - pos[a].second);
				// �Ÿ��� 2 ���ϸ� ��Ƽ������ �����ִ��� üũ
				if (dist <= 2)
				{
					// �Ÿ��� 1�̸� ��Ƽ���� ���� �� ����
					if (dist <= 1 || !IsBlocked(pos[p], pos[a], places[room]))
					{
						flag = false;
						answer.push_back(0);
						break;
					}
				}
			}
		}

		if (flag) // ��� �����ڰ� ��Ű�� ������ 1
		{
			answer.push_back(1);
		}
	}
	return answer;
}

int main()
{
	vector<vector<string>> places = { 
		{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, 
		{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, 
		{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, 
		{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, 
		{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
	solution(places);
	return 0;
}