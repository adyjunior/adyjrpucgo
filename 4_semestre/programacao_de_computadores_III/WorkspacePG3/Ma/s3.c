#include<ncurses.h>
#include<stdio.h>
#include<string.h>
#include<time.h>   
   //       ***********************************************************
   //****** ALUNOS: THIAGO FILISBINO DA SILVA, RAFAEL CANDIDO DA SILVA *********
   //       ***********************************************************
 
struct MEMORIA
{
  int dados[10];
  char instrucao[10][2][18];
};
typedef struct MEMORIA memoria;

void ciclo_busca(WINDOW *std,int *PC,int *MAR,char MBR[2][18],char IR[18],char IBR[18],memoria *m,int *clock);
void mascarag(WINDOW *std);//---->mascara geral 
void ler_arquivo(memoria *m,FILE *arq);
void preenche_IR_MAR(char *IR,int *MAR,char *instrucao);
void imprime_memoria(WINDOW *std,int linha,int col,memoria m);
void decod_instr(WINDOW *std,int *PC, char *IR,int *MAR, int *AC, int *MQ, char *MBR,char IBR[18], memoria *mem,int *clock,int *lin,int *col);
void load_mq (WINDOW *std, int *AC, int *MQ,int *clock);
void load_mqm(WINDOW *std, int *MQ,int MAR, char *MBR, memoria mem,int *clock);
void stor_m(WINDOW *std, int *AC,int MAR, char *MBR, memoria *mem,int *clock);
void load_m(WINDOW *std, int *AC,int MAR, char *MBR, memoria *mem,int *clock);
void load_menosm(WINDOW *std, int *AC,int MAR, char *MBR, memoria *mem,int *clock);
void load_modm(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem,int *clock);
void load_menosmodm(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem,int *clock);
void jump_m019(WINDOW *std, int MAR,int *PC,char IBR[18],int *clock,int *lin,int *col);
void jump_m2039(WINDOW *std, int *AC, int *MQ, char *IR,int *MAR,int *PC, char *MBR,char IBR[18], memoria *mem,int *clock,int *lin);
void jump_maism019(WINDOW *std,int *MQ,int MAR,int *PC, int AC,char *MBR,char *IR,char IBR[18],memoria *mem,int *clock,int *lin,int *col);
void jump_maism2039(WINDOW *std, int *AC, int *MQ, char *IR,int *MAR,int *PC, char *MBR,char IBR[18], memoria *mem,int *clock,int *lin,int *col);
void add_m(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem,int *clock);
void add_modm(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem,int *clock);
void sub_m(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem,int *clock);
void sub_modm(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem,int *clock);
void mul_m(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem, int *MQ,int *clock);
void div_m(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem, int *MQ,int *clock);
void lsh(WINDOW *std, int *AC,int *clock);
void rsh(WINDOW *std, int *AC,int *clock);
void stor_m819(WINDOW *std, int AC, int MAR, char *MBR, memoria *mem,int *clock);
void stor_m2839(WINDOW *std, int AC,int MAR, char *MBR, memoria *mem,int *clock);



int main(int narg,char *narq[])
{
  //char *narq;//--->nome do arquivo
  FILE *arq=NULL;
  char MBR[2][18],IR[18],IBR[18];
  int MAR,PC=10,AC=0,MQ=0,aux;
  int lin,col,r=0,clock=0,tempo,jamp=0;
  time_t start,end;
  memoria m;
  WINDOW *std=NULL;
  std=initscr();
  start_color();
  if(narg!=2)
  {
    mvwprintw(std,1,17,"Numero de argumentos invalidos!!");
    wrefresh(std);
  }
  init_pair(1,COLOR_BLACK,COLOR_BLUE);
  init_pair(2,COLOR_WHITE,COLOR_BLACK);
  init_pair(3,COLOR_RED,COLOR_BLUE);
  init_pair(4,COLOR_WHITE,COLOR_RED);
  init_pair(5,COLOR_BLACK,COLOR_WHITE);
  init_pair(6,COLOR_BLACK,COLOR_GREEN);
  init_pair(7,COLOR_RED,COLOR_BLUE);
  wattrset(std,COLOR_PAIR(1));
  wbkgd(std,COLOR_PAIR(1));
  arq=fopen(narq[1],"r");
  
    if(narg!=2)
      {
         mvwprintw(std,1,17,"Numero de argumentos invalidos!!");
         wrefresh(std);
	 endwin();
       
      }
    else
       {
         if(!arq)
           { 
             mvwprintw(std,1,17,"Falha na abertura ou arquivo inexistente!!!!");
             wrefresh(std);
	   }
	 else
	   {
               ler_arquivo(&m,arq);
	       mascarag(std);
	       strcpy(IBR,"");
                for(lin=18,col=34;PC<20&&strcmp(m.instrucao[PC-10][0],"");PC++,lin++)//olhar o pc -16
		  {
		    wattrset(std,COLOR_PAIR(7));
		    mvwprintw(std,lin,col,"->");
		  mvwprintw(std,lin-1,col,"  ");
	          ciclo_busca(std,&PC,&MAR,MBR,IR,IBR,&m,&clock);
		  //clock=r;
		  //r=0;
		  decod_instr(std, &PC, IR, &MAR, &AC, &MQ, *MBR,IBR, &m,&clock,&lin,&col);
		  //clock=r;
		  //r=0;
		  if(strcmp(IBR,""))
		  {
		    ciclo_busca(std,&PC,&MAR,MBR,IR,IBR,&m,&clock);
		    //clock=r;
		    //r=0;
		    decod_instr(std, &PC, IR, &MAR, &AC, &MQ, *MBR,IBR, &m,&clock,&lin,&col);
		    }
		  }
	   }
       }

    endwin();
}


