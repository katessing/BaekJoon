#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dist[100001]; // visited 겸 거리 배열 (전역변수는 자동 0 초기화)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    dist[n] = 1; // 시작점을 1로 설정 (방문 체크용)

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // 1. 꺼낸 뒤에 정답인지 확인 (가장 깔끔함)
        if (cur == k) {
            cout << dist[cur] - 1; // 시작할 때 더한 1을 빼줌
            return 0;
        }

        int next_moves[3] = { cur - 1, cur + 1, cur * 2 };

        for (int nxt : next_moves) {
            // 2. 범위 벗어나면 패스
            if (nxt < 0 || nxt > 100000) continue;

            // 3. 이미 방문했으면 패스 (값이 0이 아니면 방문한 것)
            if (dist[nxt] != 0) continue;

            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
}