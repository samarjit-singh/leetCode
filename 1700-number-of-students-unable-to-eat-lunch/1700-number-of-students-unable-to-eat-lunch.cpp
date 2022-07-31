class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> student_choice; // declaring a queue 
        for(int i=0;i<n;i++){ 
            student_choice.push(students[i]); // and pushing student elemnts in it
        }
        
        int rotation = 0,i = 0;
        while(student_choice.size() && rotation < student_choice.size()){
            if(student_choice.front() == sandwiches[i]){
                student_choice.pop();
                i++;
                rotation = 0;
            } else {
                int choice = student_choice.front();
                student_choice.pop();
                student_choice.push(choice);
                rotation++;
            }
        }
        return student_choice.size();
    }
};