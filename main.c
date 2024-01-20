#include <stdio.h>

typedef struct {
    int idtache;
    char description[500];
    char date_fin[500];
} Tache;

void afficherTaches(Tache tache) {
    printf("=======\n");
    printf("ID : %d\n", tache.idtache);
    printf("Description : %s\n", tache.description);
    printf("Date de fin : %s\n", tache.date_fin);
    printf("=======\n");
}

void supprimerTache(Tache liste[], int *nbTaches, int idASupprimer) {
    int index = -1;
    for (int i = 0; i < *nbTaches; i++) {
        if (liste[i].idtache == idASupprimer) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        liste[index] = liste[*nbTaches - 1];
        (*nbTaches)--;
        printf("Tâche supprimée avec succès !\n");
    } else {
        printf("Aucune tâche avec l'ID %d n'a été trouvée.\n", idASupprimer);
    }
}

int main() {
    int capacite = 100;  // Capacité initiale du tableau
    Tache *liste = (Tache *)malloc(capacite * sizeof(Tache));  // Allocation dynamique
    if (liste == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    int nbTaches = 1;
    int choix;

    while (1) { 
        printf("---- Gestionnaire de taches ----\n");
        printf("Choisir une action : \n");
        printf("1. Ajouter une tâche\n");
        printf("2. Supprimer une tâche\n");
        printf("3. Afficher les tâches\n");
        printf("4. Quitter\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                liste[nbTaches].idtache = nbTaches;
                printf("Entrez la description de la tâche : \n");
                scanf(" %[^\n]s", liste[nbTaches].description);
                printf("Entrez la date de fin de la tâche : \n");
                scanf(" %[^\n]s", liste[nbTaches].date_fin);
                nbTaches++;
                break;
            case 2:
                /* code */
                int idASupprimer;
                printf("Entrez l'ID de la tâche à supprimer : ");
                scanf("%d", &idASupprimer);
                supprimerTache(liste, &nbTaches, idASupprimer);
                break;
            case 3:
                for (int i = 1; i < nbTaches; i++)
                    afficherTaches(liste[i]);
                break;
            case 4:
                printf("Au revoir !\n");
                return 0;  
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 4.\n");
        }
        
    }
    free(liste);
    return 0;
}
