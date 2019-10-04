//
// Created by nozotrox on 10/4/19.
//
#import <iostream>
#import <string>
#include "Exemplar.h"
#include "Leitor.h"

#ifndef GESTAO_BIBLIOTECA_DOCUMENTO_H
#define GESTAO_BIBLIOTECA_DOCUMENTO_H

using namespace std;

class Documento {
protected:
    string titulo;
    string assunto;
    int cota;
    string editora;
    Exemplar* exemplares;
    int ano;
    Leitor* dominio; //::>> quem esta sob o dominio do livro

public:
    Documento();
    Documento(const Documento &doc);
    ~Documento();
    string getTitulo();
    string getAssunto();
    int getCota();
    string getEditora();
    Exemplar* getExemplar();
    int getAno();
    Leitor* getLeitor();
    void setTitulo(string titulo);
    void setAssunto(string assuto);
    void setCota(int cota);
    void setEditora(string editora);
    void setExemplar(Exemplar* exemplar[]);
    void setAno(int ano);
    void setDominio(Leitor* dominio[]);

};


#endif //GESTAO_BIBLIOTECA_DOCUMENTO_H
