#include "node.h"

node::node()
{
     for(int i=0;i<256;i++){
                ptrs[i]=NULL;
            }
            info=NULL;
            Word="";
}
void node::setfilename(string name){
    filename=name;
}
string node::getfilename()
{
    return filename;
}



