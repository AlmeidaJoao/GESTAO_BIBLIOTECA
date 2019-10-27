//
// Created by nozotrox on 10/4/19.
//
#include<string>


#ifndef GESTAO_BIBLIOTECA_LEITOR_H
#define GESTAO_BIBLIOTECA_LEITOR_H

#include "ExemplarLivro.h"


using namespace std;

class ExemplarLivro;

class Leitor {

private:
    string nome;
    int numero_leitor;
    string categoria;
    int prioridade;
    string data_inscricao;
    int validade;
    ExemplarLivro* livroEmprestado;
    Documento* docEmConsulta;

public:
    Leitor();
    Leitor(const Leitor &leitor);
    ~Leitor();
    string getNome();
    int getNumeroLeitor();
    string getCategoria();
    int getPrioridade();
    string getDataInscricao();
    int getValidade();
    ExemplarLivro* getExemplaresLivro();
    Documento* getDocEmConsulta();
    void setNode(string nome);
    void setNumberoLeitor(int numeroLeitor);
    void setCategoria(string categoria);
    void setPrioridade(int prioridade);
    void setDataInscricao(string dataInscricao);
    void setValidade(int validade);
    void seExemplaresLivro(ExemplarLivro* exemplares);
    void setDocEmConsulta(Documento* docEmConsulta);

};


#endif //GESTAO_BIBLIOTECA_LEITOR_H
