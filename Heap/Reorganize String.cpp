class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.size();
        vector<int>freq(26,0);

        for(int i =0;i<n;i++){
            char ch = s[i];
            freq[ch-'a']++;
            if(freq[ch-'a']>(n+1)/2){ //if any char's freq >(n+1)/2,not possible to reorganize the string return empty string
                return "";
            }
        }
        priority_queue<pair<int,char>, vector<pair<int,char>>> pq;
        
        //push all the characters with their respective freq in max heap
        for(int i =0; i<26; i++){
            char ch = i+'a';
            if(freq[ch-'a']>0){
              pq.push({freq[ch-'a'],ch});
            }            
        }
      
        string result ="";
        while(pq.size()>=2){
            auto P1 = pq.top();
            pq.pop();
            auto P2 = pq.top();
            pq.pop();
            result.push_back(P1.second);
            P1.first--;
            result.push_back(P2.second);
            P2.first--;
            if(P1.first>0){
                pq.push(P1);
            }
             if(P2.first>0){
                pq.push(P2);
            }
        }
        if(!pq.empty()){
            result.push_back(pq.top().second);
        }
        return result;
    }
};
