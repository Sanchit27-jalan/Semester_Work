#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 1000

typedef struct TrieNode {
    struct TrieNode* children[26];
    int is_end_of_word;
    char target_words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    int num_target_words;
} TrieNode;

TrieNode* createNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    newNode->is_end_of_word = 0;
    newNode->num_target_words = 0;
    for (int i = 0; i < 26; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

int isTargetWordPresent(TrieNode* node, char* target_word) {
    for (int i = 0; i < node->num_target_words; i++) {
        if (strcmp(node->target_words[i], target_word) == 0) {
            return 1;
        }
    }
    return 0;
}

void insert(TrieNode* root, char* word, char* target_word) {
    TrieNode* current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
        if (!isTargetWordPresent(current, target_word)) {
            strcpy(current->target_words[current->num_target_words], target_word);
            current->num_target_words++;
        }
    }
    current->is_end_of_word = 1;
}
int insertion(char *one, char *two, int one_l, int two_l)
{
    // printf("%d %d\n",one_l,two_l);
    int min = one_l;
    if (min > two_l)
    {
        min = two_l;
    }
    int i;
    for (i = 0; i < min; ++i)
    {
        if(one[i]==two[i]){
            continue;
        }
        else if(one[i]>two[i]){
            return 0;
        }
        else{
            return 1;
        }
    }
    return 1;
}
void merge(char **strarray, int l, int mid, int r, int n, int maxlength)
{
    int t = r - l + 1;
    char **strnew = (char **)malloc(t * sizeof(char *));
    for (int i = 0; i < t; ++i)
    {
        strnew[i] = (char *)malloc(sizeof(char) * maxlength);
    }
    int j = 0;
    int leftsize = mid - l + 1;
    int rightsize = r - mid;
    int leftfilled = 0;
    int leftindex = l;
    int rightfilled = 0;
    int rightindex = mid + 1;
    while (j < t)
    {
        if (leftfilled == leftsize)
        {
            int i;
            for (i = 0; i < strlen(strarray[rightindex]); ++i)
            {
                strnew[j][i] = strarray[rightindex][i];
            }
            strnew[j][i] = '\0';
            j++;
            rightfilled++;
            rightindex++;
        }
        else if (rightfilled == rightsize)
        {
            int i;
            for (i = 0; i <strlen(strarray[leftindex]); ++i)
            {
                strnew[j][i] = strarray[leftindex][i];
            }
            strnew[j][i] = '\0';
            j++;
            leftfilled++;
            leftindex++;
        }
        else
        {
            int value = insertion(strarray[leftindex], strarray[rightindex], strlen(strarray[leftindex]), strlen(strarray[rightindex]));
            if (value==1)
            {

                int i;
                for (i = 0; i < strlen(strarray[leftindex]); ++i)
                {
                    strnew[j][i] = strarray[leftindex][i];
                }
                strnew[j][i] = '\0';
                j++;
                leftfilled++;
                leftindex++;
            }
            else
            {
                int i;
                for (i = 0; i < strlen(strarray[rightindex]); ++i)
                {
                    strnew[j][i] = strarray[rightindex][i];
                }
                strnew[j][i] = '\0';
                j++;
                rightfilled++;
                rightindex++;
            }
        }
    }

    for (int i = 0; i < t; ++i)
    {
        int j;
        for (j = 0; j < strlen(strnew[i]); ++j)
        {
            strarray[l + i][j] = strnew[i][j];
        }
        strarray[l + i][j] = '\0';
    }
    for (int i = 0; i < t; ++i)
    {
        free(strnew[i]);
    }
    free(strnew);
    return;
}
void mergesortd(char **strarray, int l, int r,int n, int maxlength)
{
    if (l >= r)
    {
        return;
    }
    else
    {
        int mid = (l + r) / 2;
        mergesortd(strarray, l, mid,n, maxlength);
        mergesortd(strarray, mid + 1, r,n, maxlength);
        merge(strarray, l, mid, r, n, maxlength);
    }
}
void search(TrieNode* root, char* prefix) {
    TrieNode* current = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (current->children[index] == NULL) {
            printf("0\n");
            return;
        }
        current = current->children[index];
    }
    char **ans=malloc(sizeof(char*)*current->num_target_words);
    for(int i=0;i<current->num_target_words;i++){
        ans[i]=malloc(sizeof(char)*MAX_WORD_LENGTH);
    }
    printf("%d ", current->num_target_words);
    
    for (int i = 0; i < current->num_target_words; i++) {
        // printf("%s ", current->target_words[i]);
        strcpy(ans[i],current->target_words[i]);
    }
    mergesortd(ans,0,current->num_target_words-1,current->num_target_words,MAX_WORD_LENGTH);
    for (int i = 0; i < current->num_target_words; i++) {
       printf("%s ",ans[i]);
    }
    printf("\n");
}

int main() {
    int sessions;
    scanf("%d", &sessions);

    TrieNode* trie = createNode();

    // Read sessions
    for (int i = 0; i < sessions; i++) {
        int num_guesses;
        scanf("%d", &num_guesses);

        char target_word[MAX_WORD_LENGTH];
        scanf("%s", target_word);

        insert(trie, target_word, target_word);

        for (int j = 0; j < num_guesses; j++) {
            char guess_word[MAX_WORD_LENGTH];
            scanf("%s", guess_word);
            insert(trie, guess_word, target_word);
        }
    }

    int num_queries;
    scanf("%d", &num_queries);

    // Process queries
    for (int i = 0; i < num_queries; i++) {
        char query[MAX_WORD_LENGTH];
        scanf("%s", query);
        search(trie, query);
    }

    return 0;
}