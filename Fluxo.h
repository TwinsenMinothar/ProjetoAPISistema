//
// Created by camil on 13/01/2018.
//

#ifndef PROJETOAPISISTEMA_FLUXO_H
#define PROJETOAPISISTEMA_FLUXO_H

#include "Sistema.h"

class Fluxo {
public:

    virtual Fluxo &operator=(const Fluxo &)=0;

    virtual double executa()=0;

    virtual const string &getNome() const =0;

    virtual Sistema *getOrigem() const =0;

    virtual Sistema *getDestino() const =0;

    virtual void setNome(const string &nome)=0;

    virtual void setOrigem(Sistema *origem)=0;

    virtual void setDestino(Sistema *destino)=0;

    virtual bool operator==(const Fluxo &rhs) const =0;

    virtual bool operator!=(const Fluxo &rhs) const =0;

};


#endif //PROJETOAPISISTEMA_FLUXO_H
