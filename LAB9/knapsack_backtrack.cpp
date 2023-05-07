#include<bits/stdc++.h>
using namespace std;

int n, W, maxValue = INT_MIN;
vector<int> w, v, ans;

void knapsack(int idx, int curW, int curV, vector<int> &curAns) {
    if (curW > W) return;
    if (idx == n) {
        if (curV > maxValue) {
            maxValue = curV;
            ans = curAns;
        }
        return;
    }
    curAns[idx] = 0;
    knapsack(idx+1, curW, curV, curAns);
    curAns[idx] = 1;
    knapsack(idx+1, curW+w[idx], curV+v[idx], curAns);
}

int main() {
    cin >> n >> W;
    w.resize(n);
    v.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    vector<int> curAns(n);
    knapsack(0, 0, 0, curAns);
    cout << "Max Value: " << maxValue << endl;
    cout << "Selected items: ";
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) continue; // skip items that were not selected
        cout << i+1 << " "; // output 1-indexed items
    }
    cout << endl;
    return 0;
}
