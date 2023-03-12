
int PEM_write_X509_CERT_PAIR(FILE *fp,X509_CERT_PAIR *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write(PTR_i2d_X509_CERT_PAIR_006a9fb0,"CERTIFICATE PAIR",fp,x,(EVP_CIPHER *)0x0,
                         (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}

