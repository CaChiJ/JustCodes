#include <iostream>
#include <vector>

using namespace std;

const int NOT_FOUND = 0;
const int FOUND_1 = -1;
const int FOUND_2 = -2;


struct Node
{
    int number;
    vector<Node *> adj;
};

Node nodes[50001];


int calcLCA(Node* node, int child1, int child2, int parent) {
	bool child1Found = node->number == child1;
	bool child2Found = node->number == child2;
	
	vector<Node *> adj = node->adj;
	
	// cout << node->number << "읭" << endl;
	
	for (auto iter = adj.begin(); iter != adj.end(); iter++) {
		if ((*iter)->number == parent) {
			continue;
		}
		
		int subResult = calcLCA(*iter, child1, child2, node->number);

		switch(subResult) {
			case FOUND_1:
				child1Found = true;
				break;
			case FOUND_2:
				child2Found = true;
				break;
			case NOT_FOUND:
				// nothing to do here
				break;
			default:
				return subResult;
		}
	}
	
	if (child1Found && child2Found) {
		return node->number;
	} else if (child1Found) {
		return FOUND_1;
	} else if (child2Found) {
		return FOUND_2;
	} else {
		return NOT_FOUND;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	
	for (int i = 1; i <= N; ++i) {
		nodes[i].number = i;
	}
	
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
			
		// set tree
		nodes[a].adj.push_back(nodes + b);
		nodes[b].adj.push_back(nodes + a);
	}
	
	int M;
	cin >> M;
	
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		
		cout << calcLCA(nodes + 1, a, b, 0) << '\n';
	}
	
	return 0;
}