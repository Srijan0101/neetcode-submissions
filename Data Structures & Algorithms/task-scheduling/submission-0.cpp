class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> count(26, 0);

        for(auto it : tasks){

            count[it-'A']++;
        }

        priority_queue<int> pq;
        for (int cnt : count) {
            if (cnt > 0) pq.push(cnt);
        }
        
        queue<pair<int, int>> q;
        int time = 0;

        while(!pq.empty() || !q.empty()){

            time++;
            if(!pq.empty()){

                int top = pq.top()-1;
                pq.pop();

                if(top>0) q.push({top, time+n});
            }
            if(!q.empty()){

                if(time == q.front().second){
                    int cnt = q.front().first;
                    q.pop();
                    pq.push(cnt);
                }
            }
        }

        return time;
    }
};
