//
// Created by Feliciano Jr. Mazoio on 11/6/2019.
//

#include "EntradaFila.h"

EntradaFila::EntradaFila() {
    prioridade = -1;
    leitor = NULL;
}

EntradaFila::EntradaFila(const EntradaFila &entradaFila) {
    prioridade = entradaFila.prioridade;
    leitor = entradaFila.leitor;
}

EntradaFila::~EntradaFila() {}
