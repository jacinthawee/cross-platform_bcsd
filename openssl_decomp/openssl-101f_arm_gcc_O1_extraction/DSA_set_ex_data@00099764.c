
int DSA_set_ex_data(DSA *d,int idx,void *arg)

{
  int iVar1;
  
  iVar1 = CRYPTO_set_ex_data(&d->ex_data,idx,arg);
  return iVar1;
}
