/// p.420 ���� 35_�� �����ϱ�
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> parents;
vector<int> ranks;

int Find(int x)
{
    if (parents[x] == x)
    {
        return x;
    }
    parents[x] = Find(parents[x]);
    return parents[x];
}

void Union(int x, int y)
{
    int root1 = Find(x);
    int root2 = Find(y);
    if (root1 != root2)
    {
        if (ranks[root1] == ranks[root2])
        {
            parents[root2] = root1;
            ++ranks[root1];
        }
        else
        {
            if (ranks[root1] < ranks[root2])
            {
                parents[root1] = root2;
            }
            else
            {
                parents[root2] = root1;
            }
        }
    }
}

bool IsCycle(int node1, int node2)
{
    return Find(node1) == Find(node2);
}

bool CmpCosts(vector<int> a, vector<int> b)
{
    if (a[2] == b[2])
    {
        return a[0] < b[0];
    }
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    // ��� ����� ó�� ��Ʈ�� �ڱ� �ڽ��̴�.
    for (int i = 0; i < n; i++)
    {
        parents.push_back(i);
    }
    ranks.assign(n, 0);
    // costs �迭 ��� ���� ������������ ����
    sort(costs.begin(), costs.end(), CmpCosts);
    
    // cost ���� ������ ����Ŭ ���Ե��� �ʴ� ��� �߰�(����Ŭ ���ԵǴ� ��� = ��Ʈ�� ���� ���)
    for (auto& v : costs)
    {
        if (!IsCycle(v[0], v[1]))
        {
            Union(v[0], v[1]);
            answer += v[2];
        }
    }
    return answer;
}