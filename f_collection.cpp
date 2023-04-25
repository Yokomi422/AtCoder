#include <iostream>
#include <string>
#include <algorithm> 
#include <cmath>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <iomanip>
#include <set>
#include <tuple>
#include <cassert>
#include <bitset>
#include <numeric>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;

//---------------------------------------------------------------------------------//
//配列の最初を取り除く関数
template<typename T>
void pop_front(std::vector<T> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}
//---------------------------------------------------------------------------------


//---------------------------------------------------------------------------------//
//a,bを比べてより小さい方に変化する(変更しないのも含む)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------//
//配列を出力する関数
void output(const vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
//---------------------------------------------------------------------------------//
//aのb乗を計算する関数
 
ll Pow(int a, int b) {
    if (b == 0) return 1;
    return Pow(a,b-1) * a;
}
//---------------------------------------------------------------------------------//
//n進数を10進数に変換する関数
ll base_to_long(string s) {
    ll ans = 0, M = s.size() - 1,x = 1;
    for (int i = M; i >= 0; i--) {
        ans += (s[i] - '0') * x;
        x *= 8;
    }
    return ans;
}
//---------------------------------------------------------------------------------//
//10進数をn進数に変化する関数
string s_to_base9(ll n) {
    string s;
    while (n > 0) {
        char c = n%9 + '0';
        s = c + s;
        n /= 9;
    }
    return s;
}

//自作スタック
struct Stack {
    int data[MAX_SIZE];
    int top;
    Stack() {
        top = 0;
    }
    bool empty() {
        return top == 0;
    }
    bool full() {
        return top = MAX_SIZE;
    }
    void push(int x) {
        data[top] = x;
        top++;
    }
    void pop() {
        top--;
    }
    int front() {
        if (top == 0) {
            cout << -1 << endl;
        }
        top--;
        return data[top];
    }
};
//自作queue
int const MAX_SIZE = 100000;

struct Queue {
    int top,tail;
    int data[MAX_SIZE];

    Queue() {
        top = 0;
        tail = 0;
    }
    bool empty() {
        return top == tail;
    }
    bool full() {
        return ((tail + 1)%MAX_SIZE == top);
    }
    void push(int x) {
        data[top] = x;
        top++;
    }
    int front() {
        return data[top - 1];
    }
    void pop() {
        top--;
    }
};
