//
// Created by Feliciano Jr. Mazoio on 11/6/2019.
//

#ifndef GESTAO_BIBLIOTECA_ENTRADALEITOR_H
#define GESTAO_BIBLIOTECA_ENTRADALEITOR_H


#include "../Leitor.h"

class EntradaLeitor {
public:
    Leitor* leitor;
    EntradaLeitor* proximoLeitor;
    EntradaLeitor();
    ~EntradaLeitor();
};


#endif //GESTAO_BIBLIOTECA_ENTRADALEITOR_H
