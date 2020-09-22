#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/map-sum-pairs/
*/

/*
We will use trie here.
The idea here is to store at every node sum of the values of its childs.
For inserting: we will check if the key is already in the trie. If yes then we
will add (update = newvalue-oldvalue) from the root to its terminal node.
For sum: we will simply traverse to the node and return the value  stored at that
node.
*/

class MapSum {
public:
    struct trienode
    {
        int data;
        bool isend;
        trienode *child[26];
    };

    trienode *root = new trienode();

    trienode* newNode()
    {
        trienode *n = new trienode();
        n->data = 0;
        for (int i = 0; i < 26; i++)
            n->child[i] = NULL;
        n->isend = false;
        return n;
    }
    map<string, int> present;

    MapSum()
    {
    }

    void insert(string key, int val)
    {
        int update = val;
        if (present.count(key))
        {
            update -= present[key];
        }
        trienode *curr = root;
        int ch = 0;
        for (int i = 0; i < key.size(); i++)
        {
            ch = key[i] - 'a';
            if (curr->child[ch] == NULL)
            {
                curr->child[ch] = newNode();
            }
            curr = curr->child[ch];
            curr->data += update;
        }
        curr->isend = true;
        present[key] = val;
    }

    int sum(string prefix)
    {
        trienode *curr = root;
        int ch;
        for (int i = 0; i < prefix.length(); i++)
        {
            ch = prefix[i] - 'a';
            if (curr->child[ch] == NULL)
                return 0;
            curr = curr->child[ch];
        }
        return curr->data;
    }
};
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main()
{
    MapSum* pc = new MapSum();
    pc->insert("apple", 3);
    cout << pc->sum("ap") << "\n";
    pc->insert("app", 2);
    cout << pc->sum("ap");
    return 0;
}