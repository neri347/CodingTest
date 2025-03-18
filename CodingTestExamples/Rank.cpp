/// 순위
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
    vector<unordered_set<int>> winnersInfo(n + 1); // i번째 플레이어에 이긴 플레이어들
    vector<unordered_set<int>> losersInfo(n + 1); // i번째 플레이어에 진 플레이어들

    // 그래프 생성 및 위상정보 갱신
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
        // 위상 0인 노드 큐에 추가
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
            // player를 이긴 사람들 loser의 winnerInfo에 추가
            for (int p : winnersInfo[player])
            {
                winnersInfo[loser].insert(p);
            }
            topology[loser]--;

            if (topology[loser] == 0) // 위상 0이 된 노드 큐에 추가
            {
                q.push(loser);
            }
        }
    }

    // winnerInfo 토대로 loserInfo 저장
    for (int i = 1; i < winnersInfo.size(); i++)
    {
        for (auto& p : winnersInfo[i])
        {
            losersInfo[p].insert(i);
        }
    }

    // 승패정보가 n-1개만큼 나온 플레이어는 순위를 알 수 있다
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