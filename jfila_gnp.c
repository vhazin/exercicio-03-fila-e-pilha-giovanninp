#include <stdlib.h>
#include <stdio.h>

typedef struct User{
    int value;
    struct User *next;
}user;

user *root;

void show(){
    user *tmp;
    tmp = root;
    while (tmp != NULL){
        if(tmp->value != 0){
            printf("%d ",tmp -> value);
        }
        tmp = tmp -> next;
    }
}

void insert(int value){
    user *tmp;
    tmp = root;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    user *newUser = (user *)malloc(sizeof(user));
    newUser -> value = value;
    newUser -> next = NULL;
    tmp -> next = newUser;
}

void remov(int value){
    user *tmp,*prev;
    tmp,prev = root;

    while(tmp != NULL){
        if(value == tmp -> value){
            prev -> next = tmp -> next;
            tmp -> value = 0;
        }
        prev = tmp;
        tmp = tmp -> next;
    }
}   

int check(int value){
    user *tmp;
    tmp = root;
    while(tmp != NULL){
        if (tmp-> value == value){
            return value;
        }
        tmp = tmp -> next;
    }
    return 0;
}

int main(void){
    root = (user*)malloc(sizeof(user));
    root -> value = 0;
    root -> next = NULL;
    
    int n,m,actualN,actualM;

    scanf("%d",&n);

    for (int i = 0;i<n;i++){
        scanf("%d",&actualN);
        if (check(actualN) == 0){
            insert(actualN);
        }
    }

    scanf("%d",&m);

    for (int j = 0;j < m;j++){
        scanf("%d",&actualM);
        remov(actualM);
    }

    show();
    



    return 0;
}