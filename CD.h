//
// Created by nozotrox on 10/4/19.
//

#ifndef GESTAO_BIBLIOTECA_CD_H
#define GESTAO_BIBLIOTECA_CD_H


#include "Documento.h"

class CD: public Documento{
private:
    int duracao; //::>> em segundos
public:
    CD(string titulo, string assunto, string editora, int ano, int cota,int duracao);
    ~CD();
    int getDuracao();
    void setDuracao(int duracao);

};


#endif //GESTAO_BIBLIOTECA_CD_H
