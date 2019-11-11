//
// Created by nozotrox on 10/4/19.
//

#ifndef GESTAO_BIBLIOTECA_LIVRO_H
#define GESTAO_BIBLIOTECA_LIVRO_H
#define MAX_CAPACITY_LEITOR 9

#include "Documento.h"
#include "Autor.h"

class Leitor;

class ExemplarLivro;

class Livro: public Documento {

private:
    string ISBN;
    Autor* autor; //::>> Autor sera definido depois da criacao do livro
    int nPaginas;
    Leitor* dominioEmprestimo;
    int exemplarDisp; //::>> Controla se o livro tem exemplares disponiveis
    int nLeitoresEpera;
    ExemplarLivro* exemplaresLivro[MAX_CAPACITY_LEITOR + 1] = {0}; //::>> Inicializa com variavies NULL
    FilaLeitor* leitores; //::>> Inicializa com variaveis NULL


public:
    Livro(string titulo, string assunto, string editora, int ano, int cota, string ISBN, int nPaginas);
    Livro(const Livro &livro);
    ~Livro();
    string getISBN();
    Autor* getAutor();
    int getNPaginas();
    Leitor* getDominioEmprestimo();
    ExemplarLivro* getExemplaresLivro();
    bool isAvailable(); //::>> Verifica se algum exemplar esta disponivel
    bool areWaiting(); //::>> Verifica se a lista de espera contem algum elemento;
    void cederLivro(Leitor* leitor); //::>> Verifica a possibilidade de entregar o livro ao leitor
    void emprestarLivro(Leitor* leitor); //::>> Cede o livro ao leitor
    void receberExemplar(ExemplarLivro* exemplarLivro); //::>> Recebe o livro do leitor e guarda na usa fila de exemplares
    void setISBN(string isbn);
    void setAutor(Autor* autor);
    void adicionarAListaDeEspera(Leitor* leitor);
    void setDominioEmprestimo(Leitor dominioEmprestimo[]);
    void setExemplaresLivro(ExemplarLivro exemplaresLivro[]);
    void toString();
};


#endif //GESTAO_BIBLIOTECA_LIVRO_H
