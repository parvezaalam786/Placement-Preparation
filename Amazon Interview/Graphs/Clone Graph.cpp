/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
/**************** BFS *****************/
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node)
{
    if (node == NULL)
        return NULL;

    queue<UndirectedGraphNode*> que;
    que.push(node);

    map<UndirectedGraphNode*, UndirectedGraphNode*> clone;
    clone[node] = new UndirectedGraphNode(node->label);

    while (!que.empty())
    {
        UndirectedGraphNode *curr = que.front();
        que.pop();

        for (auto child : curr->neighbors)
        {
            if (!clone.count(child))
            {
                clone[child] = new UndirectedGraphNode(child->label);
                que.push(child);
            }
            clone[curr]->neighbors.push_back(clone[child]);
        }
    }
    return clone[node];
}

/******************* DFS *************************/

UndirectedGraphNode *DFS(UndirectedGraphNode* root, map<UndirectedGraphNode*, UndirectedGraphNode*>& clone)
{
    if (root == NULL)
        return NULL;
    if (clone.count(root))
        return clone[root];

    UndirectedGraphNode *node = new UndirectedGraphNode(root->label);
    clone[root] = node;

    for (auto child : root->neighbors)
    {
        node->neighbors.push_back(DFS(child, clone));
    }
    return clone[root];
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node)
{
    map<UndirectedGraphNode*, UndirectedGraphNode*> clone;
    UndirectedGraphNode *root = DFS(node, clone);
    return root;
}
