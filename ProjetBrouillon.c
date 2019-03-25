#include<stdlib.h>
#include<time.h>
#include<stdio.h>


/*************** DEFINE ***************/
#define lambda 0.7 //devient malade, donc 1-lambda prob rester sain
#define gamma 0.2 //devient immunisé, donc 0.8 prob décès
//on considère pour le moment que l'état "malade" dure qu'un jour t
#define RAND_MAX  8 //nb de voisins max
#define MAX 10 //taille de tab Population 10 x 10


/*************** PROTOTYPES ***************/
tab** convert_txt_to_list(void);
int calcul_nb_arcs;
void creation_graphe(graphe* G)
void first_sick(void);


/*************** STRUCTURES ***************/

typedef struct _individu
{ 
  int id; //on les identifie/différencie par des nombres
	int love;
  enum  etat;
  _individu* voisin;
} individu;



typedef struct 
{
	int	nb_individus;
	individu** successeurs; 
} graphe;

  
enum (SAIN, MALADE, IMMUNISE, MORT);


/*************** FONCTIONS ***************/
tab** convert_txt_to_list(void)
{ //creer une fonction qui convert le fichier texte en tab** pour pouvoir utiliser les indices?

}
  

int calcul_nb_arcs
{
	int nb_arcs;
	FILE *fp;
	printf("Enter file name :");
	scanf("%c", &f);
	fp = fopen(f, "r");
  
	if (fp != NULL) // le fichier est trouve
	{
		while (fscanf(fp,"%d%d%d", &id, &id_voisin, &affinité) == 3)) //on lit jusqu'à la fin du fichier
		{
			nb_arcs += 1;
		}
	}
	else printf("Le fichier n'a pas été trouvé.");
	fclose(fp);
	return nb_arcs;
}  


void creation_graphe(graphe* G)
{
	int nb_arcs;
	nb_arcs = calcul_nb_arcs();

	FILE *fp;
	printf("Enter file name :");
	scanf("%c", &f);
	fp = fopen(f, "r");

	if (fp != NULL) // le fichier est trouve
	{
		int nb_individus;
		fscanf(fp, "%d", &nb_individus);	
		G->nb_individus 	= nb_individus;
		G->successeurs	= (individu**)malloc(nb_individus * sizeof(individu*));

		for (int i = 0; i < nb_individus; i++) 
		{	
			G->successeurs[i]	= NULL;
		}
		
		for (int i = 0; i < nb_arcs; i++) 
		{
			fscanf(fp, "%d %d %d", &id, &id_voisin, &affinite);
			//u--; // decrement pour gerer le decalage entre le numeros des sommets dans le fichiers et les index dans les tableaux
			//v--;
			//ajout d'un arc (u,v) : un maillon est ajoute en debut de la liste de successeurs de u
			individu* p		= (individu*) malloc(sizeof(individu));
			p->individu = id_voisin;
			p->etat		= 0;
			p->love = affinite;
			p->voisin			= G->successeurs[id];
			G->successeurs[id]	= p;
		}
	}
  
	else printf("Le fichier n'a pas été trouvé.");

	fclose(fp);
}




void first_sick(void)
{
  
  
}

