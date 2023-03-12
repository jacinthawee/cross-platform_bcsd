
void next_serial(char *param_1)

{
  BIO *a;
  BIO *bp;
  BIO *a_00;
  BIO *pBVar1;
  BIO *pBVar2;
  char acStack_41c [1024];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  a = (BIO *)ASN1_INTEGER_new();
  a_00 = a;
  bp = a;
  if (a != (BIO *)0x0) {
    bp = BIO_new_file(param_1,"r");
    if (bp == (BIO *)0x0) {
      ERR_clear_error();
      BIO_printf(bio_err,"Warning: could not open file %s for reading, using serial number: 1\n",
                 param_1);
      pBVar1 = (BIO *)ASN1_INTEGER_set((ASN1_INTEGER *)a,1);
      pBVar2 = a;
      a_00 = bp;
joined_r0x000421a6:
      a = pBVar2;
      if (pBVar1 != (BIO *)0x0) goto LAB_00042126;
    }
    else {
      a_00 = (BIO *)a2i_ASN1_INTEGER(bp,(ASN1_INTEGER *)a,acStack_41c,0x400);
      if (a_00 == (BIO *)0x0) {
        BIO_printf(bio_err,"unable to load number from %s\n",param_1);
      }
      else {
        a_00 = (BIO *)ASN1_INTEGER_to_BN((ASN1_INTEGER *)a,(BIGNUM *)0x0);
        if (a_00 != (BIO *)0x0) {
          ASN1_INTEGER_free((ASN1_INTEGER *)a);
          a = (BIO *)BN_add_word((BIGNUM *)a_00,1);
          if (a != (BIO *)0x0) {
            pBVar2 = (BIO *)BN_to_ASN1_INTEGER((BIGNUM *)a_00,(ASN1_INTEGER *)0x0);
            pBVar1 = pBVar2;
            goto joined_r0x000421a6;
          }
        }
      }
    }
  }
  pBVar2 = (BIO *)0x0;
  ASN1_INTEGER_free((ASN1_INTEGER *)a);
LAB_00042126:
  BIO_free_all(bp);
  BN_free((BIGNUM *)a_00);
  if (local_1c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pBVar2);
}

