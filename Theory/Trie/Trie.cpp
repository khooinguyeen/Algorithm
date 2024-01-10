/*
Operation	Time Complexity	Auxiliary Space
Insertion	O(n)	        O(n*m)
Searching	O(n)	        O(1)

Note: Insert and search costs O(key_length), however, the memory requirements of Trie is O(ALPHABET_SIZE * key_length * N) 
where N is the number of keys in Trie. There are efficient representations of trie nodes (e.g. compressed trie, ternary search 
tree, etc.) to minimize the memory requirements of the trie.
*/

#include <iostream>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct  TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        pNode->children[i] = NULL;
    }
    return (pNode);
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (unsigned int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    
    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (unsigned int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return (false);

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->isEndOfWord);
}

int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct TrieNode *root = getNode();
 
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
 
    // Search for different keys
    char output[][32] = {"Not present in trie", "Present in trie"};
 
    // Search for different keys
    cout<<"the"<<" --- "<<output[search(root, "the")]<<endl;
    cout<<"these"<<" --- "<<output[search(root, "these")]<<endl;
    cout<<"their"<<" --- "<<output[search(root, "their")]<<endl;
    cout<<"thaw"<<" --- "<<output[search(root, "thaw")]<<endl;
    return 0;
}