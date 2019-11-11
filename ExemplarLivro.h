//
// Created by nozotrox on 10/4/19.
//

#ifndef GESTAO_BIBLIOTECA_EXEMPLARLIVRO_H
#define GESTAO_BIBLIOTECA_EXEMPLARLIVRO_H


#include "Exemplar.h"
#include "Livro.h"

class Leitor;

class ExemplarLivro: public Exemplar {

private:
    Leitor* ultimoLeitor;

public:
    ExemplarLivro();
    ExemplarLivro(bool situacao, Estado estado, int codigo, Livro *livro);
    ExemplarLivro(const ExemplarLivro &exemplarLivro);
    ~ExemplarLivro();
    Leitor* getUltimoLeitor();
    void setUtlimoLeitor(Leitor* leitor);
    void toString();

};


#endif //GESTAO_BIBLIOTECA_EXEMPLARLIVRO_H
