#include<iostream>
#include<algorithm>
#include<random>
#include<math.h>
#include<chrono>
#include"resources/ArrayList.cxx"
#include"resources/Heap.cxx"
using std::cout;
using std::endl;

struct Point{
    Point(double x, double y)
    :x(x),y(y){}

    Point()
    :x(0),y(0){}

    bool operator < (const Point& p){
        return x <p.x;
    }

    bool operator > (const Point&p){
        return x > p.x;
    }

    double x,y;
};

std::ostream& operator <<(std::ostream& os, const Point& p){
    os<<p.x<<" "<<p.y;
    return os; 
}

class ClosestPoints{
    public:

    ClosestPoints(int n)
    :sz(n){
        data=new ArrayList<Point>(n);
    }

    int size(){
        return sz;
    }

    void print(){
        data->print();
    }

    Point* getBuf(){ return data->buf;}

    //wypelnia liste liczbami
    void fill(){
        //wpisywanie
        std::string s1,s2;
        while(std::cin>>s1 && std::cin>>s2){
            //zamienia string na double
            data->push_back(Point(atof(s1.c_str()),atof(s2.c_str())));
        }

        //sortowanie ze wzgledu na X
        Heap<Point> h(1);
        data->buf=h.sortIter(data->buf,data->size());
    }

    //oblicza odleglosc dwoch punktow
    long double distance(const Point& p1, const Point& p2){
        return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
    }


    //zwraca mniejsza z wartosci a i b
    double min(double a, double b){
        return a < b ? a : b ;
    }

    double bruteForce(Point p[], int size){
        double minDist=1;
        double currDist;

        //obliczanie najmniejszego dystansu
        for(int i=0; i<size; i++)
            for(int j=i+1; j<size; j++)
                if((currDist=distance(p[i],p[j])) < minDist) minDist=currDist;
            
    return minDist;
    }

    double algorithm(Point p[], int size){
    //gdy sa 3 punkty lub 2
    if(size<=3) return bruteForce(p,size);

    //punkt podzialu
    int mid=(size)/2;

    //rekurencyjnie znajdz najmniejszy dystans po lewej i prawej stronie tablicy
    double smallLeft = algorithm(p,mid);
    double smallRight = algorithm(p+mid,size-mid);

    double minDist=min(smallLeft,smallRight);
    //tablica na punkty blizej linii niz minDist
    Point closeLine[size];
    int j=0;
    for(int i=0; i<size; i++){
        if(abs(p[i].x - p[mid].x) < minDist){
            closeLine[j]=p[i];
            j++;
            }
        }
        return min(minDist, closestOnLine(closeLine, j, minDist)); 
    }

    //znajduje pare punktow najblizszych przy przecieciu tablicy na dwie czesci
    double closestOnLine(Point a[], int size, double minDist){
        //sortuje punkty ze wzgledu na wspolrzedna y
        std::sort(a,a+size,compareY);

        double min=minDist;
        double tempDist;
        for (int i = 0; i < size; i++) 
            for (int j = i+1; j < size && (a[j].y - a[i].y) < min; j++) 
                if ((tempDist=distance(a[i],a[j])) < min) 
                    min = tempDist;
        return min;
    } 

    static bool compareY(const Point& p1, const Point& p2){
        return p1.y < p2.y ? true : false ;
    }

    private:
    ArrayList<Point> *data;
    int sz;
};


int main(int argc, char const *argv[])
{
    if(argc!=2){
        cout<<"Podaj ilosc liczb do listy punktow"<<endl;
        exit(-1);
    }

    try{
        ClosestPoints cp(std::stoi(argv[1]));
        cp.fill();

        auto start=std::chrono::high_resolution_clock::now();
        double brf=cp.bruteForce(cp.getBuf(),cp.size());
        auto end=std::chrono::high_resolution_clock::now();
        double xx=std::chrono::duration<double>(end-start).count();

        start=std::chrono::high_resolution_clock::now();
        double alg=cp.algorithm(cp.getBuf(),cp.size());
        end=std::chrono::high_resolution_clock::now();

        cout<<"Czas wykonania bruteForce: "<<xx<<", najmniejszy dystans: "<<brf<<endl;
        cout<<"Czas wykonania algorytmu: "<<std::chrono::duration<double>(end-start).count()<<", najmniejszy dystans: "<<alg<<endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(-2);
    }
    catch(const char* msg){
        std::cerr<<msg<<endl;
        exit(-1);
    }
    


    return 0;
}
