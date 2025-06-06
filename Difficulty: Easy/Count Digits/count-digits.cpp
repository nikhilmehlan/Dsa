int countDigits(int n) {
    // code here
    int cnt=0;
    while(n>0){
        n=n/10;
        cnt++;
    }
    return cnt;
}