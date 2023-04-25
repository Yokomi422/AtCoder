#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;
//https://algo-logic.info/binary-search/#
//ソート済みであることを忘れずに
//問題例 1.平均の最大化 2.配列の中のどこにあるか
vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
int bi_search(int key) {
        //右端と左端のindexを入力する
        int left = 0,right = a.size() - 1;
        while (left <= right) {
            int mid = (left + right)/2;
            if (a[mid] == key) return mid;
            else if (a[mid] > key) right = mid - 1;
            else if (a[mid] < key) left = mid + 1;
        }
    return -1;
    }


//目的のkeyのインデックスを返す(もしなければ-1を出力)
int main() {
    cout << bi_search(243) << endl;
}