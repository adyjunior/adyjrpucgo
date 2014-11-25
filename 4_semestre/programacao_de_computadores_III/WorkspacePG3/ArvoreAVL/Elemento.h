#ifndef ELEMENTO_H_
#define ELEMENTO_H_

class Elemento {

private:
	float posicao;

public:

	Elemento(){};
	~Elemento(){};
    float getPosicao() const{return posicao;}

    void setPosicao(float posicao){this->posicao = posicao;}

};

#endif /* ELEMENTO_H_ */
