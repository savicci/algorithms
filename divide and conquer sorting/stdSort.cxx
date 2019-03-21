#include<iostream>
#include<time.h>
#include<vector>
#include<algorithm>


int main(int argc, char const *argv[])
{
    if(argc!=2){
        printf("Podaj wielkosc tablicy liczb");
        exit(-1);
    }
    
    //std::vector<int> vec(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());;
    //clock_t t;
    //t=clock();
    int vec[atoi(argv[1])];
    int i=0;

    while(scanf("%d",&vec[i])!=EOF)
        i++;

    std::sort(vec,vec+std::stoi(argv[1]));
    //t=clock()-t;
    //printf("Czas std::sort(): %ld",t);

    //do wyswietlania
    // for(int i=0;i<vec.size();i++)
    //     printf("%d ",vec[i]);

    return 0;
}
