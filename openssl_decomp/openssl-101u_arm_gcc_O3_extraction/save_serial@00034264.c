
ASN1_INTEGER * save_serial(char *param_1,char *param_2,BIGNUM *param_3,ASN1_INTEGER **param_4)

{
  size_t sVar1;
  size_t sVar2;
  BIO_METHOD *pBVar3;
  BIO *bp;
  long lVar4;
  ASN1_INTEGER *a;
  char acStack_120 [260];
  
  if (param_2 == (char *)0x0) {
    sVar1 = strlen(param_1);
    if (0xff < (int)sVar1) goto LAB_000342fc;
    BUF_strlcpy(acStack_120,param_1,0x100);
    pBVar3 = BIO_s_file();
    bp = BIO_new(pBVar3);
  }
  else {
    sVar1 = strlen(param_1);
    sVar2 = strlen(param_2);
    if (0xff < (int)(sVar2 + sVar1 + 1)) {
LAB_000342fc:
      BIO_printf(bio_err,"file name too long\n");
      return (ASN1_INTEGER *)0x0;
    }
    BIO_snprintf(acStack_120,0x100,"%s.%s",param_1,param_2);
    pBVar3 = BIO_s_file();
    bp = BIO_new(pBVar3);
  }
  if (bp == (BIO *)0x0) {
    ERR_print_errors(bio_err);
    return (ASN1_INTEGER *)0x0;
  }
  lVar4 = BIO_ctrl(bp,0x6c,5,acStack_120);
  if (lVar4 < 1) {
    a = (ASN1_INTEGER *)0x0;
    perror(param_1);
  }
  else {
    a = BN_to_ASN1_INTEGER(param_3,(ASN1_INTEGER *)0x0);
    if (a == (ASN1_INTEGER *)0x0) {
      BIO_printf(bio_err,"error converting serial to ASN.1 format\n");
    }
    else {
      i2a_ASN1_INTEGER(bp,a);
      BIO_puts(bp,"\n");
      if (param_4 == (ASN1_INTEGER **)0x0) {
        BIO_free_all(bp);
        ASN1_INTEGER_free(a);
        return (ASN1_INTEGER *)0x1;
      }
      *param_4 = a;
      a = (ASN1_INTEGER *)0x1;
    }
  }
  BIO_free_all(bp);
  return a;
}

