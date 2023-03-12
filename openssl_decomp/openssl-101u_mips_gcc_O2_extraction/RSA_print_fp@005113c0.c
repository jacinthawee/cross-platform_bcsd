
int RSA_print_fp(FILE *fp,RSA *r,int offset)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  int iVar2;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(4,0x74,7,"rsa_prn.c",0x48);
    return 0;
  }
  BIO_ctrl(bp,0x6a,0,fp);
  iVar1 = (*(code *)PTR_EVP_PKEY_new_006a7620)();
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_EVP_PKEY_set1_RSA_006a7624)(iVar1,r);
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_EVP_PKEY_print_private_006a7750)(bp,iVar1,offset,0);
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar1);
      goto LAB_00511464;
    }
  }
  iVar2 = 0;
LAB_00511464:
  BIO_free(bp);
  return iVar2;
}

