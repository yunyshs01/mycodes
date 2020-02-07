#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { 0,1,0,-1 };
const int dy[] = { -1,0,1,0 };
	static int call = 0;

int howMany( int** table,int** dp, int curx, int cury, const int width, const int height) {
	call++;
	//cout << table[cury][curx] << endl;
	
	dp[cury][curx] = 0;
	if (curx + 1 == width && cury + 1 == height) {
		dp[cury][curx]++;
		return 1;		

	}

	for (int i = 0; i < 4; i++) {
		if (cury == 0 && i == 0)continue;
		if (curx + 1 == width&&i == 1)continue;
		if (cury + 1 == height && i == 2)continue;
		if (curx == 0 && i == 3)continue;
		int nx = curx + dx[i];
		int ny = cury + dy[i];
		if (table[cury][curx] > table[ny][nx]) {
			if (dp[ny][nx] > 0) {
				
				 dp[cury][curx] += dp[ny][nx];
				
			}
			else {
				dp[cury][curx] += howMany(table, dp, nx, ny, width, height);
			}
		}
		else {
			//dp[ny][nx] = 0;
		}
	}
	
	return dp[cury][curx];
}

int main() {
	ios::sync_with_stdio(0);
	int h, w;
	cin >> h >> w;

	int** table = new int*[h];
	int** dp = new int*[h];
	for (int  i = 0; i < h; i++) {
		table[i] = new int[w];
		dp[i] = new int[w];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int a;
			cin >> a;
			table[i][j] = a;
			dp[i][j] = -1;
		}
	}
	queue<int> q;
	queue<int> back;
	q.push(0);
	back.push(-1);
	int ways = 1;
	while (!q.empty())
	{
		int now = q.front();
		int y = now / h;
		int x = now % h;
		dp[y][x] = ways;
		for (int i = 0; i < 4; i++) {
			if (i ==0 && y == 0)continue;
			if (i == 1 && x == w - 1)continue;
			if (i == 2 && y == h - 1)continue;
			if (i == 3 && x == 0) continue;

			int nx = x + dx[i];
			int ny = y + dy[i];
			int next = ny*h + nx;
			if (back.front() == next)continue;

			if (table[ny][nx] < table[y][x]) {
				if (dp[ny][nx] == -1) {
					q.push(next);
					back.push(now);
				}
			}

		}

	}

	

	for (int i = 0; i < h; i++) {
		delete[] table[i];
		delete[] dp[i];
	}
	delete[] table;
	delete[] dp;
}