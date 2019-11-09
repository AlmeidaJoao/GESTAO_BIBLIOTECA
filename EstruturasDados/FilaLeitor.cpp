//
// Created by Feliciano Jr. Mazoio on 11/6/2019.
//

#include <iostream>
#include "FilaLeitor.h"
#include "../Leitor.h"
#include "../Encapsuladores/EntradaFila.h"

FilaLeitor::FilaLeitor() {
    currentSize = 0;
}

FilaLeitor::FilaLeitor(const FilaLeitor &fila) {
    this->currentSize = fila.currentSize;
}


bool FilaLeitor::isFull() {
    return currentSize == MAX_CAPACITY_LEITORES;
}

bool FilaLeitor::inList(Leitor *leitor) {
    for(int i = 0; i < currentSize; i++){
        if(leitor->getNumeroLeitor() == fila[i]->leitor->getNumeroLeitor()){
            return true;
        }
    }
    return false;
}

void FilaLeitor::inserirLeitor(Leitor* leitor) {
    int key = leitor->getPrioridade(); // Funcionara como o avaliador da prioridade
    if(isFull()){
        //Imprimir mensagem
        return;
    }
    int hole = currentSize; // criar burraco
    int parent = (hole - 1) / 2; // encontrar o pai do burraco
    while(hole > 0 && key < fila[parent]->prioridade){ // borbulhar para cima
        fila[hole] = fila[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    EntradaFila* entradaFila = new EntradaFila(); entradaFila->leitor = leitor; entradaFila->prioridade = leitor->getPrioridade(); // criacao de uma nova entrada para a fila
    fila[hole] = entradaFila;
    currentSize++;
}

Leitor* FilaLeitor::verPrimeiro() {
    return fila[0]->leitor;;
}

Leitor* FilaLeitor::removerPrimeiro() {

    // guardar o valor do minimo
    Leitor* leitor = fila[0]->leitor;
    currentSize--;

    // trocar as posicoes do ultimo com o primeiro
    fila[0] = fila[currentSize];
    fila[currentSize] = NULL;
    //Borbulhar para baixo caso a fila permita ( se existir mais de um elemento na fila);
    if(currentSize > 1){
        percolarBaixo(0);
    }
    return leitor;

}

void FilaLeitor::percolarBaixo(int pos) {

    EntradaFila* entradaRaiz = fila[pos];
    int prioridadeRaiz = entradaRaiz->prioridade;

    int hole = pos; // Criar burraco
    int child = hole * 2 + 1;

    while(child < currentSize){
        // Encontrar o menor filho
        if( child < currentSize - 1  && fila[child+1]->prioridade < fila[child]->prioridade) child++;

        // Borbulhar para baixo
        if(fila[child]->prioridade < prioridadeRaiz){
            fila[hole] = fila[child];
            hole = child;
            child = hole * 2 + 1;
        } else {
            break;
        }

    }

    fila[hole] = entradaRaiz;
}

void FilaLeitor::toString() {
    cout << endl;
    cout << "=================" << endl;
    for(int i = 0; i < currentSize; i ++){
        cout << i << ". " << fila[i]->leitor->getNome() << "\n";
    }
    cout << "=================";
    cout << endl;
}