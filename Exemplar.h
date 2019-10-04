//
// Created by nozotrox on 10/4/19.
//
#include <iostream>
#include <string>



#ifndef GESTAO_BIBLIOTECA_EXEMPLAR_H
#define GESTAO_BIBLIOTECA_EXEMPLAR_H

#ifndef GESTAO_BIBLIOTECA_DOCUMENTO_H
#define GESTAO_BIBLIOTECA_DOCUMENTO_H


using namespace std;

class Documento;

class Exemplar {

protected:
    string situacao;
    string estado;
    int codigo;
    Documento* documento;

public:
    Exemplar();
    Exemplar(const Exemplar &exmplar);
    ~Exemplar();
    string getSituacao();
    string getEstado();
    int getCodio();
    Documento* getDocumento();
    void setSituacao(string situacao);
    void setEstado(string estado);
    void setCodigo(int codigo);
    void setDocumento(Documento* doc);
};

#endif
#endif //GESTAO_BIBLIOTECA_EXEMPLAR_H
