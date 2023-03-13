
int BIO_printf(BIO *bio,char *format,...)

{
  int iVar1;
  
  iVar1 = BIO_vprintf(bio,format,&stack0x0000000c);
  return iVar1;
}

