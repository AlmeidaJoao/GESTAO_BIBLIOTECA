//
// Created by nozotrox on 10/4/19.
//

#include <iostream>
#include "Livro.h"
#include "Leitor.h"
#include "ExemplarLivro.h"
#include "EstruturasDados/FilaLeitor.h"

class Autor;

Livro::Livro(string titulo, string assunto, string editora, int ano, int cota, string ISBN, int nPaginas) :  Documento(titulo, assunto, editora, ano, cota)  {
    this->ISBN = ISBN;
    this->nPaginas = nPaginas;
    this->autor = NULL;
    this->nLeitoresEpera = 0;
    this->leitores = new FilaLeitor();
    this->exemplarDisp = 2;
    this->tipo = "Livro";
}

Livro::Livro(const Livro &livro) : Documento(livro) {
    this->ISBN = livro.ISBN;
    this->nPaginas = livro.nPaginas;
    this->autor = livro.autor;
    this->dominioEmprestimo = livro.dominioEmprestimo;
    this->autor = livro. autor;
    this->leitores = livro.leitores;
    this->exemplarDisp = livro.exemplarDisp;
}

Livro::~Livro() {}

string Livro::getISBN() {
    return ISBN;
}

Autor* Livro::getAutor(){
    return autor;
}

ExemplarLivro* Livro::getExemplaresLivro() {
    return *exemplaresLivro;
}

bool Livro::isAvailable() {
    return exemplarDisp > 0;
}

bool Livro::areWaiting(){
    return nLeitoresEpera > 0;
}

void Livro::emprestarLivro(Leitor *leitor) {
    ExemplarLivro* exemplar = static_cast<ExemplarLivro* >(exemplares[exemplarDisp]);
    bool levou = leitor->levarLivro(exemplar);
    if(levou){
        // levou o livro com sucesso
        cout << "::: Livro Emprestado!";
        // Definir o utlimo leitor do livro
        exemplar->setUtlimoLeitor(leitor);
        // Remover o exemplar da lista dos diponiveis
        exemplares[exemplarDisp] = NULL;
        exemplarDisp--;
        // Caso o leitor exista na lista de espera, remove-se ele de la
        if(leitores->inList(leitor)){
            leitores->removerPrimeiro();
        }
    } else {
        // esgotou a quantidade de livros que deveria levar
        cout << "::: Esgotou a quantidade de livros que deve levar emprestado. Devolva os livros para que possa levar mais emprestado." << endl;
    }
}

void Livro::receberExemplar(ExemplarLivro *exemplarLivro) {
    exemplarDisp++;
    exemplares[exemplarDisp] = exemplarLivro;
}

void Livro::cederLivro(Leitor* leitor) {
    // Verificar se existe um exemplar disponivel
    if(isAvailable()){
        // Verificar se existe alguem na lista de espera
        if(areWaiting()){
            // Verificar se resta livro para os que estao na lista de espera
            bool seResta = (exemplarDisp - nLeitoresEpera) > 0;
            if(seResta){
                emprestarLivro(leitor);
            } else {
                // Verificar se o leitor e o que esta no topo da lista de espera
                int codPrimeiro = leitores->verPrimeiro()->getNumeroLeitor();
                if(leitor->getNumeroLeitor() == codPrimeiro){
                    emprestarLivro(leitor);
                    return;
                }

                // Caso contrario devera esperar ou ficara na lista de espera
                cout << "::: Livro nao esta disponivel. Sera adicionado a lista de espera. " << endl;


                if(!leitores->inList(leitor)){
                    // Leitor nao estava na lista de espera e devera ser adicionado
                    leitores->inserirLeitor(leitor);
                    nLeitoresEpera++;
                    // Imprimir lista de espera
                }
                leitores->toString();
            }
        } else {
            // Se nao existem leitores na lista de espera
            emprestarLivro(leitor);
        }
    } else {
        // Livro nao esta disponivel: Adicionar a lista de espera
        cout << "::: Livro nao esta disponivel. Sera adicionado a lista de espera. " << endl;
        // Adicionar a lista de espera
        if(!leitores->inList(leitor)){
            leitores->inserirLeitor(leitor);
            nLeitoresEpera++;
        }
        // Imprimir lista de espera
        leitores->toString();

    }
}


void Livro::setISBN(string isbn) {
    ISBN = isbn;
}

void Livro::setAutor(Autor *autor) {
    this->autor = autor;
    autor->adicionarDocumentos(this);
}

void Livro::setDominioEmprestimo(Leitor *dominioEmprestimo) {
    dominioEmprestimo = dominioEmprestimo;
}

void Livro::setExemplaresLivro(ExemplarLivro *exemplaresLivro) {
    exemplaresLivro = exemplaresLivro;
}

void Livro::toString() {
    string autor = (this->autor == NULL)? "---" : this->autor->getNome();
    printf(" Titulo: %s\n Autor: %s\n Assunto: %s \n Editora: %s \n Ano: %d \n Cota: %d \n ISBN: %-10s \n Paginas:%d \n =============================== \n", titulo.c_str(), autor.c_str(),  assunto.c_str(), editora.c_str(), ano, cota, ISBN.c_str(),nPaginas);
}