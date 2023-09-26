#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//In ordinea crescatoare a timpului de terminare

typedef struct
{
    int n;
    int m;
    char nume[50];
}activ;

void functie(int n, activ* a)
{
    activ aux ;
    int ultim ;

    for(int i =0 ; i<n-1 ; i++) //am sortat cresc dupa timpul de finalizare
        for(int j =i+1; j<n ; j++)
        {
            if(a[i].m > a[j].m)
            {
                aux = a[i];
                a[i] = a[j];
                a[j]= aux;
            }
        }

    ultim = a[0].m;
    printf("%s ", a[0].nume );

    for(int i = 1; i<n ; i++){

        if( ultim <= a[i].n) //nu se suprapune timpul de finis cu inceputul celeilalte
        {
            printf("%s ", a[i].nume);
            ultim = a[i].m;
        }
    }
}

int main()
{
    FILE* f = fopen("activitati.txt", "r");
    if(f == NULL){
        printf("vubw");
        return 0;
    }

    activ* a = (activ*)calloc(100, sizeof(activ)); //vect de structuri

    int n,m;
    char nume[50];
    int k=0;

    while( fscanf(f, "%s %d %d", nume, &n, &m ) == 3 ) //citire
    {
        strcpy(a[k].nume, nume);
        a[k].n = n;
        a[k].m = m;
        k++;
    }

    fclose(f);

    functie(k, a);

    return 0;
}
