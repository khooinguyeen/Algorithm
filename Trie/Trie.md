- If we store keys in a binary search tree, a well balanced BST will need time proportional to M * log N, where M is the maximum string length and N is the number of keys in the tree. Using Trie, the key can be searched in O(M) time


#Insert Operation in Trie:
- Every character of the input key is inserted as an individual Trie node. Note that the children is an array of pointers (or references) to next-level trie nodes. 
- The key character acts as an index to the array children. 
- If the input key is new or an extension of the existing key, construct non-existing nodes of the key, and mark the end of the word for the last node. 
- If the input key is a prefix of the existing key in Trie, Simply mark the last node of the key as the end of a word. 

#Search Operation in Trie:
Searching for a key is similar to the insert operation. However, It only compares the characters and moves down. The search can terminate due to the end of a string or lack of key in the trie. 
- In the former case, if the isEndofWord field of the last node is true, then the key exists in the trie. 
- In the second case, the search terminates without examining all the characters of the key, since the key is not present in the trie.

Note: Insert and search costs O(key_length), however, the memory requirements of Trie is O(ALPHABET_SIZE * key_length * N) where N is the number of keys in Trie. There are efficient representations of trie nodes (e.g. compressed trie, ternary search tree, etc.) to minimize the memory requirements of the trie.