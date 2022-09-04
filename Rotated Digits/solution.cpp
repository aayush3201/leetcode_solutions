class Solution {
public:
    int rotatedDigits(int n) {
        int c = 0;
        for(int i = 1; i<=n; i++)
            if(isGood(i))
                c++;
        return c;
    }
private:   
    bool isGood(int x){
        int temp = x;
        int newNum = 0;
        int power = 0;
        while(temp != 0){
            int dig = temp%10;
            if(dig == 3 || dig == 4 || dig == 7)
                return false;
            else if(dig == 0 || dig == 1 || dig == 8)
                newNum = dig*pow(10,power) + newNum;
            else if(dig == 2)
                newNum = 5*pow(10,power) + newNum;
            else if(dig == 5)
                newNum = 2*pow(10,power) + newNum;
            else if(dig == 6)
                newNum = 9*pow(10,power) + newNum;
            else newNum = 6*pow(10,power) + newNum;
            temp/=10;
            power++;
        }

        return x != newNum;
    }
};
