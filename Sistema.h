//
// Created by camil on 13/01/2018.
//

#ifndef PROJETOAPISISTEMA_SISTEMA_H
#define PROJETOAPISISTEMA_SISTEMA_H

#include <string>

using std::string;

class Sistema {

private:
    string nome;
    double valor;
public:
    Sistema();

    Sistema(string, double);

    Sistema(Sistema &sistema);

    virtual ~Sistema();

    Sistema &operator=(const Sistema &sistema);

    bool operator==(const Sistema &rhs) const;

    bool operator!=(const Sistema &rhs) const;

    const string &getNome() const;

    void setNome(const string &nome);

    double getValor() const;

    void setValor(double valor);

    bool operator>(const Sistema &rhs) const;

    bool operator<=(const Sistema &rhs) const;

    bool operator>=(const Sistema &rhs) const;

    bool operator<(const Sistema &rhs) const;
};


#endif //PROJETOAPISISTEMA_SISTEMA_H
