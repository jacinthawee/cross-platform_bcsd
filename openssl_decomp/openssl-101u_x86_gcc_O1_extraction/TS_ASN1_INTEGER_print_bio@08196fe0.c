
bool TS_ASN1_INTEGER_print_bio(BIO *param_1,ASN1_INTEGER *param_2)

{
  char *__s;
  int iVar1;
  size_t len;
  bool bVar2;
  int in_GS_OFFSET;
  BIGNUM local_34;
  int local_20;
  
  bVar2 = false;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  BN_init(&local_34);
  ASN1_INTEGER_to_BN(param_2,&local_34);
  __s = BN_bn2hex(&local_34);
  if (__s != (char *)0x0) {
    iVar1 = BIO_write(param_1,"0x",2);
    if (0 < iVar1) {
      len = strlen(__s);
      iVar1 = BIO_write(param_1,__s,len);
      bVar2 = 0 < iVar1;
    }
    CRYPTO_free(__s);
  }
  BN_free(&local_34);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

