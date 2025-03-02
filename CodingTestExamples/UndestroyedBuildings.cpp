/// 파괴되지 않은 건물
/// https://school.programmers.co.kr/learn/courses/30/lessons/92344
/// O(n*m)의 로직을 O(1)으로 줄이는 것이 관건
/// 누적합으로 줄일 수 있다.
/// (1,1)부터 (2,2) 까지의 직사각형 영역을 n만큼 변화시킨다고 한다면,
/// (1,1)과 (3,3)을 n으로 두고, (1,3)과 (3,1)을 -n으로 둔 후,
/// 전체 행렬의 왼쪽에서 오른쪽으로 더해주고 그 후 위에서 아래로 더해주면(위아래 -> 좌우 순으로도 가능)
/// 원하는 영역을 n만큼 변화시킬 수 있다.
/// ---------------------------------------------
/// 0	0	0	0
/// 0	n	0	-n
/// 0	0	0	0
/// 0	-n	0	n
/// ---------------------------------------------
/// (왼쪽에서 오른쪽으로 더한 후)
/// 0	0	0	0
/// 0	n	n	0
/// 0	0	0	0
/// 0	-n	-n	0
/// ---------------------------------------------
/// (위에서 아래로 더한 후)
///	0	0	0	0
/// 0	n	n	0
/// 0	n	n	0
/// 0	0	0	0

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> temp(n + 1, vector<int>(m + 1, 0));

    for (auto& vec : skill)
    {
        int type = vec[0];
        int r1 = vec[1];
        int c1 = vec[2];
        int r2 = vec[3];
        int c2 = vec[4];
        int degree = vec[5];
        if (type == 1) // 공격
        {
            temp[r1][c1] -= degree;
            temp[r2 + 1][c2 + 1] -= degree;
            temp[r1][c2 + 1] += degree;
            temp[r2 + 1][c1] += degree;
        }
        else
        {
            temp[r1][c1] += degree;
            temp[r2 + 1][c2 + 1] += degree;
            temp[r1][c2 + 1] -= degree;
            temp[r2 + 1][c1] -= degree;
        }
    }

    // 왼쪽으로 오른쯕으로 합
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            temp[i][j] += temp[i][j - 1];
        }
    }
    // 위에서 아래로 합
    for (int j = 0; j < m; j++)
    {
        for (int i = 1; i < n; i++)
        {
            temp[i][j] += temp[i - 1][j];
        }
    }

    // 기존 board와 temp 합치기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] += temp[i][j];
        }
    }

    // 파괴되지 않은 건물 개수 세기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] > 0)
            {
                ++answer;
            }
        }
    }

    return answer;
}

int main()
{

	return 0;
}