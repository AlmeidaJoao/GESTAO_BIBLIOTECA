//
// Created by Feliciano Jr. Mazoio on 11/2/2019.
//

#ifndef GESTAO_BIBLIOTECA_BIBLIOTECA_H
#define GESTAO_BIBLIOTECA_BIBLIOTECA_H


#include "Livro.h"
#include "Encapsuladores/EntradaDoc.h"
#include "Encapsuladores/EntradaAutor.h"
#include "Encapsuladores/EntradaLeitor.h"

#define MAX_CAPACITY 127

class Leitor;

class Biblioteca {

private:
    EntradaDoc* documentos[MAX_CAPACITY] = {0}; //::>> tabela de dispersao dedicada somente a livros | Esta inicializacao faz com que todos elementos do array sejam NULL
    EntradaDoc* livros[MAX_CAPACITY] = {0}; //::>> tabela de dispersao dedicada somente a livros | Esta inicializacao faz com que todos elementos do array sejam NULL
    EntradaAutor* autores[MAX_CAPACITY] = {0}; //::>> catalogo de autores em tabela de dispersão | Esta inicializacao faz com que todos elementos do array sejam NULL
    EntradaLeitor* leitores[MAX_CAPACITY] = {0}; //::>> catalogo para leitores que usaram a biblioteca pelo menos uma vez | Esta inicializacao faz com que todos elementos do array sejam NULL
    Livro* catalogoLivros;
    int size; //::>> Controla o numero de documentos que a biblioteca possui



public:
    Biblioteca();
    Biblioteca(const Biblioteca &biblioteca);
    ~Biblioteca();
   //::>> Lista que armazenara todos os rootDocumentos da Biblioteca

    int getSize(); //::>> Retorna o tamanho da lista
    //void inserirDocumento(Documento* documento); //::>> Insercao de qualquer tipo de documento

    void adicionarLivro(); //::>> Insercao de um livro atraves de um prompt
    void emprestarLivro(); //::>> Emprestiom de um livro atraves de um prompt
    void receberLivro(); //::>> Valida o leitor com um prompt atraves do seu nome
    void receberLivro(Leitor* leitor); //::>> Devolve um dos livros que levou emprestado atraves de um prompt
    void executarImpressoes(); //::>> Imprime dados relacionado a um determinado objecto
    void removerDocumento(); //::>> Remove o documento partindo do codigo;


    void inserirDocumento(EntradaDoc* newDoc, int hashCode); //::>> Inserir um documento, qualquer que seja
    void inserirDocumento(Documento* doc); //::>> Inserir um documento, qualquer que seja
    void inserirLivro(Livro* doc); //::>> Inserir especificamente um livro
    void inserirAutor(Autor* autor); //::>> Inserir o autor ao catalogo de autores
    void inserirLeitor(Leitor* leitor); //::>> Iserir o leitor ao catalog de leitores
    void guardarLivro(ExemplarLivro* exemplarLivro); //::>> Armazena na biblioteca o livro emprestado
    void imprimirTodosAutores();
    void imprimirTodosDocumentos();
    void removerDocumento(int hash, int codigo);
    void removerAutor(Autor* autor); // Remove o autor


    Livro* findDocumento(string titulo); //::>> Encontra o livro pretendito pelo titulo
    Autor* findAutor(string nome); //::>> Encontrar o autor no catalogo a partir do nome
    Leitor* findLeitor(string nome); //::>> Encontrar o leitor no catalogo a partir do nome
    int hash(string str); //::>> Funcao de dispersao
    bool isEmpty(); //::>> Verifica se esta vazio
    bool isFull(); //::>> Verifica se esta cheio

};


#endif //GESTAO_BIBLIOTECA_BIBLIOTECA_H
