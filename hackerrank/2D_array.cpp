int hourglassSum(vector<vector<int>> arr) {
    int maxsum=-64;

    for(int i=0; i<=3; i++) {
        for(int j=0; j<=3; j++) {
            int sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]
                    +arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];

            if(maxsum<sum) {
                maxsum=sum;
            }
        }
    }

    return maxsum;
}