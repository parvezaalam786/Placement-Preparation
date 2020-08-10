vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();
    if (A[n - 1] < 9)
    {
        A[n - 1] += 1;
    }
    else {
        int i = n - 1;
        while (A[i] == 9) {
            A[i] = 0;
            i--;
        }
        if (i < 0)
        {   A.push_back(0);
            A[0] = 1;
        }
        else
            A[i] += 1;
    }
    if (A[0] == 0)
    {
        int x = 0;
        while (A[x] == 0)
            x++;
        vector<int> v1;
        for (int i = x; i < A.size(); i++)
        {
            v1.push_back(A[i]);
        }
        return v1;
    }
    return A;
}
