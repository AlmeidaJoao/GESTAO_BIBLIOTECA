//
// Created by nozotrox on 10/4/19.
//

#ifndef GESTAO_BIBLIOTECA_DVD_H
#define GESTAO_BIBLIOTECA_DVD_H


#include "Documento.h"

class DVD: public Documento{
    int duracao; //::>> em segundos
public:
    DVD();
    ~DVD();
    int getDuracao();
    void setDuracao(int duracao);
};


#endif //GESTAO_BIBLIOTECA_DVD_H
