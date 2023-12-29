#include<stdio.h>

typedef struct {
    int id;
    char modele[20];
    int capacite;
    float prix;
} Bus;

typedef struct {
    int id;
    char nom[20];
    char prenom[20];
    char email[50];
} Voyageur;

typedef struct {
    int id;
    int id_bus;
    int id_voyageur;
    char date[10];
} Reservation;

Bus bus[100];
int nb_bus = 0;
void ajouter_bus(Bus b) {
    if (nb_bus < 100) {
        bus[nb_bus] = b;
    }
    else {
        printf("Le tableau de bus est plein !\n");
    }
}

int bus_disponible(int a){
    for(int i=0; i<100; i++){
        if (bus[i].id == a)
            return 1;
    }
    return 0;
}

void creer_compte_bus() {
    Bus b;
    printf("Entrez un identifiant : \n");
    scanf("%d", &b.id);
    printf("Entrez le modele: \n");
    scanf ("%s" , b.modele);
    printf("Entrez la capacite : \n");
    scanf("%d", &b.capacite);
    printf("Entrez le prix : \n");
    scanf("%f", &b.prix);
    ajouter_bus(b);
    printf("Votre compte a ete cree avec succes !\n");
}

Voyageur voy[1000];
int nb_voyageurs = 0;
void ajouter_voyageur(Voyageur v) {
    if (nb_voyageurs < 1000) {
        voy[nb_voyageurs] = v;
        nb_voyageurs++;
    }
    else {
        printf("Le tableau de voyageurs est plein !\n");
    }
}

int recherche_v(int b){
    for(int i=0; i<1000; i++){
        if (voy[i].id == b)
            return 1;
    }
    return 0;
}

void creer_compte_voyageur() {
    Voyageur v;
    printf("Entrez votre nom : \n");
    gets (v.nom);
    printf("Entrez votre prenom : \n");
    gets (v.prenom);
    printf("Entrez votre email : \n ");
    gets (v.email);
    printf("Entrez un identifiant  : \n");
    scanf("%d", &v.id);
    ajouter_voyageur(v);
    printf("Votre compte a ete cree avec succes !\n");
    printf("Votre identifiant est : %d\n", v.id);
}

Reservation res[1000];
int nb_res = 0;
void ajouter_reservation(Reservation r) {
    if (nb_res < 1000) {
        res[nb_res] = r;
        nb_res++;
    }
    else {
        printf("Le tableau de reservation est plein !\n");
    }
}

void creer_reservation() {
    Reservation r;
    int c,id;
    printf("Entrez le numero du bus que vous voulez reserver : ");
    scanf("%d", &c);
    if (bus_disponible(c)==1) {
            r.id_bus = c;
            printf("Entrez votre identifiant de voyageur : ");
            scanf("%d", &id);
            if (recherche_v(id)==1) {
                    printf("Entrez la date du voyage (JJ/MM/AAAA) : ");
                    scanf("%s", r.date);
                    printf("Entrez un identifiant pour la reservation : ");
                    scanf("%d", &r.id);
                    ajouter_reservation(r);
                    printf("Votre réservation a été effectuée avec succès !\n");
                    printf("Votre numéro de réservation est : %d\n", r.id);
            }
            else {
                    printf("Votre identifiant de voyageur est invalide !\n");
            }
    }
    else{
            printf("Le bus que vous avez choisi n'est pas disponible !\n");
    }
}
void afficher_details_bus(int c) {
    int found = 0;

    for (int i = 0; i < 100; i++) {
        if (bus_disponible(c)==1 ){
            printf("\nDétails du bus avec l'ID %d :\n", c);
            printf("Modèle: %s\n", bus[i].modele);
            printf("Capacité: %d\n", bus[i].capacite);
            printf("Prix: %.2f\n", bus[i].prix);
            printf("-------------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Aucun bus trouve avec l'ID %d.\n", c);
    }
}

void modifier_details_reservation(int id) {
    int found = 0;

    for (int i = 0; i < nb_res; i++) {
        if (res[i].id == id) {
            int x;
            printf("Quel detail de la reservation avec l'ID %d souhaitez-vous modifier?\n", id);
            printf("1. Date\n");
            printf("2. Bus\n");
            printf("Entrez votre choix : ");
            scanf("%d", &x);

            switch (x) {
                case 1:
                    printf("Modifiez la date actuelle de la réservation (actuelle: %s) : ", res[i].date);
                    scanf("%s", res[i].date);
                    printf("La date de la réservation avec l'ID %d a ete modifiee avec succes!\n", id);
                    break;

                case 2:
                    printf("Modifiez le bus actuelle de la réservation (actuelle: %s) : ", res[i].id_bus);
                    scanf("%d", &res[i].id_bus);
                    printf("Le bus de la réservation avec l'ID %d a ete modifiee avec succes!\n", id);
                    break;

                default:
                    printf("Choix invalide.\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Aucune réservation trouvée avec l'ID %d.\n", id);
    }
}

int main(){
        int choix;

    do {

        printf("\nMenu:\n");
        printf("1. Creer un nouveau compte voyageur\n");
        printf("2. Creer un nouveau compte bus\n");
        printf("3. Creer une nouvelle reservation\n");
        printf("4. Afficher les details des bus\n");
        printf("5. Afficher et modifier les details d'une reservation\n");
        printf("6. Quitter\n");

        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                 creer_compte_voyageur();
                 break;
            case 2:
                 creer_compte_bus();
                 break;
            case 3:
                 creer_reservation();
                 break;
            case 4:
    {
        int c;
        printf("Entrez l'ID du bus que vous souhaitez afficher : ");
        scanf("%d", &c);
        afficher_details_bus(c);
    }
    break;
            case 5:
{
    int reservation_id;
    printf("Entrez l'ID de la réservation dont vous souhaitez modifier les details : ");
    scanf("%d", &reservation_id);
    modifier_details_reservation(reservation_id);
}
break;
            case 6:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 6);

    return 0;
}
