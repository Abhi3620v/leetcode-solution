class Solution {
public:
    string longestWord(vector<string>& words) {
       unordered_set<string> s(words.begin(), words.end());

       string ans = "";

       for(string word : words){
            bool valid = true;
            string temp = "";

            for(char ch : word){
                temp += ch;
                if(s.find(temp) == s.end()){
                    valid = false;
                    break;
                }
            }

            if(valid){
                if(temp.length() > ans.length()){
                    ans = temp;
                } else if(temp.length() == ans.length() && temp < ans){
                    ans = temp;
                }
            }

       }
       return ans;                                
    }
};