//
// Created by Feliciano Jr. Mazoio on 11/9/2019.
//

#include "FilaDocumento.h"

FilaDocumento::FilaDocumento() {
    size = 0;
}

FilaDocumento::FilaDocumento(const FilaDocumento &filaDocumento) {
    this->size = filaDocumento.size;
}

FilaDocumento::~FilaDocumento() {}

bool FilaDocumento::isFull() {
    return size == MAX_CAPACITY_DOCUMENTO;
}

void FilaDocumento::inserirDocumento(Documento *doc) {
    if(isFull()){
        //Imprimir mensagem
        return;
    }
    int hole = size; // criar burraco
    int parent = (hole - 1) / 2; // encontrar o pai do burraco
    bool isBigger = hole > 0 && doc->getTitulo() > fila[parent]->getTitulo();
    while(hole > 0 && !isBigger){ // borbulhar para cima
        fila[hole] = fila[parent];
        hole = parent;
        parent = (hole - 1) / 2;
        isBigger =  doc->getTitulo() >= fila[parent]->getTitulo();
    }
    fila[hole] = doc;
    size++;
}

void FilaDocumento::inserirDocumento(Documento *doc, int criterio) {
    if(isFull()){
        //Imprimir mensagem
        return;
    }
    int hole = size; // criar burraco
    int parent = (hole - 1) / 2; // encontrar o pai do burraco
    bool isBigger;
    if(criterio == 1){
        // Organizar por tema
        isBigger = hole > 0 && doc->getAssunto() > fila[parent]->getAssunto();
    } else {
        isBigger = hole > 0 && doc->getTitulo() > fila[parent]->getTitulo();
    }

    while(hole > 0 && !isBigger){ // borbulhar para cima
        fila[hole] = fila[parent];
        hole = parent;
        parent = (hole - 1) / 2;
        isBigger =  doc->getTitulo() >= fila[parent]->getTitulo();
    }
    fila[hole] = doc;
    size++;

}

void FilaDocumento::toString() {
    for(int i = 0; i < size; i++){
        fila[i]->toString();
    }
}