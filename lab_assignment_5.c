/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

int length(node* head) {
    int count = 0;
    node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

char* toCString(node* head) {
    int len = length(head);
    char* str = (char*)malloc((len + 1) * sizeof(char));
    int i = 0;
    node* current = head;
    while (current != NULL) {
        str[i] = current->letter;
        i++;
        current = current->next;
    }
    str[i] = '\0';
    return str;
}

void insertChar(node** pHead, char c) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->letter = c;
    newNode->next = NULL;
    if (*pHead == NULL) {
        *pHead = newNode;
    } else {
        node* current = *pHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteList(node** pHead) {
    node* current = *pHead;
    while (current != NULL) {
        node* next = current->next;
        free(current);
        current = next;
    }
    *pHead = NULL;
}

int main(void) {
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt", "r");
    
    fscanf(inFile, " %d\n", &numInputs);
    
    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &strLen);
        
        for (i = 0; i < strLen; i++) {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }
        
        str = toCString(head);
        printf("String is: %s\n", str);
        free(str);
        
        deleteList(&head);
        
        if (head != NULL) {
            printf("deleteList is not correct!\n");
            break;
        }
    }
    
    fclose(inFile);
    
    return 0;
}
