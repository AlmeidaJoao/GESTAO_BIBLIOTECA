//
// Created by nozotrox on 10/4/19.
//


#ifndef GESTAO_BIBLIOTECA_DOCUMENTO_H
#define  GESTAO_BIBLIOTECA_DOCUMENTO_H

#define MAX_CAPACITY_EXEMPLAR 10
#include <string>


using namespace std;

class Exemplar;
class FilaLeitor;
class Leitor;


class Documento {
protected:

    int codigo;
    string tipo; //::>> Controla o tipo de documento;
    string titulo;
    string assunto;
    int cota; //::>> Numero de exemplares que o documento possui
    string editora;
    Exemplar* exemplares[MAX_CAPACITY_EXEMPLAR] = {0}; //::>> lista que armazena todos os exemplares do documento
    int ano;


public:
    static int ultimoCodigo;
    Documento();
    Documento(string titulo, string assunto, string editora, int ano, int cota);
    Documento(string titulo, string assunto, string editora, int ano, int cota, string tipo);
    Documento(const Documento &doc);
    ~Documento();
    int getCodigo();
    string getTipo();
    string getTitulo();
    int getQtdExemp(); //::>> Retorna o numero de exemplares que o documento possui
    string getAssunto();
    int getCota(); //::>> Retorna o numero de expemplares que o documento possui
    string getEditora();
    Exemplar* getExemplares();
    void cederLivroConsulta(Leitor* leitor); // Ceder o livro para que o leitor consulte
    void retornarLivroConsulta(Leitor* leitor); // Rotornar o livro consultado
    int getAno();
    void setTitulo(string titulo);
    void setAssunto(string assuto);
    void setCota(int cota);
    void setEditora(string editora);
    void setAno(int ano);
    void criarExemplar(int cota);
    void toString();

};

#endif
