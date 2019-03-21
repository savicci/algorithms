//szuka najwiekszego prostokata
#include<iostream>
#include<string>
#include"resources/Stack.hxx"
using std::cout;
using std::endl;
using std::cin;

std::string input;

class RectangleFinder{
    public:
    //wczytywanie ze standardowego wejscia
    RectangleFinder(int w,int h)
    :w(w),h(h){
        A = new char*[w];
        for(int i=0; i<w; i++)
            A[i]=new char[h];

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>input;
                A[i][j]=input[0];
            }
        }

        s = new Stack(h);
    }

    ~RectangleFinder(){
        for(int i=0; i<w; i++)
            delete []A[i];
        delete[] A;
    }

    int algorithm(){
        //tworzenie histogramu
        int histogram[h][w];
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                histogram[i][j]=0;
                int tempInd=i;
                if(A[i][j]=='0') continue;

                while(tempInd>=0){
                    if(A[tempInd][j]=='1'){
                        histogram[i][j]++;
                        tempInd--;
                    }
                    else break;
                }
            }
        }

        int maxArea=0,tempArea;

        //znajdywanie prostokata z uzyciem stosu
        int max_area,area_with_top;
        for(int i=0;i<h;i++){
        int j = 0; 
        while (j < w) 
        { 
            //jesli wysokosc slupka jest wieksza lub rowna poprzedniej to dodaj na stos
            if (s->empty() || histogram[i][j] > histogram[i][s->top()]){ 
                s->push(j); 
                j++;
            }
            else
            {
                //oznacz najwieksza wysokosc slupka i oblicz pole 
                int top = s->top();  
                s->pop();  
                tempArea = histogram[i][top] * (s->empty() ? j : j - s->top() - 1); 
                if(tempArea > maxArea) maxArea=tempArea; 
            } 
        } 
    
        while (!s->empty()) { 
            int top = s->top(); 
            s->pop(); 
            tempArea = histogram[i][top] * (s->empty() ? j : j - s->top() - 1);     
            if(tempArea > maxArea) maxArea=tempArea;
            }
        }
    return maxArea;
    }


    private:
    Stack *s;
    char **A;
    int w,h;
};

int main(int argc, char const *argv[])
{
    //rozmiary prostokata
    int width=0,height=0;

    cin>>input;
    width=std::stoi(input);
    cin>>input;
    height=std::stoi(input);

   RectangleFinder rf(width,height);
   cout<<"Pole najwiekszego prostokata wynosi "<<rf.algorithm()<<endl;

    return 0;
}

