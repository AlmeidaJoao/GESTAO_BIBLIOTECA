//
// Created by nozotrox on 10/4/19.
//
#include <string>
#include "Documento.h"

#ifndef GESTAO_BIBLIOTECA_AUTOR_H
#define GESTAO_BIBLIOTECA_AUTOR_H


using namespace std;

class Autor {
private:
    string nome;
    Documento* documentos;

public :
    Autor();
    Autor(const Autor &autor);
    ~Autor();
    string getNome();
    Documento* getDocumentos();
    void setNome(string nome);
    void setDocumentos(Documento* documentos);

};


#endif //GESTAO_BIBLIOTECA_AUTOR_H
