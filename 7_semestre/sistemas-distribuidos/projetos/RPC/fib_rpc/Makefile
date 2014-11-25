all: simp todosC client server

simp : simp.x
	rpcgen -C simp.x

	
todosC: *.c
	gcc -c *.c
	
client: fibclient.o simp_clnt.o simp_xdr.o
	gcc -o client fibclient.o simp_clnt.o simp_xdr.o -lnsl
	
server:	fibservice.o simp_svc.o simp_xdr.o
	gcc -o server fibservice.o simp_svc.o simp_xdr.o -lrpcsvc -lnsl


