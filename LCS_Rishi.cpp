/*
    author: Rishi Mohan Jha
    created_at: 22-12-2021  10:25 PM
*/

#include<bits/stdc++.h>
using namespace std;

#define ll        long long
#define ff        first
#define ss        second
#define pb        push_back
#define sz(x)     ((int)(x).size())
#define all(a)    (a).begin(),(a).end()

string a, b;

void LCS(int n, int m) {
      vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
      for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                  if (i == 0 || j == 0)
                        dp[i][j] = 0;
                  else if (a[i - 1] == b[j - 1])
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                  else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
      }

      int len =  dp[n][m];

      string ans;
      int cnt = 1;

      int i = n, j = m;
      while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                  ans += b[j - 1];
                  i--;
                  j--;
            }
            else {
                  if (dp[i][j - 1] > dp[i - 1][j]) {
                        j--;
                  }
                  else {
                        i--;
                  }
            }
      }
      reverse(all(ans));
      cout << ans << endl;
}

void Solve() {
      cin >> a >> b;
      int n = sz(a), m = sz(b);

      LCS(n, m);
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);  int t = 1;
      while (t--) Solve();
}
