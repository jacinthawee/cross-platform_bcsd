
int PEM_write_X509_AUX(FILE *fp,X509 *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write(i2d_X509_AUX + 1,"TRUSTED CERTIFICATE",fp,x,(EVP_CIPHER *)0x0,(uchar *)0x0,
                         0,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}
