#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET_SIZE 26
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
};
struct nodesession
{
    char *targetword;
    struct TrieNode *trie;
};

struct TrieNode *createNode()
{
    struct TrieNode *newNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    newNode->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}
int compare(const void *a, const void *b)
{
    const char *rowA = *(const char **)a;
    const char *rowB = *(const char **)b;
    return strcmp(rowA, rowB);
}
void insert(struct TrieNode *root, char *word)
{
    struct TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';
        if (current->children[index] == NULL)
        {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = 1;
}

int search(struct TrieNode *root, const char *word)
{
    struct TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';
        if (current->children[index] == NULL)
        {
            return 0;
        }
        current = current->children[index];
        if (current->isEndOfWord || word[i + 1] == '\0')
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    struct nodesession **arr = malloc(sizeof(struct nodesession *) * n);
    for (int i = 0; i < n; i++)
    {
        int numberofguesses;
        scanf("%d", &numberofguesses);
        char *targetword = malloc(sizeof(char) * 1000);
        scanf("%s", targetword);
        arr[i] = (struct nodesession *)malloc(sizeof(struct nodesession));
        arr[i]->targetword = malloc(sizeof(char) * (strlen(targetword) + 1));
        strcpy(arr[i]->targetword, targetword);
        arr[i]->trie = createNode();
        char *guessword = malloc(sizeof(char) * 1000);
        for (int j = 0; j < numberofguesses; j++)
        {
            scanf("%s", guessword);
            insert(arr[i]->trie, guessword);
        }
        free(targetword);
        free(guessword);
    }
    int queries;
    scanf("%d", &queries);
    int filled;
    for (int i = 0; i < queries; i++)
    {
        char **ans = malloc(sizeof(char *) * n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = (char *)malloc(sizeof(char) * 1000);
        }
        filled = 0;
        char *word = malloc(sizeof(char) * 1000);
        scanf("%s", word);
        int maxlength = 0;
        for (int j = 0; j < n; j++)
        {
            int answer = search(arr[j]->trie, word);
            // printf("ans for %d is \n %d",j)
            if (answer == 1)
            {
                if (strlen(arr[j]->targetword) > maxlength)
                {
                    maxlength = strlen(arr[j]->targetword);
                }
                strcpy(ans[filled], arr[j]->targetword);
                filled++;
            }
        }
        free(word);
        // printf("%d ", filled);
        // for(int k=0;k<filled;k++){
        //     printf("%s ",ans[k]);
        // }
        // printf("\n");
        if(filled==0){
            printf("%d\n",0);
            for (int k= 0; k < n; k++)
            {
                free(ans[k]);
            }
            free(ans);
        }
        else{
            int answer=filled;
            qsort(ans,filled,sizeof(ans[0]),compare);
            for(int k=1;k<filled;k++){
                if(strcmp(ans[k-1],ans[k])==0){
                    filled--;
                }
            }
            printf("%d ",filled);
            int k=0;
            while(k<answer){
                if(strcmp(ans[k],ans[k+1])==0){
                    printf("%s ",ans[k]);
                    k=k+2;
                }
                else{
                    printf("%s ",ans[k]);
                    k=k+1;
                }
            }
            printf("\n");
            for (int k= 0; k < n; k++)
            {
                free(ans[k]);
            }
            free(ans);
        }
        // if (filled != 0)
        // {
        //     char *rows[filled];
        //     for (int k = 0; k < filled; k++)
        //     {
        //         rows[i] = ans[i];
        //     }
        //     // mergesortd(ans, 0, filled - 1, filled, maxlength);
        //     qsort(rows, filled, sizeof(char *), compareRows);
        //     int a = 0;
        //     for (int k = 0; k < filled - 1; i++)
        //     {
        //         // printf("%s ", rows[i]);
        //         if (strcmp(rows[k], rows[k + 1]) == 0)
        //         {
        //             continue;
        //         }
        //         else
        //         {
        //             a++;
        //         }
        //     }
        //     a++;
        //     // if(strcmp(rows[filled-2],rows[filled-1]!=0)){
        //     //     a++;
        //     // }
        //     printf("%d ", a);
        //     for (int k = 0; k < filled - 1; k++)
        //     {
        //         // printf("%s ", rows[i]);
        //         if (strcmp(rows[k], rows[k + 1]) == 0)
        //         {
        //             continue;
        //         }
        //         else
        //         {
        //             printf("%s ", rows[k]);
        //         }
        //     }
        //     printf("%s\n", rows[filled - 1]);
        //     for (int k = 0; k < n; k++)
        //     {
        //         free(ans[k]);
        //     }
        //     free(ans);
        // }
        // else
        // {
        //     printf("%d\n", 0);
        //     for (int k= 0; k < n; k++)
        //     {
        //         free(ans[k]);
        //     }
        //     free(ans);
        // }
    }
}
