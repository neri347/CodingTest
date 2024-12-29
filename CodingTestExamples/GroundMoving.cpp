/// ���� �̵�
/// https://school.programmers.co.kr/learn/courses/30/lessons/62050
/// �� �ٽ� Ǯ� ��.
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isVisited[301][301];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int maxRow, maxColumn;

struct Node
{
    int r;
    int c;
    int cost;
    bool operator<(const Node& n) const
    {
        return cost > n.cost;
    }
};

bool IsValid(int nx, int ny)
{
    return nx >= 0 && ny >= 0 && nx <= maxRow && ny <= maxColumn;
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    maxRow = land[0].size() - 1;
    maxColumn = land.size() - 1;
    priority_queue<Node> pq;
    pq.push({ 0,0,0 });

    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();
        // ť�� ���� isVisited�� false���µ� �ٸ������� ���ŵǾ �湮�� �� ��尡 ���� �� �ִ�.
        if (isVisited[current.c][current.r])
        {
            continue;
        }
        isVisited[current.c][current.r] = true;
        answer += current.cost;
        for (int i = 0; i < 4; ++i)
        {
            int nx = current.r + dx[i];
            int ny = current.c + dy[i];
            // ��ǥ�� land �迭 �ȿ� �����ϴ°�
            if (IsValid(nx, ny))
            {
                // �湮�ߴ� ���� �ƴ� ���� üũ
                if (!isVisited[ny][nx])
                {
                    // ��ٸ� ���� �̵� ������ ���̶�� ��� 0
                    int diff = abs(land[current.c][current.r] - land[ny][nx]);
                    if (diff <= height)
                    {
                        pq.push({ nx, ny, 0 });
                    }
                    else
                    {
                        pq.push({ nx, ny, diff });
                    }
                }
            }
        }
    }

    return answer;
}

int main()
{

	return 0;
}