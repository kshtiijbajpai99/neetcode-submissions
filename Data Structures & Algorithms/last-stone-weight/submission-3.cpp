class Solution {
public:
priority_queue<int>pq;
    int lastStoneWeight(vector<int>& stones) {
     for(int num:stones){
        pq.push(num);
     }
     while(pq.size()>1){
        int stone1=pq.top();
        pq.pop();
        int stone2 =pq.top();
        pq.pop();

        if(stone1!=stone2){
            int diff=stone1-stone2;
            pq.push(diff);
        }
        else{
            continue;
        }


        
     }

     if(pq.empty())
     return 0;

     return pq.top();
       
     
    }
};
