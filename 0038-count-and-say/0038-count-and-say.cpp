class Solution {
public:

    string recursion(int n, int num, string str) {
        if(n == num) {
            return str;
        }

        string currStr = "";
        int i = 0;

        while(i < str.size()) {
            char currChar = str[i];
            int count = 0;

            while(i < str.size() && str[i] == currChar) {
                i++;
                count++;
            }

            currStr += to_string(count) + currChar;
        }
        
        

        return recursion(n, num + 1, currStr);
    }

    string countAndSay(int n) {
        return recursion(n, 1, "1");
    }
};