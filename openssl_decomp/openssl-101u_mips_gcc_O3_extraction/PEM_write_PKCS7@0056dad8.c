
int PEM_write_PKCS7(FILE *fp,PKCS7 *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write(PTR_i2d_PKCS7_006a8e4c,"PKCS7",fp,x,(EVP_CIPHER *)0x0,(uchar *)0x0,0,
                         (undefined1 *)0x0,(void *)0x0);
  return iVar1;
}
