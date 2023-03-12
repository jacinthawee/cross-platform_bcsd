
int EVP_PKEY_set_type(EVP_PKEY *pkey,int type)

{
  int *piVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  int iVar3;
  code *pcVar4;
  ENGINE *local_14;
  
  local_14 = (ENGINE *)0x0;
  if (pkey == (EVP_PKEY *)0x0) {
    pEVar2 = EVP_PKEY_asn1_find(&local_14,type);
    if (local_14 != (ENGINE *)0x0) {
      ENGINE_finish(local_14);
    }
    if (pEVar2 != (EVP_PKEY_ASN1_METHOD *)0x0) {
      return 1;
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
    if ((type == pkey->save_type) && (pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0)) {
      return 1;
    }
    if (pkey->engine != (ENGINE *)0x0) {
      ENGINE_finish(pkey->engine);
      pkey->engine = (ENGINE *)0x0;
    }
    piVar1 = (int *)EVP_PKEY_asn1_find(&local_14,type);
    if (piVar1 != (int *)0x0) {
      iVar3 = *piVar1;
      pkey->ameth = (EVP_PKEY_ASN1_METHOD *)piVar1;
      pkey->type = iVar3;
      pkey->save_type = type;
      pkey->engine = local_14;
      return 1;
    }
  }
  ERR_put_error(6,0x9e,0x9c,"p_lib.c",0xef);
  return 0;
}

