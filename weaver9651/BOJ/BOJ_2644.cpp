#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int from, to;
int edge_numbers;
bool adjacent_matrix[101][101] = {false,};
int dist[101] = {0,};

void init() {
  cin >> N;
  cin >> from >> to;
  cin >> edge_numbers;

  int a, b;
  for (int i = 0; i < edge_numbers; i++) {
    cin >> a >> b;
    adjacent_matrix[a][b] = true;
    adjacent_matrix[b][a] = true;
  }
}

int bfs() {
  int cur;
  vector<bool> visit(N+1, false);
  queue<int> q;
  q.push(from);
  visit[from] = true;

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    for (int next = 1; next <= N; next++) {
      if (adjacent_matrix[cur][next] && !visit[next]) {
	visit[next] = true;
	dist[next] = dist[cur] + 1;
	if (next == to) {
	  return dist[next];
	}
	q.push(next);
      }
    }
  }
  
  return -1;
}

int main() {
  init();
  int result = bfs();
  cout << result << endl;

  return 0;
}
