//
// Created by Feliciano Jr. Mazoio on 11/7/2019.
//

#include "PilhaExemplar.h"

PilhaExemplar::PilhaExemplar() {
    size = 0;
    cabeca = NULL;
}

PilhaExemplar::~PilhaExemplar() {
}

bool PilhaExemplar::isEmpty() {
    return size == 0;
}

void PilhaExemplar::enqueue(Exemplar *exemplar) {
    EntradaExemplar* entradaExemplar = new EntradaExemplar();
    entradaExemplar->exemplar = exemplar;
    if(isEmpty()){
        // Definir a cabeca da pilha
        cabeca = entradaExemplar;
    }else {
        // Adicionar o elemento a cabeca
        entradaExemplar->proximoExemplar = cabeca;
        cabeca = entradaExemplar;
    }
    size++;
}

Exemplar* PilhaExemplar::dequeue() {
    EntradaExemplar* exemplar = cabeca;
    Exemplar* exe = exemplar->exemplar;
    cabeca = exemplar->proximoExemplar;
    size--;
    return exe;
}