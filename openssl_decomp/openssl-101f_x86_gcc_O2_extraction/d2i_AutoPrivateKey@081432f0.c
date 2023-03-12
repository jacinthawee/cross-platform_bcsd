
EVP_PKEY * d2i_AutoPrivateKey(EVP_PKEY **a,uchar **pp,long length)

{
  _STACK *st;
  int iVar1;
  int iVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  PKCS8_PRIV_KEY_INFO *pPVar4;
  EVP_PKEY *pkey;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = *pp;
  st = (_STACK *)d2i_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY **)0x0,&local_24,length);
  iVar1 = sk_num(st);
  if (iVar1 == 6) {
    iVar1 = 0x74;
LAB_08143366:
    sk_pop_free(st,ASN1_TYPE_free);
    if ((a == (EVP_PKEY **)0x0) || (pkey = *a, pkey == (EVP_PKEY *)0x0)) {
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0xd,0x9a,6,"d2i_pr.c",0x50);
        pkey = (EVP_PKEY *)0x0;
        goto LAB_08143424;
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
        if (iVar1 != 0) goto joined_r0x0814341a;
        pEVar3 = pkey->ameth;
      }
      if (*(int *)(pEVar3 + 0x24) == 0) {
        ERR_put_error(0xd,0x9a,0xd,"d2i_pr.c",0x75);
      }
      else {
        pPVar4 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,pp,length);
        if (pPVar4 != (PKCS8_PRIV_KEY_INFO *)0x0) {
          EVP_PKEY_free(pkey);
          pkey = EVP_PKCS82PKEY(pPVar4);
          PKCS8_PRIV_KEY_INFO_free(pPVar4);
          goto joined_r0x0814341a;
        }
      }
    }
    if ((a == (EVP_PKEY **)0x0) || (pkey != *a)) {
      EVP_PKEY_free(pkey);
      pkey = (EVP_PKEY *)0x0;
    }
    else {
      pkey = (EVP_PKEY *)0x0;
    }
  }
  else {
    iVar1 = sk_num(st);
    if (iVar1 == 4) {
      iVar1 = 0x198;
      goto LAB_08143366;
    }
    iVar1 = 6;
    iVar2 = sk_num(st);
    if (iVar2 != 3) goto LAB_08143366;
    pPVar4 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,pp,length);
    sk_pop_free(st,ASN1_TYPE_free);
    if (pPVar4 == (PKCS8_PRIV_KEY_INFO *)0x0) {
      ERR_put_error(0xd,0xcf,0xa7,"d2i_pr.c",0x9d);
      pkey = (EVP_PKEY *)0x0;
      goto LAB_08143424;
    }
    pkey = EVP_PKCS82PKEY(pPVar4);
    PKCS8_PRIV_KEY_INFO_free(pPVar4);
joined_r0x0814341a:
    if (a != (EVP_PKEY **)0x0) {
      *a = pkey;
    }
  }
LAB_08143424:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pkey;
}

