
uint * TS_REQ_to_TS_VERIFY_CTX(int param_1,uint *param_2)

{
  size_t __n;
  ASN1_OBJECT *pAVar1;
  undefined4 uVar2;
  X509_ALGOR *pXVar3;
  ASN1_STRING *pAVar4;
  void *pvVar5;
  uchar *__src;
  uint *ptr;
  uint uVar6;
  undefined4 *puVar7;
  byte bVar8;
  
  bVar8 = 0;
  if (param_1 == 0) {
    OpenSSLDie("ts_verify_ctx.c",0x76,"req != NULL");
  }
  if (param_2 == (uint *)0x0) {
    ptr = (uint *)CRYPTO_malloc(0x28,"ts_verify_ctx.c",0x42);
    if (ptr == (uint *)0x0) {
      ERR_put_error(0x2f,0x90,0x41,"ts_verify_ctx.c",0x46);
      return (uint *)0x0;
    }
    *ptr = 0;
    ptr[9] = 0;
    puVar7 = (undefined4 *)((uint)(ptr + 1) & 0xfffffffc);
    for (uVar6 = (uint)((int)ptr + (0x28 - (int)(undefined4 *)((uint)(ptr + 1) & 0xfffffffc))) >> 2;
        uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
    }
  }
  else {
    X509_STORE_free((X509_STORE *)param_2[1]);
    sk_pop_free((_STACK *)param_2[2],X509_free);
    ASN1_OBJECT_free((ASN1_OBJECT *)param_2[3]);
    X509_ALGOR_free((X509_ALGOR *)param_2[4]);
    CRYPTO_free((void *)param_2[5]);
    BIO_free_all((BIO *)param_2[7]);
    ASN1_INTEGER_free((ASN1_INTEGER *)param_2[8]);
    GENERAL_NAME_free((GENERAL_NAME *)param_2[9]);
    *param_2 = 0;
    param_2[9] = 0;
    puVar7 = (undefined4 *)((uint)(param_2 + 1) & 0xfffffffc);
    for (uVar6 = (uint)((int)param_2 +
                       (0x28 - (int)(undefined4 *)((uint)(param_2 + 1) & 0xfffffffc))) >> 2;
        ptr = param_2, uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
    }
  }
  *ptr = 0x6e;
  pAVar1 = (ASN1_OBJECT *)TS_REQ_get_policy_id(param_1);
  if (pAVar1 == (ASN1_OBJECT *)0x0) {
    *ptr = *ptr & 0xfffffffb;
  }
  else {
    pAVar1 = OBJ_dup(pAVar1);
    ptr[3] = (uint)pAVar1;
    if (pAVar1 == (ASN1_OBJECT *)0x0) goto LAB_081985c8;
  }
  uVar2 = TS_REQ_get_msg_imprint(param_1);
  pXVar3 = (X509_ALGOR *)TS_MSG_IMPRINT_get_algo(uVar2);
  pXVar3 = X509_ALGOR_dup(pXVar3);
  ptr[4] = (uint)pXVar3;
  if (pXVar3 != (X509_ALGOR *)0x0) {
    pAVar4 = (ASN1_STRING *)TS_MSG_IMPRINT_get_msg(uVar2);
    uVar6 = ASN1_STRING_length(pAVar4);
    ptr[6] = uVar6;
    pvVar5 = CRYPTO_malloc(uVar6,"ts_verify_ctx.c",0x8d);
    ptr[5] = (uint)pvVar5;
    if (pvVar5 != (void *)0x0) {
      __n = ptr[6];
      __src = ASN1_STRING_data(pAVar4);
      memcpy((void *)ptr[5],__src,__n);
      pAVar4 = (ASN1_STRING *)TS_REQ_get_nonce(param_1);
      if (pAVar4 == (ASN1_STRING *)0x0) {
        *ptr = *ptr & 0xffffffdf;
      }
      else {
        pAVar4 = ASN1_INTEGER_dup(pAVar4);
        ptr[8] = (uint)pAVar4;
        if (pAVar4 == (ASN1_STRING *)0x0) goto LAB_081985c8;
      }
      return ptr;
    }
  }
LAB_081985c8:
  if (param_2 == (uint *)0x0) {
    X509_STORE_free((X509_STORE *)ptr[1]);
    sk_pop_free((_STACK *)ptr[2],X509_free);
    ASN1_OBJECT_free((ASN1_OBJECT *)ptr[3]);
    X509_ALGOR_free((X509_ALGOR *)ptr[4]);
    CRYPTO_free((void *)ptr[5]);
    BIO_free_all((BIO *)ptr[7]);
    ASN1_INTEGER_free((ASN1_INTEGER *)ptr[8]);
    GENERAL_NAME_free((GENERAL_NAME *)ptr[9]);
    *ptr = 0;
    ptr[9] = 0;
    puVar7 = (undefined4 *)((uint)(ptr + 1) & 0xfffffffc);
    for (uVar6 = (uint)((int)ptr + (0x28 - (int)(undefined4 *)((uint)(ptr + 1) & 0xfffffffc))) >> 2;
        uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
    }
    CRYPTO_free(ptr);
    return (uint *)0x0;
  }
  X509_STORE_free((X509_STORE *)param_2[1]);
  sk_pop_free((_STACK *)param_2[2],X509_free);
  ASN1_OBJECT_free((ASN1_OBJECT *)param_2[3]);
  X509_ALGOR_free((X509_ALGOR *)param_2[4]);
  CRYPTO_free((void *)param_2[5]);
  BIO_free_all((BIO *)param_2[7]);
  ASN1_INTEGER_free((ASN1_INTEGER *)param_2[8]);
  GENERAL_NAME_free((GENERAL_NAME *)param_2[9]);
  *param_2 = 0;
  param_2[9] = 0;
  puVar7 = (undefined4 *)((uint)(param_2 + 1) & 0xfffffffc);
  for (uVar6 = (uint)((int)param_2 + (0x28 - (int)(undefined4 *)((uint)(param_2 + 1) & 0xfffffffc)))
               >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
  }
  return (uint *)0x0;
}

