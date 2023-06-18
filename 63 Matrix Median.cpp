vector<int> merge(vector<int>& a1, vector<int>& a2) {
    int i = 0;
    int j = 0;
    int n = a1.size();
    int m = a2.size();
    vector<int> arr;

    while (i < n && j < m) {
        if (a1[i] < a2[j]) {
            arr.push_back(a1[i]);
            i++;
        } else {
            arr.push_back(a2[j]);
            j++;
        }
    }

    if (i < n) {
        while (i < n) {
            arr.push_back(a1[i]);
            i++;
        }
    }

    if (j < m) {
        while (j < m) {
            arr.push_back(a2[j]);
            j++;
        }
    }

    return arr;
}

int getMedian(vector<vector<int>>& matrix) {
    vector<int> arr;
    for (int i = 0; i < matrix.size(); i++) {
        arr = merge(arr, matrix[i]);
    }

    int k = arr.size();

    if (k % 2 != 0)
        return arr[k / 2];
    else
        return (arr[k / 2] + arr[(k / 2) - 1]) / 2;

    return 0;
}
