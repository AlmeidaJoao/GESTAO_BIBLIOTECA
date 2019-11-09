//
// Created by Feliciano Jr. Mazoio on 11/2/2019.
//


#include <algorithm>
#include <iostream>
#include "Biblioteca.h"

Biblioteca::Biblioteca() {
    size = 0;
    catalogoLivros = NULL;
}

Biblioteca::Biblioteca(const Biblioteca &biblioteca) {
    size = biblioteca.size;
    catalogoLivros = biblioteca.catalogoLivros;
}

Biblioteca::~Biblioteca() {}

//==================================== GETTERS E SETTERS ======================================
int Biblioteca::getSize() {
    return size;
}

bool Biblioteca::isEmpty() {
    return size == 0;
}

bool Biblioteca::isFull() {
    return size == MAX_CAPACITY;
}
//=============================================================================================



//===================================== METODOS COM PROMPT ====================================
void Biblioteca::removerDocumento() {
    string titulo;
    int opcao;
    cout << "=================================================" << endl;
    imprimirTodosDocumentos();
    cout << "=================================================" << endl;
    cout << endl << endl;
    cout << "Titulo documento: ";
    getline(cin, titulo);
    Documento* documento = findDocumento(titulo);
    if(documento != NULL){
        cout << "=======================\n";
        documento->toString();
        cout << "\n=======================\n";
        cout << "Remover? (1.sim, 0.nao): ";
        cin >> opcao;
        if(opcao == 1){
            int hashCode = this->hash(documento->getTitulo());
            removerDocumento(hashCode, documento->getCodigo());
        }
    } else {
        cout << ":::: DOCUMENTO NAO EXISTENTE :::::";
    }


}

void Biblioteca::adicionarLivro() {
    string titulo, assunto, editora, ISBN, nome_autor;
    int ano, cota,  nPaginas;

    cout << "Titulo:  ";
    getline(cin, titulo);
    cout << "Assunto: ";
    getline(cin, assunto);
    cout << "Editora: ";
    getline(cin, editora);
    cout << "ISBN: ";
    getline(cin, ISBN);
    cout << "Cota: ";
    cin >> cota;
    cin.ignore();
    cout << "Autor: ";
    getline(cin, nome_autor);

    //Validacao
    if(cota > 10 || cota < 0){
        cout << "::>>Cota deve ser menor que 10!\n\n";
        return;
    }

    printf("=================\n\nTitulo:%s \n Assunto:%s \n Editora:%s \n ISBN: %s \n Autor:%s\n===============\n\n", titulo.c_str(), assunto.c_str(), editora.c_str(), ISBN.c_str(), nome_autor.c_str());

    // Verificar a existencia de um autor partindo do seu nome
    Autor* autor = findAutor(nome_autor);

    if(autor == NULL){
        //Criacao de um novo autor
        autor = new Autor(nome_autor);
        //Inserir o autor no catalogo
        inserirAutor(autor);
    }
    //Criacao do livro
    Livro* livro = new Livro(titulo, assunto, editora, ano, cota, ISBN, nPaginas);
    livro->setAutor(autor);
    //Inserir o livro na biblioteca
    inserirLivro(livro);
    //Reacionar o autor ao livro
    autor->adicionarDocumentos(livro);


    cout << "Livro Inserido!" << endl;

}

