
ASN1_INTEGER * save_serial(char *param_1,char *param_2,BIGNUM *param_3,ASN1_INTEGER **param_4)

{
  size_t sVar1;
  size_t sVar2;
  BIO_METHOD *type;
  BIO *bp;
  long lVar3;
  ASN1_INTEGER *a;
  ASN1_INTEGER *pAVar4;
  int in_GS_OFFSET;
  char local_120 [256];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_2 == (char *)0x0) {
    sVar1 = strlen(param_1);
    if (0xff < (int)sVar1) goto LAB_0807b920;
    BUF_strlcpy(local_120,param_1,0x100);
  }
  else {
    sVar1 = strlen(param_1);
    sVar2 = strlen(param_2);
    if (0xff < (int)(sVar1 + 1 + sVar2)) {
LAB_0807b920:
      pAVar4 = (ASN1_INTEGER *)0x0;
      BIO_printf(bio_err,"file name too long\n");
      goto LAB_0807b8df;
    }
    BIO_snprintf(local_120,0x100,"%s.%s",param_1,param_2);
  }
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    pAVar4 = (ASN1_INTEGER *)0x0;
    ERR_print_errors(bio_err);
  }
  else {
    lVar3 = BIO_ctrl(bp,0x6c,5,local_120);
    if (lVar3 < 1) {
      pAVar4 = (ASN1_INTEGER *)0x0;
      perror(param_1);
    }
    else {
      a = BN_to_ASN1_INTEGER(param_3,(ASN1_INTEGER *)0x0);
      if (a == (ASN1_INTEGER *)0x0) {
        BIO_printf(bio_err,"error converting serial to ASN.1 format\n");
        pAVar4 = a;
      }
      else {
        i2a_ASN1_INTEGER(bp,a);
        BIO_puts(bp,"\n");
        if (param_4 == (ASN1_INTEGER **)0x0) {
          BIO_free_all(bp);
          pAVar4 = (ASN1_INTEGER *)0x1;
          ASN1_INTEGER_free(a);
          goto LAB_0807b8df;
        }
        *param_4 = a;
        pAVar4 = (ASN1_INTEGER *)0x1;
      }
    }
    BIO_free_all(bp);
  }
LAB_0807b8df:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

