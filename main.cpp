#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
//6#define Otladka

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
                delete[] mas;
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
        float min(){
            float znachMin=pow(10,7);
            for (int i=0;i<n;i++){
                if (*(mas+i)<znachMin){
                    znachMin=*(mas+i);
                }
            }
            return znachMin;
        }
        float max(){
            float znachMax=-1*pow(10,7);
            for (int i=0;i<n;i++){
                if (*(mas+i)>znachMax){
                    znachMax=*(mas+i);
                }
            }
            return znachMax;
        }
        void Add(float ch){//функция добавления элемента в массив
            Dynarray newmas;
            newmas.NewMas(this->GetSize()+1,this->GetDat(),this->GetSize());
            newmas.ChangeValue(newmas.GetSize()-1,ch);
            //cout<<newmas.GetDat(newmas.GetSize()-1)<<endl;
            this->NewMas(newmas.GetSize());
            for (int i=0;i<newmas.GetSize();i++){
                *(mas+i)=*(newmas.GetDat()+i);
            }
        }
        void swap(int pos1,int pos2){
            float dopzn=*(mas+pos1);
            *(mas+pos1)=*(mas+pos2);
            *(mas+pos2)=dopzn;

        }
        void Delete(int pos){
            int k=0;
            Dynarray newmas;
            newmas.NewMas(this->GetSize(),this->GetDat(),this->GetSize());
            this->NewMas(newmas.GetSize()-1);
            for (int i=0;i<newmas.GetSize();i++){
                if (i==pos){
                    k=1;
                    continue;
                }
                *(mas+i-k)=*(newmas.GetDat()+i);
            }
        }
        float getsr(){
            float sr=0;
            for (int i=0;i<n;i++){
                sr=sr+*(mas+i);
            }
            return sr/n;
        }
        Dynarray filterAboveAverage(){
            Dynarray newmas;
            float sr=getsr();
            for(int i=0;i<n;i++){
                if (*(mas+i)>sr){
                    newmas.Add(*(mas+i));
                }
                
            }
            return newmas;

        }


};

int main(){
    int kolizm;
    cout<<"==Анализ сенсора=="<<endl;
    cout<<"Введите количество измерений: ";
    Dynarray bazadann;
    #ifdef Otladka
    bazadann.Add(10);
    bazadann.Add(15);
    bazadann.Add(8);
    bazadann.Add(-2);
    bazadann.Add(18);
    bazadann.Add(20);
    #endif
    #ifndef Otladka
    cin>>kolizm;
    cout<<endl;
    cout<<"Введите значения: ";
    
    float ch;
    for (int i=0;i<kolizm;i++){

        cin>>ch;
        bazadann.Add(ch);

    }
    #endif
    cout<<endl;
    cout<<"Среднее значение: "<<bazadann.getsr()<<endl;
    cout<<"Минимум: "<<bazadann.min()<<endl;
    cout<<"Максимум: "<<bazadann.max()<<endl;
    cout<<"Значения выше среднего"<<endl;
    Dynarray sr=bazadann.filterAboveAverage();
    #ifdef Otladka
    for (int i=0;i<bazadann.GetSize();i++){
        cout<<bazadann.GetDat(i)<<" ";
    }
    cout<<endl;
    #endif
    for (int i=0;i<sr.GetSize();i++){
        cout<<sr.GetDat(i)<<" ";
    }
}