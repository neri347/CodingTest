/// 양궁 대회
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
        ryon[10] += arrow; // 남은 화살 0점에 다 쏜다
        int apeachScore = 0;
        int ryonScore = 0;
        for (int i = 0; i < ryon.size(); i++)
        {
            if (apeach[i] >= ryon[i])
            {
                if (apeach[i] > 0) // 어피치 라이언 둘 다 한 발도 못 맞추면 점수반영 안됨
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

    // 그 점수에 어피치보다 1개 더 쏘거나
    if (arrow > apeach[score])
    {
        int shoot = apeach[score] + 1;
        ryon[score] += shoot;
        DFS(arrow - shoot, score - 1, ryon);
        ryon[score] -= shoot;
    }
    // 아예 안 쏜다
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