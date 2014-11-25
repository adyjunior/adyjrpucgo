/*  descricao XDR para listas */


#define OK    0 
#define  ERRO 1 

struct no{
          int         dado;
          struct no * next;
         }; 


program  LISTAPROG{
 version  LISTAVER{
       int init ( int )=1;
       int  insere ( int ) = 2;
       int  deleta ( int ) =3; 
       int  consulta ( int ) = 4;
       int  imprima ( int ) =5;
} = 1;
} = 0x20000199;

