string armstrongNumber(int n) 
    {
        int temp = n;
        int ans = 0;
        while(temp)
        {
            int digit = temp % 10;
            ans += pow((double)digit,3.0);
            temp = temp / 10;
        }
        if(ans == n)
            return "true";
        else
            return "false";
        // code here
    }
