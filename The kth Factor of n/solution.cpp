class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 1;
        int fact = 1;
        while (fact <= n) {
            if(n%fact == 0) {
                if (i == k)
                    return fact;
                i++;
            }
            fact++;
        }
        return -1;
    }
};