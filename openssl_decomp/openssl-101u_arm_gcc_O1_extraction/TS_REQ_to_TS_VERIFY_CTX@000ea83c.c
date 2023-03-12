
uint * TS_REQ_to_TS_VERIFY_CTX(int param_1,uint *param_2)

{
  ASN1_OBJECT *pAVar1;
  undefined4 uVar2;
  X509_ALGOR *pXVar3;
  ASN1_STRING *pAVar4;
  uint num;
  void *__dest;
  uchar *__src;
  uint *__s;
  
  if (param_1 == 0) {
    OpenSSLDie("ts_verify_ctx.c",0x79,"req != NULL");
    if (param_2 == (uint *)0x0) goto LAB_000ea980;
LAB_000ea852:
    X509_STORE_free((X509_STORE *)param_2[1]);
    sk_pop_free((_STACK *)param_2[2],X509_free + 1);
    ASN1_OBJECT_free((ASN1_OBJECT *)param_2[3]);
    X509_ALGOR_free((X509_ALGOR *)param_2[4]);
    CRYPTO_free((void *)param_2[5]);
    BIO_free_all((BIO *)param_2[7]);
    ASN1_INTEGER_free((ASN1_INTEGER *)param_2[8]);
    GENERAL_NAME_free((GENERAL_NAME *)param_2[9]);
    memset(param_2,0,0x28);
    __s = param_2;
  }
  else {
    if (param_2 != (uint *)0x0) goto LAB_000ea852;
LAB_000ea980:
    __s = (uint *)CRYPTO_malloc(0x28,"ts_verify_ctx.c",0x43);
    if (__s == (uint *)0x0) {
      ERR_put_error(0x2f,0x90,0x41,"ts_verify_ctx.c",0x47);
      return param_2;
    }
    memset(__s,(int)param_2,0x28);
  }
  *__s = 0x6e;
  pAVar1 = (ASN1_OBJECT *)TS_REQ_get_policy_id(param_1);
  if (pAVar1 == (ASN1_OBJECT *)0x0) {
    *__s = *__s & 0xfffffffb;
  }
  else {
    pAVar1 = OBJ_dup(pAVar1);
    __s[3] = (uint)pAVar1;
    if (pAVar1 == (ASN1_OBJECT *)0x0) goto LAB_000ea90c;
  }
  uVar2 = TS_REQ_get_msg_imprint(param_1);
  pXVar3 = (X509_ALGOR *)TS_MSG_IMPRINT_get_algo();
  pXVar3 = X509_ALGOR_dup(pXVar3);
  __s[4] = (uint)pXVar3;
  if (pXVar3 != (X509_ALGOR *)0x0) {
    pAVar4 = (ASN1_STRING *)TS_MSG_IMPRINT_get_msg(uVar2);
    num = ASN1_STRING_length(pAVar4);
    __s[6] = num;
    __dest = CRYPTO_malloc(num,"ts_verify_ctx.c",0x90);
    __s[5] = (uint)__dest;
    if (__dest != (void *)0x0) {
      __src = ASN1_STRING_data(pAVar4);
      memcpy(__dest,__src,__s[6]);
      pAVar4 = (ASN1_STRING *)TS_REQ_get_nonce(param_1);
      if (pAVar4 == (ASN1_STRING *)0x0) {
        *__s = *__s & 0xffffffdf;
        return __s;
      }
      pAVar4 = ASN1_INTEGER_dup(pAVar4);
      __s[8] = (uint)pAVar4;
      if (pAVar4 != (ASN1_STRING *)0x0) {
        return __s;
      }
    }
  }
LAB_000ea90c:
  if (param_2 == (uint *)0x0) {
    X509_STORE_free((X509_STORE *)__s[1]);
    sk_pop_free((_STACK *)__s[2],X509_free + 1);
    ASN1_OBJECT_free((ASN1_OBJECT *)__s[3]);
    X509_ALGOR_free((X509_ALGOR *)__s[4]);
    CRYPTO_free((void *)__s[5]);
    BIO_free_all((BIO *)__s[7]);
    ASN1_INTEGER_free((ASN1_INTEGER *)__s[8]);
    GENERAL_NAME_free((GENERAL_NAME *)__s[9]);
    memset(__s,0,0x28);
    CRYPTO_free(__s);
    return (uint *)0x0;
  }
  X509_STORE_free((X509_STORE *)param_2[1]);
  sk_pop_free((_STACK *)param_2[2],X509_free + 1);
  ASN1_OBJECT_free((ASN1_OBJECT *)param_2[3]);
  X509_ALGOR_free((X509_ALGOR *)param_2[4]);
  CRYPTO_free((void *)param_2[5]);
  BIO_free_all((BIO *)param_2[7]);
  ASN1_INTEGER_free((ASN1_INTEGER *)param_2[8]);
  GENERAL_NAME_free((GENERAL_NAME *)param_2[9]);
  memset(param_2,0,0x28);
  return (uint *)0x0;
}

