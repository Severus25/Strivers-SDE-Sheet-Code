// Problem Statement:
// You are given a non-empty string S containing no spaces' and a dictionary of non- empty strings (say the list of words). 
// You are supposed to construct and return all possible sentences after adding spaces in the originally given string 'S', 
// such that each word in a sentence exists in the given dictionary.

// Sample Input 1:
// 1
// 6
// god is now no where here
// godisnowherenowhere
// Sample Output 1:
// god is no where no where god is no where now here
// god is now here no where
// god is now here now here.
// Explanation To Sample Input 1:
// One way to make sentences is to take "god" and append a space, then take "is" and append space, take "now" from the dictionary 
// and take "here" as well. Similarly, for other sentences also, we can add space to get other
// possible sentences. Note that we can reuse dictionary words as "no"
// and "now" are used two times in the same sentence.

// Sample Input 2:
// 1
// 4
// god is no here
// godisnowhere
// Sample Output 2:
// No output to be printed
// Explanation To Sample Input 2:
// We can not make any sentence because after making "god is no" we will be stuck with "where". There is no way to break "where" 
// further such that we can get any word from the dictionary.

// Problem Solution:
#include <bits/stdc++.h> 
void dfs(int i,string &s,string temp,unordered_set<string> &hashmap,vector<string> &ans){
    if(i == s.size()){
        temp.pop_back();
        ans.push_back(temp);
        return;
    }
    string word;
    for(int j=i;j<s.size();j++){
        if(hashmap.count(word+=s[j])){
            dfs(j+1,s,temp+word+" ",hashmap,ans);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary){
    vector<string> ans;
    unordered_set<string> hashmap(dictionary.begin(),dictionary.end());
    dfs(0,s,"",hashmap,ans);
    return ans;
}
