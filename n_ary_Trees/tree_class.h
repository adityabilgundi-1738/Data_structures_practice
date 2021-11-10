#include<vector>
using namespace std;

template<typename T>

class treenode{
    public:
    T data;
    vector<treenode<T>*> children;

    treenode(T data){//constructor
        this->data = data;
    }
    ~treenode(){//when delete class is called it generally calls its destructor
        for (int i = 0; i < children.size(); i++){
            delete children[i];
        }
    }
};

