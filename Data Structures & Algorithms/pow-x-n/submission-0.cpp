class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long power=n;
            if (power < 0) {
            x = 1 / x;
            power = -power;
        }
          while (power > 0) {

            // Agar power ODD hai
            if (power % 2 == 1) {

                // Current x ko answer me multiply karo
                ans = ans * x;
            }


            // x ka square karo
            //
            // Example:
            // x = 2
            // x = 4
            // x = 16
            // x = 256
            x = x * x;


            // Power ko half karo
            power = power / 2;
        }


        return ans;
    

    }
};
