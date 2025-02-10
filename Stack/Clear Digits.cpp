Class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        stack<char>st;

        for(int i =0;i<n; i++){
            //if the char is a number
            if(isdigit(s[i]) && !st.empty()){
                st.pop();
            }else{
                //that char is a letter
                st.push(s[i]);
            }            
        }
      string result;

       while(!st.empty()){
        result = st.top()+ result;
        st.pop();
       }
        return result;
    }
};
