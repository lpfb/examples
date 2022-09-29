
struct tNode {
    int value;
    struct tNode *left;
    struct tNode *right;
};

struct binaryTree {
    struct tNode *root;
    int levels;
};

struct binaryTree *createBinaryTree(void);
struct tNode *createNode(struct binaryTree *t, int value);
void insert(struct binaryTree *t, int value);
void lookup(struct binaryTree *t, int value);
