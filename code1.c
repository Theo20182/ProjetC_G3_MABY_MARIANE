#include "graph.h"

int calculTailleTab(Graph* G, int id) {
    int taille = 0;
    Node* temp = G->list_successors[id];
    while(G->list_successors[id] != NULL){
        taille++;
        G->list_successors[id] = G->list_successors[id]->successor;
    }
    G->list_successors[id] = temp;
   return taille;     
}

/////////////////////////////////////////////////

int calculNb_arcs(const char* name_file) {
    int nb_arcs = 0;
    int u, v, w;

	FILE *fp;
	fp = fopen(name_file, "r");
  
	if (fp != NULL) // le fichier est trouve
	{
		while(fscanf(fp,"%d%d%d", &u, &v, &w) == 3) //on lit jusqu'à la fin du fichier
		{
			nb_arcs += 1;
		}
	}
	else 
        printf("Le fichier n'a pas été trouvé.");
    
	fclose(fp);
	return nb_arcs;
}


/////////////////////////////////////////////////
/////////////////////////////////////////////////


void afficheVoisin(Graph* G) {
    for(int i = 0; i < G->nb_nodes; i++){
        Node* temp = G->list_successors[i];
        while(G->list_successors[i] != NULL){
            printf("id:%d voisin:%d etat:%d potentiel:%d\n", i, G->list_successors[i]->id, G->list_successors[i]->state, G->list_successors[i]->potentiel);
            
            G->list_successors[i] = G->list_successors[i]->successor;
        }
        G->list_successors[i] = temp;
    }
}

/////////////////////////////////////////////////

void afficheStat(Graph* G){
    for (int i = 0; i < G->nb_nodes; i++) {   
        printf("id:%d etat:%d potentiel:%d force:%.2f dead:%.2f\n", i, G->list_successors[i]->state, G->list_successors[i]->potentiel, G->list_successors[i]->force, G->list_successors[i]->dead);
    }
}

/////////////////////////////////////////////////

//void detectDoublons(Graph* G) {
//    
//    int taille;
//    int id = 0;
//    int v = 0;
//    list* tab;
//    while(id < G->nb_nodes) {
//        
//        taille = calculTailleTab(G, id);
//        int tab1[taille][2];
//        int k=0;
//    
//        Node* temp = G->list_successors[id];
//        while(G->list_successors[id] != NULL) {
//            tab1[k][0] = G->list_successors[id]->id;
//            tab1[k][1] = k;
//            printf("id:%d val:%d idd:%d\n", id, tab1[k][0], tab1[k][1]);
//            G->list_successors[id] = G->list_successors[id]->successor;
//            k++;
//        }
//        G->list_successors[id] = temp;
// 
//        printf("\n");
//        
//        int r;
//       
//        for(int i = 0; i < taille; i++) {
//            r = 0;
//            for(int j = 1; (j < taille) && (j > i); j++) {
//                if(tab1[j][0] == tab1[i][0]) {
//                    v=
//                    printf("id2:%d val:%d idd:%d\n", id, tab1[j][0], tab1[i][1]);
//                    r++;
//                    v++;
//                    tab->nb_id = r;
//                    tab->list_individu[r-1]->id = id;
//                    tab->list_individu[r-1]->list_voisin[v];
//                }
//            }
//            r++;
//        }
//         printf("\n");
//        id++;
//    }
//    for(int i = 0; i < G->nb_nodes; i++){
//        printf("2 - id:%d val:%d \n", tab[i][0][0], tab[i][1][0]);
//    }
//}

/////////////////////////////////////////////////

void defineState(Graph* G, int id, int state) {
    Node* temp = G->list_successors[id];
    while (G->list_successors[id] != NULL) {
        G->list_successors[id]->state = state;
        G->list_successors[id] = G->list_successors[id]->successor;
    }
    G->list_successors[id] = temp;
}

/////////////////////////////////////////////////

int* createVoisin(int L, int voisin_max) {
    int* tab	= (int*) malloc(voisin_max*sizeof(int));
    for(int i = 0; i < voisin_max; i++)
        tab[i] = rand()%L;
    return tab;
}


