#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct cellule{
    char val;
    struct cellule* suiv;
} cellule;

typedef struct {
    cellule* tete;
    cellule* queue;
} file;

file creerFile(){
    file F;
    F.tete = NULL;
    F.queue = NULL;
    return F;
}

bool fileVide(file F){
    if(F.tete == NULL){
        return true;
    } else {
        return false;
    }
}

void enfiller(file F, char val){
    cellule *courant;
    courant = (cellule*)malloc(sizeof(cellule));
    courant->val = val;
    courant->suiv = NULL;
    if(!fileVide(F)){
        F.queue->suiv = courant;
    } else {
        F.tete = courant;
    }
    F.queue = courant;
}

int defiller(file F){
    cellule *tmp;
    char val;
    if(!fileVide(F)){
        tmp = F.tete;
        val = F.tete->val;
        F.tete = F.tete->suiv;
        free (tmp);
    } else {
        printf("La file est vide, impossible de supprimer des valeurs");
    }
    return val;
}   

void eclaterFile(file f, file fl, file fc){
    cellule *courant = f.tete, *courant1 = fl.tete, *courant2 = fc.tete;
    if(fileVide(f)){
        printf("La file est vide\n");
    } else {
        do{
            if(isalpha(courant->val)){
                if(courant1 == NULL){
                    courant1 = (cellule*)malloc(sizeof(cellule));
                    courant1->suiv = NULL;
                    fl.tete = courant1;
                    fl.queue = courant1;
                } else {
                    courant1->suiv = (cellule*)malloc(sizeof(cellule));
                    courant1 = courant1->suiv;
                    courant1->suiv = NULL;
                    fl.queue = courant1;
                }
                courant1->val = courant->val;
                courant = courant->suiv;
            } else if(isdigit(courant->val)){
                if(courant2 == NULL){
                    courant2 = (cellule*)malloc(sizeof(cellule));
                    courant2->suiv = NULL;
                    fc.tete = courant2;
                    fc.queue = courant2;
                } else {
                    courant2->suiv = (cellule*)malloc(sizeof(cellule));
                    courant2 = courant2->suiv;
                    courant2->suiv = NULL;
                    fc.queue = courant2;
                }
                courant2->val = courant->val;
                courant = courant->suiv;
            }
        }while(courant != f.queue);
    }
}

void afficherFile(file* f) {
    if (f == NULL || f->tete == NULL) {
        printf("La file est vide.\n");
        return;
    }

    cellule* temp = f->tete;
    while (temp != NULL) {
        printf("%c ", temp->val);
        temp = temp->suiv;
    }
    printf("\n");
}

int main() {
    file f = creerFile();
    file fl = creerFile();
    file fc = creerFile();
    char c[5] = "HEL5O";
    //for(int i = 0; i < 5; i++){
        enfiller(f, 'c');
    //}

    //eclaterFile(f, fl, fc);
    afficherFile(&f);
    //afficherFile(&fl);
    //afficherFile(&fc);

    
    return 0;
}