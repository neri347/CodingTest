/// 합승 택시 요금
/// https://school.programmers.co.kr/learn/courses/30/lessons/72413
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 99999999;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = MAX;
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, MAX));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                cost[i][j] = 0;
            }
        }
    }

    for (auto& vec : fares)
    {
        int from = vec[0];
        int to = vec[1];
        int weight = vec[2];
        cost[from][to] = weight;
        cost[to][from] = weight;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cost[i][k] + cost[k][j] < cost[i][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) // 경유하는 장소
    {
        int c = cost[s][i] + cost[i][a] + cost[i][b];
        answer = min(answer, c);
    }

    return answer;
}

int main()
{

	return 0;
}