/*
The same procedure like 208. Only need to modify the search method.
using DFS.
*/
class WordDictionary {
public:
    struct TrieNode{
    public:
        TrieNode *child[26];
        bool isWord;
        TrieNode():isWord(false){
            for(auto &c:child) c=NULL;
        }
    };
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p=root;
        for(auto c:word){
            int i=c-'a';
            if(!p->child[i]) p->child[i]=new TrieNode();
            p=p->child[i];
        }
        p->isWord=true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(word,root,0);
    }

    bool searchWord(string &word, TrieNode *p,int i){
        if(i==word.size()) return p->isWord;
        if(word[i]=='.'){
            for(auto c:p->child){
                if(c&&searchWord(word,c,i+1)) return true;
            }
            return false;
        }
        else{
            return p->child[word[i]-'a']&&searchWord(word,p->child[word[i]-'a'],i+1);
        }
    }
private:
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */


 前辈您好,

我是2017Fall Rutgers University 17Fall Master肖阳, 本硕都是CS. 目前正在找18 Summer的实习. 现在leetcode已经刷了200题, 大多数是medium, 少数的hard.我对C++，Python比较擅长，希望能做偏system或者backend的工作.

不知您是否有空内推一下2018 Summer SDE Internship. 如果现在不适合内推，希望您能告知我. 谢谢了. 以下是简历链接. 谢谢您，
Resume:https://drive.google.com/open?id=11056vYk