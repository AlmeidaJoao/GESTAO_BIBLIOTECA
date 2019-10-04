//
// Created by nozotrox on 10/4/19.
//

#ifndef GESTAO_BIBLIOTECA_REVISTA_H
#define GESTAO_BIBLIOTECA_REVISTA_H


#include "Documento.h"

class Revista: public Documento {
private:
    string ISSN;
    string url;

public:
    Revista();
    Revista(const Revista &revista);
    ~Revista();
    string getISSN();
    string getUrl();
    void setISSN(string ISSN);
    void setUrl(string url);

};


#endif //GESTAO_BIBLIOTECA_REVISTA_H
