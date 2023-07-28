class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        int x=num;
        while(x!=0)
        {
            int dig=x%10;
            sum+=dig;
            x=x/10;
        }
        if(sum<10)
        {
            return sum;
        }
        else{
            return addDigits(sum);
        }
    }
};