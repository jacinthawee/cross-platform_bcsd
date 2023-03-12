
BIGNUM * load_serial(char *param_1,int param_2,ASN1_INTEGER **param_3)

{
  ASN1_INTEGER *ai;
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  int iVar2;
  BIGNUM *rnd;
  ASN1_INTEGER *pAVar3;
  int in_GS_OFFSET;
  char local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ai = ASN1_INTEGER_new();
  if (ai == (ASN1_INTEGER *)0x0) {
    rnd = (BIGNUM *)0x0;
    goto LAB_0807b6b2;
  }
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    rnd = (BIGNUM *)0x0;
    ERR_print_errors(bio_err);
  }
  else {
    lVar1 = BIO_ctrl(bp,0x6c,3,param_1);
    if (lVar1 < 1) {
      if (param_2 == 0) {
        rnd = (BIGNUM *)0x0;
        perror(param_1);
      }
      else {
        rnd = BN_new();
        if (((rnd == (BIGNUM *)0x0) || (iVar2 = BN_pseudo_rand(rnd,0x40,0,0), iVar2 == 0)) ||
           (pAVar3 = BN_to_ASN1_INTEGER(rnd,ai), pAVar3 == (ASN1_INTEGER *)0x0)) {
          BIO_printf(bio_err,"Out of memory\n");
        }
joined_r0x0807b71d:
        if ((rnd != (BIGNUM *)0x0) && (param_3 != (ASN1_INTEGER **)0x0)) {
          *param_3 = ai;
          BIO_free(bp);
          goto LAB_0807b6b2;
        }
      }
    }
    else {
      iVar2 = a2i_ASN1_INTEGER(bp,ai,local_420,0x400);
      if (iVar2 == 0) {
        rnd = (BIGNUM *)0x0;
        BIO_printf(bio_err,"unable to load number from %s\n",param_1);
      }
      else {
        rnd = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
        if (rnd != (BIGNUM *)0x0) goto joined_r0x0807b71d;
        BIO_printf(bio_err,"error converting number from bin to BIGNUM\n");
      }
    }
    BIO_free(bp);
  }
  ASN1_INTEGER_free(ai);
LAB_0807b6b2:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return rnd;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

