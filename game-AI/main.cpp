#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 
#include <cmath>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <cassert>
#include <bitset>
#include <typeinfo>
#include <utility>
#include <list>
#include <numeric>
#include <random>

//座標を保持する構造体
struct Coord {
    int y_;
    int x_;
    Coord(const int y = 0, const int x = 0) : y_(y), x_(x) {}
};

constexpr const int H = 3;
constexpr const int W = 3;
constexpr const int END_TURN = 4;

class MazeState {
    private:
        int points_[H][W] = {};
        int turn_ = 0;
    public:
        Coord character_ = Coord();
        int game_score = 0;
        MazeState() {}

        MazeState(const int seed) {
            auto mt_for_construct = std::mt19937(seed);
            this->character_.y_ = mt_for_construct() % H;
            this->character_.x_ = mt_for_construct() % W;

            for (int y = 0; y < H; y++) {
                for (int x = 0; x < W; x++) {
                    if (y == character_.y_ && x == character_.x_) {
                        continue;
                    }
                    this->points_[y][x] = mt_for_construct() % 10;
                }
            }
        }

        bool isDone() const {
            return this->turn_ == END_TURN;
        }
};

int main() {
}