/////////////////////////////////////////////////
/////////////////////////////////////////////////


void writeFile(int L) {
    int v, p1, p2, j, n, i = 0;   //L'id du voisin, le degré de love  
    srand(time(NULL));
    FILE *fp;
    char name_file[20];
    
    printf("Enter file name :");
	scanf("%s", name_file);
    fp = fopen(name_file, "w");
    fprintf(fp, "%d\n", L);
    
    while(i < L) {  //On itère sur l'id de l'individu
        j = rand()%VOISIN_MAX + 1; //On choisit son nombre de voisin
        int* tab	= (int*) malloc(j*sizeof(int));
        tab = createVoisin(L, j);
        for(int k = 0; k < j; k++){
            //On itère sur l'id de voisin
            if(rand()%2){
                v = tab[k];       //On choisit l'id du voisin
                if(v != i){               
                    p1 = rand()%100 + 1;//On choisit le p
                    p2 = rand()%100 + 1;
                    fprintf(fp, "%d %d %d\n", i, v, p1);
                    n++;
                    fprintf(fp, "%d %d %d\n", v, i, p2);
                    n++;
                }
            }
        }
        if(n == 0)
            i--;
        n = 0;
        i++;
    }
    
    fclose(fp);
}

void createGraph(Graph* G)
{
	FILE *fp;
    char name_file[20];
    
    printf("Enter file name :");
	scanf("%s", name_file);
	fp = fopen(name_file, "r");
    
    int id;
    printf("CHOOSE THE FIRST SICK : \n"); //Entrer l'id
	printf("(enter an id)\n");
	scanf("%d", &id);
    
	if (fp != NULL) 
	{
		int nb_nodes, nb_arcs, u, v, w;
        nb_arcs = calculNb_arcs(name_file);
        
        fscanf(fp, "%d", &nb_nodes);
		G->nb_nodes = nb_nodes;
		G->list_successors = (Node**) malloc(nb_nodes * sizeof(Node*));

		for (int i = 0; i < nb_nodes; i++) { 
			G->list_successors[i] = NULL;
        }

		for (int j = 0; j < nb_arcs; j++)
		{
			fscanf(fp, "%d %d %d", &u, &v, &w);
			Node* s	= (Node*) malloc(sizeof(Node)); 
			s->id = v;
			s->potentiel = w;
            
            if(id == u)
                s->state = 1;
            else
                s->state = 0;

			s->successor = G->list_successors[u];
			G->list_successors[u] = s;
            printf("id : %d voisin : %d potentiel : %d etat : %d\n", u, s->id, s->potentiel, s->state);
		}
	}
	else printf("File not found.");
	fclose(fp);
}

/////////////////////////////////////////////////

void initStat(Graph* G) {
    for(int i = 0; i < G->nb_nodes; i++){
        float faiblesse = rand()%100;
        float force = rand()%100;
        float dead = 100-force;
        Node* temp = G->list_successors[i];
        while (G->list_successors[i] != NULL) {
                G->list_successors[i]->force = force/100;
        
                G->list_successors[i]->dead = dead/100;
        
                G->list_successors[i] = G->list_successors[i]->successor;
        }
        G->list_successors[i] = temp;
    }
}


/////////////////////////////////////////////////
/////////////////////////////////////////////////


