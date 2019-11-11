//
// Created by Feliciano Jr. Mazoio on 11/2/2019.
//

#ifndef GESTAO_BIBLIOTECA_BIBLIOTECA_H
#define GESTAO_BIBLIOTECA_BIBLIOTECA_H


#include "Livro.h"
#include "Encapsuladores/EntradaDoc.h"
#include "Encapsuladores/EntradaAutor.h"
#include "Encapsuladores/EntradaLeitor.h"
#include "EstruturasDados/PilhaExemplar.h"

#define MAX_CAPACITY 127

class Leitor;

class Biblioteca {

private:
    EntradaDoc* documentos[MAX_CAPACITY] = {0}; //::>> tabela de dispersao dedicada somente a livros | Esta inicializacao faz com que todos elementos do array sejam NULL
    EntradaDoc* livros[MAX_CAPACITY] = {0}; //::>> tabela de dispersao dedicada somente a livros | Esta inicializacao faz com que todos elementos do array sejam NULL
    EntradaAutor* autores[MAX_CAPACITY] = {0}; //::>> catalogo de autores em tabela de dispersão | Esta inicializacao faz com que todos elementos do array sejam NULL
    EntradaLeitor* leitores[MAX_CAPACITY] = {0}; //::>> catalogo para leitores que usaram a biblioteca pelo menos uma vez | Esta inicializacao faz com que todos elementos do array sejam NULL
    Livro* catalogoLivros;
    PilhaExemplar* pilhaExemplares; //::>> Pilha que vai receber os exemplares apos a devolucao
    int bookSize; //::>> Controla o tamanho dos livros que existem na biblioteca;
    int size; //::>> Controla o numero de documentos que a biblioteca possui;



public:
    Biblioteca();
    Biblioteca(const Biblioteca &biblioteca);
    ~Biblioteca();
   //::>> Lista que armazenara todos os rootDocumentos da Biblioteca

    int getSize(); //::>> Retorna o tamanho da lista
    //void inserirDocumento(Documento* documento); //::>> Insercao de qualquer tipo de documento

    void adicionarLivro(); //::>> Insercao de um livro atraves de um prompt
    void adicionarCD(); // Insercao de um CD
    void adicionarDVD(); //Insercao de um DVD
    void adicionarRevista(); //Insercao de uma revista
    void emprestarLivro(); //::>> Emprestiom de um livro atraves de um prompt
    void receberLivro(); //::>> Valida o leitor com um prompt atraves do seu nome
    void receberLivro(Leitor* leitor); //::>> Devolve um dos livros que levou emprestado atraves de um prompt
    void reporExemplares(); //::>> Devolve os exemplares para os respecitivos lugares, alterando informacoes sobre o estado e o ultimo leitor
    void executarImpressoes(); //::>> Imprime dados relacionado a um determinado objecto
    void removerDocumento(); //::>> Remove o documento partindo do codigo;
    void pesquisarDocumento(); //::>> Pesquisa o documento com um prompt que vai permitir que possa escolher se pretende fazer por codigo ou titulo
    void pesquisarAutor(); //::>> Pesquisa o autor atraves de um prompt pque resuqita o nome do autor
    void inserirDocumento(); //::>> insercao de um documento atraves de um submenu que permite escolher que tipo de documento
    void consultarDocumento(); //::>> Permite a consulta de um documento a partir de um prompt ao usuario
    void devolverDocConsulta(); //::>> Permite devolvoer um documento consultado
    void executarConsultas(); //::>> Permite escolher entre executar um consulta ou devolver um docuemnto consultado
    int validarCota(); //::>> Valida a cota que esta a ser inserida para um livro




    void inserirDocumento(EntradaDoc* newDoc, int hashCode); //::>> Inserir um documento, qualquer que seja
    void inserirDocumento(Documento* doc); //::>> Inserir um documento, qualquer que seja
    void inserirLivro(Livro* doc); //::>> Inserir especificamente um livro
    void inserirAutor(Autor* autor); //::>> Inserir o autor ao catalogo de autores
    void inserirLeitor(Leitor* leitor); //::>> Iserir o leitor ao catalog de leitores
    Leitor* inserirNovoLeitor(string nomeLeitor); //::>> Permite a insercao de um novo leitor a biblioteca
    void guardarLivro(ExemplarLivro* exemplarLivro); //::>> Armazena na biblioteca o livro emprestado
    void guardarLivroNaPilha(ExemplarLivro* exemplarLivro); //::>> Armazena  livro na pilha de devolucoes
    void imprimirTodosAutores();
    void imprimirTodosDocumentos();
    void imprimirTodosLivrosEmOrdem(int option);
    void removerDocumento(int hash, int codigo);
    void removerAutor(Autor* autor); // Remove o autor
    void consultarDocumento(Leitor* leitor, Documento* doc); // Ceder um documento para a consulta
    void devolverDocConsulta(Leitor* leitor); // Devolver o documento que estava a consultar


    Documento* findDocumento(int codigo); //::>>Encontra o documento atraves do codigo
    Documento* findDocumento(string titulo); //::>> Encontra o livro pretendito pelo titulo
    Autor* findAutor(string nome); //::>> Encontrar o autor no catalogo a partir do nome
    Leitor* findLeitor(string nome); //::>> Encontrar o leitor no catalogo a partir do nome
    int hash(string str); //::>> Funcao de dispersao
    bool isEmpty(); //::>> Verifica se esta vazio
    bool isFull(); //::>> Verifica se esta cheio

};


#endif //GESTAO_BIBLIOTECA_BIBLIOTECA_H
