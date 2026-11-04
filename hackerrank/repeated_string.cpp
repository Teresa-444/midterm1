
long repeatedString(string s, long n) {
    long long countA=0;

    for(int i=0;i<s.size();i++) {
        if(s[i]=='a') {
            countA++;
        }
    }

    long long full=n/s.size();
    long long rem=n%s.size();

    long long result=countA*full;

    for(int i=0;i<rem;i++) {
        if(s[i]=='a') {
            result++;
        }
    }

    return result;
}
