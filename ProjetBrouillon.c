#include<stdlib.h>
#include<time.h>
#include<stdio.h>


/* DEFINE */
#define lambda 0.7 //devient malade, donc 1-lambda prob rester sain
#define gamma 0.2 //devient immunisé, donc 0.8 prob décès
//on considère pour le moment que l'état "malade" dure qu'un jour t
#define RAND_MAX  7 //nb de voisins max


/* PROTOTYPES */
void initialiser_population(void);


/* STRUCTURES */
typedef struct
{ 
  int id; //on les identifie/différencie par des nombres
  enum  etat;
  individu voisins[srand(time())]; //nb de voisins aléatoire entre 0 et RAND_MAX
} individu;
  
enum (SAIN, MALADE, IMMUNISE, MORT);

/* FONCTIONS */
//creer une fonction qui convert le fichier texte en tab** pour pouvoir utiliser les indices?

void initialiser_population(void)
{
  FILE *fp;
    fp = fopen("Population.txt", "a+");
      if (fp != NULL)
      { 
        //for all individus du fichier texte
        //mettre enum à 0 pour les mettre sains
        //si la population est définie dans un tab** :
        for (int i = 0; i < MAX; i++)
        {
            tab[i]->enum = 0;
            for (int j = 0; j <= RAND_MAX; j++)
            {
             tab[i]->voisins[j]->enum = 0;
            }
        }
      }
      else
      {
        fprint("Fichier non trouve");
      }
  fcole(fp);
}
