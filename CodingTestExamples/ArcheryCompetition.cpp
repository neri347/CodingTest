/// ��� ��ȸ
///https://school.programmers.co.kr/learn/courses/30/lessons/92342
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> apeach;
vector<int> answer;
int diff = -1;

void DFS(int arrow, int score, vector<int>& ryon)
{
    if (arrow == 0 || score == -1)
    {
        ryon[10] += arrow; // ���� ȭ�� 0���� �� ���
        int apeachScore = 0;
        int ryonScore = 0;
        for (int i = 0; i < ryon.size(); i++)
        {
            if (apeach[i] >= ryon[i])
            {
                if (apeach[i] > 0) // ����ġ ���̾� �� �� �� �ߵ� �� ���߸� �����ݿ� �ȵ�
                {
                    apeachScore += 10 - i;
                }
            }
            else
            {
                ryonScore += 10 - i;
            }
        }

        if (ryonScore > apeachScore)
        {
            int curDiff = ryonScore - apeachScore;
            if (curDiff > diff)
            {
                diff = curDiff;
                answer = ryon;
            }
        }
        ryon[10] -= arrow;
        return;
    }

    // �� ������ ����ġ���� 1�� �� ��ų�
    if (arrow > apeach[score])
    {
        int shoot = apeach[score] + 1;
        ryon[score] += shoot;
        DFS(arrow - shoot, score - 1, ryon);
        ryon[score] -= shoot;
    }
    // �ƿ� �� ���
    DFS(arrow, score - 1, ryon);
}

vector<int> solution(int n, vector<int> info) {
    apeach = info;
    vector<int> ryon(info.size(), 0);
    DFS(n, 10, ryon);
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    return answer;
}

int main()
{

	return 0;
}