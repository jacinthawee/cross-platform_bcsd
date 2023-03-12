
EVP_PKEY * d2i_AutoPrivateKey(EVP_PKEY **a,uchar **pp,long length)

{
  _STACK *st;
  int iVar1;
  PKCS8_PRIV_KEY_INFO *pPVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  EVP_PKEY *pkey;
  uchar *local_1c;
  
  local_1c = *pp;
  st = (_STACK *)d2i_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY **)0x0,&local_1c,length);
  iVar1 = sk_num(st);
  if (iVar1 == 6) {
    iVar1 = 0x74;
LAB_000b8a76:
    sk_pop_free(st,ASN1_TYPE_free + 1);
    if ((a == (EVP_PKEY **)0x0) || (pkey = *a, pkey == (EVP_PKEY *)0x0)) {
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0xd,0x9a,6,"d2i_pr.c",0x50);
        return (EVP_PKEY *)0x0;
      }
    }
    else if (pkey->engine != (ENGINE *)0x0) {
      ENGINE_finish(pkey->engine);
      pkey->engine = (ENGINE *)0x0;
    }
    iVar1 = EVP_PKEY_set_type(pkey,iVar1);
    if (iVar1 == 0) {
      ERR_put_error(0xd,0x9a,0xa3,"d2i_pr.c",0x62);
    }
    else {
      pEVar3 = pkey->ameth;
      if (*(code **)(pEVar3 + 0x5c) != (code *)0x0) {
        iVar1 = (**(code **)(pEVar3 + 0x5c))(pkey,pp,length);
        if (iVar1 != 0) goto joined_r0x000b8b96;
        pEVar3 = pkey->ameth;
      }
      if (*(int *)(pEVar3 + 0x24) == 0) {
        ERR_put_error(0xd,0x9a,0xd,"d2i_pr.c",0x75);
      }
      else {
        pPVar2 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,pp,length);
        if (pPVar2 != (PKCS8_PRIV_KEY_INFO *)0x0) {
          EVP_PKEY_free(pkey);
          pkey = EVP_PKCS82PKEY(pPVar2);
          PKCS8_PRIV_KEY_INFO_free(pPVar2);
          goto joined_r0x000b8b96;
        }
      }
    }
    if ((a == (EVP_PKEY **)0x0) || (pkey != *a)) {
      EVP_PKEY_free(pkey);
      return (EVP_PKEY *)0x0;
    }
    pkey = (EVP_PKEY *)0x0;
  }
  else {
    iVar1 = sk_num(st);
    if (iVar1 == 4) {
      iVar1 = 0x198;
      goto LAB_000b8a76;
    }
    iVar1 = sk_num(st);
    if (iVar1 != 3) {
      iVar1 = 6;
      goto LAB_000b8a76;
    }
    pPVar2 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,pp,length);
    sk_pop_free(st,ASN1_TYPE_free + 1);
    if (pPVar2 == (PKCS8_PRIV_KEY_INFO *)0x0) {
      ERR_put_error(0xd,0xcf,0xa7,"d2i_pr.c",0x9d);
      return (EVP_PKEY *)0x0;
    }
    pkey = EVP_PKCS82PKEY(pPVar2);
    PKCS8_PRIV_KEY_INFO_free(pPVar2);
joined_r0x000b8b96:
    if (a != (EVP_PKEY **)0x0) {
      *a = pkey;
    }
  }
  return pkey;
}

