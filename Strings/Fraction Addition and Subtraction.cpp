/*
https://leetcode.com/problems/fraction-addition-and-subtraction/
*/
class Solution {
public:
    string fractionAddition(string expression)
    {
        if (expression[0] != '-')
        {
            expression.insert(expression.begin(), '+');
        }
        vector<int> numerator, denominator;

        int len = expression.length();
        for (int i = 0; i < len; )
        {
            int sign = 1;
            if (expression[i] == '-')
                sign = -1;
            i++;
            string nm = "", dm = "";
            while (i < len and expression[i] >= '0' and expression[i] <= '9')
            {
                nm += expression[i];
                i++;
            }
            i++;
            while (i < len and expression[i] >= '0' and expression[i] <= '9')
            {
                dm.push_back(expression[i]);
                i++;
            }
            int x = stoi(nm);
            int y = stoi(dm);
            x = x * sign;

            numerator.push_back(x);
            denominator.push_back(y);
        }

        // for (int i = 0; i < numerator.size(); i++)
        // {
        //     cout << numerator[i] << "/" << denominator[i] << " , ";
        // }
        // cout << "\n";

        int lcm = denominator[0];

        for (int i = 1; i < denominator.size(); i++)
        {
            lcm = (lcm * denominator[i]) / __gcd(lcm, denominator[i]);
        }

        int sum = 0;
        for (int i = 0; i < numerator.size(); i++)
        {
            int m = lcm / denominator[i];
            numerator[i] = numerator[i] * m;
            sum += numerator[i];
        }
        int g = __gcd(abs(sum), lcm);
        sum = sum / g;
        lcm = lcm / g;
        // cout << sum << " " << lcm << "\n";

        string ans = to_string(sum) + "/" + to_string(lcm);
        return ans;

    }
};