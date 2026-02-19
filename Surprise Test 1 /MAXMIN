int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    
    int minu= INT_MAX;
    
    for(int i=0; i+k-1<arr.size(); i++)
    {
        int un= arr[i+k-1]-arr[i];
        minu=min(minu, un);
    }
    return minu;
}
