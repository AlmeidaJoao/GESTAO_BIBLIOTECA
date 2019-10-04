//
// Created by nozotrox on 10/4/19.
//

#ifndef GESTAO_BIBLIOTECA_LIVRO_H
#define GESTAO_BIBLIOTECA_LIVRO_H


#include "Documento.h"
#include "Autor.h"
#include "ExemplarLivro.h"

class Livro: public Documento {
private:
    string ISBN;
    Autor* autor;
    int nPaginas;
    Leitor* dominioEmprestimo;
    ExemplarLivro* exemplaresLivro;

public:
    Livro();
    Livro(const Livro &livro);
    ~Livro();
    string getISBN();
    Autor* getAutor();
    int getNPaginas();
    Leitor* getDominioEmprestimo();
    ExemplarLivro* getExemplaresLivro();
    void setISBN(string isbn);
    void setAutor(Autor* autor);
    void setDominioEmprestimo(Leitor* dominioEmprestimo[]);
    void setExemplaresLivro(ExemplarLivro* exemplaresLivro[]);
};


#endif //GESTAO_BIBLIOTECA_LIVRO_H
