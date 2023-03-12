
int PEM_write_SSL_SESSION(FILE *fp,SSL_SESSION *x)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_PEM_ASN1_write_006a94d0)
                    (PTR_i2d_SSL_SESSION_006a8d78,"SSL SESSION PARAMETERS",fp,x,0,0,0,0,0);
  return iVar1;
}

