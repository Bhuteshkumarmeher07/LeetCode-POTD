class Solution {
public:
    int pivotInteger(int n) {
    int l = 1, r = n, sum = n * (n + 1) / 2;
    while (l <= r) {
        int m = (l + r) / 2;
        if(m*m==sum)return m;
        else if (m * m < sum )
            l = m + 1;
        else
            r = m -1 ;
    }
    return  -1;
}
};
