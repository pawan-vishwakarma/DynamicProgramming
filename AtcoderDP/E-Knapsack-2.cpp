#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
char _;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main() {
    fast_io;
    int N, W;
    cin >> N >> W;
    vector<int> values(N);
    vector<int> weights(N);
    int total_value = 0;
    for (int i = 0; i < N; ++i) {
        cin >> weights[i] >> values[i];
        total_value += values[i];
    }

    vector<ll> DP(total_value + 1, 1e12 + 10);
    DP[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = total_value; j >= values[i]; j--) {
            DP[j] = min(DP[j], DP[j - values[i]] + weights[i]);

        }
    }

    ll answer = 0;
    for (ll i = 0; i <= total_value; i++) {
        if (DP[i] <= W) {
            answer = i;
        }
    }
    cout << answer << endl;

}