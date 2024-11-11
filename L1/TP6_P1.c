#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    char nom[20];
    char prenom[20];
    char sexe[10];
    int age;
    char maladie[100];
}  Patient;

/*struct Patient{
    int num;
    char nom[20];
    char prenom[20];
    char sexe;
    int age;
    char maladie[100];
};*/

void createPfile(){
    FILE* p_file = NULL;
    Patient p;
    int n = 0;
    p_file = fopen("Patients.txt", "w");
    do{
        printf("Donner le nombre de patients: ");
        scanf("%d", &n);
    }while(n <= 0);
    for(int i = 0; i < n; i++){
        p.num = i+1;
        printf("Donner le nom de patient: ");
        scanf("%s", &p.nom);
        printf("Donner le prenom de patient: ");
        scanf("%s", &p.prenom);
        printf("Donner le sexe de patient (Feminin ou Masculin): ");
        scanf("%s", &p.sexe);
        printf("Donner l'age de patient: ");
        scanf("%d", &p.age);
        printf("Donner la maladie de patient: ");
        scanf("%s", &p.maladie);
        fprintf(p_file, "%d %s %s %s %d %s\n", p.num, p.nom, p.prenom, p.sexe, p.age, p.maladie);
    }
    fclose(p_file);
}

void nbrFemme(){
    FILE* f = NULL;
    Patient p;
    int cpt = 0;
    f = fopen("Patients.txt", "r");
    if(f == NULL){
        printf("impossible de lire le fichier");
        exit;
    }
    char ch[100];
    do{
        fscanf(f, "%d %s %s %s %d %s\n", &p.num, &p.nom, &p.prenom, &p.sexe, &p.age, &p.maladie);
        if(strcasecmp(p.sexe, "Feminin") != 0){
            cpt++;
        }
    }while(fgets(ch, sizeof(ch), f) != NULL);
    fclose(f);
    printf("il y a %d femmes\n", cpt);
}

void chercheNom(){
    FILE* f = NULL;
    Patient p;
    char nom[20];
    char ch[100];
    f = fopen("Patients.txt", "r");
    if(f == NULL){
        printf("impossible de lire le fichier");
        exit;
    }
    printf("Entrer le nom de patient a chercher: ");
    scanf("%s", &nom);
    do{
        fscanf(f, "%d %s %s %s %d %s\n", &p.num, &p.nom, &p.prenom, &p.sexe, &p.age, &p.maladie);
        if(strcasecmp(p.nom, nom) != 0){
            printf("%d %s %s %s %d %s", p.num, p.nom, p.prenom, p.sexe, p.age, p.maladie);
        }
    }while(fgets(ch, sizeof(ch), f) != 0);
    fclose(f);
}

void chercheAge(){
    FILE* f = NULL;
    Patient p;
    char ch[100];
    int age;
    f = fopen("Patients.txt", "r");
    if(f == NULL){
        printf("impossible de lire le fichier");
        exit;
    }
    do{
        printf("Entrer l'age de(s) patient(s) a chercher: ");
        scanf("%d", &age);
    }while (age < 0);
    do{
        fscanf(f, "%d %s %s %s %d %s\n", &p.num, &p.nom, &p.prenom, &p.sexe, &p.age, &p.maladie);
        if(p.age >= age){
            printf("%d %s %s \n", p.num, p.nom, p.prenom);
        }
    }while(fgets(ch, sizeof(ch), f) != 0);
    fclose(f);
}

void chercherLettre(){
    FILE* f = NULL;
    Patient p;
    char ch[100];
    char c;
    f = fopen("Patients.txt", "r");
    if(f == NULL){
        printf("impossible de lire le fichier");
        exit;
    }
    do{
        printf("Entrer la lettre de(s) patient(s) a chercher: ");
        scanf("%s", &c);
    }while(c == '\0');
    do{
        fscanf(f, "%d %s %s %s %d %s\n", &p.num, &p.nom, &p.prenom, &p.sexe, &p.age, &p.maladie);
        if(p.nom[0] == c){
            printf("%d %s %s \n", p.num, p.nom, p.prenom);
        }
    }while(fgets(ch, sizeof(ch), f) != 0);

    fclose(f);
}

