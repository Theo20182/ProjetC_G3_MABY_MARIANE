#include "graph.h"
#define VOISIN_MAX  7
#define LOVE_MAX    10

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

int main(void) {
    int L = 10;
    writeFile(L);
}
