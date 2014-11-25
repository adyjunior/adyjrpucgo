#include"sintatico.h"
#include "analex.h"

extern struct Token *lookAHead;

int A(int flag){
	int Bv,Rh,Rs,Av;

	Bv = B(flag);
	Rh = Bv;
	Rs = R(Rh,flag);
	Av = Rs;

	return Av;
}


int R(int Rh, int flag){
	if(lookAHead == NULL){
		return 0;
	}

	int Bv,R1h,R1s,Rs;

	if(strcmp(lookAHead->lexema,"+") == 0){
		lookAHead = lookAHead->prox;
		Bv = B(flag);
		if(flag){
			R1h = Rh + Bv;
		}
		R1s = R(R1h,flag);
		Rs =  R1s;

	}else if(strcmp(lookAHead->lexema,"-") == 0){
		lookAHead = lookAHead->prox;
		Bv = B(flag);
		if(flag){
			R1h = Rh - Bv;
		}
		R1s = R(R1h,flag);
		Rs =  R1s;
	}else{
		Rs = Rh;
	}

	return Rs;
}


int B(int flag){
	int Cv,Sh,Ss,Bv;

	Cv = C(flag);
	Sh = Cv;
	Ss = S(Sh,flag);
	Bv = Ss;

	return Bv;
}

int S(int Sh, int flag){
	if(lookAHead == NULL){
		return 0;
	}
	int Cv,S1h,S1s,Ss;

	if(strcmp(lookAHead->lexema,"*") == 0){
		lookAHead = lookAHead->prox;
		Cv = C(flag);
		if(flag){
			S1h = Sh * Cv;
		}
		S1s = S(S1h,flag);
		Ss = S1s;
	}else if(strcmp(lookAHead->lexema,"/") == 0){
		lookAHead = lookAHead->prox;
		Cv = C(flag);
		if(flag){
			if(Cv == 0){
				printf("Excecao : Divisao por 0");
				exit(2);
			}
			S1h = Sh / Cv;
		}
		S1s = S(S1h,flag);
		Ss = S1s;
	}else{
		Ss = Sh;
	}

	return Ss;
}


int C(int flag){
	int Dv,Th,Ts,Cv;

	Dv = D(flag);
	Th = Dv;
	Ts = T(Th,flag);
	Cv = Ts;

	return Cv;
}


int T(int Th, int flag){
	if(lookAHead == NULL){
		return 0;
	}

	int Dv,Ts,T1s,T1h;

	if(strcmp(lookAHead->lexema,"^") == 0){
		//printf("%s",lookAHead->lexema);
		lookAHead = lookAHead->prox;
		Dv = D(flag);
		if(flag){
			T1h = pow(Th,Dv);
		}
		T1s = T(T1h,flag);
		Ts = T1s;
	}else{
		Ts = Th;
	}

	return Ts;
}


int D(int flag){
	if(lookAHead == NULL){
		return 0;
	}
	int Dv, Hh;

	if(lookAHead->tipo == 8 || lookAHead->tipo == 9){
		//printf(" %s ",lookAHead->lexema);
		if(flag){
			Dv = atoi(lookAHead->lexema);
		}
		lookAHead = lookAHead->prox;
	}else if(lookAHead->tipo == 1){
		//lookAHead->simbolo->valor = 0;
		if(flag){
			Dv = lookAHead->simbolo->valor;
		}
		//lookAHead->simbolo->valor = Dv;
		lookAHead = lookAHead->prox;
	}else if(strcmp(lookAHead->lexema,"(") == 0){
		lookAHead = lookAHead->prox;
		Dv = E(flag);
		struct Token *teste1 = lookAHead;
		if(lookAHead == NULL){
			return 0;
		}
		if(strcmp(lookAHead->lexema,")") == 0){
			lookAHead = lookAHead->prox;
		}else{
			printf("ERRO : ) esperado");
			exit(2);
		}
	}else if(strcmp(lookAHead->lexema,"senao") == 0){
		lookAHead = lookAHead->prox;

		if(strcmp(lookAHead->lexema,"\n") == 0){
			lookAHead = lookAHead->prox;

			struct Token *aux = lookAHead;

			if(strcmp(lookAHead->lexema,"inicio") == 0){
				lookAHead = lookAHead->prox;

				if(strcmp(lookAHead->lexema,"\n") == 0){
					lookAHead = lookAHead->prox;

					if(strcmp(lookAHead->lexema,"fim") == 0){
						lookAHead = lookAHead->prox;
					}else{
						lookAHead = aux;
						Hh = flag;
						H(Hh);
					}
				}
			}
		}

			//Hh = flag;
			//H(Hh);
	}else{
		printf("ERRO : Operando esperado");
		exit(2);
	}

	return Dv;

}

