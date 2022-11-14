
#include <iostream>

#define M 6
#define DEGREE (M/2)

typedef int KEY_VALUE;

struct BTree_Node {
    struct BTree_Node** childrens;
    int nums; //key的数量
    KEY_VALUE* keys; 
    int leaf; //bool也是可以的
};

struct BTree {
    struct  BTree_Node* root;
    int t; //DEGREE
};

struct BTree_Node* Create_Btree_Node(struct BTree* T) {
   // malloc
    return 0;
}

void btree_split_child(struct BTree* T, //树根 
    struct BTree_Node* x,  //父节点
    int i)   //要分裂父节点的第几个子节点
{
    int t = T->t; //DEGREE
    BTree_Node* y = x->childrens[i];
    BTree_Node* z = Create_Btree_Node(T); //新建节点z作为分裂节点
    z->nums = t - 1;
    //y的右半边的指针和key复制到z节点，z位于y的右侧 
    int j = 0;
    for (j = 0; j < t - 1; j++) {
        z->keys[j] = y->keys[j + t];
    }
    if (y->leaf == 0) {
        for (j = 0; j < t; j++) {
            z->childrens[j] = y->childrens[j + t];
        }
    }
    //父节点x位置i后节点值往后移动一位
    y->nums = t - 1;
    for (j = x->nums; j >= i + 1; j--) {
        x->childrens[j + 1] = x->childrens[j];
    }

    x->childrens[i + 1] = z; //把z放在y之后

    for (j = x->nums - 1; j >= i; j--) {
        x->keys[j + 1] = x->keys[j];
    }
    x->keys[i] = y->keys[t - 1];
    x->nums += 1;
    
}

void btree_insert_nonfull(struct BTree* T, 
    struct BTree_Node* x, //比对key值的节点
    KEY_VALUE k) //需要插入的key值 
{
    int i = x->nums-1;  //课程代码为int i = x->nums;
    
    if (x->leaf == 1) {
        //插入的数据都是插在叶子节点上
    }
    else {
        //递归找到对应节点，比对节点key值
        while (i >= 0 && x->keys[i] > k)i--;

        if (x->childrens[i + 1]->nums == M - 1) {
            btree_split_child(T, x, i + 1);
        }
        btree_insert_nonfull(T, x->childrens[i + 1], k);
    }

}

void btree_insert(struct BTree* T, 
    struct BTree_Node* x, //插入的节点
    KEY_VALUE key)  //需要插入的值
{
    //只有一个根节点的分裂情况
    struct BTree_Node* r = T->root;
    if (r->nums == M - 1) { //根节点是满的即分裂
        struct BTree_Node* node = Create_Btree_Node(T);
        node->childrens[0] = r;
        T->root = node;
        btree_split_child(T, node, 0);
    }
    else {
        int i = x->nums - 1;
        while (x->keys[i] > key)            i--;
    
    }

}

void btree_delete_key(struct BTree* T,
    struct BTree_Node* x, //比对key值的节点
    KEY_VALUE k) //需要删除的key值 
{



}


int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

