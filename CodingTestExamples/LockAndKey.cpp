/// �ڹ���� ����
/// https://school.programmers.co.kr/learn/courses/30/lessons/60059
#include <string>
#include <vector>

using namespace std;

void Rotate(vector<vector<int>>& key, int dir)
{
    vector<vector<int>> original = key;
    int n = key.size();
    if (dir == 1) // �ð���� ȸ��
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                key[j][n - 1 - i] = original[i][j];
            }
        }
    }
    else // �ݽð���� ȸ��
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                key[n - 1 - j][i] = original[i][j];
            }
        }
    }
}

bool Check(int x, int y, vector<vector<int>> board, const vector<vector<int>>& key, const vector<vector<int>>& lock)
{
    int n = lock.size();
    int m = key.size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i + x][j + y] += key[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i + m - 1][j + m - 1] != 1)
            {
                return false;
            }
        }
    }
    return true;
}

bool MoveKey(const vector<vector<int>>& key, const vector<vector<int>>& lock)
{
    int n = lock.size();
    int m = key.size();
    int sz = 2 * (m - 1) + n;

    vector<vector<int>> board(sz, vector<int>(sz, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i + m - 1][j + m - 1] += lock[i][j];
        }
    }

    // (i, j) = ������ġ
    for (int i = 0; i < n + m - 1; i++)
    {
        for (int j = 0; j < n + m - 1; j++)
        {
            if (Check(i, j, board, key, lock))
            {
                return true;
            }
        }
    }
    return false;
}

bool OpenLock(const vector<vector<int>>& key, const vector<vector<int>>& lock)
{
    // lock �� ��� 1�� ���
    bool flag = true;
    for (int i = 0; i < lock.size(); i++)
    {
        for (int j = 0; j < lock.size(); j++)
        {
            if (lock[i][j] != 1)
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        return true;
    }

    // ȸ�� X
    vector<vector<int>> tempKey1 = key;
    if (MoveKey(tempKey1, lock))
    {
        return true;
    }
    for (int i = 0; i < 3; i++)
    {
        // �ð���� ȸ�� 90 180 270
        Rotate(tempKey1, 1);
        if (MoveKey(tempKey1, lock))
        {
            return true;
        }
    }

    vector<vector<int>> tempKey2 = key;
    // �ݽð���� ȸ�� 90 180 270
    for (int i = 0; i < 3; i++)
    {
        // �ð���� ȸ�� 90 180 270
        Rotate(tempKey2, -1);
        if (MoveKey(tempKey2, lock))
        {
            return true;
        }
    }

    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    return OpenLock(key, lock);
}

int main()
{

	return 0;
}