//
// Created by nozotrox on 10/4/19.
//

#include "Exemplar.h"

//construtor sem parametros
Exemplar::Exemplar() {
    this->situacao = "x";
    this->estado = BOM;
    this->codigo = 0;
    this->documento = NULL;
}

//construtor padrao para a classe exemplar
Exemplar::Exemplar(bool situacao, Estado estado, int codigo, Documento *documento) {
    this->situacao = situacao;
    this->estado = estado;
    this->codigo = codigo;
    this->documento = documento;
}

Exemplar::Exemplar(const Exemplar &exmplar) {
    this->situacao = exmplar.situacao;
    this->estado = exmplar.estado;
    this->codigo = exmplar.codigo;
    this->documento = exmplar.documento;
}

Exemplar::~Exemplar() {
}


// Retorna o estado de conservacao
Estado Exemplar::getEstado() {
    return estado;
}

bool Exemplar::getSituacao() {
    return situacao;
}

int Exemplar::getCodio() {
    return codigo;
}

Documento* Exemplar::getDocumento() {
    return documento;
}

void Exemplar::setEstado(Estado estado) {
    this->estado = estado;
}

void Exemplar::setSituacao(bool situacao) {
    this->situacao = situacao;
}
