
int __regparm3 int_new_class(int param_1)

{
  int iVar1;
  
  CRYPTO_lock(param_1,9,(char *)0x2,(int)"ex_data.c");
  iVar1 = ex_class;
  ex_class = ex_class + 1;
  CRYPTO_lock(ex_class,10,(char *)0x2,(int)"ex_data.c");
  return iVar1;
}

