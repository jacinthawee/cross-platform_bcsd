
int ECParameters_print_fp(FILE *fp,EC_KEY *key)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  int iVar2;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x94,0x20,"eck_prn.c",0x6b);
    return 0;
  }
  BIO_ctrl(bp,0x6a,0,fp);
  iVar1 = (*(code *)PTR_EVP_PKEY_new_006a7620)();
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_EVP_PKEY_set1_EC_KEY_006a86a8)(iVar1,key);
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_EVP_PKEY_print_params_006a7754)(bp,iVar1,4,0);
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar1);
      goto LAB_0050a348;
    }
  }
  iVar2 = 0;
LAB_0050a348:
  BIO_free(bp);
  return iVar2;
}