int E(int flag){
	int Fv,Uh,Us,Ev;

	Fv = F(flag);
	Uh = Fv;
	Us = U(Uh,flag);
	Ev = Us;

	return Ev;

}

int U(int Uh, int flag){
	if(lookAHead == NULL){
		return 0;
	}

	int Fv,Us,U1s,U1h;

	if(strcmp(lookAHead->lexema,".ou.") == 0){
		//printf("%s",lookAHead->lexema);
		lookAHead = lookAHead->prox;
		Fv = F(flag);
		if(flag){
			U1h = (Uh || Fv);
		}
		U1s = U(U1h,flag);
		Us = U1s;
	}else{
		Us = Uh;
	}

	return Us;
}

int F(int flag){
	int Gv,Vh,Vs,Fv;

	Gv = G(flag);
	Vh = Gv;
	Vs = V(Vh,flag);
	Fv = Vs;

	return Fv;
}

int V(int Vh, int flag){
	if(lookAHead == NULL){
		return 0;
	}

	int Gv,Vs,V1s,V1h;

	if(strcmp(lookAHead->lexema,".e.") == 0){
		//printf("%s",lookAHead->lexema);
		lookAHead = lookAHead->prox;
		Gv = G(flag);

		if(flag){
			V1h = (Vh && Gv);
		}
		V1s = V(V1h, flag);
		Vs = V1s;
	}else{
		Vs = Vh;
	}

	return Vs;
}

int G(int flag){
	int Av,Wh,Ws,Gv;

	Av = A(flag);
	Wh = Av;
	Ws = W(Wh,flag);
	Gv = Ws;

	return Gv;
}


int W(int Wh, int flag){
	if(lookAHead == NULL){
		return 0;
	}

	int Av,Ws,W1s,W1h;

	if(strcmp(lookAHead->lexema,"<") == 0){
		//printf("%s",lookAHead->lexema);
		lookAHead = lookAHead->prox;
		Av = A(flag);
		if(flag){
			W1h = (Wh < Av);
		}
		W1s = V(W1h,flag);
		Ws = W1s;
	}else if(strcmp(lookAHead->lexema,">") == 0){
		lookAHead = lookAHead->prox;
		Av = A(flag);
		if(flag){
			W1h = (Wh > Av);
		}
		W1s = V(W1h,flag);
		Ws = W1s;
	}else{
		Ws = Wh;
	}

	return Ws;
}


int J(int flag){
	if(lookAHead == NULL){
		return 0;
	}


	int Jv=0, Ev;
	int Hh, Dh;// K == D na especificacao

	struct Token *aux2 = lookAHead;

	if(lookAHead->tipo == 1){
		struct Token *aux = lookAHead;
		//printf(" %s ",lookAHead->lexema);
		lookAHead = lookAHead->prox;

		if(strcmp(lookAHead->lexema,"<-") == 0){
			//aux = lookAHead;
			lookAHead = lookAHead->prox;
			Ev = E(flag);

			if(aux->simbolo == NULL){
				exit(0);
			}

			aux->simbolo->valor = Ev;
			Jv = aux->simbolo->valor;
		}

	} else if(strcmpi(lookAHead->lexema,"escreva") == 0){
		lookAHead = lookAHead->prox;

		if(lookAHead == NULL){
			return 0;//erro
		}

		//struct Token *debug = lookAHead;

		if(lookAHead->tipo == 1){// se for id
			if(flag){
				printf("%8.2d\n", lookAHead->simbolo->valor);
			}
			//printf("%d", lookAHead->simbolo->valor);
			lookAHead = lookAHead->prox;
		}else if(lookAHead->tipo == 6){//se for string
			if(flag){
				printf("%s", lookAHead->lexema);
			}
			lookAHead = lookAHead->prox;
		}else{
			printf("ERRO : Operando esperado para a escrita.");
			exit(2);
			//erro
		}

	}else if(strcmp(lookAHead->lexema,"\n") == 0){
		return Jv;
	}else if(strcmpi(lookAHead->lexema,"se") == 0){
		lookAHead = lookAHead->prox;
		if(lookAHead == NULL){
			return 0;
		}

		if(strcmp(lookAHead->lexema,"(") == 0){
			lookAHead = lookAHead->prox;

			Ev = E(flag);


			if(strcmp(lookAHead->lexema,")") == 0){
				lookAHead = lookAHead->prox;

				if(lookAHead == NULL){
					return 0;
				}

				if(strcmp(lookAHead->lexema,"\n") == 0){
					lookAHead = lookAHead->prox;
					if(Ev){
						Hh = 1;
						Dh = 0;
					}else{
						Hh = 0;
						Dh = 1;
					}

					H(Hh);
					//K(Kh);
					aux2 = lookAHead;
					D(Dh);

				}else{
					printf("ERRO : Quebra de linha esperada");
					exit(2);
				}

			}else{
				printf("ERRO : Operando ) esperado.");
				exit(2);
			}

		}else{
			printf("ERRO : Operando ( esperado.");
			exit(2);
		}


	}else{
		struct Token *teste = lookAHead;
		printf("ERRO : Operando esperado");
		exit(2);
	}

	return Jv;
}


