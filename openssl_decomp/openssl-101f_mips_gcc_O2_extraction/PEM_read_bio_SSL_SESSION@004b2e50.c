
SSL_SESSION * PEM_read_bio_SSL_SESSION(BIO *bp,SSL_SESSION **x,undefined1 *cb,void *u)

{
  SSL_SESSION *pSVar1;
  
  pSVar1 = (SSL_SESSION *)
           (*(code *)PTR_PEM_ASN1_read_bio_006a94c4)
                     (PTR_d2i_SSL_SESSION_006a8d70,"SSL SESSION PARAMETERS",bp,x,cb,u,&_gp);
  return pSVar1;
}

