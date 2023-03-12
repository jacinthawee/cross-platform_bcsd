
EVP_PKEY * d2i_PrivateKey(int type,EVP_PKEY **a,uchar **pp,long length)

{
  int iVar1;
  PKCS8_PRIV_KEY_INFO *p8;
  EVP_PKEY *pEVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  EVP_PKEY *pkey;
  uchar *local_24 [2];
  
  local_24[0] = *pp;
  if ((a == (EVP_PKEY **)0x0) || (pkey = *a, pkey == (EVP_PKEY *)0x0)) {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0xd,0x9a,6,"d2i_pr.c",0x4f);
      return (EVP_PKEY *)0x0;
    }
  }
  else if (pkey->engine != (ENGINE *)0x0) {
    ENGINE_finish(pkey->engine);
    pkey->engine = (ENGINE *)0x0;
  }
  iVar1 = EVP_PKEY_set_type(pkey,type);
  if (iVar1 == 0) {
    ERR_put_error(0xd,0x9a,0xa3,"d2i_pr.c",0x5d);
  }
  else {
    pEVar3 = pkey->ameth;
    if (*(code **)(pEVar3 + 0x5c) != (code *)0x0) {
      iVar1 = (**(code **)(pEVar3 + 0x5c))(pkey,local_24,length);
      pEVar2 = pkey;
      if (iVar1 != 0) goto LAB_000b5f22;
      pEVar3 = pkey->ameth;
    }
    if (*(int *)(pEVar3 + 0x24) == 0) {
      ERR_put_error(0xd,0x9a,0xd,"d2i_pr.c",0x70);
    }
    else {
      p8 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,local_24,length);
      if (p8 != (PKCS8_PRIV_KEY_INFO *)0x0) {
        pEVar2 = EVP_PKCS82PKEY(p8);
        PKCS8_PRIV_KEY_INFO_free(p8);
        if (pEVar2 != (EVP_PKEY *)0x0) {
          EVP_PKEY_free(pkey);
LAB_000b5f22:
          *pp = local_24[0];
          if (a != (EVP_PKEY **)0x0) {
            *a = pEVar2;
            return pEVar2;
          }
          return pEVar2;
        }
      }
    }
  }
  if ((a == (EVP_PKEY **)0x0) || (*a != pkey)) {
    EVP_PKEY_free(pkey);
  }
  return (EVP_PKEY *)0x0;
}