void Biblioteca::emprestarLivro() {
    string nomeLeitor;
    string tituloLivro;
    string opcao;
    int opcao2;
    cout << endl;
    cout << "Nome: ";
    getline(cin, nomeLeitor);
    // Verificar a exitencia do letior no catalogo
    Leitor* leitor = findLeitor(nomeLeitor);
    // Caso nao exista, criar uma nova entrada para o leitor
    if(leitor == NULL){
        cout << ":: Novo Leitor. Escolha a sua categoria atraves da letra!" << endl;
        printf("i.%s   ii.%s   iii.%s   iv.%s", "Professor (P)", "Estudante (E)", "Funcionario (F)", "Outors(O)\n");
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore();
        cout << endl;
        // Criacao do novo leitor e adicionar ao catalogo
        leitor = new Leitor(nomeLeitor, opcao, "HOje", 100);
        inserirLeitor(leitor);
    }
    cout << "Titulo: ";
    getline(cin, tituloLivro);
    Livro* livro = findDocumento(tituloLivro);
    // Caso tenha encontrado o livro
    if(livro != NULL){
        // imprimir dados do livro
        livro->toString();
        cout << "Confirma? (1.Sim/0.Nao): ";
        cin >> opcao2;
        cin.ignore();

        // confirma o livro e o leva emprestado
        if(opcao2 == 1){
            livro->cederLivro(leitor);
            return;
        } else {
            // nao confirma o livro e deve procurar novamente ou sair
            livro == NULL;
        }
    } else {
        cout << "::Livro nao existente!";
    }

}

void Biblioteca::receberLivro() {
    string nome;
    cout << "Nome: ";
    getline(cin, nome);
    Leitor* leitor = findLeitor(nome);
    //::>> Caso encontre o leitor
    if(leitor != NULL){
        receberLivro(leitor);
        return;
    }
    cout << "!!!!!!!!!!!!! NENHUM LEITOR COM O NOME ECONTRADO !!!!!!!!!!!!!!!!";
}

void Biblioteca::receberLivro(Leitor *leitor) {

    if(leitor->getLivrosLevados() == 0){
        // leitor nao possui algum livro na sua lista
        cout << "!!!!!!!! NAO LEVOU EMPRESTADO ALGUM LIVRO !!!!!!!!!!!!";
        cout << endl;
        return;
    }

    int opcao;
    cout << "===========LIVROS==============" << endl << endl;
    for(int i = 0; i < leitor->getLivrosLevados(); i++){
        cout << (i+1) << ". " << leitor->getExemplaresLivro()[i].getDocumento()->getTitulo() << endl;
    }
    cout << "===============================" << endl << endl;
    cout << "Escolha o livro: ";
    cin >> opcao;
    cin.ignore();

    // verificar as opcoes escolhidas
    if(opcao > leitor->getLivrosLevados()){
        // Escolheu uma opcao fora dos limites
        cout << "::Escolheu nenhum livro!" << endl;
        return;
    }

    // Pegar o exemplar do livro partindo do codigo do exemplar
    int codigoExemplar = leitor->getExemplaresLivro()[opcao - 1].getCodio();
    ExemplarLivro* exemplarLivro = leitor->devolverLivro(codigoExemplar);
    guardarLivro(exemplarLivro); // guardar o livro na biblioteca

}

//============================= METODOS DE ACESSO DIRECTO DIRECA ==============================
void Biblioteca::removerDocumento(int hash, int codigo) {

    //::>> Verificar se tem um livro atras e em frente
    EntradaDoc* entradaDoc = documentos[hash];
    EntradaDoc* prevDoc = NULL; // O Documento que esta antes do documento a remover
    while(entradaDoc != NULL && entradaDoc->documento->getCodigo() != codigo){
        prevDoc = entradaDoc;
        entradaDoc = entradaDoc->proximoDocumento;
    }
    Documento* doc = entradaDoc->documento;

    if(prevDoc != NULL){
        //::>> Nao e um root da lista de colisao
        prevDoc->proximoDocumento = entradaDoc->proximoDocumento;
    } else {
        //::>> E um root da tabela de disperao
        documentos[hash] = entradaDoc->proximoDocumento;
    }

    if(doc->getTipo() == "Livro"){
        Livro* livro = static_cast<Livro*>(doc);
        Autor* autor = livro->getAutor();
        autor->removerDocumento(doc);
        if(autor->getSize() == 0){
            //remover autor;
            removerAutor(autor);
        }
    }
    delete(entradaDoc->documento);
    delete(entradaDoc);

    cout << "\n:::::: DOCUMENTO REMOVIDO ::::::\n" << endl;
}


