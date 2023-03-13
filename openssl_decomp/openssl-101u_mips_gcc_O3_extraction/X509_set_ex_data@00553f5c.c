
int X509_set_ex_data(X509 *r,int idx,void *arg)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00553f68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_CRYPTO_set_ex_data_006a8360)(&r->ex_data);
  return iVar1;
}

