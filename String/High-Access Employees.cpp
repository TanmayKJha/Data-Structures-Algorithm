class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {

        unordered_map<string,vector<int>>mp;
        vector<string>res;
        for(int i = 0; i<access_times.size(); i++){
            string employee = access_times[i][0];
            string time = access_times[i][1];
            int minutes = stoi(time.substr(0,2))*60 + stoi(time.substr(2,2));
            mp[employee].push_back(minutes);
        }
        
        for(auto& [employee,times] : mp){
            sort(times.begin(), times.end());
            if (times.size() < 3) continue; 
            for(int i = 0; i<=times.size()-3; i++){ 
                if((times[i+2]-times[i])<60){
                   res.push_back(employee);
                   break;
                }
            }
        }
        return res;
    }
};

//time complexity -->sorting(NlogN)+ Slidingwindow loop(O(N));
//Space complexity-->O(N) for map
