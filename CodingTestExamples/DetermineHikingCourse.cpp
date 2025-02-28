/// ����ڽ� ���ϱ�
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
    sort(summits.begin(), summits.end()); // ���츮 ��ȣ �ִ��� ���� �� ������� ����

    // �׷��� ����
    vector<vector<pair<int, int>>> adjList(n + 1);
    for (auto& path : paths)
    {
        int p1 = path[0];
        int p2 = path[1];
        int w = path[2];
        adjList[p1].push_back({ p2, w });
        adjList[p2].push_back({ p1, w });
    }

    // ������ Ž�� ���� ����
    unordered_set<int> gateSet;
    for (int gate : gates)
    {
        gateSet.insert(gate);
    }

    // ���츮 ���� Ž�� ���� ����
    unordered_set<int> summitSet;
    for (int summit : summits)
    {
        summitSet.insert(summit);
    }

    vector<int> dp(summits.size(), INT_MAX); // �� ���츮������ intensity�� �ּҰ� ����

    // �� ���������� �� ���츮���� �ִܰ��
    for (int i = 0; i < gates.size(); i++)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        vector<int> intensityVec(n + 1, INT_MAX); // �� ���������� �ִ� intensity
        pq.push({ 0, gates[i] });
        dist[gates[i]] = 0;
        intensityVec[gates[i]] = 0;

        while (!pq.empty())
        {
            int weight = pq.top().first;
            int vertex = pq.top().second;
            pq.pop();

            // ����츮�� ���������� �� �̻� Ž���� �ʿ� ����
            if (summitSet.find(vertex) != summitSet.end())
            {
                break;
            }

            for (auto& p : adjList[vertex])
            {
                int to = p.first;
                int w = p.second;

                // �ٸ� �Ա��� �湮���� �ʴ´�.
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

        // intensityVec - ���츮���� ���� ��Ʈ������ �ִ� intensity�� ����
        // dp - intensity �� �ּҰ��� �����س��´�.
        for (int j = 0; j < summits.size(); j++)
        {
            dp[j] = min(dp[j], intensityVec[summits[j]]);
        }
    }

    // �ּ� intensity�� �� �� �ִ� ���츮 ���
    // ���� intensity�� �� �� �ִ� ���츮�� �������� ���츮 ���� ���� �� ���
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