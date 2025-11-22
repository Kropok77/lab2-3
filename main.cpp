#include <iostream>
#include <cstdlib>
using namespace std;


// Структура данных динамических массивов
struct Dynarray{
    private:
    int n=0;
    float* mas=nullptr;
    int size=sizeof(float);
    void init(int n){
        mas=new float[n];
    }
    
    public:
    ~Dynarray() {
        if (mas != nullptr) {
            delete[] mas;
            mas = nullptr;  
        }
    }
        void deli(bool flag_chist){
            if (flag_chist){
                delete mas;
                mas=nullptr;
                n=0;
            }else{
                mas=nullptr;
                n=0;
            }
        }
        void NewMas(int bn=0,float nmas[]=nullptr, int razmnmas=0){// 1 входной аршумент инициализация функции 
            // 3 аргумента пересоздание массива с элементами другой
            //0 аргументов инициализация переменных
            init(bn);
            if (bn<razmnmas){
                cout<<"SYSERROR: mas1<mas2";
                exit(1);
            }
            if (nmas!=nullptr){
                for (int x=0;x<razmnmas;x++){
                    *(mas+x)=*(nmas+x);
                }
            }
            n=bn;
        }
        void ChangeValue(int pos,float ch){
            *(mas+pos)=ch;
        }
        float GetDat(int pos){
            if (pos>n){
                cout<<"SYSEXIT: Posnotinmas"<<endl;
                exit(2);
            }
            return *(mas+pos);
        }
        float* GetDat(){
            return mas;
        }
        int GetSize(){
            return n;
        }
        void Add(float ch){//функция добавления элемента в массив
            Dynarray newmas;
            newmas.NewMas(this->GetSize()+1,this->GetDat(),this->GetSize());
            newmas.ChangeValue(newmas.GetSize()-1,ch);
            cout<<newmas.GetDat(newmas.GetSize()-1)<<endl;
            //this->deli(true);
            this->NewMas(newmas.GetSize());
            for (int i=0;i<newmas.GetSize();i++){
                *(mas+i)=*(newmas.GetDat()+i);
            }
            //newmas.deli(true);
            //delete &newmas;

    }


};
int main(){
    Dynarray z;
    Dynarray b;
    b.NewMas(2);
    b.ChangeValue(0,15);
    b.ChangeValue(1,64);
    
    z.NewMas(3,b.GetDat(),b.GetSize());
    z.Add(1488);
    cout<<z.GetSize()<<endl;
    cout<<z.GetDat(2)<<endl;
}