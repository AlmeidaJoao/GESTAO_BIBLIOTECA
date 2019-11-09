//
// Created by nozotrox on 10/4/19.
//
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include "Documento.h"
#include "ExemplarLivro.h"


#define MAX_COTA_LIVRO 10
#define MAX_COTA_DOCUMENTO 1


Documento::Documento() {
    this->titulo = "#";
}
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
//    for(int i = 0; i < doc.cota; i++){
//        this->exemplares[i] = doc.exemplares[i];
//    }
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
    return *exemplares;
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


void Documento::setEditora(string editora) {
    this->editora = editora;
}
//==============================================



//================= HELPERS ======================================
//Metodo para criar exemplares automaticamente partindo da cota passada
void Documento::criarExemplar(int cota) {

    srand(time(NULL)); // inicializacao do numero random. E so feita uma vez
    int codigoDocumento; //codigo random para o exemplar

    if(cota == MAX_COTA_LIVRO){
        //::>> Criacao de exemplares de livro
        for(int i = 0; i < 3; i++){
            codigoDocumento = rand() % 1000 + 2000;
            //::>> Fazer dowcast para livro como o construtor faz o uso de livro
            ExemplarLivro* exemplar = new ExemplarLivro(false, BOM , codigoDocumento , static_cast<Livro *>(this));
            exemplares[i] = exemplar;
        }


    } else {
        //::>> Criacao de exemplares de outros rootDocumentos
        for(int i = 0; i < cota; i++){
            codigoDocumento = rand() % 1000 + 2000;
            Exemplar* exemplar = new Exemplar(false, BOM , codigoDocumento , this);
            exemplares[i] = exemplar;
        }

    }
}

void Documento::toString(){
    printf("%-65s %-115s %-50s %-10d %-10d \n", titulo.c_str(), assunto.c_str(), editora.c_str(), ano, cota);
}
//===========================================

