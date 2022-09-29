#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

struct binaryTree *createBinaryTree(void) {
    struct binaryTree *t = (struct binaryTree*)malloc(sizeof(struct binaryTree));
    t->levels = -1;
    t->root = NULL;

    return t;
}

struct tNode *createNode(struct binaryTree *t, int value) {
    struct tNode *node = (struct tNode*)malloc(sizeof(struct tNode));

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert(struct binaryTree *t, int value) {
    struct tNode *node = t->root;
    struct tNode *newNode = createNode(t, value);

    if(t->root == NULL) {
        t->root = newNode;
        return;
    }

    while(true) {
        if(node->value < value) {
            if(!node->right) {
                node->right = newNode;
                break;
            }
            node = node->right;

        } else if (node->value == value) { // Equals
            free(newNode);
            node = NULL;

        } else {
            if(!node->left) {
                node->left = newNode;
                break;
            }
            node = node->left;
        }
    }
}


void lookup(struct binaryTree *t, int value) {
    if(!t->root)
        return;

    struct tNode *node = t->root;

    printf("(root) ");

    while(node != NULL) {
        printf("%d", node->value);

        if(node->value < value) {
            node = node->right;
            printf(" -> ");

        } else if (node->value == value) {
            printf("\n");
            node = NULL;
            return;

        } else {
            printf(" <- ");
            node = node->left;

        }
    }
    printf("NOT FOUND\n");
}
