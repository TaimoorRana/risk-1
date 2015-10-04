#include <iostream>
#include <stdlib.h>
#include <map>
#include <list>
#include "./../shared_structures/country.h"
#include "./../shared_structures/continent.h"
#include "./../shared_structures/global_settings.h"
using namespace std;
// Cette fonction fait simplement le produit entre deux matrices d'ordre N
int** produit(int** A,int** B,int N)
{
    int** C = (int**)malloc(N * sizeof(int*));

    for (int i=0;i<N;i++) {
        C[i]=(int*)malloc(N * sizeof(int));
        for (int j=0;j<N;j++) {
            C[i][j]=0;
            for (int k=0;k<N;k++) {
                C[i][j]=A[i][k]*B[k][j]+C[i][j];
            }
        }
    }
    return C;
}

// Cette fonction remplit une matrice avec la valeur k chaque fois que le coeff de A est plus petit que B
// Elle sert dans le calcul des distances minimales entres les pays
int** min(int N,int** A,int** B,int k)
{
    int** C = (int**)malloc(N * sizeof(int*));

    for (int i=0;i<N;i++)
    {
        C[i]=(int*)malloc(N * sizeof(int));
        for (int j=0;j<N;j++) {
            if(A[i][j]<B[i][j] && A[i][j]!=0 && B[i][j]==N)
                C[i][j]=k;
            else
                C[i][j]=B[i][j];
        }
    }
    return C;
}

// Cette fonction rend un tableau avec les distances minimales entre les pays
int** distance(int N,int** voisinage)
{
    int** distance;
    distance = (int**)malloc(N * sizeof(int*));
    int** tampon;
    tampon = (int**)malloc(N * sizeof(int));

    for (int i=0;i<N;i++)
    {
        distance[i]=(int*)malloc(N * sizeof(int));
        tampon[i]=(int*)malloc(N * sizeof(int));
        for (int j=0;j<N;j++) {
            distance[i][j]=N;
            tampon[i][j]=voisinage[i][j];
        }
    }

    for (int k=0;k<N;k++)
    {
        distance=min(N,tampon,distance,k+1);
        tampon=produit(tampon,voisinage,N);
    }

    return distance;
}

// Cette fonction rend le nombre de triangles dans une map
// Cet argument rentre dans le calcul de la compacité d'une map
// voisinage est le tableau de voisinage des pays et N est le nombre des pays (taille du tableau)
int nombretriangles(int **voisinage,int N)
{
    int** tampon;
    int nombre=0;
    tampon = (int**)malloc(N * sizeof(int));

    for (int i=0;i<N;i++)
    {
        tampon[i]=(int*)malloc(N * sizeof(int));
        for (int j=0;j<N;j++) {
            tampon[i][j]=voisinage[i][j];
        }
    }

    tampon=produit(tampon,voisinage,N);
    tampon=produit(tampon,voisinage,N);

    for (int i=0;i<N;i++)
        nombre=nombre+tampon[i][i];

    free(tampon);

    return nombre*1.0/6;
}
// Cette fonction permet d'initialiser une matrice avec la matrice de voisinage tout en tenant compte des modifs
void initialiser2 (int** matrice, Global_Settings * global_settings)
{
    int i,j,N;
    set<Country*> countries = global_settings->get_countries();
    set<Country*>::iterator  it1, it2;

    N=countries.size();
    matrice = (int**)malloc(N * sizeof(int*));

    for (int i=0;i<N;i++)
    {
        matrice[i]=(int*)malloc(N * sizeof(int));
    }
    for (it1 = countries.begin(); it1 != countries.end(); ++it1)
    {
        i=(*it1)->get_id();
        set<Country*> neighbors = global_settings->get_neighbors(*it1);
        //get_neighbors with a single o =)
        for (it2 = neighbors.begin(); it2 !=neighbors.end(); ++it2) {
            j=(*it2)->get_id();
            matrice[i][j]=1;
            matrice[j][i]=1;
        }
    }
    return;
}
// Cette fonction permet d'initialiser une matrice avec la matrice de voisinage
void initialiser (int **matrice,int N)
{
    /* The parameter N is defined on shared stuctures data
     * For example, global_settings->get_cards().size();
     * Is the matrix "matrice" the adjacence list of the countries?
     * If affirmative, it is also defined on the class Global_Settings
     * I would suggest obtaining it from this class rather than declaring it here
     * Maybe with a header int ** matrix (Global_Settings* global_settings)
     */
    matrice = (int**)malloc(N * sizeof(int*));
    for (int i=0;i<N;i++)
    {
        matrice[i]=(int*)malloc(N * sizeof(int));
    }
    //    matrice = {
    //        {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    //        {1,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,1,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,1,0,0,1,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
    //        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1},
    //        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0}
    //     };
}

// Cette fonction permet de calculer le nombre de triangle dans un graphe où il n'y a qu une liste de sommets
int nombretrianglesState(list<Country*> liste,int** A,int N) {

    int i,j;
    int** tamp;

    tamp = (int**)malloc(N * sizeof(int*));
    for (int i=0;i<N;i++)
    {
        tamp[i]=(int*)malloc(N * sizeof(int));
        for (int j=0;j<N;j++) {
            tamp[i][j]=0;
        }
    }

    list<Country*>::iterator it;
    for (it = liste.begin(); it != liste.end(); ++it)
    {
        //i=it->id; id is a private field
        i = (*it)->get_id();
        tamp[i][i]=1;
    }

    A=produit(tamp,A,N);
    A=produit(A,tamp,N);
    free(tamp);

    return nombretriangles(A,N);
}

// La fonction finale qui permettra de calculer le nombre de triangles dans les pays d'un joueur
int evaluatecompacite(list<Country*> liste) {
    int** A;
    int N=42;
    // N=(graph->first).size();
    // initialiser2 (A,Global_Settings);
    initialiser(A,N);
    nombretrianglesState(liste,A,N);
    free(A);
}
