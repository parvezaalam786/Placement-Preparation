class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        stack<int> s1;
        for (auto x : asteroids)
        {
            if (s1.empty())
                s1.push(x);
            else if (x > 0 and s1.top() > 0 or x < 0 and s1.top() < 0 or s1.top()<0 and x>0) // No collisions are possible
                s1.push(x);
            else
            {
                bool blast = false;
                while (!s1.empty() and (x<0 and s1.top()>0))
                {
                    if (abs(x) > abs(s1.top()))
                    {
                        s1.pop();
                    }
                    else if (abs(x) == abs(s1.top()))
                    {
                        blast = true;
                        s1.pop();
                        break;
                    }
                    else
                    {
                        blast = true;
                        break;
                    }

                }
                if (blast == false)
                    s1.push(x);
            }
        }
        vector<int> ans;
        while (!s1.empty())
        {
            ans.push_back(s1.top());
            s1.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};