//
// Created by nozotrox on 10/4/19.
//

#ifndef GESTAO_BIBLIOTECA_DVD_H
#define GESTAO_BIBLIOTECA_DVD_H


#include "Documento.h"

class DVD: public Documento{
    int duracao; //::>> em segundos
public:
    DVD(string titulo, string assunto, string editora, int ano, int cota,int i);
    ~DVD();
    int getDuracao();
    void setDuracao(int duracao);
};


#endif //GESTAO_BIBLIOTECA_DVD_H
