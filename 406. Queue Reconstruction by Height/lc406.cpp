/*
First we sorted the people array based on their first element, if the first is the same, we follow the order to the second element.
Then we traverse the sorted array based on the second element. If two element have the same second, we inserted based on their first element.
*/
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int,int>> res;
        sort(people.begin(),people.end(),
            [](const pair<int,int> &a, const pair<int,int> &b){
                return a.first>b.first||(a.first==b.first&&a.second<b.second);
            });
        for(auto p:people)
            res.insert(res.begin()+p.second,p);
        return res;
    }
};


/*
This method elimate the space complexity.
Though not as not concise as the first solution.
*/
class Solution {
public:

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });
        for (int i = 1; i < people.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < i; ++j) {
                if (cnt == people[i].second) {
                    pair<int, int> t = people[i];
                    for (int k = i - 1; k >= j; --k) {
                        people[k + 1] = people[k];
                    }
                    people[j] = t;
                    break;
                }
                if (people[j].first >= people[i].first) ++cnt;
            }
        }
        return people;
    }
};

/*
The same method as 2nd, but uinsg internal API.
*/
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),
            [](const pair<int,int> &a, const pair<int,int> &b){
                return a.first>b.first||(a.first==b.first&&a.second<b.second);
            });
        for(int i=0;i<people.size();++i){
            auto p=people[i];
            if(p.second!=i){
                people.erase(people.begin()+i);
                people.insert(people.begin()+p.second,p);
            }
        }
        return people;
    }
};