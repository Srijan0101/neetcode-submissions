class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;

        for(auto it : stones) pq.push(it);

        while(pq.size()>1){

            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();

            if(stone1==stone2) continue;
            else pq.push(stone1-stone2);
        }

        if(pq.empty()) return 0;
        return pq.top();
    }
};
