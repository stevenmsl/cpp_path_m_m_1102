#include <vector>
#include <queue>
#include <functional>
#include "util.h"

using namespace sol1102;

void Util::testMaxHeap(vector<vector<int>> &input)
{
    /* how to produce maxheap  */
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

    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> q(compare);

    for (auto i = 0; i < input.size(); i++)
    {
        for (auto j = 0; j < input[i].size(); j++)
        {
            q.push(vector<int>{i, j, input[i][j]});
        }
    }

    auto top = q.top();
}