/*
https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
*/
//Kadane's algo
int Solution::maxSubArray(const vector<int> &A) {
	int sum1 = A[0], sum2 = A[0];
	for (int i = 1; i < A.size(); i++)
	{
		sum1 = max(A[i], sum1 + A[i]);
		sum2 = max(sum2, sum1);
	}
	return sum2;
}
