
void TS_VERIFY_CTX_cleanup(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  byte bVar3;
  
  bVar3 = 0;
  if (param_1 != (undefined4 *)0x0) {
    X509_STORE_free((X509_STORE *)param_1[1]);
    sk_pop_free((_STACK *)param_1[2],X509_free);
    ASN1_OBJECT_free((ASN1_OBJECT *)param_1[3]);
    X509_ALGOR_free((X509_ALGOR *)param_1[4]);
    CRYPTO_free((void *)param_1[5]);
    BIO_free_all((BIO *)param_1[7]);
    ASN1_INTEGER_free((ASN1_INTEGER *)param_1[8]);
    GENERAL_NAME_free((GENERAL_NAME *)param_1[9]);
    *param_1 = 0;
    param_1[9] = 0;
    puVar2 = (undefined4 *)((uint)(param_1 + 1) & 0xfffffffc);
    for (uVar1 = (uint)((int)param_1 +
                       (0x28 - (int)(undefined4 *)((uint)(param_1 + 1) & 0xfffffffc))) >> 2;
        uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + (uint)bVar3 * -2 + 1;
    }
  }
  return;
}

