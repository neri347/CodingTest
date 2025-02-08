/// N + 1 카드게임
/// https://school.programmers.co.kr/learn/courses/30/lessons/258707
/// 각 카드마다 비용이 있고,
/// 코인 한도 내에서 드는 비용이 낮은 순대로 내면 된다.
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
    unordered_map<int, bool> cardMap; // 들고 있는 카드
    unordered_map<int, int> costMap; // 카드숫자, 비용
    priority_queue<Pair> pq;
    while (idx < n / 3)
    {
        cardMap[cards[idx]] = true;
        // 들고 있는 카드 중에 짝이 맞는 것이 있다면 큐에 넣어준다.
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