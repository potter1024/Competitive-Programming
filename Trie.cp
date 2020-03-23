struct TrieNode{
    map<char,TrieNode*> children;
    bool endofword;
    ll cnt=0;
    TrieNode(){
        endofword=false;
    }
};
TrieNode *root=new TrieNode();
void insert(string word)
{
    TrieNode *current=root;
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
        {
            node=new TrieNode();
            current->children[ch]=node;
        }
        current=node;
        current->cnt++;
    }
    current->endofword=true;
}
bool prefixsearch(string word)
{
    TrieNode *current=root;
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
            return false;
        current=node;
    }
    return true;
}
bool wordsearch(string word)
{
    TrieNode *current=root;
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
            return false;
        current=node;
    }
    if(current->endofword==true)
        return true;
    else
        return false;
}
void delet(TrieNode *node)          // delete the tree
{
    TrieNode *cur=node;
    if(!cur)
    {
        return;
    }
    for(ll i = 0; i <= 25; i++)
    {
        if(cur -> children[(char)(i+'A')])
        {
            delet(cur -> children[(char)(i+'A')]);
        }
    }
    delete(node);
}
void deletion(string word)
{
    TrieNode *current=root;
    for(ll i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        current=node;
        if(i==word.size()-1)
        {
            current->endofword=false;
            break;
        }
    }
}
