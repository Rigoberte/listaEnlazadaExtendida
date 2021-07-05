#include "Lista.h"

Lista::Nodo::Nodo(const int& d): data(d), next(nullptr), back(nullptr) {
}

Lista::Lista(): head_(nullptr), last_(nullptr), length_(0) {
}

Lista::Lista(const Lista& l) : Lista() {
    *this = l;
}

Lista::~Lista() {
    while (length_ != 0) {
        this->eliminar(0);
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {
    while (length_ != 0) {
        this->eliminar(0);
    } // No supe como usar ~Lista() :(

    Nodo* nodo_iesimo_aCopiar = aCopiar.head_;
    while (nodo_iesimo_aCopiar != nullptr)
    {
        this->agregarAtras(nodo_iesimo_aCopiar->data);
        nodo_iesimo_aCopiar = nodo_iesimo_aCopiar->next;
    }
    this->length_ = aCopiar.length_;
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nodoNuevo = new Nodo(elem);
    if (length_ == 0)
    {
        head_ = nodoNuevo;
        last_ = head_;
    }
    else
    {
        head_->back = nodoNuevo;
        nodoNuevo->next = head_;
        head_ = nodoNuevo;
    }
    length_++;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nodoNuevo = new Nodo(elem);
    if (length_ == 0)
    {
        head_ = nodoNuevo;
        last_ = head_;
    }
    else
    {
        last_->next = nodoNuevo;
        nodoNuevo->back = last_;
        last_ = nodoNuevo;
    }
     length_++;
}

void Lista::eliminar(Nat i) {
        Nodo* nodo_iesimo = this->head_;
        int n = i;
        while (n > 0)
        {
            nodo_iesimo = nodo_iesimo->next;
            n--;
        }

        if (nodo_iesimo->next != nullptr)
        {
            (nodo_iesimo->next)->back = nodo_iesimo->back;
        }
        else
        {
            last_ = nodo_iesimo->back;
        }

        if (nodo_iesimo->back != nullptr)
        {
            (nodo_iesimo->back)->next = nodo_iesimo->next;
        }
        else
        {
            head_ = nodo_iesimo->next;
        }
        length_--;
        nodo_iesimo->data = NULL;
        delete nodo_iesimo;
}

int Lista::longitud() const {
    return length_;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* nodo_iesimo = head_;
    while(i>0)
    {
        nodo_iesimo = nodo_iesimo->next;
        i--;
    }
    return nodo_iesimo->data;
}

int& Lista::iesimo(Nat i) {
    Nodo* nodo_iesimo = head_;
    while(i>0)
    {
        nodo_iesimo = nodo_iesimo->next;
        i--;
    }
    return nodo_iesimo->data;
}

void Lista::mostrar(ostream& o) {
    Nodo* nodo_iesimo = head_;
    o << "[";
    while(nodo_iesimo != nullptr)
    {
        o << nodo_iesimo->data << " ,";
        nodo_iesimo = nodo_iesimo->next;
    }
    o << "]";
}