void Biblioteca::removerAutor(Autor *autor) {
    char key = autor->getNome()[0];
    char hash = toupper(key) - toupper('a');

    EntradaAutor* entradaAutor = autores[hash];
    EntradaAutor* prevAut = NULL; // O Documento que esta antes do documento a remover
    while(entradaAutor != NULL && entradaAutor->autor->getNome() != autor->getNome()){
        prevAut = entradaAutor;
        entradaAutor = entradaAutor->proximoAutor;
    }

    if(prevAut != NULL){
        //::>> Nao e um root da lista de colisao
        prevAut->proximoAutor = entradaAutor->proximoAutor;
    } else {
        //::>> E um root da tabela de disperao
        autores[hash] = entradaAutor->proximoAutor;
    }

    cout << entradaAutor->autor->getNome() << endl;
    cout << ":::::: AUTOR REMOVIDO ::::::\n" << endl;
    delete(entradaAutor->autor);
    delete(entradaAutor);


}
void Biblioteca::executarImpressoes() {
    int opcao;
    string options[] = {"Imprimir todos autores", "Imprimir todos documentos"};
    for(int i = 0; i < 2; i++){
        printf("%2d.%s\n", (i+1), options[i].c_str());
    }
    cout << "Escolha a opcao: ";
    cin >> opcao;
    cin.ignore();

    if(opcao == 1){
        cout << "=================================================" << endl;
        imprimirTodosAutores();
        cout << "=================================================" << endl;
    } else if (opcao == 2){
        cout << "=================================================" << endl;
        imprimirTodosDocumentos();
        cout << "=================================================" << endl;
    } else {
        cout << "=================================================" << endl;
        cout << "Opcao invalida!!!";
        cout << "=================================================" << endl;
    }
}

void Biblioteca::imprimirTodosDocumentos() {
    printf("%-20s %-25s %-25s %-15s %10s\n", "Codigo", "Titulo", "Editora", "Exemplares", "Tipo");
    for(int i = 0; i < MAX_CAPACITY; i++){
        EntradaDoc* entradaDoc = documentos[i];
        while(entradaDoc != NULL){
            entradaDoc->documento->toString();
            entradaDoc = entradaDoc->proximoDocumento;
        }
    }

}


void Biblioteca::imprimirTodosAutores() {
    printf("\n%-20s %-20s\n", "Nome", "N. Documentos");
    for(int i = 0; i < MAX_CAPACITY; i++){
        EntradaAutor* entradaAutor = autores[i];
        while(entradaAutor != NULL){
            entradaAutor->autor->toString();
            entradaAutor = entradaAutor->proximoAutor;
        }
    }

}

void Biblioteca::guardarLivro(ExemplarLivro *exemplarLivro) {
    Livro* livro = static_cast<Livro* >(exemplarLivro->getDocumento());
    livro->receberExemplar(exemplarLivro);
    cout << "=== Livro Devolvido ===";
}

int Biblioteca::hash(string str) {
    // Converter o str para lowercase
    for_each(str.begin(), str.end(), [](char & c) {
        c = ::tolower(c);
    });

    int a = 127; // um numero primo qualquer
    int b = MAX_CAPACITY; // b e a capacidade maxima da tabela de dispersao
    int charCode;
    int hashCode = 0;
    for ( int i = 0; i< str.length(); i++ ) {
        charCode = str[i];
        hashCode = (hashCode * a + charCode) % b;
    }
    return hashCode;
}

void Biblioteca::inserirDocumento(Documento *doc) {
    //::>> Verificar se esta cheio
    if(isFull()){
        //::>> Expandir a tabela
        return;
    }

    string titulo = doc->getTitulo();
    int hashCode = hash(titulo);
    EntradaDoc* newDoc = new EntradaDoc();
    newDoc->documento = doc;
    inserirDocumento(newDoc, hashCode);
    //::>> Inserir o documento como hashCode
    //::>> Este metodo adiciona automacitamente ao catalogo de todos os rootDocumentos da biblioteca
}

