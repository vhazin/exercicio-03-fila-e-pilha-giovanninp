#include <stdio.h>
#include <stdlib.h>

typedef struct User{
    int value;
    struct User *next;
}user;

void show(user *root){
    user *tmp;
    tmp = root;
    while (tmp != NULL){
        if(tmp -> value != 0){
            printf("%d ",tmp->value);
        }
        tmp = tmp -> next;
    }
}

int checkExistence(user *root,int cvalue){
    int result = 0;
    user *tmp;
    tmp = root;
    while(tmp != NULL){
        if (tmp -> value == cvalue){
            result = 1;
        }
        tmp = tmp -> next;
    }
    return result;
    
}

int main(void) {
    user *root = (user *)malloc(sizeof(user));
    root -> value = 0;
    root -> next = NULL;



    int actualValue,n,m;

    scanf("%d",&n);

    for(int i = 0;i < n;i++){
        scanf("%d",&actualValue);
        if(checkExistence(root,actualValue) != 1){
            user *actualUser = (user *)malloc(sizeof(user));
            actualUser -> value = actualValue;
            actualUser -> next = NULL;

            user *temp;
            temp = root;
            while(temp->next != NULL){
                temp = temp -> next;
            }
            temp -> next = actualUser;
        }
    }

    scanf("%d",&m);
    for(int j = 0;j < m;j++){
        scanf("%d",&actualValue);
        user *tmp,*prev;
        tmp = root;
        while(tmp != NULL){
            if(tmp->value = actualValue){
                prev -> next = tmp -> next;
                tmp->value = 0;
            }
            prev = tmp;
            tmp = tmp -> next;
        }
        
    }
    show(root);

    return 0;
}