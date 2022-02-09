#include "solution.h"
#include <vector>
#include <queue>
using namespace sol1102;
using namespace std;

/*takeaways
  - not quite happy with the solution as it has
    a very big assumption where the path with
    the maximum score can be found if we
    keep picking the neighbor with the greatest
    value
    - this happens to be right for these 3 examples
    - it will break easily
      - check testbreak() in the main.cpp
*/

int Solution::path(vector<vector<int>> &input)
{
    /*
       - maxHeap to store the coordinates and value
         of an element
       - the element with the greatest value will be
         on top the heap
    */

    /* C++ note
       - this is just how the priority queue
         is designed to decide who is on top
       - in this case we how we implement
         the compare logic here will produce
         a maxHeap
    */
    auto compare = [](vector<int> &a, vector<int> &b)
    {
        if (a[2] != b[2])
            /* flip a & b to produce maxHeap */
            /* bigger value on top */
            return b[2] > a[2];
        /* tie-breakers */
        if (a[0] != b[0])
            /* smaller row index on top */
            return a[0] > b[0];
        if (a[1] != b[1])
            /* smaller col index on top */
            return a[1] > b[1];
        return false;
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> heap(compare);

    const int rows = input.size();
    const int cols = input[0].size();

    auto visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

    /* left, right, up, and down */
    auto dirs = vector<vector<int>>{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    heap.push({0, 0, input[0][0]});
    visited[0][0] = true;
    int score = input[0][0];

    while (!heap.empty())
    {
        auto e = heap.top();
        heap.pop();
        score = min(score, e[2]);

        if (e[0] == rows - 1 && e[1] == cols - 1)
        {
            return score;
        }

        for (auto dir : dirs)
        {
            auto x = e[0] + dir[0];
            auto y = e[1] + dir[1];
            if (x >= 0 && x < rows && y >= 0 && y < cols && !visited[x][y])
            {
                visited[x][y] = true;
                /* let heap figure out which one to pick next */
                heap.push(vector<int>{x, y, input[x][y]});
            }
        }
    }

    /* you won't get here anyway */
    return score;
}