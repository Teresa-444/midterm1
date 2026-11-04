int minimumSwaps(vector<int> arr) {
    int swaps=0;
    int n=arr.size();

    for(int i=0; i<n; i++) {
        while(arr[i] != i+1) {
            int target = arr[i]-1;
            swap(arr[i], arr[target]);
            swaps++;
        }
    }

    return swaps;
}