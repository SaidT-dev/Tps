#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct cellule{
    size_t id;
    char *nom;
    char *prenom;
    int salaire_sous;
    int salaire_conj;
    struct cellule* suiv;
} liste;

liste* creerListeSouscripteurs(){
    liste *Souscripteur = NULL;
    liste *courant = Souscripteur;
    liste *nouv;
    int nbr;
    printf("Entrer le nombre de souscripteurs: ");
    scanf("%d", &nbr);
    for(size_t i = 0; i < nbr; i++){
        nouv = (liste*)malloc(sizeof(liste));
        nouv->nom = malloc(20 * sizeof(char)); 
        nouv->prenom = malloc(20 * sizeof(char)); 
        printf("Entrer les information de souscripteur n %d:\n", i+1);
        printf("Nom: ");
        scanf("%s", nouv->nom);
        printf("Preom: ");
        scanf("%s", nouv->prenom);
        printf("Salaire de souscripteur: ");
        scanf("%d", &nouv->salaire_sous);
        printf("Salaire de son conjoint (Entrer -1 pour les conjoints sans salaire ou souscripteur sans conjoint): ");
        scanf("%d", &nouv->salaire_conj);
        nouv->id = i+1;
        nouv->suiv = NULL;
        if(Souscripteur == NULL){
            Souscripteur = nouv;
        } else {
            courant->suiv = nouv;
        }
        courant = nouv;
    }
    //free(nouv);
    return Souscripteur;
}

bool Benificie(liste *Souscripteur, size_t id){
    liste *courant = Souscripteur;
    bool elegible;
    if(Souscripteur == NULL){
        printf("La liste des souscripteur est vide");
        exit(-1);
    }
    while (courant != NULL){
        if(courant->id == id){
            if(courant->salaire_conj >= 0 && courant->salaire_conj+courant->salaire_sous >= 60000){
                elegible  = true;
            } else if(courant->salaire_conj == -1 && courant->salaire_sous >= 60000){
                elegible =  true;
            } else {
                elegible =  false;
            }
        }
        courant = courant->suiv;
    }
    return elegible;
}

//procedure qui separe les benificiere et les non benificiere
void filtreBeni(liste *Souscripteur){
    FILE *b = NULL;
    FILE *nb = NULL;
    liste *courant = Souscripteur;

    b = fopen("Beneficiaire.txt", "w");
    nb = fopen("NonBeneficiaire.txt", "w");

    if(Souscripteur == NULL){
        printf("La liste des souscripteur est vide");
        exit(-1);
    }
    while (courant != NULL){
        if(Benificie(Souscripteur, courant->id)){
            fprintf(b, "%d | nom: %s | prenom: %s | salaire de conjoint: %d | salaire de souscripteur: %d \n", courant->id, courant->nom, courant->prenom, courant->salaire_conj, courant->salaire_sous);
        } else {
            fprintf(nb, "%d | nom: %s | prenom: %s | salaire de conjoint: %d | salaire de souscripteur: %d \n", courant->id, courant->nom, courant->prenom, courant->salaire_conj, courant->salaire_sous);
        }
        courant = courant->suiv;
    }
}

void afficherListe(liste *souscripteur){
    liste *courant = souscripteur;
    while(courant != NULL){
        printf("%d | nom: %s | prenom: %s | salaire de conjoint: %d | salaire de souscripteur: %d \n", courant->id, courant->nom, courant->prenom, courant->salaire_conj, courant->salaire_sous);
        courant = courant->suiv;
    }
    printf("\n");
}

int main(){
    liste *souscripteur = creerListeSouscripteurs();
    afficherListe(souscripteur);
    filtreBeni(souscripteur);
    return 0;
}