//    Defining of root node:  TrieNode *root=new TrieNode();
struct TrieNode
{
    map<char,TrieNode*> children;
    bool endofword;
    TrieNode()
    {
        endofword=false;
    }
};
void insert(TrieNode *root,string word)
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
    }
    current->endofword=true;
}
bool prefixsearch(TrieNode *root,string word)
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
bool wordsearch(TrieNode *root,string word)
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
void deletion(TrieNode *root,string word)
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
