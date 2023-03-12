
int EVP_PKEY_set1_EC_KEY(EVP_PKEY *pkey,ec_key_st *key)

{
  int *piVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  int iVar3;
  code *pcVar4;
  ENGINE *local_14;
  
  local_14 = (ENGINE *)0x0;
  if (pkey == (EVP_PKEY *)0x0) {
    pEVar2 = EVP_PKEY_asn1_find(&local_14,0x198);
    if (local_14 != (ENGINE *)0x0) {
      ENGINE_finish(local_14);
    }
    if (pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) {
LAB_000ae07c:
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
    if ((pkey->save_type != 0x198) || (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0)) {
      if (pkey->engine != (ENGINE *)0x0) {
        ENGINE_finish(pkey->engine);
        pkey->engine = (ENGINE *)0x0;
      }
      piVar1 = (int *)EVP_PKEY_asn1_find(&local_14,0x198);
      if (piVar1 == (int *)0x0) goto LAB_000ae07c;
      iVar3 = *piVar1;
      pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar1;
      pkey->type = iVar3;
      pkey->engine = local_14;
      pkey->save_type = 0x198;
    }
  }
  (pkey->pkey).ec = key;
  if (key != (ec_key_st *)0x0) {
    EC_KEY_up_ref(key);
    key = (ec_key_st *)0x1;
  }
  return (int)key;
}

