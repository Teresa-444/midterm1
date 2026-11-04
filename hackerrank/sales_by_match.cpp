int sockMerchant(int n, vector<int> ar) {
    sort(ar.begin(),ar.end());

    int pairs=0;

    for(int i=0;i<n-1;i++) {
        if(ar[i]==ar[i+1]) {
            pairs++;
            i++;
        }
    }

    return pairs;
}