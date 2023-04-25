#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;

//https://qiita.com/drken/items/97e37dd6143e33a64c8c
//ここではいわゆるめぐる式ニ分探索

vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
//indexが条件を満たすか
bool judge(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

int bi_search(int key) {
    //index = 0が条件を満たすこともあるので初期条件は-1
    int left = -1;
    //index = a.size() - 1が条件を満たさないこともあるので初期値はa.size()
    int right = a.size();
    while (right - left > 1) {
        int mid = (right + left)/2;
        if (judge(mid,key)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    cout << bi_search(51) << endl;

}