class Solution {
public:
priority_queue<pair<int,int>>pq;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      for(int i=0;i<points.size();i++){
        int x=points[i][0];
        int y=points[i][1];

        int dis=x*x+y*y;
        pq.push({dis,i});

        if(pq.size()>k)
        pq.pop();
      }
      vector<vector<int>>ans;
      for(int i=0;i<k;i++){
        ans.push_back(points[pq.top().second]);

        pq.pop();
      }
      return ans;

    }
};
