//
// Created by nozotrox on 10/4/19.
//

#ifndef GESTAO_BIBLIOTECA_EXEMPLARLIVRO_H
#define GESTAO_BIBLIOTECA_EXEMPLARLIVRO_H


#include "Exemplar.h"
#include "Leitor.h"

class Leitor;

class ExemplarLivro: public Exemplar {

private:
    Leitor* ultimoLeitor;

public:
    ExemplarLivro();
    ExemplarLivro(const ExemplarLivro &exemplarLivro);
    ~ExemplarLivro();
    Leitor* getUltimoLeitor();
    void setUtlimoLeitor(Leitor* leitor);

};


#endif //GESTAO_BIBLIOTECA_EXEMPLARLIVRO_H
