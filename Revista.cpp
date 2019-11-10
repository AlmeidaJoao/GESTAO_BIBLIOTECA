//
// Created by nozotrox on 10/4/19.
//

#include "Revista.h"


Revista::Revista(string titulo, string assunto, string editora, int ano, int cota,string issn,string url) :  Documento(titulo, assunto, editora, ano, cota)  {
    this->url =url;
    this->ISSN = issn;
    this->tipo = "Revista";
}

void Revista::setISSN(string ISSN)
{
  this->ISSN = ISSN;
}
void Revista::setUrl(string url)
{
    this->url = url;
}
