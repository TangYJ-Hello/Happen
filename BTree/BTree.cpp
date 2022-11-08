
#include <iostream>

#define M 6
#define DEGREE (M/2)

typedef int KEY_VALUE;

struct BTree_Node {
    struct BTree_Node** childrens;
    int nums; //key的数量
    KEY_VALUE* keys; 
    int leaf; //bool也是可以的
}btree_node;

struct BTree {
    struct  BTree_Node* root;

}btree; //别名无法用于新建对象？

struct BTree_Node* Create_Btree_Node(struct BTree* T) {
   // malloc
    return 0;
}

void btree_split_child(struct BTree* T, //树根 
    struct BTree_Node* x,  //父节点
    int i)   //要分裂父节点的第几个子节点
{
    struct BTree_Node* y = x->childrens[i];

    //新建节点z作为分裂节点
    struct BTree_Node* z = Create_Btree_Node(T);

    //中间节点未赋值到父节点中



    //左半边的指针和key复制到z节点 
    for (int j = 0; j < DEGREE - 1; j++) {
        z->keys[j] = y->keys[j];
    }
    for (int j = 0; j < DEGREE; j++) {
        z->childrens[j] = y->childrens[j];
        z->nums = j + 1;
    }

    //y的左半边节点是否需要置空？？

}

void btree_insert_nonfull(struct BTree* T, 
    struct BTree_node* x, //比对key值的节点
    KEY_VALUE k) //需要插入的key值 
{
    
    //递归找到对应节点，比对节点key值

    //插入的数据都是插在叶子节点上

}

void btree_insert(struct BTree* T, KEY_VALUE key) {
    //key作用 ? ?

    //只有一个根节点的分裂情况
    struct BTree_Node* r = T->root;
    if (r->nums == M - 1) { //根节点是满的即分裂？是否需要判断根节点是否为叶子节点
        struct BTree_Node* node = Create_Btree_Node(T);

        node->childrens[0] = r;
        T->root = node;

        btree_split_child(T, node, 0);
    }
    else {
    
    
    }

}




int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

