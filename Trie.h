#ifndef TRIE_H
#define TRIE_H
#include <string>
#include "node.h"


using namespace std;


class Trie
{
    public:
        Trie();
        int found;
        void setfoundzero();
        void insertword(string word,int point,class node * top);
        void find(string value,int point, class node * top);
        void printall(class node * top);
        void suggest(string value,int point, class node * top);
};

#endif // TRIE_H
