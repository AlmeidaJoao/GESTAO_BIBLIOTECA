//
// Created by Feliciano Jr. Mazoio on 11/7/2019.
//

#ifndef GESTAO_BIBLIOTECA_PILHAEXEMPLAR_H
#define GESTAO_BIBLIOTECA_PILHAEXEMPLAR_H


#include "../Encapsuladores/EntradaExemplar.h"

class PilhaExemplar {
private:
    EntradaExemplar* cabeca;
    int size;

public:
    PilhaExemplar();
    ~PilhaExemplar();
    bool isEmpty();
    void enqueue(Exemplar* exemplar);
    Exemplar dequeue();

};


#endif //GESTAO_BIBLIOTECA_PILHAEXEMPLAR_H
