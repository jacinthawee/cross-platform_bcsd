
EVP_PKEY * d2i_AutoPrivateKey(EVP_PKEY **a,uchar **pp,long length)

{
  _STACK *st;
  int iVar1;
  PKCS8_PRIV_KEY_INFO *pPVar2;
  EVP_PKEY *pEVar3;
  EVP_PKEY_ASN1_METHOD *pEVar4;
  EVP_PKEY *pEVar5;
  uchar *local_28;
  uchar *local_24 [2];
  
  local_28 = *pp;
  st = (_STACK *)d2i_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY **)0x0,&local_28,length);
  local_28 = *pp;
  iVar1 = sk_num(st);
  if (iVar1 == 6) {
    iVar1 = 0x74;
  }
  else {
    iVar1 = sk_num(st);
    if (iVar1 == 4) {
      iVar1 = 0x198;
    }
    else {
      iVar1 = sk_num(st);
      if (iVar1 == 3) {
        pPVar2 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,&local_28,length);
        sk_pop_free(st,ASN1_TYPE_free + 1);
        if (pPVar2 == (PKCS8_PRIV_KEY_INFO *)0x0) {
          ERR_put_error(0xd,0xcf,0xa7,"d2i_pr.c",0xa1);
          return (EVP_PKEY *)0x0;
        }
        pEVar5 = EVP_PKCS82PKEY(pPVar2);
        PKCS8_PRIV_KEY_INFO_free(pPVar2);
        if (pEVar5 != (EVP_PKEY *)0x0) {
          *pp = local_28;
          if (a != (EVP_PKEY **)0x0) {
            *a = pEVar5;
            return pEVar5;
          }
          return pEVar5;
        }
        return (EVP_PKEY *)0x0;
      }
      iVar1 = 6;
    }
  }
  sk_pop_free(st,ASN1_TYPE_free + 1);
  local_24[0] = *pp;
  if ((a == (EVP_PKEY **)0x0) || (pEVar5 = *a, pEVar5 == (EVP_PKEY *)0x0)) {
    pEVar5 = EVP_PKEY_new();
    if (pEVar5 == (EVP_PKEY *)0x0) {
      ERR_put_error(0xd,0x9a,6,"d2i_pr.c",0x4f);
      return (EVP_PKEY *)0x0;
    }
  }
  else if (pEVar5->engine != (ENGINE *)0x0) {
    ENGINE_finish(pEVar5->engine);
    pEVar5->engine = (ENGINE *)0x0;
  }
  iVar1 = EVP_PKEY_set_type(pEVar5,iVar1);
  if (iVar1 == 0) {
    ERR_put_error(0xd,0x9a,0xa3,"d2i_pr.c",0x5d);
  }
  else {
    pEVar4 = pEVar5->ameth;
    if (*(code **)(pEVar4 + 0x5c) != (code *)0x0) {
      iVar1 = (**(code **)(pEVar4 + 0x5c))(pEVar5,local_24,length);
      pEVar3 = pEVar5;
      if (iVar1 != 0) goto LAB_000b6056;
      pEVar4 = pEVar5->ameth;
    }
    if (*(int *)(pEVar4 + 0x24) == 0) {
      ERR_put_error(0xd,0x9a,0xd,"d2i_pr.c",0x70);
    }
    else {
      pPVar2 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,local_24,length);
      if (pPVar2 != (PKCS8_PRIV_KEY_INFO *)0x0) {
        pEVar3 = EVP_PKCS82PKEY(pPVar2);
        PKCS8_PRIV_KEY_INFO_free(pPVar2);
        if (pEVar3 != (EVP_PKEY *)0x0) {
          EVP_PKEY_free(pEVar5);
LAB_000b6056:
          *pp = local_24[0];
          if (a != (EVP_PKEY **)0x0) {
            *a = pEVar3;
            return pEVar3;
          }
          return pEVar3;
        }
      }
    }
  }
  if ((a == (EVP_PKEY **)0x0) || (pEVar5 != *a)) {
    EVP_PKEY_free(pEVar5);
  }
  return (EVP_PKEY *)0x0;
}

