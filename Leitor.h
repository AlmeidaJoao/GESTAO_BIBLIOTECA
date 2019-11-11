//
// Created by nozotrox on 10/4/19.
//
#include<string>


#ifndef GESTAO_BIBLIOTECA_LEITOR_H
#define GESTAO_BIBLIOTECA_LEITOR_H

#include "ExemplarLivro.h"
#define MAX_LIVROS_EMPRESTADOS 3


using namespace std;

class ExemplarLivro;
class Documento;
class FilaLeitor;

class Leitor {

private:
    string nome;
    int numero_leitor;
    string categoria;
    int prioridade;
    string data_inscricao;
    int validade;
    int livrosLevados; //Controla o numero de livros levados em emprestimo
    ExemplarLivro* livroEmprestado[MAX_LIVROS_EMPRESTADOS] = {0}; //Lista que armazena os livros emprestados pelo leitor
    Exemplar* docEmConsulta;


public:
    Leitor();
    Leitor(string nome, string categoria, string data_inscricao, int validade);
    Leitor(const Leitor &leitor);
    ~Leitor();
    string getNome();
    int getNumeroLeitor();
    string getCategoria();
    int getLivrosLevados();
    int getPrioridade();
    string getDataInscricao();
    int getValidade();
    ExemplarLivro* getExemplaresLivro();
    Exemplar* getDocEmConsulta();
    bool levarLivro(ExemplarLivro* livro);
    ExemplarLivro* devolverLivro(int codigoExemplar);
    void setNome(string nome);
    void setNumeroLeitor(int numeroLeitor);
    void setCategoria(string categoria);
    void setPrioridade(int prioridade);
    void setDataInscricao(string dataInscricao);
    void setValidade(int validade);
    void setDocEmConsulta(Exemplar* docEmConsulta);

};


#endif //GESTAO_BIBLIOTECA_LEITOR_H
