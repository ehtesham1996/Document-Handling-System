#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;


class node
{
    public:



        node();
        char info;
        string Word;
        string filename;
        class node* ptrs[256];

        void setfilename(string name);
        string getfilename();

};

#endif // NODE_H
