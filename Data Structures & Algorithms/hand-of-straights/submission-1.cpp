class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        
        int n = hand.size();
        if(n%gs) return false;

        unordered_map<int, int> m;
        for(auto it : hand){
            m[it]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto it : m){

            pq.push(it.first);
        }

        while(pq.size()){

            int curr = pq.top();
            for(int i = curr; i < curr+gs; i++){

                if(m.find(i)==m.end()) return false;
                m[i]--;
                if(m[i]==0){
                    if(i!=pq.top()) return false;
                    pq.pop();
                }
            }
        }

        return true;
    }
};
