//
// Created by soria on 23/04/2022.
//

#ifndef PRUEBA_ORDENA_H
#define PRUEBA_ORDENA_H


template<typename T>
void intercambia(T &a, T &b){
    T c=a;
    a=b;
    b=c;
}

template <typename  T>
void ordena (T* vector[],int tamv){
    for(int i=0;i<tamv-1;++i){
        for(int j=i+1;j<tamv;++j){
            if(*vector[i]< *vector[j]){
                intercambia(vector[i],vector[j]);
            }
        }
    }
}

#endif //PRUEBA_ORDENA_H