void addP(){
    FILE* f = NULL;
    char ch[100];
    Patient p;
    Patient np;
    int last;
    //Ouvrir en mode lecture et chercher le dernier numero de la liste
    f = fopen("Patients.txt", "r");
    if(f == NULL){
        printf("impossible de lire le fichier");
        exit;
    }
    while(fscanf(f, "%d %s %s %s %d %s\n", &p.num, p.nom, p.prenom, p.sexe, &p.age, p.maladie) != EOF) {
            last = p.num;
    }
    fclose(f);
    //Ouvrir en mode ajout et ajouter le nouveau patient
    f = fopen("Patients.txt", "a");
    if(f == NULL){
        printf("impossible de lire le fichier");
        exit;
    }
    np.num = last + 1;
    printf("Donner le nom de patient: ");
    scanf("%s", &np.nom);
    printf("Donner le prenom de patient: ");
    scanf("%s", np.prenom);
    printf("Donner le sexe de patient (Feminin ou Masculin): ");
    scanf("%s", np.sexe);
    printf("Donner l'age de patient: ");
    scanf("%d", &np.age);
    printf("Donner la maladie de patient: ");
    scanf("%s", &np.maladie);
    fprintf(f, "%d %s %s %s %d %s\n", np.num, np.nom, np.prenom, np.sexe, np.age, np.maladie);
   fclose(f);
}

void delP(){
    FILE* f = NULL;
    FILE* temp = NULL;
    Patient p;
    int num;
    char ch[100];
    f = fopen("Patients.txt", "r");
    temp = fopen("ftemp.txt", "w");
    if(f == NULL || temp == NULL){
        printf("impossible de lire le fichier");
        exit;
    }
    do{
        printf("Entrer le numero de patient a supprimer: ");
        scanf("%s", &num);
    }while(num <= 0);
    while(fscanf(f, "%d %s %s %s %d %s\n", &p.num, &p.nom, &p.prenom, &p.sexe, &p.age, &p.maladie) != EOF){
        if(p.num != num){
            fprintf(temp, "%d %s %s %s %d %s\n", p.num, p.nom, p.prenom, p.sexe, p.age, p.maladie);
        }
    }
    fclose(f);
    fclose(temp);
    remove("Patients.txt");
    rename("ftemp.txt", "Patients.txt");
    printf("Le patient a ete supprimer");
}

int main(){
    char c;
    system("cls");
    printf("=================Creation de fichier patient=================\n");
    createPfile();
    int option;
    do{
        do{
            system("cls");
            printf("================== Choisisez une option ==================\n");
            printf("========= 1- Compter le nombre de femme =======================\n");
            printf("========= 2- Chercher un patien par nom =======================\n");
            printf("========= 3- Chercher les patient avec un age minimum =========\n");
            printf("========= 4- Chercher les patient par lettre ==================\n");
            printf("========= 5- Ajouter un patient ===============================\n");
            printf("========= 6- Suprimer un patient ==============================\n");
            printf("========= 6- Exit =============================================\n");
            scanf("%d", &option);
            switch(option){
                case 1:
                    nbrFemme();
                    break;
                case 2:
                    chercheNom();
                    break;
                case 3:
                    chercheAge();
                    break;
                case 4:
                    chercherLettre();
                    break;
                case 5:
                    addP();
                    break;
                case 6:
                    delP();
                    break;
                case 7:
                    break;
                default :
                    printf("Cette option n'existe pas\n");
                }
        }while(option <= 0 || option > 7);
        printf("Refaire? (o/n: ");
        scanf("%s", &c);
    }while(c != 'n');
}
