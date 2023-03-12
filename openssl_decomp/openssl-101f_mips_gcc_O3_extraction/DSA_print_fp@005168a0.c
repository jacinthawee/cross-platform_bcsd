
int DSA_print_fp(FILE *bp,DSA *x,int off)

{
  BIO_METHOD *type;
  BIO *bp_00;
  int iVar1;
  int iVar2;
  
  type = BIO_s_file();
  bp_00 = BIO_new(type);
  if (bp_00 == (BIO *)0x0) {
    ERR_put_error(10,0x69,7,"dsa_prn.c",0x48);
    return 0;
  }
  BIO_ctrl(bp_00,0x6a,0,bp);
  iVar1 = (*(code *)PTR_EVP_PKEY_new_006a8710)();
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_EVP_PKEY_set1_DSA_006a8758)(iVar1,x);
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_EVP_PKEY_print_private_006a8840)(bp_00,iVar1,off,0);
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar1);
      goto LAB_00516944;
    }
  }
  iVar2 = 0;
LAB_00516944:
  BIO_free(bp_00);
  return iVar2;
}
