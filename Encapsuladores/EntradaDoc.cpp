//
// Created by Feliciano Jr. Mazoio on 11/4/2019.
//

#include "EntradaDoc.h"
EntradaDoc::EntradaDoc() {
    documento = NULL;
    proximoDocumento = NULL;
}

EntradaDoc::EntradaDoc(const EntradaDoc &entradaDoc) {
    documento = entradaDoc.documento;
    proximoDocumento = entradaDoc.proximoDocumento;
}

EntradaDoc::~EntradaDoc() {}

