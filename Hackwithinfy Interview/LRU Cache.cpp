#include<bits/stdc++.h>
using namespace std;

map<int, list<int>::iterator> check;
list<int> dq;
int cache = 4;

void lru(int x)
{
    // not in the cache
    if (check.find(x) == check.end())
    {
        cout << "Miss" << "\n";

        // checking if the cache is full
        if (dq.size() == cache)
        {
            int x = dq.back();
            dq.pop_back();
            check.erase(x);
        }
    }
    else
    {
        cout << "Hit" << "\n";
        dq.erase(check[x]);
    }

    dq.push_front(x);
    check[x] = dq.begin();
}

int main()
{
    lru(1);
    lru(2);
    lru(3);
    lru(4);
    lru(1);
    lru(2);
    lru(5);
    lru(1);
    lru(2);
    lru(3);
    lru(4);
    lru(5);
    return 0;
}