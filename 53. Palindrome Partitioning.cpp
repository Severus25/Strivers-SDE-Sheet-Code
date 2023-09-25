// Problem Statement:
// Given a string s, partition s such that every 
// substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.

// Example 1:
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

// Example 2:
// Input: s = "a"
// Output: [["a"]]

// Problem Solution:
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0,s,path,res);
        return res;
    }

    void func(int index, string s, vector<string> &path, vector<vector<string>> &res){
        if(index == s.size()){
            res.push_back(path);
            return;
        }

        for(int i=index;i<s.size();i++){
            //Check if next indices forms a palindrome
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                //Check if index can be further divided into palindrome
                func(i+1,s,path,res);
                //Backtracking
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s,int start,int end){
        //Checks for palindrome
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};
