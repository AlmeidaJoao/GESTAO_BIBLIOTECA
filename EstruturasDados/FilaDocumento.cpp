//
// Created by Feliciano Jr. Mazoio on 11/9/2019.
//

#include "FilaDocumento.h"
#include "../Livro.h"

FilaDocumento::FilaDocumento() {
    size = 0;
    criterio = 0;
}

FilaDocumento::FilaDocumento(const FilaDocumento &filaDocumento) {
    this->size = filaDocumento.size;
    this->criterio = filaDocumento.criterio;
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


Documento* FilaDocumento::removerMinimo() {
    Documento* doc = fila[0];
    size--;

    // trocar as posicoes do ultimo com o primeiro
    fila[0] = fila[size];
    fila[size] = NULL;
    //Borbulhar para baixo caso a fila permita ( se existir mais de um elemento na fila);
    if(size > 1){
        percolarBaixo(0);
    }
    return doc;
}

void FilaDocumento::percolarBaixo(int pos) {
    Documento* raiz = fila[pos];
    string prioridadeRaiz = (criterio == 1)? raiz->getAssunto() : raiz->getTitulo();
    bool isBigger;

    int hole = pos; // Criar burraco
    int child = hole * 2 + 1;

    while(child < size){
        // Encontrar o menor filho
        if(fila[child+1] != NULL){
            isBigger = (criterio == 1)? fila[child+1]->getAssunto() > fila[child]->getAssunto() : fila[child+1]->getTitulo() > fila[child]->getTitulo();
        } else {
            isBigger = true; // para se negado por baixo;
        }

        if( child < size - 1  && !isBigger) child++; //aqui

        // Borbulhar para baixo
        isBigger = (criterio == 1)? fila[child]->getAssunto() > prioridadeRaiz : fila[child]->getTitulo() > prioridadeRaiz;
        if(!isBigger){
            fila[hole] = fila[child];
            hole = child;
            child = hole * 2 + 1;
        } else {
            break;
        }

    }
    fila[hole] = raiz;
}

void FilaDocumento::toString() {
    int copySize = size; // O size ira reduzir ao remover os documetnos
    Documento* doc = NULL;
    for(int i = 0; i < copySize; i++){
        doc = removerMinimo();
        if(doc->getTipo() == "Livro" && criterio != 0){ //::>> Caso tenha escolhido um criterio. Criterio 0 significa que nao escolheu algum
            static_cast<Livro*>(doc)->toString();
        }else {
            doc->toString();
        }

    }
}