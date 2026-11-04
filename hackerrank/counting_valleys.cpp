int countingValleys(int steps, string path) {
    int altitude=0;
    int valleys=0;

    for(int i=0;i<steps;i++) {
        if(path[i]=='U') {
            altitude++;
            if(altitude==0) {
                valleys++;
            }
        } else {
            altitude--;
        }
    }

    return valleys;
}