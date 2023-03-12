
char * TS_ASN1_INTEGER_print_bio(BIO *param_1,ASN1_INTEGER *param_2)

{
  char *__s;
  int iVar1;
  size_t len;
  char *pcVar2;
  BIGNUM BStack_24;
  
  BN_init(&BStack_24);
  ASN1_INTEGER_to_BN(param_2,&BStack_24);
  __s = BN_bn2hex(&BStack_24);
  if (__s != (char *)0x0) {
    iVar1 = BIO_write(param_1,&DAT_0015dcd4,2);
    if (iVar1 < 1) {
      pcVar2 = (char *)0x0;
    }
    else {
      len = strlen(__s);
      iVar1 = BIO_write(param_1,__s,len);
      if (iVar1 < 1) {
        pcVar2 = (char *)0x0;
      }
      else {
        pcVar2 = (char *)0x1;
      }
    }
    CRYPTO_free(__s);
    __s = pcVar2;
  }
  BN_free(&BStack_24);
  return __s;
}

