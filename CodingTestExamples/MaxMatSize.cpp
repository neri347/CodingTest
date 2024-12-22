/// 공원
/// https://school.programmers.co.kr/learn/courses/30/lessons/340198
/// 완전탐색 알고리즘을 적용 -> 공원 한 변의 크기가 최대 50이라 O(n^2)이상 나와도 될 것이라고 생각 
/// -> 완전 탐색 알고리즘을 적용할 것이라고 생각함.
/// 돗자리의 최대 크기를 구하는 것이므로 가지고 있는 돗자리 중 가장 큰 돗자리를 깔 수 있는 경우를 찾으면
/// 결과값을 가장 큰 돗자리의 크기로 갱신하고 그 값을 반환하고 바로 종료시키는 로직을 추가함으로써
/// 불필요한 탐색을 줄일 수 있게 함.
#include <string>
#include <vector>

using namespace std;
vector<vector<string>> parkVec;
bool CheckMat(int mat, int startX, int startY)
{
	for (int i = 0; i < mat; ++i)
	{
		for (int j = 0; j < mat; ++j)
		{
			int nx = startX + i;
			int ny = startY + j;
			if (nx >= parkVec.size() || ny >= parkVec[0].size())
			{
				return false;
			}
			if (parkVec[nx][ny] != "-1")
			{
				return false;
			}
		}
	}
	return true;
}
int solution(vector<int> mats, vector<vector<string>> park) {
	int answer = -1;
	parkVec = park;
	int maxMat = 0;
	for (int mat : mats)
	{
		if (mat > maxMat)
		{
			maxMat = mat;
		}
	}

	for (int i = 0; i < park.size(); ++i)
	{
		for (int j = 0; j < park[i].size(); ++j)
		{
			for (int mat : mats)
			{
				if (CheckMat(mat, i, j))
				{
					answer = max(answer, mat);
					// 가장 큰 돗자리를 깔 수 있다면 그 값을 반환하고 종료
					if (answer == maxMat)
					{
						return answer;
					}
				}
			}
		}
	}

	return answer;
}