//************************************************************************************
/*Essa funcao busca a funcao a ser executada(conforme a logica de operacao do simulador IAS
Parametros: WINDOW *std= um ponteiro para a janela std
            int *PC= um ponteiro que vai armazenar numeros pequenos
            int *MAR= um ponteiro para
            char MBR[2][18]= uma matriz de caracteres
            char IR[18]= um vetor de caracteres
            memoria *mem= um ponteiro para a estrutura memoria
Retorno:sem retorno 
Situacao:funcionando                                                                  */
//************************************************************************************
void ciclo_busca(WINDOW *std,int *PC,int *MAR,char MBR[2][18],char IR[18],char IBR[18],memoria *m,int *clock)
{

  if(!strcmp(IBR,""))
    {
      wattrset(std,COLOR_PAIR(1));
      imprime_memoria(std,8,41,*m);//posicionar a impresao
      wattrset(std,COLOR_PAIR(2));
      mvwprintw(std,20,25,"%d",*PC);
      //wattrset(std,COLOR_PAIR(4));
      mvwprintw(std,5,4,"%d",*clock);
      wrefresh(std);
      getch();
      (*clock)++;
      mvwprintw(std,5,4,"%d",*clock);
      *MAR=*PC;
      wattrset(std,COLOR_PAIR(2));
      mvwprintw(std,24,23,"        ");
      mvwprintw(std,24,23,"%d",*MAR);
      wrefresh(std);
      getch();
      //wattrset(std,COLOR_PAIR(4));
      (*clock)++;
      mvwprintw(std,5,4,"%d",*clock);
      strcpy(MBR[0],m->instrucao[*MAR-10][0]);
      strcpy(MBR[1],m->instrucao[*MAR-10][1]);
      wattrset(std,COLOR_PAIR(2));
      mvwprintw(std,16,11,"               ");
      mvwprintw(std,17,11,"               ");
      mvwprintw(std,16,11,"%s",MBR[0]);
      mvwprintw(std,17,11,"%s",MBR[1]);
      wrefresh(std);
      getch();
      //wattrset(std,COLOR_PAIR(4));
      (*clock)++;
      mvwprintw(std,5,4,"%d",*clock);
      strcpy(IBR,MBR[1]);
      if(strcmp(IBR,""))
	{
	 wattrset(std,COLOR_PAIR(2));
	 mvwprintw(std,20,3,"               ");
	 mvwprintw(std,20,3,"%s",IBR);
	 wrefresh(std);
	 getch();
         //wattrset(std,COLOR_PAIR(4));
         (*clock)++;
          mvwprintw(std,5,4,"%d",*clock);
	}
      wattrset(std,COLOR_PAIR(2));
      preenche_IR_MAR(IR,MAR,MBR[0]);
      mvwprintw(std,24,3,"               ");
      mvwprintw(std,24,3,"%s",IR);
      wrefresh(std);
      mvwprintw(std,24,23,"        ");
      mvwprintw(std,24,23,"%d",*MAR);
      wrefresh(std);
      getch();
      //wattrset(std,COLOR_PAIR(4));
      (*clock)++;
      mvwprintw(std,5,4,"%d",*clock);
    }
  else
    {
      wattrset(std,COLOR_PAIR(2));
      preenche_IR_MAR(IR, MAR, IBR);
      strcpy(IBR,"");
      mvwprintw(std, 20, 3, "%s", IBR);
      mvwprintw(std, 24, 3, "                ");
      mvwprintw(std, 24, 3, "%s", IR);
      wrefresh(std);
      mvwprintw(std, 24, 23, "         ");
      mvwprintw(std, 24, 23, "%d", *MAR);
      wrefresh(std);
      getch();
      //wattrset(std,COLOR_PAIR(4));
      (*clock)++;
      mvwprintw(std,5,4,"%d",*clock);
    }
  // return(clock);
}




//***********************************************************************************
/*Essa funcao faz a leitura do arquivo que vai armazenar os codigos do IAS
Parametros: memoria *mem= um ponteiro do tipo estrutura memoria
            FILE *arq= um arquivo que contem os dados do programa em txt
Retorno:sem retorno
Situacao:funcionando                                                               */
//***********************************************************************************
void ler_arquivo(memoria *m,FILE *arq)
{
  int cline,flag,cont,cinstrucao,ccarac;
  char caracter;
  for(cline=0;cline<10;cline++)
    {
      flag=0;
      m->dados[cline]=0;
      for(caracter=0,cont=0;caracter!=10;cont++)
	{
	  fread(&caracter,sizeof(char),1,arq);
	  if(!cont&&caracter==45)
	    flag=1;
	  else
	    if(caracter>47&&caracter<58)
	      m->dados[cline]=(m->dados[cline]*10)+(caracter-48);
	}
      if(flag)
	m->dados[cline]=-m->dados[cline];
    }
  for(cline=0;cline<11;cline++)
    for(cinstrucao=0;cinstrucao<2;cinstrucao++)
      {
	caracter=0;
	for(ccarac=0;caracter!=10&&caracter!=59&&ccarac<18;ccarac++)
	  {
	    m->instrucao[cline][cinstrucao][ccarac]=0;
	    if(!feof(arq))
	      {
		fread(&caracter,sizeof(char),1,arq);
		if(caracter!=10&&caracter!=59)
		  m->instrucao[cline][cinstrucao][ccarac]=caracter;
	      }
	  }
      }

}
//*****************************************************************************






