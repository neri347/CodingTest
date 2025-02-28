/// 등산코스 정하기
/// https://school.programmers.co.kr/learn/courses/30/lessons/118669
#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    int num = INT_MAX;
    int intensity = INT_MAX;
    sort(summits.begin(), summits.end()); // 봉우리 번호 최대한 낮은 곳 출력위해 정렬

    // 그래프 생성
    vector<vector<pair<int, int>>> adjList(n + 1);
    for (auto& path : paths)
    {
        int p1 = path[0];
        int p2 = path[1];
        int w = path[2];
        adjList[p1].push_back({ p2, w });
        adjList[p2].push_back({ p1, w });
    }

    // 시작점 탐색 위해 저장
    unordered_set<int> gateSet;
    for (int gate : gates)
    {
        gateSet.insert(gate);
    }

    // 봉우리 지점 탐색 위해 저장
    unordered_set<int> summitSet;
    for (int summit : summits)
    {
        summitSet.insert(summit);
    }

    vector<int> dp(summits.size(), INT_MAX); // 각 봉우리까지의 intensity의 최소값 저장

    // 각 시작점부터 각 봉우리까지 최단경로
    for (int i = 0; i < gates.size(); i++)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        vector<int> intensityVec(n + 1, INT_MAX); // 그 지점까지의 최대 intensity
        pq.push({ 0, gates[i] });
        dist[gates[i]] = 0;
        intensityVec[gates[i]] = 0;

        while (!pq.empty())
        {
            int weight = pq.top().first;
            int vertex = pq.top().second;
            pq.pop();

            // 산봉우리에 도착했으면 더 이상 탐색할 필요 없음
            if (summitSet.find(vertex) != summitSet.end())
            {
                break;
            }

            for (auto& p : adjList[vertex])
            {
                int to = p.first;
                int w = p.second;

                // 다른 입구는 방문하지 않는다.
                if (gateSet.find(to) != gateSet.end())
                {
                    continue;
                }

                if (dist[to] > w)
                {
                    dist[to] = w;
                    pq.push({ dist[to], to });
                    intensityVec[to] = max(intensityVec[vertex], w);
                }
            }
        }

        // intensityVec - 봉우리까지 가는 루트에서의 최대 intensity를 저장
        // dp - intensity 중 최소값을 저장해놓는다.
        for (int j = 0; j < summits.size(); j++)
        {
            dp[j] = min(dp[j], intensityVec[summits[j]]);
        }
    }

    // 최소 intensity로 갈 수 있는 봉우리 출력
    // 같은 intensity로 갈 수 있는 봉우리가 여러개면 봉우리 숫자 작은 것 출력
    for (int i = summits.size() - 1; i >= 0; i--)
    {
        if (dp[i] <= intensity)
        {
            intensity = dp[i];
            num = summits[i];
        }
    }

    return { num, intensity };
}

int main()
{

	return 0;
}