class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int i = 0;
        int sign = 1;
        int n = s.size();
        
        // Ignore leading whitespaces
        while (i < n && s[i] == ' ') 
            i++;
        
        // If the string is empty or starts with an invalid character
        if (i == n || (s[i] < '0' || s[i] > '9') && s[i] != '-' && s[i] != '+') 
            return 0; 
        
        // Handle the sign
        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        } else if (i < n && s[i] == '+') { // Handle optional '+' sign
            i++;
        }

        // Skip leading zeros
        while (i < n && s[i] == '0') {
            i++; 
        }

        // Traverse the string to build the integer
        while (i < n) {
            if (s[i] < '0' || s[i] > '9')
                break;

            // Check for overflow before updating result
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;  // Return INT_MAX or INT_MIN based on the sign
            }

            result = result * 10 + (s[i] - '0');
            i++;
        }

        return result * sign;
    }
};
