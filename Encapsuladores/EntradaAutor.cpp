//
// Created by Feliciano Jr. Mazoio on 11/5/2019.
//

#include "EntradaAutor.h"

EntradaAutor::EntradaAutor() {
    autor = NULL;
    proximoAutor = NULL;
}

EntradaAutor::EntradaAutor(const EntradaAutor &enAut) {
    autor = enAut.autor;
    proximoAutor = enAut.proximoAutor;
}

EntradaAutor::~EntradaAutor() {}

