
//https://practice.geeksforgeeks.org/problems/minimum-swaps/1/?track=amazon-graphs&batchId=192

// return the minimum number of swaps required to sort the arra
int minSwaps(int arr[], int N) {

    vector<pair<int, int>> v1(N);
    for (int i = 0; i < N; i++)
    {
        v1[i].first = arr[i];
        v1[i].second = i;
    }
    sort(v1.begin(), v1.end());
    vector<bool> visited(N, false);

    int cnt = 0;


    for (int i = 0; i < N; i++)
    {
        if (visited[i] || v1[i].second == i)
            continue;
        int j = i;
        int cycle = 0;
        while (!visited[j])
        {
            visited[j] = true;
            j = v1[j].second;
            cycle++;
        }
        if (cycle > 0)
            cnt += (cycle - 1);
    }
    return cnt;
}