//
// Created by Feliciano Jr. Mazoio on 11/6/2019.
//

#ifndef GESTAO_BIBLIOTECA_FILALEITOR_H
#define GESTAO_BIBLIOTECA_FILALEITOR_H




#define MAX_CAPACITY_LEITORES 20


class EntradaFila;
class Leitor;

class FilaLeitor {
private:
    int currentSize; // Tamanho da fila com prioridade
    EntradaFila* fila[MAX_CAPACITY_LEITORES] = {0};

public:
    FilaLeitor();
    FilaLeitor(const FilaLeitor &fila);
    ~FilaLeitor();
    bool isFull();
    bool inList(Leitor* leitor); // Verifica se o leitor esta na lista
    void inserirLeitor(Leitor* leitor); //Insercao do leitor
    Leitor* verPrimeiro();
    Leitor* removerPrimeiro(); //Remover o que tiver maior prioridade
    void percolarBaixo(int pos); //Borbulhar para baixo quando ocorre uma remocao;
    void toString();

};


#endif //GESTAO_BIBLIOTECA_FILALEITOR_H
