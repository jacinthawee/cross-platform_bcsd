
int BIO_set_ex_data(BIO *bio,int idx,void *data)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00522004. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_CRYPTO_set_ex_data_006a9480)(&bio->ex_data);
  return iVar1;
}

