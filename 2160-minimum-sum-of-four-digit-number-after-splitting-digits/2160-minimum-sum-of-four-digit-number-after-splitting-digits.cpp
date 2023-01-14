class Solution {
public:
    int minimumSum(int num) {
        priority_queue<int> pq;
        
        while(num>0){
            int a = num%10;
            pq.push(a);
            num = num/10;
        }
        
        string num1 = "";
        string num2 = "";
        
        for(int i=0;i<2;i++){
            num1 += to_string(pq.top());
            pq.pop();
            num2 += to_string(pq.top());
            pq.pop();
        }
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        int ans = stoi(num1)+stoi(num2);
        
        return ans;
    }
};