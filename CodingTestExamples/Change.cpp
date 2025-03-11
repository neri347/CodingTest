/// °Å½º¸§µ·
/// https://school.programmers.co.kr/learn/courses/30/lessons/12907
#include <string>
#include <vector>

using namespace std;

const int mod = 1'000'000'007;

int solution(int n, vector<int> money) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (auto& m : money)
    {
        for (int i = 1; i <= n; i++)
        {
            if (m > i)
            {
                continue;
            }
            dp[i] += dp[i - m] % mod;
        }
    }
    return dp[n] % mod;
}

int main()
{

	return 0;
}