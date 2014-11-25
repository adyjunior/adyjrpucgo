#include "ArvoreAVL.h"

ArvoreAVL::ArvoreAVL() {
	Root = NULL;
	Contador = 0;
}

ArvoreAVL::~ArvoreAVL() {
	delete Root;
}

No* ArvoreAVL::getRoot() {
	return Root;
}

int ArvoreAVL::getContador() {
	return Contador;
}

bool ArvoreAVL::push(No** Raiz, No* P) {
	if(!(*Raiz)) {
		*Raiz = P;
		P->setBal(0);
		Contador++;
		return true;
	}

	No** Left = (*Raiz)->getPttLeft();
	No** Right = (*Raiz)->getPttRight();

	if((P->getEL()).getPosicao() < ((*Raiz)->getEL()).getPosicao()) {
		if(push(Left, P)) {
			if((*Raiz)->getBal() == 0) {
				(*Raiz)->setBal(-1);
				return true;
			}
			if((*Raiz)->getBal() == 1) {
				(*Raiz)->setBal(0);
				return false;
			}
			if((*Left)->getBal() == -1) {
				RSD(Raiz);
				return false;
			}
			RDD(Raiz);
			return false;
		}
		return false;
	} else {
		if(push(Right, P)) {
			if((*Raiz)->getBal() == 0) {
				(*Raiz)->setBal(1);
				return true;
			}
			if((*Raiz)->getBal() == -1) {
				(*Raiz)->setBal(0);
				return false;
			}
			if((*Right)->getBal() == 1) {
				RSE(Raiz);
				return false;
			}
			RDE(Raiz);
			return false;
		}
	}
	return false;
}

bool ArvoreAVL::pop(No** Raiz, No** P, float K) {
  if(!(*Raiz)) {
    return false;
  }

	No** Left = (*Raiz)->getPttLeft();
	No** Right = (*Raiz)->getPttRight();

  if(K < ((*Raiz)->getEL()).getPosicao()) {
    if(pop(Left, P, K)) {
      (*Raiz)->setBal((*Raiz)->getBal()+1);
      if((*Raiz)->getBal() == 2) {
        if(((*Raiz)->getPtRight())->getBal() == -1) {
          RDE(Raiz);
          return true;
        } else {
          RSE(Raiz);
          return true;
        }
      } else {
        if((*Raiz)->getBal() == 0) {
          return true;
        }
      }
    }
    return false;
  }

  if(K > ((*Raiz)->getEL()).getPosicao()) {
    if(pop(Right, P, K)) {
      (*Raiz)->setBal((*Raiz)->getBal()-1);
      if((*Raiz)->getBal() == -2) {
        if(((*Raiz)->getPtLeft())->getBal() == 1) {
          RDD(Raiz);
          return true;
        } else {
          RSD(Raiz);
          return true;
        }
      } else {
        if((*Raiz)->getBal() == 0) {
          return true;
        }
      }
    }
    return false;
  }

  if((*Raiz)->getPtRight() != 0 && (*Raiz)->getPtLeft() != 0) {
  	No* PTR;
    Elemento EL;

    PTR = sucessor(Right);
    EL = (*Raiz)->getEL();
    (*Raiz)->setEL(PTR->getEL());
    PTR->setEL(EL);

    if(pop(Right, P, K)) {
      (*Raiz)->setBal((*Raiz)->getBal()-1);
      if((*Raiz)->getBal() == -2) {
        if(((*Raiz)->getPtLeft())->getBal() == 1) {
          RDD(Raiz);
          return true;
        } else {
        	RSD(Raiz);
        	return true;
        }
      } else {
        if((*Raiz)->getBal() == 0) {
          return true;
        }
      }
    }
    return false;
  }

  if((*Raiz)->getPtLeft()) {
    Elemento EL;

    (*Raiz)->setBal(((*Raiz)->getPtLeft())->getBal());
    ((*Raiz)->getPtLeft())->setBal((*Raiz)->getBal());

    EL = (*Raiz)->getEL();
    (*Raiz)->setEL(((*Raiz)->getPtLeft())->getEL());
    ((*Raiz)->getPtLeft())->setEL(EL);

    return pop(Left, P, K);
  } else {
    if((*Raiz)->getPtRight()) {
      Elemento EL;

      (*Raiz)->setBal(((*Raiz)->getPtRight())->getBal());
      ((*Raiz)->getPtRight())->setBal((*Raiz)->getBal());

      EL = (*Raiz)->getEL();
      (*Raiz)->setEL(((*Raiz)->getPtRight())->getEL());
      ((*Raiz)->getPtRight())->setEL(EL);

      return pop(Right, P, K);
    } else {
      (*P) = (*Raiz);
      (*Raiz) = 0;
      Contador--;
      return true;
    }
  }
}

