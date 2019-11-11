//
// Created by nozotrox on 10/4/19.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Leitor.h"
#include "Documento.h"
#include "ExemplarLivro.h"


#define MAX_COTA_LIVRO 10
#define MAX_COTA_DOCUMENTO 1

int Documento::ultimoCodigo = 2001;

Documento::Documento() {
    this->titulo = "#";
    this->codigo = 0;
}
//Contrutor base do documetno
Documento::Documento(string titulo, string assunto, string editora, int ano, int cota) {
    // Gerar um codigo unico
    // inicializacao do numero random. E so feita uma

    this->codigo = ultimoCodigo++;
    this->titulo = titulo;
    this->assunto = assunto;
    this->editora = editora;
    this->ano = ano;
    this->cota = cota;
    criarExemplar(cota);
}

Documento::Documento(string titulo, string assunto, string editora, int ano, int cota, string tipo) {
    // Gerar um codigo unico
    // inicializacao do numero random. E so feita uma

    this->codigo = ultimoCodigo++;
    this->titulo = titulo;
    this->assunto = assunto;
    this->editora = editora;
    this->ano = ano;
    this->cota = cota;
    this->tipo = tipo;
    criarExemplar(cota);
}


//Copy constructor para evictar com que os dados do objecto sejam perdidos quando mudarem de escopo
Documento::Documento(const Documento &doc) {
    this->codigo = doc.codigo;
    this->titulo = doc.titulo;
    this->assunto = doc.assunto;
    this->editora = doc.editora;
    this->ano = doc.ano;
    this->cota = doc.cota;

}

//================ GETTERS ==============================
Documento::~Documento() {}

int Documento::getCodigo() {
    return codigo;
}

string Documento::getTitulo() {
    return  titulo;
}

string Documento::getTipo() {
    return tipo;
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
int Documento::getQtdExemp() {
    int qtd = 0;
    for(int i = 0; i < MAX_CAPACITY_EXEMPLAR; i++){
        Exemplar* ex = exemplares[i];
        if(ex) qtd++;
    }
    return qtd;
}

//Metodo para criar exemplares automaticamente partindo da cota passada
void Documento::criarExemplar(int cota) {

    srand(time(NULL)); // inicializacao do numero random. E so feita uma vez
    int codigoDocumento; //codigo random para o exemplar

    if(tipo == "Livro"){
        //::>> Criacao de exemplares de livro
        for(int i = 0; i < cota; i++){
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

void Documento::cederLivroConsulta(Leitor *leitor) {
    Exemplar* exemplar = exemplares[cota - 1];
    leitor->setDocEmConsulta(exemplar);
    exemplares[cota-1] = NULL;
    cota--;
}

void Documento::retornarLivroConsulta(Leitor *leitor) {
    exemplares[cota] = leitor->getDocEmConsulta();
    leitor->setDocEmConsulta(NULL);
    cota++;
}


void Documento::toString(){
    string tit = titulo;
    string edit = editora;
    if(titulo.length() >= 20){
        tit = titulo.substr(0, 17) + "...";
    }

    if(editora.length() >= 20){
        edit = editora.substr(0, 17) + "...";
    }
    printf("%-20d %-25s %-25s %-15d %10s\n", getCodigo(), tit.c_str(), edit.c_str(), getQtdExemp(), getTipo().c_str());
}
//===========================================

