#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int i = 1, nb = 5, min = 1, max = 100;
    int nombre = 0, niveau = 2, jouer = 1, nv = 1;
    int saisieNombre = 0;

    printf("Bienvenue sur le celebre jeu du juste prix,\n");

    while (jouer == 1) //Permet de faire plusieurs parties
    {
        if (nv == 1) //Permet de choisir le niveau de difficulté
        {             // Niveau initialisé au préalable sur le 2
            printf("Choisis ton niveau de difficulte\n"
                    "1 entre 1 et 10 avec 3 coups\n"
                    "2 entre 1 et 100 avec 5 coups\n"
                    "3 entre 1 et 1 000 avec 10 coups\n"
                    "Niveau = ");
            scanf("%d", &niveau);
            if (niveau == 1)
            {
                max = 10;
                nb = 3;
            }
            else if (niveau == 3)
            {
                max = 1000;
                nb = 10;
            }
            else if (niveau == 2)
            {
                max = 100;
                nb = 5;
            }
            else
            {
                printf("Saisie non reconnu, niveau retenu : 2");
            }
        }


        nombre = rand()%(max + min);
        i = 1; //Réinitialisation du compteur de tour pour les nouvelles parties

        printf("\nTu dois deviner le prix auquel je pense, il se situe entre 1 et %d\n\n", max);
        printf("\nVous avez %d coups\nDonnez un nombre : ", nb);
        scanf("%d", &saisieNombre);

        while (saisieNombre != nombre && i < nb)//Tant que le nombre n'est pas trouvé et qu'il reste des tours
        {
            if (saisieNombre > nombre)
            {
                if (saisieNombre > max)
                {
                    printf("Erreur le nombre ne peut pas depasser %d\n", max);
                    printf("Donnez un nombre entre 1 et %d : ", max);
                    scanf("%d", &saisieNombre);
                }
                printf("C'est moins !\nIl vous reste %d coups\n", nb-i);
            }
            else
            {
                printf("C'est plus !\nIl vous reste %d coups\n", nb-i);
            }
            i++;
            scanf("%d", &saisieNombre);
        }
        if (saisieNombre == nombre)
        {
            printf("Bravo le juste prix est bien : %d\n", nombre);
            printf("Vous avez trouve en %d coups\n", i);
        }
        else
            printf("Vous avez perdu, le juste prix etait : %d\n", nombre);

        printf("Voulez-vous rejouer ? (0 = Non, 1 = Oui) : ");
        scanf("%d", &jouer);

        if (jouer != 1)
        {
            printf("Le jeu s'arrete\n");
            jouer = 0;
        }
        else
        {
            printf("Voulez-vous changer de niveau ? (0 = Non, 1 = Oui) : ");
            scanf("%d", &nv);
            if (nv != 1)
            {
                printf("Pas de changement de niveau.");
                nv = 0;
            }
        }

    }

    return 0;
}
