//
// Created by nozotrox on 10/4/19.
//

#include "DVD.h"
DVD::DVD(string titulo, string assunto, string editora, int ano, int cota,int duracao) :  Documento(titulo, assunto, editora, ano, cota)  {
    this->duracao = duracao;
    this->tipo = "DVD";
}

void DVD::setDuracao(int duracao)
{
    this->duracao = duracao;
}