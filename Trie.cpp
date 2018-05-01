#include "Trie.h"
#include <iostream>
#include "node.h"
#include <fstream>
#include <string>

Trie::Trie()
{
    found=0;
}

void Trie::insertword(string word,int point,class node * top){
            if(word.length()==point){
                top->Word=word;
                return;
            }
            if( top-> ptrs[word[point]]==NULL ){
                node *newnode;
                newnode= new node;
                newnode->info=word[point];
                top->ptrs[word[point]]=newnode;
                insertword(word,point+1,top->ptrs[word[point]]);
            }
            else
                insertword(word,point+1,top->ptrs[word[point]]);
        }



void Trie::find(string value,int point, class node * top){
            if((value != top->Word) && (top->ptrs[value[point]] != NULL))
                find(value,point+1,top->ptrs[value[point]]);
            else if(value==top->Word){
                found=1;
            }
        }

void Trie::printall(class node * top){
            for(int i=0;i<256;i++)
                if(top->ptrs[i]!=NULL){
                    printall(top->ptrs[i]);
                }
            if(top->Word != "")
                cout<<" -> "<<top->Word<<endl;
        }

void Trie::suggest(string value,int point, class node * top){
            if((value != top->Word) && (top->ptrs[value[point]] != NULL)){
                    suggest(value,point+1,top->ptrs[value[point]]);
            }
            else{
                    printall(top);
            }
        }
void Trie::setfoundzero(){
    found=0;
}
