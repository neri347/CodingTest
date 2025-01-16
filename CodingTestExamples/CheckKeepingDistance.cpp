/// 거리두기 확인하기
/// https://school.programmers.co.kr/learn/courses/30/lessons/81302
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 각 응시자들과의 거리 구하기
// 거리가 2이하일 경우 파티션 있는지 체크
// 거리가 2이하이고 파티션도 없으면 0
// 모두 거리두기 잘 지키면 1

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
		// 다른 사람이 왼쪽 위에 있는 경우
		if (end.first == start.first - 1 && end.second == start.second - 1)
		{
			if (places[start.first][end.second] != 'X' || places[end.first][start.second] != 'X')
			{
				return false;
			}
		}
		// 왼쪽 아래
		if (end.first == start.first + 1 && end.second == start.second - 1)
		{
			if (places[start.first][end.second] != 'X' || places[end.first][start.second] != 'X')
			{
				return false;
			}
		}
		// 오른쪽 위
		if (end.first == start.first - 1 && end.second == start.second + 1)
		{
			if (places[start.first][end.second] != 'X' || places[end.first][start.second] != 'X')
			{
				return false;
			}
		}
		// 오른쪽 아래
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

	// 한 방마다 체크
	for (int room = 0; room < places.size(); ++room)
	{
		vector<pair<int, int>> pos; // 참가자들 위치
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
		// 참가자들간의 거리 구하기
		bool flag = true; // 거리두기 준수 여부
		for (int p = 0; p < pos.size() - 1; ++p)
		{
			if (!flag)   break;
			for (int a = p + 1; a < pos.size(); ++a)
			{
				int dist = abs(pos[p].first - pos[a].first) + abs(pos[p].second - pos[a].second);
				// 거리가 2 이하면 파티션으로 막혀있는지 체크
				if (dist <= 2)
				{
					// 거리가 1이면 파티션을 놓을 수 없다
					if (dist <= 1 || !IsBlocked(pos[p], pos[a], places[room]))
					{
						flag = false;
						answer.push_back(0);
						break;
					}
				}
			}
		}

		if (flag) // 모든 참가자가 지키고 있으면 1
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