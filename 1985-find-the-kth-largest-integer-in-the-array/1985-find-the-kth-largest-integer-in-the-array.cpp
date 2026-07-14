class Solution {
    struct Comp{
        string val;

        Comp(string val){
            this->val = val;
        }

        bool operator > (const Comp &obj) const{
            if(this->val.size() != obj.val.size()){
                return this->val.size() > obj.val.size();
            }

            return this->val > obj.val;
        }
    };
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<Comp, vector<Comp>, greater<Comp>>pq;

        for(string num : nums){
            pq.push(Comp(num));

            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top().val;
    }
};