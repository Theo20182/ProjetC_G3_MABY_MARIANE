#include<stdlib.h>
#include<time.h>
#include<stdio.h>


/*************** DEFINE ***************/
#define VOISIN_MAX  7
#define LOVE_MAX    10
#define lambda 0.7 //devient malade, donc 1-lambda prob rester sain
#define gamma 0.2 //devient immunisé, donc 0.8 prob décès
//on considère pour le moment que l'état "malade" dure qu'un jour t
#define MAX 10 //taille de tab Population 10 x 10


/*************** PROTOTYPES ***************/
void writeFile(int L);
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

void writeFile(int L) {
    int v, l;   //L'id du voisin, le degré de love
    int j;      //Le nombre de voisin   
    srand(time(NULL));
    
    char name_file[20];
    FILE *fp;
    
    printf("Entrez le nom du fichier créer: ");
    scanf("%s", name_file);
    fp = fopen(name_file, "w");
    fprintf(fp, "%d\n", L);
    
    for(int i = 1; i <= L; i++) {  //On itère sur l'id de l'individu
        j = rand()%VOISIN_MAX; //On choisit son nombre de voisin
        for(int k = 0; k <= j; k++){    //On itère sur l'id de voisin
            v = rand()%L + 1;       //On choisit l'id du voisin
            if(v != i){                     //On s'assure que                                           l'individu n'est pas son                                    propre voisin                           
                l = rand()%LOVE_MAX + 1; //On choisit le degré de love
                fprintf(fp, "%d %d %d\n", i, v, l); //On écrit
            }
        }
    }
    fclose(fp);
}
//Probleme: Eviter le cas pathologique de doublons et determiner le nopmbre d'arc dans le graphe



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
			p->individu = id_voisin - 1;
			p->etat		= 0;
			p->love = affinite;
			p->voisin			= G->successeurs[id-1];
			G->successeurs[id-1]	= p; //-1 car les id commencent a 1
		}
	}
  
	else printf("Le fichier n'a pas été trouvé.");

	fclose(fp);
}




void first_sick(void)
{
  
  
}



int main(void) {
    int L = 10;
    writeFile(L);
}

