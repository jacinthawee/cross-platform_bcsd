
int PEM_write_bio_Parameters(BIO *bp,EVP_PKEY *x)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  char acStack_6c [80];
  int local_1c;
  
  pEVar2 = x->ameth;
  local_1c = __TMC_END__;
  pEVar1 = pEVar2;
  if ((pEVar2 != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (pEVar1 = *(EVP_PKEY_ASN1_METHOD **)(pEVar2 + 0x3c), pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0)) {
    BIO_snprintf(acStack_6c,0x50,"%s PARAMETERS",*(undefined4 *)(pEVar2 + 0xc));
    pEVar1 = (EVP_PKEY_ASN1_METHOD *)
             PEM_ASN1_write_bio(*(undefined1 **)(x->ameth + 0x3c),acStack_6c,bp,x,(EVP_CIPHER *)0x0,
                                (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
  }
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)pEVar1;
}

