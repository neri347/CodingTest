/// �ı����� ���� �ǹ�
/// https://school.programmers.co.kr/learn/courses/30/lessons/92344
/// O(n*m)�� ������ O(1)���� ���̴� ���� ����
/// ���������� ���� �� �ִ�.
/// (1,1)���� (2,2) ������ ���簢�� ������ n��ŭ ��ȭ��Ų�ٰ� �Ѵٸ�,
/// (1,1)�� (3,3)�� n���� �ΰ�, (1,3)�� (3,1)�� -n���� �� ��,
/// ��ü ����� ���ʿ��� ���������� �����ְ� �� �� ������ �Ʒ��� �����ָ�(���Ʒ� -> �¿� �����ε� ����)
/// ���ϴ� ������ n��ŭ ��ȭ��ų �� �ִ�.
/// ---------------------------------------------
/// 0	0	0	0
/// 0	n	0	-n
/// 0	0	0	0
/// 0	-n	0	n
/// ---------------------------------------------
/// (���ʿ��� ���������� ���� ��)
/// 0	0	0	0
/// 0	n	n	0
/// 0	0	0	0
/// 0	-n	-n	0
/// ---------------------------------------------
/// (������ �Ʒ��� ���� ��)
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
        if (type == 1) // ����
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

    // �������� �����P���� ��
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            temp[i][j] += temp[i][j - 1];
        }
    }
    // ������ �Ʒ��� ��
    for (int j = 0; j < m; j++)
    {
        for (int i = 1; i < n; i++)
        {
            temp[i][j] += temp[i - 1][j];
        }
    }

    // ���� board�� temp ��ġ��
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] += temp[i][j];
        }
    }

    // �ı����� ���� �ǹ� ���� ����
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