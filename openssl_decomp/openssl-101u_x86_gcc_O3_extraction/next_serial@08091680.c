
ASN1_INTEGER * __regparm3 next_serial(char *param_1)

{
  ASN1_INTEGER *a;
  BIO *bp;
  int iVar1;
  ASN1_INTEGER *pAVar2;
  ASN1_INTEGER *pAVar3;
  BIGNUM *a_00;
  int in_GS_OFFSET;
  char local_410 [1024];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  a = ASN1_INTEGER_new();
  if (a == (ASN1_INTEGER *)0x0) {
    a_00 = (BIGNUM *)0x0;
    bp = (BIO *)0x0;
  }
  else {
    bp = BIO_new_file(param_1,"r");
    if (bp == (BIO *)0x0) {
      ERR_clear_error();
      BIO_printf(bio_err,"Warning: could not open file %s for reading, using serial number: 1\n",
                 param_1);
      a_00 = (BIGNUM *)0x0;
      pAVar2 = (ASN1_INTEGER *)ASN1_INTEGER_set(a,1);
      pAVar3 = a;
joined_r0x080917ca:
      a = pAVar3;
      if (pAVar2 != (ASN1_INTEGER *)0x0) goto LAB_08091703;
    }
    else {
      iVar1 = a2i_ASN1_INTEGER(bp,a,local_410,0x400);
      if (iVar1 == 0) {
        a_00 = (BIGNUM *)0x0;
        BIO_printf(bio_err,"unable to load number from %s\n",param_1);
      }
      else {
        a_00 = ASN1_INTEGER_to_BN(a,(BIGNUM *)0x0);
        if (a_00 != (BIGNUM *)0x0) {
          ASN1_INTEGER_free(a);
          iVar1 = BN_add_word(a_00,1);
          a = (ASN1_INTEGER *)0x0;
          if (iVar1 != 0) {
            pAVar3 = BN_to_ASN1_INTEGER(a_00,(ASN1_INTEGER *)0x0);
            pAVar2 = pAVar3;
            goto joined_r0x080917ca;
          }
        }
      }
    }
  }
  pAVar3 = (ASN1_INTEGER *)0x0;
  ASN1_INTEGER_free(a);
LAB_08091703:
  BIO_free_all(bp);
  BN_free(a_00);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

