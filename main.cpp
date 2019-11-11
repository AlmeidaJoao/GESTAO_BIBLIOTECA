#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <fstream>

#include <string>

#include <bits/stdc++.h>

#include "Livro.h"
#include "Biblioteca.h"


#define MAX_CAPACITY 127

using namespace std;



Biblioteca *bib = new Biblioteca();
int opc = -1;
bool pass = false;
void lerFicheiro();
void inserirDadosPreliminares();
void imprimirMenu();
void usarOpcao(int i);
void loadBackup();

int main() {


    while(true){
        imprimirMenu();
        cout << endl << "Opcao: ";
        cin >> opc;
        //::>> CASO INSIRA UMA OPCAO INVALIDA ESTE EVITARA UM LOOP INFINITO
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //::::::
        usarOpcao(opc);
    }


    bib->adicionarLivro();

    return 0;
}

void loadBackup(){
    Livro* doc2 = new Livro("Jealousy","magna vestibulum aliquet ultrices erat tortor sollicitudin mi sit amet lobortis","Gorczany, Larkin and Weber",2006,5,"039209482A", 20);
    Livro* doc = new Livro("Hunter Prey","metus vitae ipsum aliquam non mauris morbi non lectus aliquam sit amet diam in magna bibendum","Torphy and Sons",1988,2, "039209482A", 20);
    Livro* doc1 = new Livro("The 19th Wife"," The facilisi cras non velit nec nisi vulputate nonummy maecenas tincidunt lacus at velit vivamus vel nulla","Corwin Inc",2005,3, "039209482A", 20);
    Livro* doc3 = new Livro("Silent Witness (Do Not Disturb)","pede ac diam cras pellentesque volutpat dui maecenas tristique est et tempus semper est quam pharetra magna","Littel LLC",1992,7, "039209482A", 20);
    Livro* doc4 = new Livro("Have Rocket, Will Travel","magnis dis parturient montes nascetur ridiculus mus etiam vel augue vestibulum rutrum rutrum neque","Cruickshank, Monahan and Crooks",2010,1, "039209482A", 20);
    Livro* doc5 = new Livro("Baadasssss! (How to Get the Man's Foot Outta Your Ass)","pellentesque quisque porta volutpat erat quisque erat eros viverra eget", "Hauck Inc",2012,4, "039209482A", 4);

    Autor* autor = new Autor("Van Hauten");
    Autor* autor2 = new Autor("Van Diesel");
    Autor* autor3 = new Autor("Van Gasoline");

    string name1 = typeid(doc).name();
    string name2 = typeid(doc).name();

    doc->setAutor(autor);
    doc1->setAutor(autor);
    doc2->setAutor(autor2);
    doc3->setAutor(autor3);
    doc4->setAutor(autor3);
    doc5->setAutor(autor3);

    bib->inserirAutor(autor);
    bib->inserirAutor(autor2);
    bib->inserirAutor(autor3);


    bib->inserirLivro(doc2);
    bib->inserirLivro(doc);
    bib->inserirLivro(doc1);
    bib->inserirLivro(doc3);
    bib->inserirLivro(doc4);
    bib->inserirLivro(doc5);

}

void inserirDadosPreliminares(){



    Leitor* leitor = new Leitor( "Carmon Elnor","P","9/3/2019",17);
    Leitor* leitor1 = new Leitor( "Corrie Greeveson","P","10/17/2019",17);
    Leitor* leitor2 = new Leitor("Domeniga Kellick","P","6/3/2019",17);
    Leitor* leitor3 = new Leitor("Loni Rainton","F","6/3/2019",17);
    Leitor* leitor4 = new Leitor("Deeyn Whyffen","F","4/15/2019",17);
    Leitor* leitor5 = new Leitor("Asia Pennells","E","5/13/2019",17);
    Leitor* leitor6 = new Leitor("Noreen Weins","O","7/13/2019",17);
    Leitor* leitor7 = new Leitor("Odelia Maggiori","e","3/5/2019",17);

    bib->inserirLeitor(leitor);
    bib->inserirLeitor(leitor1);
    bib->inserirLeitor(leitor2);
    bib->inserirLeitor(leitor3);
    bib->inserirLeitor(leitor4);
    bib->inserirLeitor(leitor5);
    bib->inserirLeitor(leitor6);
    bib->inserirLeitor(leitor7);
}

