//
// Created by nozotrox on 10/4/19.
//

#include <ctime>
#include "Leitor.h"

Leitor::Leitor() {
    nome = "#";
    numero_leitor = -1;
    categoria = "#";
    prioridade = -1;
    data_inscricao = "#";
    validade = -1;
    livrosLevados = -1;
    numero_leitor = 0;
    docEmConsulta = NULL;
}

Leitor::Leitor(string nome, string categoria, string data_inscricao, int validade) {
    srand(time(NULL));
    this->nome = nome;
    this->categoria = categoria;
    this->data_inscricao = data_inscricao;
    this->validade = validade;
    this->livrosLevados = 0;
    this->numero_leitor =  rand() % 1000 + 3000;
    // Definicao da prioridade
    if(categoria == "P"){
        prioridade = 1;
    } else if (categoria == "E"){
        prioridade = 2;
    } else if (categoria == "F"){
        prioridade = 3;
    } else {
        prioridade = 4;
    }
}

string Leitor::getNome() {
    return nome;
}

int Leitor::getNumeroLeitor() {
    return numero_leitor;
}

int Leitor::getLivrosLevados() {
    return livrosLevados;
}

string Leitor::getCategoria() {
    return categoria;
}

int Leitor::getPrioridade() {
    return prioridade;
}

string Leitor::getDataInscricao() {
    return data_inscricao;
}

int Leitor::getValidade() {
    return validade;
}

ExemplarLivro* Leitor::getExemplaresLivro() {
    return *livroEmprestado;
}

Documento* Leitor::getDocEmConsulta() {
    return docEmConsulta;
}

bool Leitor::levarLivro(ExemplarLivro *livro) {
    // caso  tenha esgotado o numero de livros levados
    if(livrosLevados == 3){
        return false;
    }
    // caso nao thenha esgotado o numero delivros emprestados
    livroEmprestado[livrosLevados] = livro;
    livrosLevados++;
    return true;
}

ExemplarLivro* Leitor::devolverLivro(int codigoExemplar) {
    ExemplarLivro* exemplarLivro;
    for(int i = 0; i < livrosLevados; i++){
        if(codigoExemplar == livroEmprestado[i]->getCodio()){
            exemplarLivro = livroEmprestado[i];
            livroEmprestado[i] == NULL; // remover o livro da lista do leitor
            livrosLevados--;
            return exemplarLivro;

        }
    }

    return NULL;
}


void Leitor::setNome(string nome) {
    this->nome = nome;
}

void Leitor::setNumeroLeitor(int numeroLeitor) {
    this->numero_leitor = numeroLeitor;
}

void Leitor::setCategoria(string categoria) {
    this->categoria = categoria;
}

void Leitor::setPrioridade(int prioridade) {
    this->prioridade = prioridade;
}

void Leitor::setDataInscricao(string dataInscricao) {
    this->data_inscricao = dataInscricao;
}

void Leitor::setValidade(int validade) {
    this->validade = validade;
}

void Leitor::setDocEmConsulta(Documento *docEmConsulta) {
    this->docEmConsulta = docEmConsulta;
}