
int PEM_write_bio_Parameters(BIO *bp,EVP_PKEY *x)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_60 [80];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = 0;
  pEVar1 = x->ameth;
  if (pEVar1 == (EVP_PKEY_ASN1_METHOD *)0x0) {
    iVar2 = 0;
  }
  else if (*(int *)(pEVar1 + 0x3c) != 0) {
    BIO_snprintf(local_60,0x50,"%s PARAMETERS",*(undefined4 *)(pEVar1 + 0xc));
    iVar2 = PEM_ASN1_write_bio(*(undefined1 **)(x->ameth + 0x3c),local_60,bp,x,(EVP_CIPHER *)0x0,
                               (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

