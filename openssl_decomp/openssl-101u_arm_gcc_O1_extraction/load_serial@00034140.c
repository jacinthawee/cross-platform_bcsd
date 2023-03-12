
void load_serial(char *param_1,BIGNUM *param_2,ASN1_INTEGER **param_3)

{
  ASN1_INTEGER *ai;
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  int iVar2;
  ASN1_INTEGER *pAVar3;
  char acStack_424 [1024];
  int local_24;
  
  local_24 = __stack_chk_guard;
  ai = ASN1_INTEGER_new();
  if (ai != (ASN1_INTEGER *)0x0) {
    type = BIO_s_file();
    bp = BIO_new(type);
    if (bp != (BIO *)0x0) {
      lVar1 = BIO_ctrl(bp,0x6c,3,param_1);
      if (lVar1 < 1) {
        if (param_2 == (BIGNUM *)0x0) {
          perror(param_1);
        }
        else {
          param_2 = BN_new();
          if (((param_2 == (BIGNUM *)0x0) || (iVar2 = BN_pseudo_rand(param_2,0x40,0,0), iVar2 == 0))
             || (pAVar3 = BN_to_ASN1_INTEGER(param_2,ai), pAVar3 == (ASN1_INTEGER *)0x0)) {
            BIO_printf(bio_err,"Out of memory\n");
          }
LAB_000341a4:
          if (param_2 != (BIGNUM *)0x0 && param_3 != (ASN1_INTEGER **)0x0) {
            *param_3 = ai;
            ai = (ASN1_INTEGER *)0x0;
          }
        }
      }
      else {
        param_2 = (BIGNUM *)a2i_ASN1_INTEGER(bp,ai,acStack_424,0x400);
        if (param_2 == (BIGNUM *)0x0) {
          BIO_printf(bio_err,"unable to load number from %s\n",param_1);
        }
        else {
          param_2 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
          if (param_2 != (BIGNUM *)0x0) goto LAB_000341a4;
          BIO_printf(bio_err,"error converting number from bin to BIGNUM\n");
        }
      }
      BIO_free(bp);
      goto LAB_000341ba;
    }
    ERR_print_errors(bio_err);
  }
  param_2 = (BIGNUM *)0x0;
LAB_000341ba:
  if (ai != (ASN1_INTEGER *)0x0) {
    ASN1_INTEGER_free(ai);
  }
  if (local_24 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_2);
  }
  return;
}

