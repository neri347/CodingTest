/// 베스트 앨범
/// https://school.programmers.co.kr/learn/courses/30/lessons/42579
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool Cmp(const pair<string, int>& a, const pair<string, int>& b)
{
	return a.second > b.second;
}

bool SongCmp(const pair<int, int>& a, const pair<int, int>& b)
{
	// 재생 수 같으면 번호 작은 순, 재생 수 다르면 재생 수 많은 순
	return a.second == b.second ? a.first < b.first : a.second > b.second;
}

// 노래정보 = 장르, 재생수, 번호
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	// 장르별로 정렬
	unordered_map<string, int> playMap;
	unordered_map<string, vector<pair<int, int>>> songs; // 장르, 번호, 재생수
	for (int i = 0; i < genres.size(); ++i)
	{
		playMap[genres[i]] += plays[i];
		songs[genres[i]].push_back({ i, plays[i] });
	}
	vector<pair<string, int>> vec(playMap.begin(), playMap.end());
	sort(vec.begin(), vec.end(), Cmp);

	// 재생수와 번호 별로 정렬
	for (int i = 0; i < vec.size(); ++i)
	{
		string genre = vec[i].first;
		if (songs[genre].size() > 1)
		{
			sort(songs[genre].begin(), songs[genre].end(), SongCmp);
			answer.push_back(songs[genre][0].first);
			answer.push_back(songs[genre][1].first);
		}
		else
		{
			answer.push_back(songs[genre][0].first);
		}
	}

	return answer;
}

int main()
{

	return 0;
}