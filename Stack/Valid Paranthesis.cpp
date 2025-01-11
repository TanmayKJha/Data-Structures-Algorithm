class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        

        for(int i =0; i < s.size();i++){
            char ch = s[i];
            // opening brackets case
            if(ch == '(' || ch == '{' || ch == '['){
            //push openming brackets in stack if any of these found
            st.push(ch);
        }

        else{
            // closing brackets case
            if (!st.empty()){
                // check for the stack is empty or not
                // store the top elemnt of the stack in cjar tyopElement
                char topElement = st.top();
                if( ch == ')' && topElement =='('){
                    st.pop();
                    
                }
                else if( ch == '}' && topElement == '{'){
                    st.pop();
                }
                 else if( ch == ']' && topElement == '['){
                    st.pop();

                }
                else{
                    return false;
                }


            }
            
            else{
                //stack is empty return false
                return false;
            }

        }
        }
         if(st.empty()){
            //valid all items were poped
            return true;
         }
         else{
            return false;
         }

        
    }
};
