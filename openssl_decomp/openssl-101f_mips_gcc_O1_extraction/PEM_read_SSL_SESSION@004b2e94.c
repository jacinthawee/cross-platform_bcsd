
SSL_SESSION * PEM_read_SSL_SESSION(FILE *fp,SSL_SESSION **x,undefined1 *cb,void *u)

{
  SSL_SESSION *pSVar1;
  
  pSVar1 = (SSL_SESSION *)
           (*(code *)PTR_PEM_ASN1_read_006a94c8)
                     (PTR_d2i_SSL_SESSION_006a8d70,"SSL SESSION PARAMETERS",fp,x,cb,u,&_gp);
  return pSVar1;
}

