//
// Created by nozotrox on 10/4/19.
//
#include <stdlib.h>
#include <stdio.h>
#include "Documento.h"


//Contrutor base do documetno
Documento::Documento(string titulo, string assunto, string editora, int ano, int cota) {
    this->titulo = titulo;
    this->assunto = assunto;
    this->editora = editora;
    this->ano = ano;
    this->cota = cota;
    criarExemplar(cota);
}


//Copy constructor para evictar com que os dados do objecto sejam perdidos quando mudarem de escopo
Documento::Documento(const Documento &doc) {
    this->titulo = doc.titulo;
    this->assunto = doc.assunto;
    this->editora = doc.editora;
    this->ano = doc.ano;
    this->cota = doc.cota;

}

//================ GETTERS ==============================
Documento::~Documento() {}


string Documento::getTitulo() {
    return  titulo;
}

string Documento::getAssunto() {
    return assunto;
}

string Documento::getEditora() {
    return editora;
}

int Documento::getAno(){
    return ano;
}

int Documento::getCota(){
    return cota;
}

Exemplar* Documento::getExemplares() {
    return exemplares;
}
//==============================================


//=============== SETTERS =====================
void Documento::setAssunto(string assuto) {
    this->assunto = assuto;
}

void Documento::setTitulo(string titulo) {
    this->titulo = titulo;
}

void Documento::setCota(int cota) {
    this->cota = cota;
}

void Documento::setExemplares(Exemplar *exemplar) {
    this->exemplares = exemplar;
}

void Documento::setEditora(string editora) {
    this->editora = editora;
}
//==============================================



//================= HELPERS ======================================
//Metodo para criar exemplares automaticamente partindo da cota passada
void Documento::criarExemplar(int cota) {

    srand(time(NULL)); // inicializacao do numero random. E so feita uma vez
    Exemplar* exemplares[cota]; //lista de todos exemplares do cocumetno
    int codigoLivro; //codigo random para o exemplar

    for(int i = 0; i < cota; i++){
        codigoLivro = rand() % 1000 + 2000;
        Exemplar* exemplar = new Exemplar(false, BOM , codigoLivro , this);
        exemplares[i] = exemplar;
    }

    // Armazenar a lista de exemplars no documento
    this->exemplares = *exemplares;
}

void Documento::toString(){
    printf("%-65s %-115s %-50s %-10d %-10d \n", titulo.c_str(), assunto.c_str(), editora.c_str(), ano, cota);
}
//===========================================