//*****************************************************************************
/*Essa funcao faz a chamada de uma mascarag(prototipo do IAS) onde vao aparecer os valores
Parametros:WINDOW *std= um ponteiro para a janela std
Retorno:sem retorno
Situacao:funcionando                                                           */
//*****************************************************************************
void mascarag(WINDOW *std)
{ int cont,lin,col,aux;
  wattrset(std,COLOR_PAIR(2));
  mvwprintw(std, 0,0,"*****************************************************************************"  );
  mvwprintw(std, 1,0,"*                            |*PROCESSADOR IAS*|                            *"  );
  mvwprintw(std, 2,0,"*****************************************************************************"  );
  wattrset(std,COLOR_PAIR(3));
  wrefresh(std);
  mvwprintw(std,4, 2, "*CLOCKS*");
  wattrset(std,COLOR_PAIR(2));
  mvwprintw(std,5, 3,   "|    |");
  wattrset(std,COLOR_PAIR(1));
  mvwprintw(std, 7, 8,      "---AC---     ---MQ----      ---------------MEMORIA------------------");
  mvwprintw(std, 8, 8,      "|       |----|       |      |00-                                   |");
  mvwprintw(std, 9, 8,      "--------     ---------      |01-                                   |");
  mvwprintw(std, 10,12,          "|             |         |02-                                   |");
  mvwprintw(std, 11, 7,     "---------´ULA'----------     |03-                                   |");
  mvwprintw(std, 12, 7,     "|                       |    |04-                                   |");
  mvwprintw(std, 13, 7,     "------------------------     |05-                                   |");
  mvwprintw(std,14,19,                 "|                |06-                                   |");
  mvwprintw(std,15,10,        "--------MBR--------       |07-                                   |");
  mvwprintw(std,16,10,        "|                 |       |08-                                   |");
  mvwprintw(std,17,10,        "|                 |       |09-                                   |");
  mvwprintw(std,18,10,        "-------------------       |10-                                   |");
  mvwprintw(std,19, 2, " -----IBR---------     --PC--     |11-                                   |");
  mvwprintw(std,20, 2, "|                 |   |     |     |12-                                   |");
  mvwprintw(std,21, 2, " -----------------     -----      |13-                                   |");
  mvwprintw(std,22,20,                  "³      ³        |14-                                   |");
  mvwprintw(std,23, 2," -----IR---------    ---MAR--     |15-                                   |");
  mvwprintw(std,24, 2,"|                |->|        |    |16-                                   |");
  mvwprintw(std,25, 2," ----------------    --------     |17-                                   |");
  mvwprintw(std,26,11,         "|                        |18-                                   |");
  mvwprintw(std,27, 2,   "CIRCUITO CONTORLADOR              |19-                                   |");
  mvwprintw(std,28, 2,   " ______________   _______________ |---------------------------------------");
  mvwprintw(std,29, 2,   "|              | |               |");
  mvwprintw(std,30, 2,   "|              | |               |");
  mvwprintw(std,31, 2,   " --------------   --------------- ");
  wattrset(std,COLOR_PAIR(2));
  mvwprintw(std,32,0,"  ***************************************************************************  ");
  mvwprintw(std,33,0,"  *                          |*PROCESSADOR IAS*|                            *  ");
  mvwprintw(std,34,0,"  ***************************************************************************  ");
 
  wrefresh(std);
  for(cont=0,lin=0,col=77;cont<32;cont++,lin++)
    {
      
      mvwprintw(std,lin,col,"  ");
      mvwprintw(std,lin,col-col,"  ");
    }
  for(lin=0;lin<48;lin++)
    {int aux=88;
      if(lin>=35)
	{
	col=col-col;
	aux=aux+aux;
	}else{
	  col=79;}
      for(cont=0;cont<=aux;cont++,col++)
	{
	  if(col%2==0)
	  {
	    wattrset(std,COLOR_PAIR(1));
	    mvwprintw(std,lin,col," ");
	  }else
	    {
		wattrset(std,COLOR_PAIR(5));
		mvwprintw(std,lin,col," ");
		 }
	  //mvwprintw(std,lin+38,col-col,"  ");
	}
    }
  for(lin=1;lin<48;lin+=2)
    {int aux=88;
      if(lin>=35)
	{
	col=col-col;
	aux=aux+aux;
	}else{
	  col=79;}
      for(cont=0;cont<=aux;cont++,col++)
	{
	  if(col%2==0)
	    {
	      wattrset(std,COLOR_PAIR(5));
	      mvwprintw(std,lin,col," ");
	    }else
	      {
		wattrset(std,COLOR_PAIR(1));
		mvwprintw(std,lin,col," ");
	      }
	  //mvwprintw(std,lin+38,col-col,"  ");
	}
	}
 aux=2;
 for(cont=0,col=0;cont<=4;cont++,aux+=2,col=col+31)
   {
     if(cont%2==0)
       aux=2;
	 else
	   aux=1;
 wattrset(std,COLOR_PAIR(aux));  
 mvwprintw(std,48,col,"     _    _    _____   ______                   ");
 mvwprintw(std,49,col,"    | |  | |  |  ___| |  ____|                  ");
 mvwprintw(std,50,col,"    | |  | |  | |     | | ___                   ");
 mvwprintw(std,51,col,"    | |  | |  | |     | ||_  |                  ");
 mvwprintw(std,52,col,"    | |__| |  | |___  | |_ | |                  ");
 mvwprintw(std,53,col,"    |______|  |_____| |______|                  ");
 wrefresh(std); 
   }
}
//*****************************************************************************






