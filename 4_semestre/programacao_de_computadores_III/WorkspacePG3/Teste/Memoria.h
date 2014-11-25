#ifndef MEMORIA_H_
#define MEMORIA_H_

class Memoria {
private:
	std::string MSDado;//most significant dado
	std::string LSDado;//least significant dado
	int MSEndereco;
	int LSEndereco;
	long long int conteudo;
public:
	Memoria(){this->conteudo=this->MSEndereco=this->LSEndereco=0;}
	~Memoria(){};
	void setConteudo(long long int conteudo){
		this->conteudo = conteudo;
	}

	long long int getConteudo(){
		return this->conteudo;
	}

    std::string getLSDado() const
    {
        return LSDado;
    }

    int getLSEndereco() const
    {
        return LSEndereco;
    }

    std::string getMSDado() const
    {
        return MSDado;
    }

    int getMSEndereco() const
    {
        return MSEndereco;
    }

    void setLSDado(std::string LSDado)
    {
        this->LSDado = LSDado;
    }

    void setLSEndereco(int LSEndereco)
    {
        this->LSEndereco = LSEndereco;
    }

    void setMSDado(std::string MSDado)
    {
        this->MSDado = MSDado;
    }

    void setMSEndereco(int MSEndereco)
    {
        this->MSEndereco = MSEndereco;
    }

};

#endif /* MEMORIA_H_ */
