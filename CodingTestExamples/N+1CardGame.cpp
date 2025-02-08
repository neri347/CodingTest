/// N + 1 ī�����
/// https://school.programmers.co.kr/learn/courses/30/lessons/258707
/// �� ī�帶�� ����� �ְ�,
/// ���� �ѵ� ������ ��� ����� ���� ����� ���� �ȴ�.
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Pair
{
    pair<int, int> p;
    int cost;
    Pair(pair<int, int> tp, int c) : p(tp), cost(c) {};

    bool operator<(const Pair other) const
    {
        return cost > other.cost;
    }
};

int solution(int coin, vector<int> cards) {
    int answer = 1;
    int n = cards.size();
    int idx = 0;
    int dest = n + 1;
    unordered_map<int, bool> cardMap; // ��� �ִ� ī��
    unordered_map<int, int> costMap; // ī�����, ���
    priority_queue<Pair> pq;
    while (idx < n / 3)
    {
        cardMap[cards[idx]] = true;
        // ��� �ִ� ī�� �߿� ¦�� �´� ���� �ִٸ� ť�� �־��ش�.
        if (cardMap[dest - cards[idx]])
        {
            Pair p({ cards[idx], dest - cards[idx] }, 0);
            pq.push(p);
        }
        ++idx;
    }
    while (idx < n)
    {
        cardMap[cards[idx]] = true;
        costMap[cards[idx]]++;
        if (cardMap[dest - cards[idx]])
        {
            Pair p({ cards[idx], dest - cards[idx] }, costMap[cards[idx]] + costMap[dest - cards[idx]]);
            pq.push(p);
        }

        if (idx % 2 == 1)
        {
            if (!pq.empty())
            {
                if (coin >= pq.top().cost)
                {
                    coin -= pq.top().cost;
                    pq.pop();
                    ++answer;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }

        ++idx;
    }

    return answer;
}

int main()
{

	return 0;
}