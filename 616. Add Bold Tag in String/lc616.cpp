/*
This question is like merging intervals. Just need some transiton.
First we find all the intervals. Notice in C++, string::find(word,i) return the first element pointer of word, in the substring i to the end. So the FOR loop means find all the required word in S.
Second we merge all the intervals. We do sort based on the first and second sequence. For i<j, if i.second<j.first, we update the intervals. Else we push j to the required vector.
Last, there is a trick to implementing adding labels. We have already know the position of the word. If we  simply insert to the head of the word. We change their relative sequence. For example, we add <b> to "ABC" for string "ABCDEF". After we add <b>. S="<b>ABCDEF". The 'C' isn't in its original position 2. To avoid this problem, we implement adding operiton from the end of string S.
*/
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<pair<int,int>> ranges=find_pairs(s,dict);
        ranges=merge(ranges);
        for(auto it=ranges.rbegin();it!=ranges.rend();it++){
            s.insert(it->second,"</b>");
            s.insert(it->first,"<b>");
        }
        return s;
    }
private:
    vector<pair<int,int>> find_pairs(string s, vector<string> &dict){
        vector<pair<int,int>> res;
        for(string word:dict){
            int n=word.size();
            for(int i=0;(i=s.find(word,i))!=string::npos;i++){
                res.push_back(pair<int,int>(i,i+n));
            }
        }
        return res;
    }
    vector<pair<int,int>> merge(vector<pair<int,int>> &a){
        vector<pair<int,int>> res;
        sort(a.begin(),a.end(),compare);
        for(int i=0,j=-1;i<a.size();i++){
            if(j<0||res[j].second<a[i].first){
                res.push_back(a[i]);
                j++;
            }
            else{
                res[j].second=max(res[j].second,a[i].second);
            }
        }
        return res;
    }
    static bool compare(pair<int,int> &a, pair<int,int> &b){
        return a.first<b.first||a.first==b.first&&a.second<b.second;
    }
};