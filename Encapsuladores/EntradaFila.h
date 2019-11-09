//
// Created by Feliciano Jr. Mazoio on 11/6/2019.
//

#ifndef GESTAO_BIBLIOTECA_ENTRADAFILA_H
#define GESTAO_BIBLIOTECA_ENTRADAFILA_H


#include "../Leitor.h"
class Leitor;

class EntradaFila {
public:
    int prioridade;
    Leitor *leitor;
    EntradaFila();
    EntradaFila(const EntradaFila &entradaFila);
    ~EntradaFila();



};


#endif //GESTAO_BIBLIOTECA_ENTRADAFILA_H
