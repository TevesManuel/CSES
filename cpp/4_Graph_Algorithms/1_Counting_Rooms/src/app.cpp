#include<iostream>
#include<string>
#include<vector>

int n, m;
std::vector<std::string> grid;

bool isFloor(int x, int y) {
    return (
        ( x >= 0 ) &&
        ( x < n ) &&
        ( y >= 0 ) &&
        ( y < m ) &&
        ( grid[x][y] == '.' )
    );
}

void dfs(int x, int y, std::vector<std::vector<bool>>& visited) {
    int x_dir[] = {1, -1, 0, 0};
    int y_dir[] = {0, 0, -1, 1};
    
    visited[x][y] = true;

    int j, k;

    for(int l = 0; l < 4; l++) { //  M ❤️ L
        j = x + x_dir[l];
        k = y + y_dir[l];

        if(isFloor(j, k) && !visited[j][k]) {
            dfs(j, k, visited);
        }
    }
} 

int main() {
    std::cin >> n;
    std::cin >> m;

    grid.resize(n);

    for(int i = 0; i < n; i++) {
        std::cin >> grid[i];
    }

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    int rooms = 0;

    for(int j = 0; j < n; j++) {
        for(int k = 0; k < m; k++) {
            // std::cout << j << " " << k << " = " << visited[j][k] << std::endl;
            // std::cout << j << " " << k << " = " << grid[j][k] << std::endl;
            if(!visited[j][k] && isFloor(j, k)) {
                rooms++;
                dfs(j, k, visited);
            }
        }
    }

    std::cout << rooms << "\n";

    return 0;
}