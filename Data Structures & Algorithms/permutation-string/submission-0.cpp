class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
        return false;

       vector<int>frq1(26,0);
       vector<int>frq2(26,0);

       for(char ch:s1){
        frq1[ch-'a']++;


       }
       int k=s1.size();
       for(int i=0;i<k;i++)
        frq2[s2[i]-'a']++;

        if(frq1==frq2)
        return true;



        for(int i=k;i<s2.size();i++){
            frq2[s2[i]-'a']++;

            frq2[s2[i-k]-'a']--;


            if(frq1==frq2)
            return true;
        }
          return false;     
    }
};
