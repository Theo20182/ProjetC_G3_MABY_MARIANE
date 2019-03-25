#include<stdlib.h>
#include<time.h>
#include<stdio.h>

#define lambda 0.7 //devient malade, donc 1-lambda prob rester sain
#define gamma 0.2 //devient immunisé, donc 0.8 prob décès
//on considère pour le moment que l'état "malade" dure qu'un jour t

typedef struct
{ 
  int id; //on les identifie/différencie par des nombres
  enum  etat;
  int voisins[];
} individu;
  

