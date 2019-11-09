//
// Created by Feliciano Jr. Mazoio on 11/5/2019.
//

#ifndef GESTAO_BIBLIOTECA_ENTRADAAUTOR_H
#define GESTAO_BIBLIOTECA_ENTRADAAUTOR_H


#include "../Autor.h"

class EntradaAutor {
public:
    Autor* autor;
    EntradaAutor* proximoAutor;
    EntradaAutor();
    EntradaAutor(const EntradaAutor &enAut);
    ~EntradaAutor();
};


#endif //GESTAO_BIBLIOTECA_ENTRADAAUTOR_H
