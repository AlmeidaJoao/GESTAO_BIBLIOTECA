//
// Created by Feliciano Jr. Mazoio on 11/9/2019.
//

#ifndef GESTAO_BIBLIOTECA_FILADOCUMENTO_H
#define GESTAO_BIBLIOTECA_FILADOCUMENTO_H
#define MAX_CAPACITY_DOCUMENTO 20

#include "../Documento.h"

//:::>> PROPOSITO DA CLASSE E APRESENTAR OS LIVROS DOS AUTORES EM ORDEM!
class FilaDocumento {
private:
    int size;
    int criterio;
    Documento* fila[MAX_CAPACITY_DOCUMENTO] = {0};


public:
    FilaDocumento();
    FilaDocumento(const FilaDocumento & filaDocumento);
    ~FilaDocumento();
    bool isFull();
    void inserirDocumento(Documento* doc); // Metodo de insercao que adiciona o documento por titulo
    void inserirDocumento(Documento* doc, int criterio); // Adiciona o documento por criterio | 2. titulo, 1. Tema|Assunto, Default: titulo
    void percolarBaixo(int pos);
    Documento* removerMinimo();
    void toString();
};


#endif //GESTAO_BIBLIOTECA_FILADOCUMENTO_H
