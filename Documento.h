//
// Created by nozotrox on 10/4/19.
//
#include "Exemplar.h"
#include "Leitor.h"

#ifndef GESTAO_BIBLIOTECA_DOCUMENTO_H
#define  GESTAO_BIBLIOTECA_DOCUMENTO_H

using namespace std;

class Documento {
protected:
    string titulo;
    string assunto;
    int cota; //::>> Numero de exemplares que o documento possui
    string editora;
    Exemplar* exemplares; //::>> lista que armazena todos os exemplares do documento
    int ano;


public:
    Documento(string titulo, string assunto, string editora, int ano, int cota);
    Documento(const Documento &doc);
    ~Documento();
    string getTitulo();
    string getAssunto();
    int getCota(); //::>> Retorna o numero de expemplares que o documento possui
    string getEditora();
    Exemplar* getExemplares();
    int getAno();
    void setTitulo(string titulo);
    void setAssunto(string assuto);
    void setCota(int cota);
    void setEditora(string editora);
    void setExemplares(Exemplar* exemplar);
    void setAno(int ano);
    void criarExemplar(int cota);
    void toString();

};

#endif