void Biblioteca::inserirLeitor(Leitor *leitor) {
    char key = leitor->getNome()[0];
    int pos = (toupper(key) - toupper('a')); //Calcula a posicao do leitor no catalogo atraves da primeira letra
    EntradaLeitor* entradaLeitor = new EntradaLeitor();
    entradaLeitor->leitor = leitor;
    EntradaLeitor* leitorInTable = leitores[pos];

    // Verirficar se existe um autor na posicao
    if(leitorInTable != NULL){
        // Caso exista inserir no inicio da tabela de dispersao
        entradaLeitor->proximoLeitor = leitorInTable;
    }
    // Inserir o autor no catalogo
    leitores[pos] = entradaLeitor;

}


void Biblioteca::inserirLivro(Livro *doc) {
    //::>> Verificar se esta cheio
    if(isFull()){
        //::>> Expandir a tabela
        return;
    }

    string titulo = doc->getTitulo();
    int hashCode = hash(titulo);
    EntradaDoc *newDoc = new EntradaDoc();
    newDoc->documento = doc;

    livros[hashCode] = newDoc; //::>> Inserir no catalogo de livros
    inserirDocumento(newDoc, hashCode); //::>> Prosseguir com a insercao no catologo de


}

void Biblioteca::inserirDocumento(EntradaDoc *newDoc, int hashCode) {


    if(documentos[hashCode] != NULL){
        //::>> O novo documento e sempre adicionado em frente a lista de colisao
        newDoc->proximoDocumento = documentos[hashCode];
    }
    //::>> Nao existia algum elemento na tabela de dispersao
    documentos[hashCode] = newDoc;
    size++;
}

void Biblioteca::inserirAutor(Autor *autor) {

    char key = autor->getNome()[0];
    int pos = (toupper(key) - toupper('a')); //Calcula a posicao do autor no catalogo atraves da primeira letra
    EntradaAutor* entradaAutor = new EntradaAutor();
    entradaAutor->autor = autor;
    EntradaAutor* autorInTable = autores[pos];

    // Verirficar se existe um autor na posicao
    if(autorInTable != NULL){
        // Caso exista inserir no inicio da tabela de dispersao
        entradaAutor->proximoAutor = autorInTable;
    }
    // Inserir o autor no catalogo
    autores[pos] = entradaAutor;

}

Autor* Biblioteca::findAutor(string nome) {
    char key = nome[0];
    char pos = toupper(key) - toupper('a');
    EntradaAutor* entradaAutor = autores[pos];
    if(entradaAutor != NULL){
        while(entradaAutor !=  NULL){
            if(entradaAutor->autor->getNome() == nome){
                return entradaAutor->autor;
            }

            entradaAutor = entradaAutor->proximoAutor;
        }
        return NULL;
    }

    return NULL;
}

Leitor* Biblioteca::findLeitor(string nome) {
    char key = nome[0];
    char pos = toupper(key) - toupper('a');
    EntradaLeitor* entradaLeitor = leitores[pos];
    if(entradaLeitor != NULL){
        while(entradaLeitor !=  NULL){
            if(entradaLeitor->leitor->getNome() == nome){
                return entradaLeitor->leitor;
            }

            entradaLeitor = entradaLeitor->proximoLeitor;
        }
        return NULL;
    }

    return NULL;
}


Livro* Biblioteca::findDocumento(string titulo){

    int hashCode = hash(titulo);
    EntradaDoc *entradaDoc = documentos[hashCode];
    if(entradaDoc == NULL) return NULL;
    while (entradaDoc->proximoDocumento != NULL){
        if(entradaDoc->documento->getTitulo() == titulo){
            return static_cast<Livro *>(entradaDoc->documento);
        }
        entradaDoc = entradaDoc->proximoDocumento;
    }

    return static_cast<Livro *>(entradaDoc->documento);
}


