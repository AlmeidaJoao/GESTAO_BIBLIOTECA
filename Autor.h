//
// Created by Feliciano Jr. Mazoio on 11/5/2019.
//

#ifndef GESTAO_BIBLIOTECA_AUTOR_H
#define GESTAO_BIBLIOTECA_AUTOR_H

#include "Encapsuladores/EntradaDoc.h"

class EntradaDoc;
class Autor {
    private:
        int size; //::>> Numero de livro que o autor possui
        string nome; //::>> Nome do autor
        EntradaDoc* rootDocumentos;//::>> Estrutura que vai permitir uma lista ligada de rootDocumentos elaborados pelo autor

    public :
        Autor(string nome);
        Autor(const Autor &autor); //::>> Construtor elaborado para evitar perda de dados
        ~Autor();
        string getNome();
        EntradaDoc* getDocumentos();
        void setNome(string nome);
        int getSize();
        void setDocumentos(Documento* documentos); //::>> Definir uma lista de rootDocumentos feito pelo autor
        void adicionarDocumentos(Documento* documento); //::> Adidionar documento a lista de documento do autor
        void toString(); // ::>> Imprimir dados do autor

};


#endif //GESTAO_BIBLIOTECA_AUTOR_H
