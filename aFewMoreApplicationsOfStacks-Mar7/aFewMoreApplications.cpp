#include <stack>
#include <vector>
#include <iostream>

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class MazeSolver {
    std::vector<std::vector<int>> maze;
    std::stack<Point> path;
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    //Q: What are dx and dy?
    //A: They are arrays that represent the four possible directions to move in the maze: up, right, down, and left.


public:
    MazeSolver(std::vector<std::vector<int>> maze) : maze(maze) {}

    bool solve() {
        return explore(0, 0);
    }

private:
    bool explore(int x, int y) {
        if (!isValid(x, y))
            return false;

        path.push(Point(x, y));
        maze[x][y] = 2; // mark as visited

        if (x == maze.size() - 1 && y == maze[0].size() - 1)
            return true; // reached the end

        for (int i = 0; i < 4; i++) {
            if (explore(x + dx[i], y + dy[i]))
                return true;
        }

        path.pop(); // backtrack
        return false;
    }

    bool isValid(int x, int y) {
        if (x < 0 || y < 0 || x >= maze.size() || y >= maze[0].size())
            return false;

        return maze[x][y] == 0;
    }

public:
    std::stack<Point> getPath() {
        return path;
    }
};


int main() {
    std::vector<std::vector<int>> maze = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };
    //Q: What are the 0s and 1s in the maze vector?
    //A: 0s are open paths, 1s are walls.

    MazeSolver solver(maze);
    if (solver.solve()) {
        std::stack<Point> path = solver.getPath();
        
        while (!path.empty()) {
            Point p = path.top();
            path.pop();
            std::cout << "(" << p.x << ", " << p.y << ")\n";
        }
    }
    else {
        std::cout << "No solution found.\n";
    }

    return 0;
}
