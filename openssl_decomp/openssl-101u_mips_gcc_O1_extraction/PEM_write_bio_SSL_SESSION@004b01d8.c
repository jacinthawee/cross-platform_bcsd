
int PEM_write_bio_SSL_SESSION(BIO *bp,SSL_SESSION *x)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_PEM_ASN1_write_bio_006a83b0)
                    (PTR_i2d_SSL_SESSION_006a7c88,"SSL SESSION PARAMETERS",bp,x,0,0,0,0,0);
  return iVar1;
}

