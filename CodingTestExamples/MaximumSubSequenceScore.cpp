/// Maximum Subsequence Score
/// https://leetcode.com/problems/maximum-subsequence-score/description/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool Cmp(const pair<int, int>& a, const pair<int, int> b)
{
    return a.first > b.first;
}

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int sz = nums1.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < sz; i++)
        {
            vec.push_back({ nums2[i], nums1[i] });
        }
        sort(vec.begin(), vec.end(), Cmp);

        long long answer = 0;
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& p : vec)
        {
            pq.push(p.second);
            sum += p.second;

            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k)
            {
                answer = max(answer, sum * p.first);
            }
        }

        return answer;
    }
};

int main()
{
    vector<int> nums1 = { 1, 3, 3, 2 };
    vector<int> nums2 = { 2, 1, 3, 4 };
    int k = 3;
    Solution solution;
    auto answer = solution.maxScore(nums1, nums2, k);
    cout << answer;
	return 0;
}