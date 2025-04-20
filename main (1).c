#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOM 100
char nom_joueur[MAX_NOM];
int score_total = 0;

// Déclarations des fonctions
void pageacceuil(int *score);
void addition(int *score);
void multiplication(int *score);
void soustraction(int *score);
void tablemultiplication(int *score);
void divisions_(int *score);
void carre(int *score);
void cube(int *score);
void sauvegarder_score();
void charger_score();

void conversion(int resultat, int *score);
void mesures_longueur(int *score);
void mesures_masse(int *score);
void mesures_aires(int *score);

int main() {
    charger_score();  // Charge le score en fonction du nom
    printf("Votre score actuel est : %d\n", score_total);
    pageacceuil(&score_total);
    sauvegarder_score();  // Sauvegarde le score final
    return 0;
}

void pageacceuil(int *score) {
    int choix = -1;

    do {
        printf("\n+-----------------------------------+\n");
        printf("|            MENU PRINCIPAL         |\n");
        printf("+-----------------------------------+\n");
        printf("| 1 : Addition                      |\n");
        printf("| 2 : Soustraction                  |\n");
        printf("| 3 : Multiplication                |\n");
        printf("| 4 : Tables des multiplications    |\n");
        printf("| 5 : Divisions                     |\n");
        printf("| 6 : Carré                         |\n");
        printf("| 7 : Cube                          |\n");
        printf("| 8 : Conversion de Longueur        |\n");
        printf("| 9 : Conversion de Masse           |\n");
        printf("| 10 : Conversion d'Aires           |\n");
        printf("| 0 : Sortir du jeu                 |\n");
        printf("+-----------------------------------+\n");
        printf("Quel est votre choix ? ");
        scanf("%d", &choix);

        switch (choix) {
            case 0:
                printf("Merci de votre visite !\n");
                return;
            case 1:
                addition(score);
                break;
            case 2:
                soustraction(score);
                break;
            case 3:
                multiplication(score);
                break;
            case 4:
                tablemultiplication(score);
                break;
            case 5:
                divisions_(score);
                break;
            case 6:
                carre(score);
                break;
            case 7:
                cube(score);
                break;
            case 8:
                mesures_longueur(score);
                break;
            case 9:
                mesures_masse(score);
                break;
            case 10:
                mesures_aires(score);
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choix != 0);
}

void addition(int *score) {
    srand(time(0));
    int nb1 = rand() % 101;
    int nb2 = rand() % 101;
    int reponse, resultat = nb1 + nb2, tentatives = 0, points = 0;

    printf("%d + %d = ?\n", nb1, nb2);

    while (tentatives < 3) {
        printf("Tentative %d : ", tentatives + 1);
        scanf("%d", &reponse);
        if (reponse == resultat) {
            points = (tentatives == 0) ? 10 : (tentatives == 1) ? 5 : 1;
            printf("Bravo, bonne réponse !\n");
            break;
        } else {
            printf("Incorrect.\n");
        }
        tentatives++;
    }

    if (tentatives == 3)
        printf("La bonne réponse était : %d\n", resultat);

    *score += points;
    printf("Score actuel : %d\n", *score);
}

void multiplication(int *score) {
    srand(time(0));
    int nb1 = rand() % 11 + 1;
    int nb2 = rand() % 11 + 1;
    int reponse, resultat = nb1 * nb2, tentatives = 0, points = 0;

    printf("%d * %d = ?\n", nb1, nb2);

    while (tentatives < 3) {
        printf("Tentative %d : ", tentatives + 1);
        scanf("%d", &reponse);
        if (reponse == resultat) {
            points = (tentatives == 0) ? 10 : (tentatives == 1) ? 5 : 1;
            printf("Bravo !\n");
            break;
        } else {
            printf("Incorrect.\n");
        }
        tentatives++;
    }

    if (tentatives == 3)
        printf("Bonne réponse : %d\n", resultat);

    *score += points;
    printf("Score actuel : %d\n", *score);
}

void soustraction(int *score) {
    srand(time(0));
    int nb1 = rand() % 101;
    int nb2 = rand() % 101;
    if (nb1 < nb2) {
        int tmp = nb1;
        nb1 = nb2;
        nb2 = tmp;
    }
    int resultat = nb1 - nb2;
    int reponse, tentatives = 0, points = 0;

    printf("%d - %d = ?\n", nb1, nb2);

    while (tentatives < 3) {
        printf("Tentative %d : ", tentatives + 1);
        scanf("%d", &reponse);
        if (reponse == resultat) {
            points = (tentatives == 0) ? 10 : (tentatives == 1) ? 5 : 1;
            printf("Bravo !\n");
            break;
        } else {
            printf("Incorrect.\n");
        }
        tentatives++;
    }

    if (tentatives == 3)
        printf("Bonne réponse : %d\n", resultat);

    *score += points;
    printf("Score actuel : %d\n", *score);
}

void tablemultiplication(int *score) {
    int table, i;
    printf("Choisissez une table : ");
    scanf("%d", &table);

    for (i = 1; i <= 10; i++) {
        int resultat = table * i;
        int reponse, tentatives = 0, points = 0;

        printf("%d x %d = ?\n", table, i);
        while (tentatives < 3) {
            printf("Tentative %d : ", tentatives + 1);
            scanf("%d", &reponse);
            if (reponse == resultat) {
                points = (tentatives == 0) ? 10 : (tentatives == 1) ? 5 : 1;
                printf("Bravo !\n");
                break;
            } else {
                printf("Incorrect.\n");
            }
            tentatives++;
        }

        if (tentatives == 3)
            printf("Bonne réponse : %d\n", resultat);

        *score += points;
    }

    printf("Score actuel : %d\n", *score);
}

void divisions_(int *score) {
    int a = 17, b = 4;
    int quotient = a / b;
    int reste = a % b;
    int q_user, r_user, essai, points = 0;

    printf("Devine le quotient et le reste de la division suivante : %d / %d\n", a, b);

    for (essai = 1; essai <= 3; essai++) {
        printf("Essai %d - Quotient : ", essai);
        scanf("%d", &q_user);
        printf("Reste : ");
        scanf("%d", &r_user);

        if (q_user == quotient && r_user == reste) {
            points = (essai == 1) ? 10 : (essai == 2) ? 5 : 1;
            printf("Bravo !\n");
            break;
        } else {
            printf("Incorrect.\n");
        }
    }

    if (points == 0)
        printf("Réponse : quotient = %d, reste = %d\n", quotient, reste);

    *score += points;
    printf("Tu as obtenu %d points. Score total : %d\n", points, *score);
}

void carre(int *score) {
    int nb, reponse_carre;
    int tentatives = 0, points = 0;

    srand(time(0));
    nb = rand() % 11 + 1;

    int carre = nb * nb;
    printf("Quel est le carré de %d ?\n", nb);

    while (tentatives < 3) {
        printf("Tentative %d : ", tentatives + 1);
        scanf("%d", &reponse_carre);
        if (reponse_carre == carre) {
            points = (tentatives == 0) ? 10 : (tentatives == 1) ? 5 : 1;
            printf("Bravo pour le carré !\n");
            break;
        } else {
            printf("Incorrect.\n");
        }
        tentatives++;
    }

    if (tentatives == 3)
        printf("Bonne réponse : %d\n", carre);

    *score += points;
    printf("Tu as gagné %d points. Score total : %d\n", points, *score);
}

void cube(int *score) {
    int nb, reponse_cube;
    int tentatives = 0, points = 0;

    srand(time(0));
    nb = rand() % 10 + 1;

    int cube = nb * nb * nb;
    printf("Quel est le cube de %d ?\n", nb);

    while (tentatives < 3) {
        printf("Tentative %d : ", tentatives + 1);
        scanf("%d", &reponse_cube);
        if (reponse_cube == cube) {
            points = (tentatives == 0) ? 10 : (tentatives == 1) ? 5 : 1;
            printf("Bravo pour le cube!\n");
            break;
        } else {
            printf("Incorrect.\n");
        }
        tentatives++;
    }

    if (tentatives == 3)
        printf("Bonne réponse : %d\n", cube);

    *score += points;
    printf("Tu as gagné %d points. Score total : %d\n", points, *score);
}

// === GESTION DU SCORE PAR FICHIER ===

void sauvegarder_score() {
    FILE *file;
    time_t now;
    struct tm *tm_info;
    char date_heure[100];

    time(&now);
    tm_info = localtime(&now);
    strftime(date_heure, sizeof(date_heure), "%Y-%m-%d %H:%M:%S", tm_info);

    file = fopen("scores.txt", "a");
    if (file != NULL) {
        fprintf(file, "Nom: %s, Date: %s, Score: %d\n", nom_joueur, date_heure, score_total);
        fclose(file);
    } else {
        printf("Erreur de sauvegarde du score.\n");
    }
}

void charger_score() {
    FILE *file;
    char ligne[200];
    int trouve = 0;
    char nom_lu[MAX_NOM];
    int score_lu;

    printf("Entrez votre nom : ");
    scanf("%s", nom_joueur);

    file = fopen("scores.txt", "r");
    if (file != NULL) {
        while (fgets(ligne, sizeof(ligne), file)) {
            sscanf(ligne, "Nom: %[^,], Date: %*[^,], Score: %d", nom_lu, &score_lu);
            if (strcmp(nom_lu, nom_joueur) == 0) {
                score_total = score_lu;
                trouve = 1;
            }
        }
        fclose(file);
    }

    if (trouve) {
        printf("Bienvenue %s, votre dernier score était : %d\n", nom_joueur, score_total);
    } else {
        printf("Bienvenue %s, vous commencez avec un nouveau score.\n", nom_joueur);
    }
}

// === JEUX CONVERSIONS ===

void conversion(int resultat, int *score){
    int reponse, tentatives = 0, points = 0;

    while (tentatives < 3) {
        printf("Tentative %d : ", tentatives + 1);
        scanf("%d", &reponse);

        if (reponse == resultat) {
            points = (tentatives == 0) ? 10 : (tentatives == 1) ? 5 : 1;
            printf("Bravo !\n");
            break;
        } else {
            printf("Incorrect.\n");
        }
        tentatives++;
    }

    if (tentatives == 3) {
        printf("La bonne réponse était : %d\n", resultat);
    }

    *score += points;
    printf("Score actuel : %d\n", *score);
}

void mesures_longueur(int *score) {
    int resultat, choix, valeur;

    printf("\n+---------------------------------------+\n");
    printf("| 1 : Convertir mètres en centimètres     |\n");
    printf("| 2 : Convertir centimètres en millimètres|\n");
    printf("| 3 : Convertir kilomètres en mètres      |\n");
    printf("| 4 : Convertir mètres en kilomètres      |\n");
    printf("+-----------------------------------------+\n");
    printf("Quel type de conversion ? ");
    scanf("%d", &choix);

    valeur = rand() % 100 + 1;

    switch (choix) {
        case 1:
            printf("Convertir %d m en cm ?\n", valeur);
            resultat = valeur * 100;
            break;
        case 2:
            printf("Convertir %d cm en mm ?\n", valeur);
            resultat = valeur * 10;
            break;
        case 3:
            printf("Convertir %d km en m ?\n", valeur);
            resultat = valeur * 1000;
            break;
        case 4:
            valeur = (rand() % 9000) + 1000;
            printf("Convertir %d m en km (entier seulement) ?\n", valeur);
            resultat = valeur / 1000;
            break;
        default:
            printf("Choix invalide.\n");
            return;
    }

    conversion(resultat, score);
}

void mesures_masse(int *score) {
    int resultat, choix, valeur;

    printf("\n+----------------------------------------+\n");
    printf("| 1 : Convertir kilogrammes en grammes     |\n");
    printf("| 2 : Convertir grammes en milligrammes     |\n");
    printf("| 3 : Convertir tonnes en kilogrammes       |\n");
    printf("| 4 : Convertir grammes en kilogrammes      |\n");
    printf("+------------------------------------------+\n");
    printf("Quel type de conversion ? ");
    scanf("%d", &choix);

    valeur = rand() % 100 + 1;

    switch (choix) {
        case 1:
            printf("Convertir %d kg en g ?\n", valeur);
            resultat = valeur * 1000;
            break;
        case 2:
            printf("Convertir %d g en mg ?\n", valeur);
            resultat = valeur * 1000;
            break;
        case 3:
            printf("Convertir %d t en kg ?\n", valeur);
            resultat = valeur * 1000;
            break;
        case 4:
            valeur = (rand() % 9000) + 1000;
            printf("Convertir %d g en kg (entier seulement) ?\n", valeur);
            resultat = valeur / 1000;
            break;
        default:
            printf("Choix invalide.\n");
            return;
    }

    conversion(resultat, score);
}

void mesures_aires(int *score) {
    int resultat, choix, valeur;

    printf("\n+----------------------------------------+\n");
    printf("| 1 : Convertir m² en cm²                 |\n");
    printf("| 2 : Convertir cm² en mm²                |\n");
    printf("| 3 : Convertir km² en m²                 |\n");
    printf("| 4 : Convertir m² en km² (entier)        |\n");
    printf("+----------------------------------------+\n");
    printf("Quel type de conversion ? ");
    scanf("%d", &choix);

    valeur = rand() % 100 + 1;

    switch (choix) {
        case 1:
            printf("Convertir %d m² en cm² ?\n", valeur);
            resultat = valeur * 10000;
            break;
        case 2:
            printf("Convertir %d cm² en mm² ?\n", valeur);
            resultat = valeur * 100;
            break;
        case 3:
            printf("Convertir %d km² en m² ?\n", valeur);
            resultat = valeur * 1000000;
            break;
        case 4:
            valeur = (rand() % 900000) + 100000;
            printf("Convertir %d m² en km² (entier seulement) ?\n", valeur);
            resultat = valeur / 1000000;
            break;
        default:
            printf("Choix invalide.\n");
            return;
    }

    conversion(resultat, score);
}