//******************************************************************************
/*Essa funcao imprime os valores de AC,MQ,MBR,IR,IBR,MAR,PC,e imprime tambem os nomes dos mesmos.
Parametros:WINDOW *std= um ponteiro para a janela std
           int l= um tipo de dado menor que um int para l 
           int c= um tipo de dado menor que um int para c
           memoria mem= um tipo de dado do tipo memoria
Retorno:sem retorno
Situacao:funcionando                                                            */
//******************************************************************************
void imprime_memoria(WINDOW *std,int linha,int col,memoria m)
{
  int cont,linha2,cinstrucao,cont2;
  linha2=linha+10;
  for(cont=0;cont<10;cont++,linha++)
  {
    mvwprintw(std,linha,col,"%d",m.dados[cont]);
    //wrefresh(std);
    }

  for(cinstrucao=0;cinstrucao<2;cinstrucao++,col=+59)
  {
	for(cont=0;cont<10;cont++,linha2++)
	    {
	    if(strcmp(m.instrucao[cont][cinstrucao],""))
		{
		  mvwprintw(std,linha2,col,"%s",m.instrucao[cont][cinstrucao]);
		  if(cinstrucao)
		  mvwprintw(std,linha2,col-1,";");
		}
	    }
	    linha2=linha;
	   wrefresh(std);
   }
}
//**************************************************************





