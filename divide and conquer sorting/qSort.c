#include<stdlib.h>//qsort
#include<stdio.h>
#include<time.h>

int compare(const void * a, const void * b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    return _a < _b ? _a : _b;
}


int main(int argc, char const *argv[])
{
    if(argc!=2){
        printf("Podaj wielkosc tablicy liczb");
        exit(-1);
    }

    int vec[atoi(argv[1])];
    int i=0;

    while(scanf("%d",&vec[i])!=EOF)
        i++;

    //clock_t t;
    //t=clock();
    qsort(vec,atoi(argv[1]),sizeof(int),compare);
    //t=clock()-t;
    //printf("Czas qsort(): %ld",t);

    //do wyswietlania
    // int size=atoi(argv[1]);
    // for(int i=0;i<size;i++)
    //     printf("%d ",vec[i]);
    
    
    return 0;
}
