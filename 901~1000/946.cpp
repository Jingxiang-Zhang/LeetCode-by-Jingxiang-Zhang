Validate Stack Sequences
Medium

Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        int j=0;
        stack<int> st;
        int size = pushed.size();
        while(i<size && j<size){
            if(st.empty()){
                st.push(pushed[i]);
                i++;
                continue;
            }
            if(st.top() == popped[j]){
                st.pop();
                j++;
                continue;
            }
            st.push(pushed[i]);
            i++;
        }
        
        while(j<size){
            if(st.top() == popped[j]){
                st.pop();
                j++;
            }
            else
                return false;
        }
        return true;
    }
};