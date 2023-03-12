
PKCS8_PRIV_KEY_INFO * EVP_PKEY2PKCS8_broken(EVP_PKEY *pkey,int broken)

{
  PKCS8_PRIV_KEY_INFO *pPVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  int iVar3;
  ASN1_STRING *pAVar4;
  int reason;
  code *pcVar5;
  double in_f12_13;
  
  pPVar1 = (PKCS8_PRIV_KEY_INFO *)(*(code *)PTR_PKCS8_PRIV_KEY_INFO_new_006a9d68)();
  if (pPVar1 == (PKCS8_PRIV_KEY_INFO *)0x0) {
    ERR_put_error(6,0x71,0x41,"evp_pkey.c",0x7c);
    return (PKCS8_PRIV_KEY_INFO *)0x0;
  }
  pEVar2 = pkey->ameth;
  pPVar1->broken = broken;
  if (pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) {
    reason = 0x76;
    iVar3 = 0x96;
  }
  else {
    pcVar5 = *(code **)(pEVar2 + 0x28);
    if (pcVar5 == (code *)0x0) {
      reason = 0x90;
      iVar3 = 0x8f;
    }
    else {
      iVar3 = (*pcVar5)(pPVar1,pkey);
      if (iVar3 != 0) {
        pAVar4 = (pPVar1->pkey->value).asn1_string;
        RAND_add(pAVar4->data,pAVar4->length,in_f12_13);
        return pPVar1;
      }
      reason = 0x92;
      iVar3 = 0x88;
    }
  }
  ERR_put_error(6,0x71,reason,"evp_pkey.c",iVar3);
  (*(code *)PTR_PKCS8_PRIV_KEY_INFO_free_006a8340)(pPVar1);
  return (PKCS8_PRIV_KEY_INFO *)0x0;
}

