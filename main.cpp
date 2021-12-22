#include "gtest/gtest.h"

#include <queue>
#include <map>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "Queue" << endl;
    queue<int> q;
    srand(time(nullptr));
    int start = clock();
    for (int i = 0; i < 100000; ++i) {
        q.push(rand() % 10000);
    }
    cout << "Add : " << clock() - start << endl;
    start = clock();
    while (!q.empty()) {
        q.pop();
    }
    cout << "Pop : " << clock() - start << endl;
    cout << "Map" << endl;
    map<int, int> m;
    srand(time(nullptr));
    start = clock();
    for (int i = 0; i < 100000; ++i) {
        m.insert(make_pair(i, rand() % 1000));
    }
    cout << "Add : " << clock() - start << endl;
    start = clock();
    for (int i = 0; i < 100000; ++i) {
        m.find(i);
    }
    cout << "Find : " << clock() - start << endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

