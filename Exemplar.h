//
// Created by nozotrox on 10/4/19.
//
#ifndef GESTAO_BIBLIOTECA_EXEMPLAR_H
#define GESTAO_BIBLIOTECA_EXEMPLAR_H


#include "Documento.h"

using namespace std;

class Documento;

// Enum que simboliza o estado de conservacao de um exemplar
enum Estado { BOM, MAU, MEDIO};

//Vai funcionar como a copia de um docuemtno
class Exemplar {

protected:
    bool situacao;// determina se esta emprestado ou livre
    Estado estado;// determina o estado de conservacao
    int codigo;
    Documento* documento; // referencia o documento a que pertence

public:
    Exemplar();
    Exemplar(bool situacao, Estado estado, int codigo, Documento* documento);
    Exemplar(const Exemplar &exmplar); // construtor de copia para evictar que perca informacao quando sair do escopo
    ~Exemplar();
    bool getSituacao();
    Estado getEstado();
    int getCodio();
    Documento* getDocumento();
    void setSituacao(bool situacao);
    void setEstado(Estado estado);
    void toString();
};


#endif //GESTAO_BIBLIOTECA_EXEMPLAR_H
