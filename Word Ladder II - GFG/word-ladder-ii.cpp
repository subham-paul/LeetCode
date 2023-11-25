//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>>ans;
        queue<pair<vector<string>, int>> q; // 1st: Seq, 2nd: Level
        q.push({{beginWord}, 1});
        unordered_set<string>st(wordList.begin(), wordList.end());
        
        int prevLevel = -1;
        vector<string>toBeRemoved;
        
        while(!q.empty()) {
            auto fNode = q.front();
            q.pop();
            
            auto currSeq = fNode.first;
            auto currString = currSeq[currSeq.size() - 1];
            auto currLevel = fNode.second;
            
            if(currLevel != prevLevel) {
                for(auto s:toBeRemoved) st.erase(s);
                toBeRemoved.clear();
                prevLevel = currLevel;
            }
            
            // Check kahi dest tak nahi poach gye
            if(currString == endWord){
                ans.push_back(currSeq);
            }
            
            for(int index=0; index<currString.length(); index++){
                char originalChar = currString[index];
                for(char ch='a'; ch<='z'; ch++){
                    currString[index] = ch;
                    // check in wordList
                    if(st.find(currString) != st.end()) {
                        auto temp = currSeq;
                        temp.push_back(currString);
                        q.push({temp, currLevel + 1});
                        toBeRemoved.push_back(currString);
                    }
                }
                // bringing back the currString to it's original State
                currString[index] = originalChar;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends