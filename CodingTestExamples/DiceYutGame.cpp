/// 주사위 윷놀이
/// https://www.acmicpc.net/problem/17825
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int type; // 빨간색 0, 파란색 1, 끝 2
	int score;
	int curPlayer = -1; // 현재 노드에 있는 플레이어 번호
	vector<Node*> next; // 연결된 노드

	Node(int inType, int inScore)
		: type(inType), score(inScore)
	{

	}
};

int dice[10];
int answer;

void Backtrack(int turn, int scores, vector<Node*> pos)
{
	if (turn == 10)
	{
		answer = max(answer, scores);
		return;
	}

	for (int p = 0; p < 4; p++)
	{
		// 도착한 경우 말 선택하지 않는다.
		if (pos[p]->type == 2)
		{
			continue;
		}
		Node* originPos = pos[p];
		Node* curPos = pos[p];
		for (int i = 0; i < dice[turn]; i++)
		{
			if (i == 0)
			{
				// 파란색 칸에서 출발할 경우 파란선 따라간다
				if (curPos->type == 1)
				{
					curPos = curPos->next[1];
				}
				else
				{
					if (curPos->next.empty())
					{
						break;
					}
					curPos = curPos->next[0];
				}
			}
			else
			{
				if (curPos->next.empty())
				{
					break;
				}
				curPos = curPos->next[0];
			}
		}
		// 다른 말이랑 겹치거나 도착했으면 이동시키지 않는다.
		if (curPos->type == 2 || curPos->curPlayer == -1)
		{
			originPos->curPlayer = -1;
			curPos->curPlayer = p;
			pos[p] = curPos;
			Backtrack(turn + 1, scores + curPos->score, pos);
			pos[p] = originPos;
			curPos->curPlayer = -1;
			originPos->curPlayer = p;
		}
	}
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		int d;
		cin >> d;
		dice[i] = d;
	}

	// 노드 연결
	// 원 모양
	Node* root = new Node(false, 0);
	Node* curNode = root;
	vector<Node*> blueNodes;
	for (int i = 2; i <= 40; i += 2)
	{
		Node* newNode = new Node(0, i);
		if (i == 10 || i == 20 || i == 30)
		{
			blueNodes.push_back(newNode);
		}

		curNode->next.push_back(newNode);
		curNode = newNode;

		if (i == 40)
		{
			Node* endNode = new Node(2, 0);
			curNode->next.push_back(endNode);
			blueNodes.push_back(newNode);
		}
	}

	// 십자 모양
	Node* newNode13 = new Node(0, 13);
	Node* newNode16 = new Node(0, 16);
	Node* newNode19 = new Node(0, 19);
	Node* newNode25 = new Node(0, 25);
	blueNodes[0]->type = 1;
	blueNodes[0]->next.push_back(newNode13);
	newNode13->next.push_back(newNode16);
	newNode16->next.push_back(newNode19);
	newNode19->next.push_back(newNode25);

	Node* newNode22 = new Node(0, 22);
	Node* newNode24 = new Node(0, 24);
	blueNodes[1]->type = 1;
	blueNodes[1]->next.push_back(newNode22);
	newNode22->next.push_back(newNode24);
	newNode24->next.push_back(newNode25);

	Node* newNode28 = new Node(0, 28);
	Node* newNode27 = new Node(0, 27);
	Node* newNode26 = new Node(0, 26);
	blueNodes[2]->type = 1;
	blueNodes[2]->next.push_back(newNode28);
	newNode28->next.push_back(newNode27);
	newNode27->next.push_back(newNode26);
	newNode26->next.push_back(newNode25);

	Node* newNode30 = new Node(0, 30);
	Node* newNode35 = new Node(0, 35);
	newNode25->next.push_back(newNode30);
	newNode30->next.push_back(newNode35);
	newNode35->next.push_back(blueNodes[3]);


	Backtrack(0, 0, { root, root, root, root });
	cout << answer;

	return 0;
}