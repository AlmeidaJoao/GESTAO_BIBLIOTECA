//
// Created by Feliciano Jr. Mazoio on 11/5/2019.
//

#include "Autor.h"

Autor::Autor(string nome) {
    this->nome = nome;
    this->size = 0;
    this->rootDocumentos = new EntradaDoc();
}

Autor::Autor(const Autor &autor) {
    this->nome = autor.nome;
    this->rootDocumentos = autor.rootDocumentos;
    this->size = autor.size;
}

Autor::~Autor() {}


string Autor::getNome() {
    return this->nome;
}

int Autor::getSize() {
    return size;
}

EntradaDoc* Autor::getDocumentos() {
    return this->rootDocumentos;
}

void Autor::adicionarDocumentos(Documento *documento) {
    if(size == 0){
        // Insercao da raiz
        rootDocumentos->documento = documento;
    } else {
        //::>> A insercao e feita no inicio da lista ligada
        EntradaDoc* docNode = new EntradaDoc();
        docNode->documento = documento;
        docNode->proximoDocumento = rootDocumentos;
        rootDocumentos = docNode;
    }
    size++;
}

void Autor::removerDocumento(Documento *documento) {

    //:: Pegar o codigo do documento
    int codigo = documento->getCodigo();
    EntradaDoc* entradaDoc = rootDocumentos;
    EntradaDoc* prevDoc = NULL;
    for(int i = 0; i < size; i++){
        if(entradaDoc->documento->getCodigo() == codigo) break;
        prevDoc = entradaDoc;
        entradaDoc = entradaDoc->proximoDocumento;
    }

    if(prevDoc == NULL){
        //::>> Primeiro na lista
        rootDocumentos = entradaDoc->proximoDocumento;
    } else {
        //::>> No meio ou fim da lista
        prevDoc = entradaDoc->proximoDocumento;
    }
    delete(entradaDoc->documento);
    delete(entradaDoc);
    size--;
}

void Autor::toString() {
    printf("%-20s %-20d\n", nome.c_str(), size);
}