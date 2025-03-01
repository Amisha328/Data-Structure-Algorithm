// Plus One
// Problem link: https://leetcode.com/problems/plus-one/description/

/* Intution:
This solution first iterates through the digits in reverse order (from the last digit to the first). If the current digit is less than 9, 
it increments the digit by one and returns the resulting array. If the current digit is 9, it sets the digit to 0 and continues iterating. 
If all digits were 9, it returns a new array with 1 as the most significant digit and all other digits as 0.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n-1; i >= 0; i--){
            // If the current digit is less than 9, it increments the digit by one 
            if(digits[i] < 9)
            {
                digits[i]+=1;
                return digits;
            } else 
            // If the current digit is 9, it sets the digit to 0 and continues iterating.
                digits[i] = 0;
        }

        // If all digits were 9, it returns a new array with 1 as the most significant digit and all other digits as 0.
        reverse(digits.begin(), digits.end());
        digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