void lerFicheiro(){
    string line;
    string titulo, assunto,autorName, editora, ISBN, nome_autor;
    string ano, cota,  nPaginas;

//    ifstream myfile("C:\\Users\\Nozotrox\\Documents\\Feliciano\\ISCTEM\\Segundo_Ano\\Segundo_Semestre\\Algoritmos_e_Estruturas_de_Dados\\Trabalho_Semestral\\example.txt")
    ifstream myfile("..\\example.txt");

    if (myfile.is_open()){

        while ( getline (myfile,line) ) {
            stringstream ss(line);
            getline(ss,titulo,';');
            getline(ss,assunto,';');
            getline(ss,editora,';');
            getline(ss, ano, ';');
            getline(ss, cota, ';');
            getline(ss,ISBN,';');
            getline(ss, nPaginas, ';');
            getline(ss,autorName,';');

            istringstream iss (ano);
            istringstream iss2 (cota);
            istringstream iss3 (nPaginas);
            int anoX, cotaX, pages;
            iss >> anoX;
            iss2 >> cotaX;
            iss3 >> pages;

            Livro* doc = new Livro(titulo,assunto,editora,anoX,cotaX,ISBN,pages);
            string name1 = typeid(doc).name();

            Autor* autor = new Autor(autorName);
            //Autor* autor2 = new Autor("Van Diesel");
            //Autor* autor3 = new Autor("Van Gasoline");
            doc->setAutor(autor);
            //doc->setAutor(autor2);
            //doc->setAutor(autor3);
            bib->inserirAutor(autor);
            //bib->inserirAutor(autor2);
            //bib->inserirAutor(autor3);
            bib->inserirLivro(doc);
        }
        myfile.close();
        cout<<"Dados carregados com sucesso"<<endl;
    }
    else {
        cout << "Unable to open file| Backup loaded " ;
        loadBackup();
    }
}

void imprimirMenu(){
    printf("\n\n====================%s==================\n", "MENU");
    if(!pass) printf("0.%s", "Carregar Dados\n");
    printf("1.%s", "Adicionar Documento\n");
    printf("2.%s", "Levar Emprestado Livro\n");
    printf("3.%s", "Devolver Livro\n");
    printf("4.%s", "Pesquisar Documento\n");
    printf("5.%s", "Pesquisar Autor\n");
    printf("6.%s", "Remover Documento\n");
    printf("7.%s", "Fazer impressoes\n");
    printf("8.%s", "Repor exemplares\n");
    printf("9.%s", "Consultas\n");
    printf("10.%s", "Sair");

    printf("\n====================%s==================\n", "/\\");
}


void usarOpcao(int i){
    switch (i) {
        case 0: if(!pass){
                inserirDadosPreliminares();
                lerFicheiro();
                pass = 1;
            } else {
                cout << "!!!!DADOS JA INSERIDOS!!!!";
            }

            break;
        case 1: bib->inserirDocumento(); pass=1; break;
        case 2:
            if(!pass )
                cout<<"!!!!CARREGUE OS DADOS PRIMEIRO!!!"<<endl;
            else
                bib->emprestarLivro();break;
        case 3:
            if(!pass )
                cout<<"!!!!CARREGUE OS DADOS PRIMEIRO!!!"<<endl;
            else
                bib->receberLivro(); break;
        case 4:
            if(!pass )
                cout<<"!!!!CARREGUE OS DADOS PRIMEIRO!!!"<<endl;
            else
                bib->pesquisarDocumento();break;
        case 5:
            if(!pass )
                cout<<"!!!!CARREGUE OS DADOS PRIMEIRO!!!"<<endl;
            else
                bib->pesquisarAutor(); break;
        case 6:
            if(!pass )
                cout<<"!!!!CARREGUE OS DADOS PRIMEIRO!!!"<<endl;
            else
                bib->removerDocumento();break;
        case 7:
            if(!pass )
                cout<<"!!!!CARREGUE OS DADOS PRIMEIRO!!!"<<endl;
            else
                bib->executarImpressoes(); break;
        case 8:
            if(!pass )
                cout<<"!!!!CARREGUE OS DADOS PRIMEIRO!!!"<<endl;
            else
                bib->reporExemplares(); break;
        case 9:
            if(!pass )
                cout<<"!!!!CARREGUE OS DADOS PRIMEIRO!!!"<<endl;
            else
                bib->executarConsultas(); break;
        case 10: exit(0);break;
        default: printf("#OPCAO NAO VALIDA");
    }
    cout << endl;
}