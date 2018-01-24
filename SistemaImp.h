//
// Created by camil on 23/01/2018.
//

#ifndef PROJETOAPISISTEMA_SISTEMAIMP_H
#define PROJETOAPISISTEMA_SISTEMAIMP_H
#include "Sistema.h"

class SistemaImp : public Sistema {
private:
    string nome;
    double valor;
public:
    SistemaImp();

    SistemaImp(string string1, double d);

    SistemaImp(Sistema &sistema);

    virtual ~SistemaImp();

    Sistema &operator=(const Sistema &sistema) override;

    bool operator==(const Sistema &rhs) const override;

    bool operator!=(const Sistema &rhs) const override;

    const string &getNome() const override;

    void setNome(const string &nome) override;

    double getValor() const override;

    void setValor(double valor) override;

    bool operator>(const Sistema &rhs) const override;

    bool operator<=(const Sistema &rhs) const override;

    bool operator>=(const Sistema &rhs) const override;

    bool operator<(const Sistema &rhs) const override;
};


#endif //PROJETOAPISISTEMA_SISTEMAIMP_H
