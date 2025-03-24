/// 금과 은 운반하기
/// https://school.programmers.co.kr/learn/courses/30/lessons/86053
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Move(int a, int b, const vector<int>& g, const vector<int>& s, const vector<int>& w, const vector<int>& t, long long time)
{
    long long gold = 0;
    long long silver = 0;
    long long total = 0;

    for (int i = 0; i < w.size(); i++)
    {
        long long roundTime = (long long)t[i] * 2;
        long long moveCount = time / roundTime;
        // 왕복한 후에 t[i]이상 시간이 남으면 광물 한번 더 가져다놓을 수 있음
        if (time % roundTime >= t[i]) ++moveCount;
        long long take = w[i] * moveCount; // 시간내로 가져다놓을 수 있는 양

        // 가지고갈 수 있는 광물의 총 양은 도시에 있는 광물 총 양만큼이다.
        gold += min((long long)g[i], take);
        silver += min((long long)s[i], take);
        total += min((long long)g[i] + s[i], take);
    }

    if (gold >= a && silver >= b && total >= a + b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    long long left = 1;
    long long right = 1e14 * 4;
    answer = right;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (Move(a, b, g, s, w, t, mid))
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return answer;
}

int main()
{
    solution(40, 40, { 10,10,10,10 }, { 10,10,10,10 }, { 10,10,10,10 }, { 1,1,1,1 });
	return 0;
}