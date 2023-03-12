
int DH_set_ex_data(DH *d,int idx,void *arg)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00518434. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_CRYPTO_set_ex_data_006a9480)(&d->ex_data);
  return iVar1;
}

