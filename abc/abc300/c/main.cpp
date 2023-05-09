#include <iostream>
#include <vector>

bool is_cross(const std::vector<std::string>& grid, int x, int y, int size) {
    for (int d = 1; d <= size; ++d) {
        if (grid[x + d][y] != '#' || grid[x - d][y] != '#' || grid[x][y + d] != '#' || grid[x][y - d] != '#') {
            return false;
        }
    }
    for (int d = 1; d <= size; ++d) {
        if ((x + size + d < grid.size() && grid[x + size + d][y] == '.') ||
            (x - size - d >= 0 && grid[x - size - d][y] == '.') ||
            (y + size + d < grid[0].size() && grid[x][y + size + d] == '.') ||
            (y - size - d >= 0 && grid[x][y - size - d] == '.')) {
            return true;
        }
    }
    return false;
}

int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> grid(H + 4, std::string(W + 4, '.'));
    for (int i = 2; i < H + 2; ++i) {
        for (int j = 2; j < W + 2; ++j) {
            std::cin >> grid[i][j];
        }
    }

    int N = std::min(H, W);
    std::vector<int> count(N + 1, 0);

    for (int i = 2; i <= H + 1; ++i) {
        for (int j = 2; j <= W + 1; ++j) {
            if (grid[i][j] == '#') {
                for (int size = 1; size <= N; ++size) {
                    if (is_cross(grid, i, j, size)) {
                        ++count[size];
                        break;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        std::cout << count[i] << (i < N ? " " : "\n");
    }

    return 0;
}
