#include <stdio.h>
#include <stdlib.h>

/*
    Professor/Professore: Victor Hazin

    Feito por/Fatto da: Giovanni Netto Procida
    Instituição/Instituizione: CESAR School

*/

typedef struct Scatola{
    int id;
    int gruppo;
    struct Scatola *pross;
    int livello;
}scatola;

void presentaScatole(scatola *radice){
    scatola *tmp = radice;
    printf("id:\tgruppo:\tlivello:\n");
    while (tmp != NULL){
        if(tmp -> gruppo != 0){
            printf("%d\t%d\t%d\n",tmp -> id,tmp -> gruppo,tmp -> livello);
        }
        tmp = tmp -> pross;
    }
}

void inserisceScatola(scatola *radice,int id,int gruppo,int livello){
    scatola *tmp = radice;
    while(tmp -> pross != NULL){
        tmp = tmp -> pross;
    }
    scatola *scatolaAttuale = (scatola *)malloc(sizeof(scatola));
    scatolaAttuale -> id = id;
    scatolaAttuale -> gruppo = gruppo;
    scatolaAttuale -> pross = NULL;
    scatolaAttuale -> livello = livello;
    tmp -> pross = scatolaAttuale;
}


void prendereScatola(scatola *radice, int id){
    scatola *tmp = radice;
    int lato = 0;
    int sopra = 0;
    int livello;
    int gruppo;
    while (tmp != NULL){
        if((tmp -> id) == id){
            livello = tmp -> livello;
            gruppo = tmp -> gruppo;
            scatola *pross = tmp -> pross;
            if(pross -> gruppo == tmp -> gruppo){
                sopra = 1;
            }
        }
        else if(tmp -> gruppo == (gruppo + 1)){
            if(tmp -> livello == livello){
                lato = 1;
            }
        }
        tmp = tmp -> pross;
    }
    int result = lato + sopra;
    printf("\n%d",result);
}


int main(void){

    // scatola *radice = (scatola *)malloc(sizeof(scatola));
    // radice -> id = 0;
    // radice -> gruppo = 0;
    // radice -> pross = NULL;
    // radice -> livello = livello;

    // scatola *ultima;
    // livello = 1;

    //numero de caixas e de pilhas:
    int n,p = 1;
    int lett[2];

    while((p != 0)&&(n != 0)){
        int livello = 0;
        scatola *radice = (scatola *)malloc(sizeof(scatola));
        radice -> id = 0;
        radice -> gruppo = 0;
        radice -> pross = NULL;
        radice -> livello = livello;
        livello = 1;

        for (int i= 0;i < 2;i++){
            scanf("%d",&lett[i]);    
        }

        n = lett[0];
        p = lett[1];
        int quantitaAtuale;
        for(int j = 1;j<p+1;j++){
            int idAttuale;
            livello = 1;
            scanf("%d",&quantitaAtuale);
            for(int x = 0;x < quantitaAtuale;x++){
                scanf("%d",&idAttuale);
                inserisceScatola(radice,idAttuale,j,livello);
                livello++;
            }
        }
        prendereScatola(radice,1);
    }
    return 0;
}