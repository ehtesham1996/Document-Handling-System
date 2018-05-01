#include <iostream>
#include "node.h"
#include <fstream>
#include <string>
#include <algorithm>
#include "Trie.h"


        using namespace std;

        int choice=0;





        int main()
        {
            //contruction of trie
            Trie tree;

            ifstream in("dictionary.txt");
            string word,current="",key;
            node *root;
            root = new node;
            while(in){
                in>>word;
                tree.insertword(word,0,root);
            }
            in.close();
            do{
                    system("cls");
            cout<<"------------------------------------------------------------"<<endl;
            cout<<"----------Welcome To Document Handling System---------------"<<endl;
            cout<<"------------------------------------------------------------"<<endl;
            cout<<"Please select your choice"<<endl;
            cout<<"(1) Spell Check and Word Suggestion "<<endl;
            cout<<"(2) Auto-Complete "<<endl;
            cout<<"(3) Document Retrieval"<<endl;
            cin>>choice;
            if(choice==1){
                system("cls");
                cout<<"---------Spell Check and Word Suggestion---------"<<endl;
                cout<<"(1) From Document"<<endl;
                cout<<"(2) Enter own word for checking spelling "<<endl;

                cin>>choice;
                if(choice==1){
                    string fn;
                    choice=0;
                    system("cls");
                    cout<<"Enter file name for testing in project directory probably(tester.txt) : " ;cin>>fn;
                    ifstream file(fn.c_str());

                    string words;
                    bool fileopened=false;
                    while(file>>words){
                        fileopened=true;
                        tree.setfoundzero();
                        transform(words.begin(), words.end(), words.begin(),::tolower);
                        tree.find(words,0,root);
                        if(!tree.found && words.length()>3 ){
                        cout<<endl<<"Spelling of  : "<<words<<" : incorrect possible suggestions include : "<<endl;
                        tree.suggest(words,0,root);
                    }
                    }
                    file.close();

                    if(!fileopened){
                        cout<<"Invalid file name "<<endl;
                        }
                    }




                else if(choice==2){
                    choice=0;
                    system("cls");
                    cout<<"Enter word to be searched : ";cin>>key;
                    tree.find(key,0,root);
                    if(!tree.found){
                        cout<<endl<<"Spelling is incorrect possible suggestions include : "<<endl;
                        tree.suggest(key,0,root);
                    }
                }
            }

            if (choice==2){
                choice=0;
                system("cls");
                cout<<"--------Auto Complete-----------"<<endl;
                cout<<"Please enter any prefix--------- : ";cin>>key;
                transform(key.begin(), key.end(), key.begin(),::tolower);
                bool ProperString=true;
                for(int i=0;i<key.length();i++){
                    if(key[i]<97 || key[i]>122){
                        ProperString=false;
                    }
                }
                if(ProperString)
                tree.suggest(key,0,root);
                else
                    cout<<"Please enter only alphabets";

            }
            if (choice==3){
                choice=0;
                node *doc1;
                node *doc2;
                node *doc3;

                doc1=new node;
                doc2=new node;
                doc3=new node;

                ifstream d1("tester.txt");
                doc1->setfilename("tester.txt");
                string temp;
                while(d1>>temp){
                    tree.insertword(temp,0,doc1);
                }
                d1.close();
                ifstream d2("TobeSpellChecked.txt");
                doc2->setfilename("TobeSpellChecked.txt");
                while(d2>>temp){
                  tree.insertword(temp,0,doc2);
                }
                d2.close();
                ifstream d3("dictionary.txt");
                doc3->setfilename("dictionary.txt");
                while(d3>>temp){
                  tree.insertword(temp,0,doc3);
                }
                d3.close();

                system("cls");
                cout<<"---------------Document Retrieval------------"<<endl;
                cout<<"Following are the three documents used :"<<endl;
                cout<<"1.tester.txt"<<endl;
                cout<<"2.TobeSpellChecked.txt"<<endl;
                cout<<"3.Dicitonary.txt"<<endl;
                cout<<"----------------------------------------------"<<endl;
                cout<<"======Enter the word you wish to search for =: ";string input;cin>>input;

                tree.setfoundzero();
                tree.find(input,0,doc1);
                bool exists=false;
                if(tree.found){
                    tree.found=0;
                    exists=true;
                    cout<<"Your search query word is in "<<doc1->getfilename()<<endl;
                }

                tree.find(input,0,doc2);
                if(tree.found){
                    tree.setfoundzero();
                    exists=true;
                    cout<<"Your search query word is in "<<doc2->getfilename()<<endl;
                }
                 tree.find(input,0,doc3);
                if(tree.found){
                    tree.setfoundzero();
                    exists=true;
                    cout<<"Your search query word is in "<<doc3->getfilename()<<endl;
                }
                if(!exists){
                    cout<<"Spelling mistake :Did you mean any of these  : "<<endl;
                    tree.suggest(input,0,doc3);
                }

            }
            int exit=2;
            cout<<"Enter 0 to goto main or any number to exit ";cin>>exit;
        }

            while(exit!=0);
            return 0;
        }
