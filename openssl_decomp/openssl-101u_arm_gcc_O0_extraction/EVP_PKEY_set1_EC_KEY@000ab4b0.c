
int EVP_PKEY_set1_EC_KEY(EVP_PKEY *pkey,ec_key_st *key)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  ENGINE *local_14;
  
  if (pkey == (EVP_PKEY *)0x0) {
    return 0;
  }
  local_14 = (ENGINE *)0x0;
  if ((pkey->pkey).ptr != (char *)0x0) {
    if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (pcVar3 = *(code **)(pkey->ameth + 0x54), pcVar3 != (code *)0x0)) {
      (*pcVar3)();
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
    if (piVar1 == (int *)0x0) {
      ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xe7);
      return 0;
    }
    iVar2 = *piVar1;
    pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar1;
    pkey->type = iVar2;
    pkey->engine = local_14;
    pkey->save_type = 0x198;
  }
  (pkey->pkey).ec = key;
  if (key != (ec_key_st *)0x0) {
    EC_KEY_up_ref(key);
    key = (ec_key_st *)0x1;
  }
  return (int)key;
}

