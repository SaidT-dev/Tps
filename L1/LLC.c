#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct cellule{ 
    int val;
    struct cellule* suiv;
} liste;

/*Créer une liste chaînée d’entiers*/
liste* createListe(){
    liste *tete = NULL, *courant, *Q;
    int n, val;

    printf("Entrer le nombre de valeur: ");
    scanf("%d", &n);
    for(size_t i = 0; i < n; i++){
        Q = (liste*)malloc(sizeof(liste));
        printf("Entrer la valeur %d: ", i+1);
        scanf("%d", &val);
        Q->val = val;
        Q->suiv = NULL;
        if(tete == NULL){
            tete = Q;
        } else {
            courant->suiv = Q;
        }
        courant = Q;
    }
    return tete;
}

/*Afficher la liste*/
void printListe(liste *tete){
    liste *courant = tete;
    while(courant != NULL){
        printf("%d ", courant->val);
        courant = courant->suiv;
    }
    printf("\n");
}

/*Calculer la somme de ses éléments*/
int sumListe(liste *tete){
    liste *courant = tete;
    int sum = 0;
    while(courant != NULL){
        sum += courant->val;
        courant = courant->suiv;
    }
    return sum;
}

/*Donner l’occurrence de la valeur V dans la list*/
int occV(liste *tete, int val){
    liste *courant = tete;
    int occ = 0;
    while(courant != NULL){
        if(courant->val == val){
            occ++;
        }
        courant = courant->suiv;
    }
    return occ;
}

/*Retourner le maximum de la liste*/
int maxListe(liste *tete){
    liste *courant = tete;
    int max = tete->val;
    while(courant != NULL){
        if(courant->val >= max){
            max = courant->val;
        }
        courant = courant->suiv;
    }
    return max;
}

/*Vérifier si une liste est triée en ordre croissant*/
bool triListe(liste *tete){
    liste *courant = tete;
    bool tri = true;
    while(courant != NULL){
        if(courant->val > courant->suiv->val){
            tri = false;
            courant = courant->suiv;
        }
    }
    return tri;
}

/*Libérer la liste*/

int main(){
    liste *L = createListe();
    printListe(L);
    printf("La somme des valeur de la liste est: %d\n", sumListe(L));
    printf("Le nombre d'occurence de 5 dans la liste est: %d\n", occV(L, 5));
    printf("Le max de la liste est: %d\n", maxListe(L));
    
    return 0;
}