//
// Created by Feliciano Jr. Mazoio on 11/4/2019.
//

#ifndef GESTAO_BIBLIOTECA_ENTRADADOC_H
#define GESTAO_BIBLIOTECA_ENTRADADOC_H


#include "../Documento.h"

class EntradaDoc {
public:
    Documento* documento;
    EntradaDoc* proximoDocumento;
    EntradaDoc();
    EntradaDoc(const EntradaDoc &entradaDoc);
    ~EntradaDoc();
};


#endif //GESTAO_BIBLIOTECA_ENTRADADOC_H
