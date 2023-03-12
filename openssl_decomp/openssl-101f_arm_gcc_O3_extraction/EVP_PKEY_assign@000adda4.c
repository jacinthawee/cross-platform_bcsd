
int EVP_PKEY_assign(EVP_PKEY *pkey,int type,void *key)

{
  int *piVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  int iVar3;
  code *pcVar4;
  ENGINE *local_1c [2];
  
  local_1c[0] = (ENGINE *)0x0;
  if (pkey == (EVP_PKEY *)0x0) {
    pEVar2 = EVP_PKEY_asn1_find(local_1c,type);
    if (local_1c[0] != (ENGINE *)0x0) {
      ENGINE_finish(local_1c[0]);
    }
    if (pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) {
LAB_000ade22:
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xef);
      return 0;
    }
  }
  else {
    if ((pkey->pkey).ptr != (char *)0x0) {
      if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
         (pcVar4 = *(code **)(pkey->ameth + 0x54), pcVar4 != (code *)0x0)) {
        (*pcVar4)();
        (pkey->pkey).ptr = (char *)0x0;
      }
      if (pkey->engine != (ENGINE *)0x0) {
        ENGINE_finish(pkey->engine);
        pkey->engine = (ENGINE *)0x0;
      }
    }
    if ((type != pkey->save_type) || (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0)) {
      if (pkey->engine != (ENGINE *)0x0) {
        ENGINE_finish(pkey->engine);
        pkey->engine = (ENGINE *)0x0;
      }
      piVar1 = (int *)EVP_PKEY_asn1_find(local_1c,type);
      if (piVar1 == (int *)0x0) goto LAB_000ade22;
      iVar3 = *piVar1;
      pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar1;
      pkey->type = iVar3;
      pkey->save_type = type;
      pkey->engine = local_1c[0];
    }
  }
  (pkey->pkey).ptr = (char *)key;
  if (key != (void *)0x0) {
    key = (void *)0x1;
  }
  return (int)key;
}