int* maladieAttack(Graph* G, int* tab2) {
    int* tab = (int*)malloc(sizeof(int));
    int a = 0, b = 0, i;
    
    while(tab2[b] != -1){    
        i = tab2[b];    
        printf("\n id:%d\n",i);
        if (G->list_successors[i]->state == 1) {
            Node* temp = G->list_successors[i];
            while (G->list_successors[i] != NULL) {
                
                int v_m = G->list_successors[i]->id;
                if (G->list_successors[i]->potentiel  >= 50) //lambda * moylove
                {
                    Node* temp2 = G->list_successors[v_m];
                    while (G->list_successors[v_m] != NULL) {
                        G->list_successors[v_m]->state = 1;
                        
                        G->list_successors[v_m] = G->list_successors[v_m]->successor;
                    } 
                    G->list_successors[v_m] = temp2;
                    
                    printf("id:%d etat:%d\n",G->list_successors[i]->id, G->list_successors[i]->state);
                
                    tab[a] = G->list_successors[i]->id;
                    a++;
                    
                }
                
                G->list_successors[i] = G->list_successors[i]->successor;
            } 
            G->list_successors[i] = temp;
        }
        b++;
    }
    tab[a] = -1;
    for(int p = 0; p <= a; p++)
        printf("%d, ", tab[p]);
    return tab;
}

/////////////////////////////////////////////////

void immune(Graph* G, int id){
    printf("id: %d\n", id);
    if((G->list_successors[id]->state == 1) && (G->list_successors[id]->force >= 40)){
        defineState(G, id, 2);
    }
}

/////////////////////////////////////////////////

void dead(Graph* G, int id){
    printf("id: %d\n", id);
    if((G->list_successors[id]->state == 1) && (G->list_successors[id]->force <= 40)){
        defineState(G, id, 3);
    }
}

/////////////////////////////////////////////////

void defineVampire(Graph* G, int id, int time){
    printf("id: %d\n", id);
    if((G->list_successors[id]->state == 2) && (time >= 3)) {
        defineState(G, id, 4);
    }
}

/////////////////////////////////////////////////

void vampireAttack(Graph* G, int id_vampire) {
    int victime = rand()%11;
    int tab[victime];
    int id;
    
    for(int i = 0; i <= victime; i++) {
        tab[i] = rand()%(G->nb_nodes);
    }
    
    for(int i = 0; i <= victime; i++) {
        id = tab[i];
        switch(G->list_successors[id]->state) {
            case 0:
                defineState(G, id, 5);
            break; 
                
            case 1:
                defineState(G, id, 6);
            break;
                
            case 2:
                defineState(G, id, 4);
            break; 
            
            case 3:
                defineState(G, id, 5);
            break;
            
            case 4:
                defineState(G, id, 6);
                defineState(G, id_vampire, 6);
            break; 
                
            default:
                printf("\n");
            break; 
        }
    }
}

/////////////////////////////////////////////////

void ghoulAttack(Graph* G, int id_ghoul) {
    int victime = rand()%11;
    int tab[victime];
    int id;
    
    for(int i = 0; i <= victime; i++) {
        tab[i] = rand()%(G->nb_nodes);
    }
    
    for(int i = 0; i <= victime; i++) {
        id = tab[i];
        switch(G->list_successors[id]->state) {
            case 0:
                defineState(G, id, 3);
            break; 
                
            case 1:
                printf("\n");
            break;
                
            case 2:
                defineState(G, id, 4);
            break; 
            
            case 3:
                defineState(G, id, 5);
            break;
            
            case 4:
                defineState(G, id_ghoul, 6);
            break; 
                
            default:
                printf("\n");
            break; 
        }
    }
    
}


/////////////////////////////////////////////////
/////////////////////////////////////////////////


void step(Graph* G, int time){
    int id;
    int* tab =(int*)malloc(sizeof(int));
    int* nxt_malade;
    
    printf("ENTER THE FIRST SICK : \n");
	printf("(enter an id)\n");
	scanf("%d", &id);
    tab[0] = id;
    tab[1] = -1;
    
    nxt_malade = maladieAttack(G, tab);
    for(int i = 0; i < time; i++){
        nxt_malade = maladieAttack(G, nxt_malade);
        printf("STOP\n");
        printf("\n");
        afficheVoisin(G);        
        printf("\n");

    }
}


/////////////////////////////////////////////////
/////////////////////////////////////////////////


int main(void) {
    int L = 10;
    srand(time(NULL));
    Graph G;
    
    writeFile(L);
    createGraph(&G);
    initStat(&G);
    afficheStat(&G);
    printf("\n");
    step(&G, 4);

    return 0;
}
