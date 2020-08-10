/*
https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
*/

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int x1 = A[i];
        int x2 = A[i + 1];
        int y1 = B[i];
        int y2 = B[i + 1];
        int x = abs(x1 - x2);
        int y = abs(y1 - y2);
        ans += max(x, y);
    }
    return ans;
}