//***********************************************************************************
/*Essa funcao preenche no espaco de IR e MAR os valores referentes a eles
Parametros:char *IR= um ponteiro de caracteres
           int *MAR= um ponteiro para
           char *instr= um ponteiro de caracteres 
Retorno:sem retorno
Situacao:funcionando                                                               */
//***********************************************************************************
void preenche_IR_MAR(char *IR,int *MAR,char *instrucao)
{
  *MAR=0;
  int flag=1,ccarac1,ccarac2;
  for(ccarac1=0,ccarac2=0;ccarac1<18&&ccarac2<18;ccarac1++,ccarac2++)
    {
      if(instrucao[ccarac2]!=40)
	{
	  IR[ccarac1]=instrucao[ccarac2];
	  IR[ccarac1+1]=0;
	}
      else
	{
	  IR[ccarac1]=instrucao[ccarac2];
	  if(flag)
	    {
	      for(ccarac1++,ccarac2++;instrucao[ccarac2]>47&&instrucao[ccarac2]<58;ccarac2++)
		*MAR=((*MAR)*10)+(instrucao[ccarac2]-48);
	      flag=0;
	    }
	  IR[ccarac1]=instrucao[ccarac2];
	  IR[ccarac1+1]=0;
	}
    }
}
//**********************************************************************************************
//**********************************************************************************************
void  decod_instr(WINDOW *std,int *PC, char *IR,int *MAR, int *AC, int *MQ, char *MBR,char IBR[18], memoria *m,int *clock,int *lin,int *col)
{
   mvwprintw(std, 29, 3, "Decodificando");
   mvwprintw(std, 30, 3, "Instrucao  ");
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   mvwprintw(std, 29, 3, "             ");
   mvwprintw(std, 30, 3, "             ");
   
    if (!strcmp(IR,"LOAD MQ"))
     load_mq(std, AC, MQ,clock);
   else
      if(!strcmp(IR, "LOAD MQ,M()"))
	load_mqm(std, MQ, *MAR, MBR, *m,clock);
      else
         if(!strcmp(IR, "STOR M()"))
	   stor_m(std, AC,*MAR, MBR, m,clock);
         else
            if(!strcmp(IR, "LOAD M()"))
	      load_m(std, AC, *MAR, MBR, m,clock);
            else
               if(!strcmp(IR, "LOAD-M()"))
		 load_menosm(std, AC, *MAR, MBR, m,clock);
               else
                  if(!strcmp(IR, "LOAD |M()|"))
		    load_modm(std, AC, *MAR, MBR, *m,clock);
                  else
                     if(!strcmp(IR, "LOAD - |M()|"))
                       load_menosmodm(std, AC, *MAR, MBR, *m,clock);
                     else
                        if(!strcmp(IR,"JUMP M(,0:19)"))
			  
			   jump_m019(std, *MAR, PC,IBR,clock,lin,col);
			  
                        else
                           if(!strcmp(IR,"JUMP M(,20:39)"))
			     jump_m2039(std, AC, MQ, IR, MAR, PC, MBR,IBR, m,clock,lin);
                           else
                              if(!strcmp(IR,"JUMP+M(,0:19)"))
				jump_maism019(std,MQ, *MAR, PC, *AC,MBR,IR,IBR,m,clock,lin,col);
                              else
                                 if(!strcmp(IR,"JUMP+M(,20:39)"))
				   jump_maism2039(std, AC, MQ, IR, MAR, PC, MBR,IBR, m,clock,lin,col);
                                 else
                                    if(!strcmp(IR, "ADD M()"))
				      add_m(std, AC, *MAR, MBR, *m,clock);
                                    else
                                       if(!strcmp(IR, "ADD |M()|")||!strcmp(IR,"ADD |-M()|"))
					 add_modm(std, AC, *MAR, MBR, *m,clock);
                                       else
                                          if(!strcmp(IR, "SUB M()")||!strcmp(IR, "SUB -M()"))
					    sub_m(std, AC, *MAR, MBR, *m,clock);
                                          else
                                             if(!strcmp(IR, "SUB |M()|")||!strcmp(IR,"SUB |-M()|"))
					       sub_modm(std, AC, *MAR, MBR, *m,clock);
                                             else
                                                if(!strcmp(IR, "MUL M()"))
						  mul_m(std, AC, *MAR, MBR, *m, MQ,clock);
                                                else
                                                   if(!strcmp(IR, "DIV M()"))
						     div_m(std, AC, *MAR, MBR, *m, MQ,clock);
                                                   else
                                                      if(!strcmp(IR,"LSH"))
							lsh(std, AC,clock);
                                                      else
                                                         if(!strcmp(IR,"RSH"))
							   rsh(std, AC,clock);
                                                         else
                                                            if(!strcmp(IR,"STOR M(,8:19)"))
                                                               stor_m819(std, *AC, *MAR, MBR, m,clock);
                                                            else
                                                               if(!strcmp(IR,"STOR M(,28:39)"))
                                                                  stor_m2839(std, *AC, *MAR, MBR, m,clock);
                                   
    //mvwprintw(std, 8, 9,"       ");
    mvwprintw(std, 29, 20, "                ");
    mvwprintw(std, 30, 20, "                ");
   //return(clock);
}
//************************************************************************************************
//essa subrotina Transfere o conteudo do registrador MQ paro o acumulador AC
//************************************************************************************************
void load_mq(WINDOW *std, int *AC, int *MQ,int *clock)
{
   mvwprintw(std, 29, 21, "Executando");
   mvwprintw(std, 30, 21, "LOAD MQ");
   *AC = *MQ;
   *MQ = 0;
   mvwprintw(std, 8, 9,"    ");
   mvwprintw(std, 8,12,"    ");
   mvwprintw(std, 8, 9, "%d", *AC);
   //mvwprintw(std, 8,23, "       ");
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
}
//************************************************************************
//Essa subrotina Transfere o conteudo da posicao de memoria X para MQ
//************************************************************************
void load_mqm(WINDOW *std, int *MQ,int MAR, char *MBR, memoria mem,int *clock)
{
   mvwprintw(std, 29, 21, "Executando");
   mvwprintw(std, 30, 21, "LOAD MQ,M(X)");
   MBR[0] = mem.dados[MAR];
   mvwprintw(std, 16, 11, "                 ");
   mvwprintw(std, 17, 11, "                 ");
   mvwprintw(std, 116, 11, "%d", MBR[0]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   *MQ = MBR[0];
   mvwprintw(std, 8, 23, "       ");
   mvwprintw(std, 8, 23, "%d", *MQ);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
}
//***********************************************************************
//Essa subrotina Transfere o conteudo do acumulador para a posicao de 
//memoria X
//***********************************************************************
void stor_m(WINDOW *std, int *AC,int MAR, char *MBR, memoria *mem,int *clock)
{int aux=0;
   mvwprintw(std, 29, 21, "Executando");
   mvwprintw(std, 30, 21, "STOR M(X)");
   MBR[0] = *AC;
   *AC = 0;
   mvwprintw(std, 8, 9, "       ");
   mvwprintw(std, 16, 11, "                 ");
   mvwprintw(std, 17, 11, "                 ");
   mvwprintw(std, 16, 11, "%d", MBR[0]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   mem->dados[MAR] = MBR[0];
   wattrset(std, COLOR_PAIR(2));
   //aux=*MAR;
   mvwprintw(std,MAR+8, 41," ");
   mvwprintw(std,MAR+8, 41,"%d",MBR[0]); //mem.dados[MAR]);
   //wattrset(std, COLOR_PAIR(3));
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
}
//**********************************************************************
//Essa subrotina Transfere valor M(X) para o acumulador
//**********************************************************************
void load_m(WINDOW *std, int *AC,int MAR, char *MBR, memoria *mem,int *clock)
{
   mvwprintw(std, 29, 21, "Executando");
   mvwprintw(std, 30, 21, "LOAD M(X)");
   MBR[0] = MAR;//mem->dados[MAR];
   mvwprintw(std, 16, 11, "                 ");
   mvwprintw(std, 17, 11, "                 ");
   mvwprintw(std, 16, 11, "%d", MBR[0]);
   wrefresh(std);
   getch();
   (*clock)++;
    mvwprintw(std,5,4,"%d",*clock);
   *AC = MBR[0];
   mvwprintw(std, 8, 9, "       ");
   mvwprintw(std, 8, 9, "%d", *AC);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock); 
}
//***************************************************************************
//Essa subrotina Transfere -M(X) para o acumulador
//***************************************************************************
void load_menosm(WINDOW *std, int *AC,int MAR, char *MBR, memoria *mem,int *clock)
{
   mvwprintw(std, 29, 21, "Executando");
   mvwprintw(std, 30, 21, "LOAD - M(X)");
   MBR[0] =-MAR; //-mem.dados[MAR];
   mvwprintw(std, 16, 11, "                 ");
   mvwprintw(std, 17, 11, "                 ");
   mvwprintw(std, 16, 11, "%d", MBR[0]);
   wrefresh(std);
   getch();
   (*clock)++;
    mvwprintw(std,5,4,"%d",*clock);
   *AC = MBR[0];
   mvwprintw(std, 8, 9, "       ");
   mvwprintw(std, 8, 9, "%d", *AC);
   wrefresh(std);
   getch();
   (*clock)++;
    mvwprintw(std,5,4,"%d",*clock);
}
//*************************************************************************
//Essa subrotina Transfere o valor absoluto de M(X) para o acumulador
//*************************************************************************
void load_modm(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem,int *clock)
{
   mvwprintw(std, 29, 21, "Executando");
   mvwprintw(std, 30, 21, "LOAD |M(X)|");
   if(mem.dados[MAR] < 0)
     MBR[0] =MAR*-1;// mem.dados[MAR]*(-1);
   else
     MBR[0] = MAR;//mem.dados[MAR];
   mvwprintw(std, 16, 11, "                 ");
   mvwprintw(std, 17, 11, "                 ");
   mvwprintw(std, 16, 11, "%d", MBR[0]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   *AC = MBR[0];
   mvwprintw(std, 8, 9, "       ");
   mvwprintw(std, 8, 9, "%d", *AC);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
}
//******************************************************************************
//Essa subrotina Transfere -|M(X)| para o acumulador
//******************************************************************************
void load_menosmodm(WINDOW *std, int *AC, int MAR, char *MBR, memoria mem,int *clock)
{
   mvwprintw(std, 29, 21, "Executando");
   mvwprintw(std, 30, 21, "LOAD - |M(X)|");
   if (mem.dados[MAR] < 0)
      MBR[0] = mem.dados[MAR];
   else
      MBR[0] = -mem.dados[MAR];
   mvwprintw(std, 16, 11, "                 ");
   mvwprintw(std, 17, 11, "                 ");
   mvwprintw(std, 16, 11, "%d", MBR[0]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   *AC = MBR[0];

   mvwprintw(std, 8, 9, "       ");
   mvwprintw(std, 8, 9, "%d", *AC);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
}
//*******************************************************
//*******************************************************
void jump_m019(WINDOW *std,int MAR,int *PC,char IBR[18],int *clock,int *lin,int *col)
{
   mvwprintw(std, 29, 21, "Executando");
   mvwprintw(std, 30, 21, "JUMP M(X,0:19)");
   wattrset(std,COLOR_PAIR(7));
   mvwprintw(std,*PC+8,34,"  ");
   *PC = MAR-1;
   *lin=*PC+8;
    wattrset(std,COLOR_PAIR(2));
   mvwprintw(std, 20, 25, "   ");
   mvwprintw(std, 20, 25, "%d", MAR);
   wrefresh(std);
    strcpy(IBR,""); 
 
}
//**************************************************************************************************************
//**************************************************************************************************************
void jump_m2039(WINDOW *std, int *AC, int *MQ, char *IR,int *MAR,int *PC, char *MBR,char IBR[18], memoria *mem,int *clock,int *lin)
{  int r=0;
   mvwprintw(std, 29, 21, "Executando");
   mvwprintw(std, 30, 21, "JUMP M(X,20:39)");
   wattrset(std,COLOR_PAIR(7));
   mvwprintw(std,*PC+8,34,"  ");
   *PC = *MAR;
   *lin=*PC+8;
   wattrset(std,COLOR_PAIR(2));
   mvwprintw(std, 20, 25, "   ");
   mvwprintw(std, 20, 25, "%d", *MAR);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   wattrset(std,COLOR_PAIR(7));
   mvwprintw(std,*lin,34,"->");
    wattrset(std,COLOR_PAIR(2));
   strcpy(&MBR[0],"");
   strcpy(&MBR[1], mem->instrucao[*MAR-10][1]);
   mvwprintw(std, 16, 11, "                ");
   mvwprintw(std, 17, 11, "                ");
   mvwprintw(std, 16, 11, "%s", &MBR[0]);
   mvwprintw(std, 17, 11, "%s", &MBR[1]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   preenche_IR_MAR(IR, MAR, &MBR[1]);
   mvwprintw(std, 24, 3, "                ");
   mvwprintw(std, 24, 3, "%s", IR);
   wrefresh(std);
   //getch();
   //(*clock)++;
   //mvwprintw(std,5,4,"%d",*clock);
   mvwprintw(std, 24, 23, "      ");
   mvwprintw(std, 24, 24, "%d", *MAR);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   //mvwprintw(std, 24, 23, "    ");
   mvwprintw(std, 29, 21, "               ");
   mvwprintw(std, 30, 21, "               ");
  
   decod_instr(std, PC, IR, MAR, AC, MQ, MBR,IBR, mem,clock,lin,lin);
   strcpy(IBR,"");   
}
//*******************************************************************
//*******************************************************************
void jump_maism019(WINDOW *std,int *MQ,int MAR,int *PC, int AC,char *MBR,char *IR,char IBR[18],memoria *mem,int *clock,int *lin,int *col)
{
   mvwprintw(std, 29, 21, "Executando");
   mvwprintw(std, 30, 21, "JUMP+M(X,0:19)");
   if(AC >= 0)
   {
     wattrset(std,COLOR_PAIR(7));
     mvwprintw(std,*PC+8,34,"  ");
     *PC = MAR-1;
     *lin=*PC+8;
     wattrset(std,COLOR_PAIR(2));
     mvwprintw(std, 20, 25, "   ");
     mvwprintw(std, 20, 25, "%d", MAR);
     wrefresh(std);
   strcpy(IBR,""); 
   }
   
}
//*****************************************************************************************************************
//*****************************************************************************************************************
void jump_maism2039(WINDOW *std, int *AC, int *MQ, char *IR,int *MAR,int *PC, char *MBR,char IBR[18], memoria *mem,int *clock,int *lin,int *col)
{int r=0;
   mvwprintw(std, 29, 21, "Executando");
   mvwprintw(std, 30, 21, "JUMP M(X,20:39)");
   if(*AC >= 0)
   {
     
     wattrset(std,COLOR_PAIR(7));
   mvwprintw(std,*PC+8,34,"  ");
   *PC = *MAR;
   *lin=*PC+8;
   wattrset(std,COLOR_PAIR(2));
   mvwprintw(std, 20, 25, "   ");
   mvwprintw(std, 20, 25, "%d", *MAR);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   wattrset(std,COLOR_PAIR(7));
   mvwprintw(std,*lin,34,"->");
    wattrset(std,COLOR_PAIR(2));
   strcpy(&MBR[0],"");
   strcpy(&MBR[1], mem->instrucao[*MAR-10][1]);
   mvwprintw(std, 16, 11, "                ");
   mvwprintw(std, 17, 11, "                ");
   mvwprintw(std, 16, 11, "%s", &MBR[0]);
   mvwprintw(std, 17, 11, "%s", &MBR[1]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   preenche_IR_MAR(IR, MAR, &MBR[1]);
   mvwprintw(std, 24, 3, "                ");
   mvwprintw(std, 24, 3, "%s", IR);
   wrefresh(std);
   //getch();
   //(*clock)++;
   //mvwprintw(std,5,4,"%d",*clock);
   mvwprintw(std, 24, 23, "      ");
   mvwprintw(std, 24, 24, "%d", *MAR);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   //mvwprintw(std, 24, 23, "    ");
   mvwprintw(std, 29, 21, "               ");
   mvwprintw(std, 30, 21, "               ");
  
   decod_instr(std, PC, IR, MAR, AC, MQ, MBR,IBR, mem,clock,lin,lin);
   strcpy(IBR,"");   

     /* *PC = *MAR;
      mvwprintw(std, 20, 25, "   ");
      mvwprintw(std, 20, 25, "%d", *PC);
      wrefresh(std);
      getch();
      (*clock)++;
      mvwprintw(std,5,4,"%d",*clock);                                                                                                                                                                                                                                                                                                      
      strcpy(&MBR[0],"");
      strcpy(&MBR[1], mem->instrucao[*MAR-10][1]);
      mvwprintw(std, 16, 11, "                ");
      mvwprintw(std, 17, 11, "                ");
      mvwprintw(std, 16, 11, "%s", &MBR[0]);
      mvwprintw(std, 17, 11, "%s", &MBR[1]);
      wrefresh(std);
      getch();
      (*clock)++;
      mvwprintw(std,5,4,"%d",*clock);
      preenche_IR_MAR(IR, MAR, &MBR[1]);
      mvwprintw(std, 24, 3, "                ");
      mvwprintw(std, 24, 3, "%s", IR);
      wrefresh(std);
      getch();
      (*clock)++;
      mvwprintw(std,5,4,"%d",*clock);
      mvwprintw(std, 24, 23, "         ");
      mvwprintw(std, 24, 23, "%d", *MAR);
      wrefresh(std);
      getch();
      (*clock)++;
      mvwprintw(std,5,4,"%d",*clock);
      mvwprintw(std, 28, 21, "               ");
      mvwprintw(std, 29, 21, "               ");*/
      //  decod_instr(std, PC, IR, MAR, AC, MQ, MBR, mem,clock,&lin,&col);
      
   }
   else
   {
      wrefresh(std);
      getch();
      (*clock)++;
      mvwprintw(std,5,4,"%d",*clock);
   }
}
//*********************************************************************
//*********************************************************************
void add_m(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem,int *clock)
{
   mvwprintw(std, 12, 8, "Executando ADD M(X)");
   MBR[0] = (*AC)+MAR;//mem.dados[MAR];
   mvwprintw(std, 16, 11, "                 ");
   mvwprintw(std, 17, 11, "                 ");
   mvwprintw(std, 16, 11, "%d", MBR[0]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   *AC = MBR[0];
   mvwprintw(std, 8, 9, "       ");
   mvwprintw(std, 8, 9, "%d", *AC);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
}
//************************************************************************
//************************************************************************
void add_modm(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem,int *clock)
{
   mvwprintw(std, 12, 8, "Executando ADD |M(X)|");
   if(mem.dados[MAR] < 0)
      MBR[0] = (*AC)+(MAR*-1);
   else
      MBR[0] = (*AC)+MAR;
   mvwprintw(std, 16, 11, "                 ");
   mvwprintw(std, 17, 11, "                 ");
   mvwprintw(std, 16, 11, "%d", MBR[0]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   *AC = MBR[0];
   mvwprintw(std, 8, 9, "       ");
   mvwprintw(std, 8, 9, "%d", *AC);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock); 
}
//*********************************************************************
//*********************************************************************
void sub_m(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem,int *clock)
{
   mvwprintw(std, 12, 8, "Executando SUB M(X)");
   MBR[0] = (*AC) - MAR;//mem.dados[MAR];
   mvwprintw(std, 16, 11, "                 ");
   mvwprintw(std, 17, 11, "                 ");
   mvwprintw(std, 16, 11, "%d", MBR[0]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   *AC = MBR[0];
   mvwprintw(std, 8, 9, "       ");
   mvwprintw(std, 8, 9, "%d", *AC);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
}
//************************************************************************
//************************************************************************
void sub_modm(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem,int *clock)
{
   mvwprintw(std, 12, 8, "Executando SUB |M(X)|");
   if(mem.dados[MAR] < 0)
      MBR[0] = (*AC)+mem.dados[MAR];
   else
      MBR[0] = (*AC)-mem.dados[MAR];
   mvwprintw(std, 16, 11, "                 ");
   mvwprintw(std, 17, 11, "                 ");
   mvwprintw(std, 16, 11, "%d", MBR[0]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   *AC = MBR[0];
   mvwprintw(std, 8, 9, "       ");
   mvwprintw(std, 8, 9, "%d", *AC);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
}
//*****************************************************************************
//*****************************************************************************
void mul_m(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem, int *MQ,int *clock)
{
   mvwprintw(std, 12, 8, "Executando MUL M(X)");
   MBR[0] = mem.dados[MAR] * (*MQ);
   mvwprintw(std, 16, 11, "                 ");
   mvwprintw(std, 17, 11, "                 ");
   mvwprintw(std, 16, 11, "%d", MBR[0]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   *AC = MBR[0];
   mvwprintw(std, 8, 9, "       ");
   mvwprintw(std, 8, 9, "%d", *AC);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
}
//*****************************************************************************
//*****************************************************************************
void div_m(WINDOW *std, int *AC,int MAR, char *MBR, memoria mem, int *MQ,int *clock)
{
   mvwprintw(std, 12, 8, "Executando DIV M(X)");
   MBR[0] = (*AC) / (mem.dados[MAR]);
   MBR[1] = (*AC) % (mem.dados[MAR]);
   mvwprintw(std, 16, 11, "                 ");
   mvwprintw(std, 17, 11, "                 ");
   mvwprintw(std, 16, 11, "Quociente: %d", MBR[0]);
   mvwprintw(std, 17, 11, "Resto: %d", MBR[1]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   *MQ = MBR[0];
   *AC = MBR[1];
   mvwprintw(std, 8, 9, "       ");
   mvwprintw(std, 8, 9, "%d", *AC);
   mvwprintw(std, 8, 23, "       ");
   mvwprintw(std, 8, 23, "%d", *MQ);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
}
//*****************************************************************************
//*****************************************************************************
void lsh(WINDOW *std, int *AC,int *clock)
{
  mvwprintw(std, 12, 8, "Executando LSH");
  *AC = (*AC) * 2;
  mvwprintw(std, 8, 9, "       ");
  mvwprintw(std, 8, 9, "%d", *AC);
  wrefresh(std);
  getch();
  (*clock)++;
  mvwprintw(std,5,4,"%d",*clock);
}
//******************************************************************************
//******************************************************************************
void rsh(WINDOW *std, int *AC,int *clock)
{
  mvwprintw(std, 12, 8, "Executando RSH");
  *AC = (*AC) / 2;
  mvwprintw(std, 8, 9, "       ");
  mvwprintw(std, 8, 9, "%d", *AC);
  wrefresh(std);
  getch();
  (*clock)++;
  mvwprintw(std,5,4,"%d",*clock);
}
//*******************************************************************************
//******************************************************************************
void stor_m819(WINDOW *std,int AC,int MAR, char *MBR, memoria *mem,int *clock)
{
   int cont1,cont2,aux1,aux2;

   mvwprintw(std, 29, 21, "Executando");
   mvwprintw(std, 30, 21, "STOR M(X,8:19)");
   for(cont1=0, cont2=0; cont2 < 18; cont1++, cont2++)
   {
      if(mem->instrucao[MAR-10][0][cont2] != 40)
      {
         (&MBR)[0][cont1]=mem->instrucao[MAR-10][0][cont2];
         (&MBR)[0][cont1+1]=0;
      }
      else
      {
         (&MBR)[0][cont1]=mem->instrucao[MAR-10][0][cont2];
         cont1++;
         if(AC < 10)
            (&MBR)[0][cont1] = AC + 48;
         else
         {
            aux1 = (AC / 10); 
	    aux2 = (AC % 10);
            (&MBR)[0][cont1] = aux1 + 48;
            cont1++;
            (&MBR)[0][cont1] = aux2 + 48;
         }
         for(cont2++;mem->instrucao[MAR-10][0][cont2] > 47 && mem->instrucao[MAR-10][0][cont2] < 58; cont2++);
         cont2--;
      }
   }
   mvwprintw(std, 16, 11, "                ");
   mvwprintw(std, 17, 11, "                ");
   mvwprintw(std, 16, 11, "%s", (&MBR)[0]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   strcpy(mem->instrucao[MAR-10][0], (&MBR)[0]);
   wattrset(std, COLOR_PAIR(1));
   mvwprintw(std, MAR+8, 41, "             ");
   mvwprintw(std, MAR+8, 41, "%s", mem->instrucao[MAR-10][0]);
   wattrset(std, COLOR_PAIR(3));
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
}
//**************************************************************************************
//*************************************************************************************
void stor_m2839(WINDOW *std, int AC,int MAR, char *MBR, memoria *mem,int *clock)
{
   int cont1,cont2,aux1,aux2;
   mvwprintw(std, 29, 21, "Executando");
   mvwprintw(std, 30, 21, "STOR M(X,28:39)");
   for(cont1=0, cont2=0; cont2 < 18; cont1++, cont2++)
   {
      if(mem->instrucao[MAR-10][1][cont2] != 40)
      {
         (&MBR)[0][cont1]=mem->instrucao[MAR-10][1][cont2];
         (&MBR)[0][cont1+1] = 0;
      }
      else
      {
         (&MBR)[0][cont1]=mem->instrucao[MAR-10][1][cont2];
         cont1++;
         if(AC < 10)
            (&MBR)[0][cont1] = AC + 48;
         else
         {
             aux1 = (AC / 10);
	     aux2 = (AC % 10);
             (&MBR)[0][cont1] = aux1 + 48;
             cont1++;
             (&MBR)[0][cont1] = aux2 + 48;
         }
         for(cont2++;mem->instrucao[MAR-10][1][cont2] > 47 && mem->instrucao[MAR-10][1][cont2] < 58; cont2++);
         cont2--;
      }
   }
   mvwprintw(std, 16, 11, "                ");
   mvwprintw(std, 17, 11, "                ");
   mvwprintw(std, 16, 11, "%s", (&MBR)[0]);
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
   strcpy(mem->instrucao[MAR-10][1], (&MBR)[0]);
   wattrset(std, COLOR_PAIR(1));
   //wbkgd(std,COLOR_PAIR(2));
   mvwprintw(std, MAR+8, 60, "            ");
   mvwprintw(std, MAR+8, 59, "%s",mem->instrucao[MAR-10][1]);
   wattrset(std, COLOR_PAIR(3));
   wrefresh(std);
   getch();
   (*clock)++;
   mvwprintw(std,5,4,"%d",*clock);
}