No* ArvoreAVL::sucessor(No** Raiz) {
	if(!((*Raiz)->getPtLeft())) {
		return (*Raiz);
	}
	return sucessor((*Raiz)->getPttLeft());
}

No* ArvoreAVL::busca(No* Raiz, float K) {
	if(!Raiz)
		return Raiz;
	if(K < (Raiz->getEL()).getPosicao())
		return busca(Raiz->getPtLeft(), K);
	if(K > (Raiz->getEL()).getPosicao())
		return busca(Raiz->getPtRight(), K);
	return Raiz;
}

void ArvoreAVL::RSD(No** Raiz) {
	No* b = (*Raiz)->getPtLeft();
	No* a = *Raiz;
	a->setPtLeft(b->getPtRight());
	b->setPtRight(a);
	*Raiz = b;

	if(b->getBal() == 0) {
		b->setBal(1);
		a->setBal(-1);
	} else {
		b->setBal(0);
		a->setBal(0);
	}
}

void ArvoreAVL::RSE(No** Raiz) {
	No* b = (*Raiz)->getPtRight();
	No* a = *Raiz;
	a->setPtRight(b->getPtLeft());
	b->setPtLeft(a);
	*Raiz = b;

	if(b->getBal() == 0) {
		b->setBal(-1);
		a->setBal(1);
	} else {
		b->setBal(0);
		a->setBal(0);
	}
}

void ArvoreAVL::RDD(No** Raiz) {
	No* a = *Raiz;
	No* b = a->getPtLeft();
	No* c = b->getPtRight();
	*Raiz = c;
	b->setPtRight(c->getPtLeft());
	a->setPtLeft(c->getPtRight());
	c->setPtLeft(b);
	c->setPtRight(a);

	if(c->getBal() == -1) {
		b->setBal(1);
		a->setBal(0);
	} else if(c->getBal() == 1) {
		b->setBal(0);
		a->setBal(1);
	 } else {
		b->setBal(0);
		a->setBal(0);
	}
	c->setBal(0);
}

void ArvoreAVL::RDE(No** Raiz) {
	No* a = *Raiz;
	No* b = a->getPtRight();
	No* c = b->getPtLeft();
	*Raiz = c;
	b->setPtLeft(c->getPtRight());
	a->setPtRight(c->getPtLeft());
	c->setPtRight(b);
	c->setPtLeft(a);

	if(c->getBal() == -1) {
		b->setBal(0);
		a->setBal(1);
	} else if(c->getBal() == 1) {
		b->setBal(1);
		a->setBal(0);
	} else {
		b->setBal(0);
		a->setBal(0);
	}
	c->setBal(0);
}

bool ArvoreAVL::inserir(Elemento Dado) {
	No* P = No::MontaNo(Dado);
	return push(&Root, P);
}

bool ArvoreAVL::excluir(No** P, float K) {
	return pop(&Root, P, K);
}

void ArvoreAVL::listar(No* Raiz) {
	if(Raiz) {
		listar(Raiz->getPtLeft());
		Raiz->print();
		listar(Raiz->getPtRight());
	}
}


void ArvoreAVL::imprimirPosOrdem(No* Raiz){
	if(Raiz) {
		listar(Raiz->getPtLeft());
		listar(Raiz->getPtRight());
		Raiz->print();

	}
}

void ArvoreAVL::imprimirPreOrdem(No* Raiz){
	if(Raiz) {
		Raiz->print();
		listar(Raiz->getPtLeft());
		listar(Raiz->getPtRight());

	}
}

bool ArvoreAVL::eVazia(){
	if(!Root) return true;
	return false;
}

