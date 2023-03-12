
EVP_PKEY * d2i_PrivateKey(int type,EVP_PKEY **a,uchar **pp,long length)

{
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  PKCS8_PRIV_KEY_INFO *p8;
  undefined4 uVar3;
  undefined4 uVar4;
  EVP_PKEY *pkey;
  
  if ((a == (EVP_PKEY **)0x0) || (pkey = *a, pkey == (EVP_PKEY *)0x0)) {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x9a,6,"d2i_pr.c",0x50);
      return (EVP_PKEY *)0x0;
    }
  }
  else if (pkey->engine != (ENGINE *)0x0) {
    (*(code *)PTR_ENGINE_finish_006a80c4)();
    pkey->engine = (ENGINE *)0x0;
  }
  iVar1 = EVP_PKEY_set_type(pkey,type);
  if (iVar1 == 0) {
    uVar4 = 0xa3;
    uVar3 = 0x62;
  }
  else {
    pEVar2 = pkey->ameth;
    if (*(code **)(pEVar2 + 0x5c) != (code *)0x0) {
      iVar1 = (**(code **)(pEVar2 + 0x5c))(pkey,pp,length);
      if (iVar1 != 0) goto LAB_0055892c;
      pEVar2 = pkey->ameth;
    }
    if (*(int *)(pEVar2 + 0x24) != 0) {
      p8 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,pp,length);
      if (p8 != (PKCS8_PRIV_KEY_INFO *)0x0) {
        EVP_PKEY_free(pkey);
        pkey = EVP_PKCS82PKEY(p8);
        PKCS8_PRIV_KEY_INFO_free(p8);
LAB_0055892c:
        if (a == (EVP_PKEY **)0x0) {
          return pkey;
        }
        *a = pkey;
        return pkey;
      }
      goto LAB_00558980;
    }
    uVar4 = 0xd;
    uVar3 = 0x75;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x9a,uVar4,"d2i_pr.c",uVar3);
LAB_00558980:
  if ((a != (EVP_PKEY **)0x0) && (pkey == *a)) {
    return (EVP_PKEY *)0x0;
  }
  EVP_PKEY_free(pkey);
  return (EVP_PKEY *)0x0;
}

