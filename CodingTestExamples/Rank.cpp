/// ����
/// https://school.programmers.co.kr/learn/courses/30/lessons/49191
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> graph(n + 1);
    vector<int> topology(n + 1);
    vector<unordered_set<int>> winnersInfo(n + 1); // i��° �÷��̾ �̱� �÷��̾��
    vector<unordered_set<int>> losersInfo(n + 1); // i��° �÷��̾ �� �÷��̾��

    // �׷��� ���� �� �������� ����
    for (auto& vec : results)
    {
        int winner = vec[0];
        int loser = vec[1];
        graph[winner].push_back(loser);
        topology[loser]++;
    }

    queue<int> q;
    for (int i = 1; i < topology.size(); i++)
    {
        // ���� 0�� ��� ť�� �߰�
        if (topology[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int player = q.front();
        q.pop();

        for (int loser : graph[player])
        {
            winnersInfo[loser].insert(player);
            // player�� �̱� ����� loser�� winnerInfo�� �߰�
            for (int p : winnersInfo[player])
            {
                winnersInfo[loser].insert(p);
            }
            topology[loser]--;

            if (topology[loser] == 0) // ���� 0�� �� ��� ť�� �߰�
            {
                q.push(loser);
            }
        }
    }

    // winnerInfo ���� loserInfo ����
    for (int i = 1; i < winnersInfo.size(); i++)
    {
        for (auto& p : winnersInfo[i])
        {
            losersInfo[p].insert(i);
        }
    }

    // ���������� n-1����ŭ ���� �÷��̾�� ������ �� �� �ִ�
    for (int i = 1; i <= n; i++)
    {
        if (winnersInfo[i].size() + losersInfo[i].size() == n - 1)
        {
            ++answer;
        }
    }

    return answer;
}

int main()
{

	return 0;
}