int H(int Hh){
	if(lookAHead == NULL){
		return 0;
	}

	int Iv;

	struct Token *aux3 = lookAHead;

	if(strcmpi(lookAHead->lexema,"inicio") == 0){
		lookAHead = lookAHead->prox;
		if(lookAHead == NULL){
			return 0;
		}

		struct Token *teste = lookAHead;

		if(strcmp(lookAHead->lexema,"\n") == 0){
			lookAHead = lookAHead->prox;
			Iv = I(Hh);

			//lookAHead = lookAHead->prox;
			teste = lookAHead;

			if(strcmp(lookAHead->lexema,"\n") == 0){
				lookAHead = lookAHead->prox;
				if(lookAHead == NULL){
					return 0;
				}

				if(strcmpi(lookAHead->lexema,"fim") == 0){
					lookAHead = lookAHead->prox;
					if(lookAHead == NULL){
						return 0;
					}

					if(strcmp(lookAHead->lexema,"\n") == 0){
						lookAHead = lookAHead->prox;

					}else{
						printf("ERRO : Quebra de linha esperada");
						exit(2);
					}

				}else{
					printf("ERRO : Fim esperado");
					exit(2);
				}

			}else{
				printf("ERRO : Quebra de linha esperada.");
				exit(2);
			}
		}else{
			printf("ERRO : Quebra de linha esperada.");
			exit(2);
		}
	}else{
		printf("ERRO : Inicio esperado");
		exit(2);
	}

	return Iv;
}


int I(int flag){
	int Jv,Xh,Xs,Iv;

	if(lookAHead == NULL){
		printf("ERRO : falha de segmentacao.");
		exit(2);
	}

	struct Token *teste = lookAHead;

	Jv = J(flag);
	Xh = Jv;
	Xs = X(Xh,flag);
	Iv = Xs;

	return Iv;
}

int X(int Xh, int flag){
	if(lookAHead == NULL){
		return 0;
	}

	int Jv,Xs=0,X1s,X1h=0;

	struct Token *aux = lookAHead;

	if(strcmp(lookAHead->lexema,"\n") == 0){
		lookAHead = lookAHead->prox;

		if(lookAHead == NULL ){
			printf("ERRO : Fim esperado.");
			exit(2);
		}

		if(strcmpi(lookAHead->lexema,"fim") == 0){
			lookAHead = aux;
			return Xs;
		}

		if(lookAHead->prox == NULL){
			printf("ERRO : Fim esperado.");
			exit(2);
		}

		if(strcmpi(lookAHead->prox->lexema,"fim") == 0){
			return Xs;
		}


		Jv = J(flag);
		X1h = Jv;
		// nao existe acao semantica.
		X1s = X(X1h,flag);
		Xs = X1s;

	}

	Xs = Xh;

	return Xs;
}


int K(int Kh){
	if(lookAHead == NULL){
		return 0;
	}

	int Hh;

	lookAHead = lookAHead->prox;

	if(lookAHead == NULL){
		return 0;
	}

	if(strcmpi(lookAHead->lexema,"senao") == 0){

		if(strcmpi(lookAHead->lexema,"\n") == 0){
			lookAHead = lookAHead->prox;
			Hh = Kh;
			H(Hh);

		}else{
			printf("ERRO : Quebra de linha esperada.");
			exit(2);
		}

	}

	return Kh;
}



