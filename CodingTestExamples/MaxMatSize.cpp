/// ����
/// https://school.programmers.co.kr/learn/courses/30/lessons/340198
/// ����Ž�� �˰����� ���� -> ���� �� ���� ũ�Ⱑ �ִ� 50�̶� O(n^2)�̻� ���͵� �� ���̶�� ���� 
/// -> ���� Ž�� �˰����� ������ ���̶�� ������.
/// ���ڸ��� �ִ� ũ�⸦ ���ϴ� ���̹Ƿ� ������ �ִ� ���ڸ� �� ���� ū ���ڸ��� �� �� �ִ� ��츦 ã����
/// ������� ���� ū ���ڸ��� ũ��� �����ϰ� �� ���� ��ȯ�ϰ� �ٷ� �����Ű�� ������ �߰������ν�
/// ���ʿ��� Ž���� ���� �� �ְ� ��.
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
					// ���� ū ���ڸ��� �� �� �ִٸ� �� ���� ��ȯ�ϰ� ����
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