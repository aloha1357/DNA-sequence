#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;

struct node
{
    char data[300];
    node *left, *right;
};

char strA[301] = {'\0'};
char strB[301] = {'\0'};
char tempStr[300] = {'\0'};
int table[301][301] = {0};
int tempIndex;
node *root;

node *newNode(char *temp)
{
    node *reg = (node *)malloc(sizeof(node));
    reg->left = NULL;
    reg->right = NULL;
    memset(reg->data, '\0', sizeof(reg->data));
    memcpy(reg->data, temp, sizeof(reg->data));
    return reg;
}

int _strcmp(char *A, char *B, int lA, int lB)
{
    if (lA == -1 && lB == -1)
        return -1;
    if (*(A + lA - 1) == *(B + lB - 1))
        return _strcmp(A, B, lA - 1, lB - 1);
    if (*(A + lA - 1) > *(B + lB - 1))
        return 1;
    return 0;
}

void insert(node *temp, node *newData)
{
    if (!root)
    {
        root = newData;
        return;
    }
    else
    {
        int A = strlen(temp->data);
        int B = strlen(newData->data);
        int C = _strcmp(temp->data, newData->data, A, B);
        if (C == -1)
        {
            free(newData);
            return;
        }
        if (C)
        {
            if (temp->left)
                insert(temp->left, newData);
            else
                temp->left = newData;
        }
        else
        {
            if (temp->right)
                insert(temp->right, newData);
            else
                temp->right = newData;
        }
    }
}

void pop(char temp[])
{
    temp[tempIndex - 1] = '\0';
    tempIndex--;
}

void push(char temp[], char d)
{
    temp[tempIndex] = d;
    tempIndex++;
}

void LCS(int A, int B)
{
    for (int i = 1; i <= A; i++)
    {
        for (int h = 1; h <= B; h++)
        {
            if (strA[i - 1] == strB[h - 1])
                table[i][h] = table[i - 1][h - 1] + 1;
            else
                table[i][h] = (table[i - 1][h] > table[i][h - 1] ? table[i - 1][h] : table[i][h - 1]);
        }
    }
}

void traceBack(int lenA, int lenB)
{
    if (!table[lenA][lenB])
    {
        if(!strlen(tempStr))
        {
            printf("No common sequence.\n");
            return ;
        }
        node *temp = root;
        insert(temp, newNode(tempStr));
        return;
    }
    if (strA[lenA - 1] == strB[lenB - 1])
    {
        push(tempStr, strA[lenA - 1]);
        traceBack(lenA - 1, lenB - 1);
        pop(tempStr);
    }
    else
    {
        if (table[lenA - 1][lenB] == table[lenA][lenB])
            traceBack(lenA - 1, lenB);
        if (table[lenA][lenB - 1] == table[lenA][lenB])
            traceBack(lenA, lenB - 1);
    }
}

void print(node *root)
{
    if (root)
    {
        print(root->left);
        for (int i = 299; i >= 0; i--)
            if (root->data[i])
                printf("%c", root->data[i]);
        printf("\n");
        print(root->right);
    }
}

void freeTree(node *root)
{
    if (root)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    while (scanf("%s%s", strA, strB) != EOF)
    {
        int A = strlen(strA);
        int B = strlen(strB);
        root = NULL;
        tempIndex = 0;
        LCS(A, B);
        traceBack(A, B);
        print(root);
        printf("\n");
        freeTree(root);
    }
    return 0;
}