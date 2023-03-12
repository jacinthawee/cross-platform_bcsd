
int DSAparams_print_fp(FILE *fp,DSA *x)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  int iVar2;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(10,0x65,7,"dsa_prn.c",0x58);
    return 0;
  }
  BIO_ctrl(bp,0x6a,0,fp);
  iVar1 = (*(code *)PTR_EVP_PKEY_new_006a8710)();
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_EVP_PKEY_set1_DSA_006a8758)(iVar1,x);
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_EVP_PKEY_print_params_006a8844)(bp,iVar1,4,0);
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar1);
      goto LAB_00516a88;
    }
  }
  iVar2 = 0;
LAB_00516a88:
  BIO_free(bp);
  return iVar2;
}

