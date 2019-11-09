//
// Created by Feliciano Jr. Mazoio on 11/7/2019.
//

#ifndef GESTAO_BIBLIOTECA_ENTRADAEXEMPLAR_H
#define GESTAO_BIBLIOTECA_ENTRADAEXEMPLAR_H


#include "../Exemplar.h"

class EntradaExemplar {
public:
    Exemplar* exemplar;
    EntradaExemplar* proximoExemplar;
    EntradaExemplar();
    ~EntradaExemplar();
};


#endif //GESTAO_BIBLIOTECA_ENTRADAEXEMPLAR_H
