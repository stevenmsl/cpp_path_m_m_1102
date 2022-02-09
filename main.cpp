#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1102;

tuple<vector<vector<int>>, int> testFixture1()
{
  vector<vector<int>> input{{5, 4, 5}, {1, 2, 6}, {7, 4, 6}};
  return make_tuple(input, 4);
}

tuple<vector<vector<int>>, int> testFixture2()
{
  vector<vector<int>> input{{2, 2, 1, 2, 2, 2}, {1, 2, 2, 2, 1, 2}};
  return make_tuple(input, 2);
}

tuple<vector<vector<int>>, int> testFixture3()
{
  vector<vector<int>> input{{3, 4, 6, 3, 4}, {0, 2, 1, 1, 7}, {8, 8, 3, 2, 7}, {3, 2, 4, 9, 8}, {4, 1, 2, 0, 0}, {4, 6, 5, 4, 3}};
  return make_tuple(input, 3);
}

tuple<vector<vector<int>>, int> testFixturebreak()
{
  vector<vector<int>> input{{5, 4, 5}, {1, 2, 1}, {7, 4, 9}};
  return make_tuple(input, 4);
}

void test1()
{
  auto fixture = testFixture1();
  cout << "Test 1 - expect to see " << to_string(get<1>(fixture))
       << endl;
  Solution sol;
  auto result = sol.path(get<0>(fixture));

  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto fixture = testFixture2();
  cout << "Test 2 - expect to see " << to_string(get<1>(fixture))
       << endl;
  Solution sol;
  auto result = sol.path(get<0>(fixture));

  cout << "result: " << to_string(result) << endl;
}

void test3()
{
  auto fixture = testFixture3();
  cout << "Test 3 - expect to see " << to_string(get<1>(fixture))
       << endl;
  Solution sol;
  auto result = sol.path(get<0>(fixture));

  cout << "result: " << to_string(result) << endl;
}

void testbreak()
{
  auto fixture = testFixturebreak();
  cout << "Test 1 - expect to see " << to_string(get<1>(fixture))
       << endl;
  Solution sol;
  auto result = sol.path(get<0>(fixture));

  cout << "result: " << to_string(result) << endl;
}

void testMaxHeap()
{
  auto fixture = testFixture2();
  auto input = get<0>(fixture);
  Util::testMaxHeap(input);
}

main()
{

  test1();
  test2();
  test3();
  // testMaxHeap();
  // testbreak();
  return 0;
}