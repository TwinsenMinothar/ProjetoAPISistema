//
// Created by camil on 13/01/2018.
//

#ifndef PROJETOAPISISTEMA_SISTEMA_H
#define PROJETOAPISISTEMA_SISTEMA_H

#include <string>

using std::string;

class Sistema {

public:

    virtual Sistema &operator=(const Sistema &sistema)=0;

    virtual bool operator==(const Sistema &rhs) const =0;

    virtual bool operator!=(const Sistema &rhs) const =0;

    virtual const string &getNome() const =0;

    virtual void setNome(const string &nome)=0;

    virtual double getValor() const =0;

    virtual void setValor(double valor)=0;

    virtual bool operator>(const Sistema &rhs) const =0;

    virtual bool operator<=(const Sistema &rhs) const =0;

    virtual bool operator>=(const Sistema &rhs) const =0;

    virtual bool operator<(const Sistema &rhs) const =0;
};


#endif //PROJETOAPISISTEMA_SISTEMA_H
