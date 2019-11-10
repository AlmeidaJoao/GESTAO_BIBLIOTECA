//
// Created by nozotrox on 10/4/19.
//

#include "CD.h"

CD::CD(string titulo, string assunto, string editora, int ano, int cota,int duracao):  Documento(titulo, assunto, editora, ano, cota) {
    this->duracao =duracao;
    this->tipo = "CD";
}

void CD::setDuracao(int duracao)
{
  this->duracao = duracao;
}