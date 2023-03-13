
EVP_PKEY * d2i_AutoPrivateKey(EVP_PKEY **a,uchar **pp,long length)

{
  _STACK *st;
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  PKCS8_PRIV_KEY_INFO *pPVar3;
  EVP_PKEY *pEVar4;
  EVP_PKEY *pkey;
  int in_GS_OFFSET;
  int local_30;
  uchar *local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = *pp;
  st = (_STACK *)d2i_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY **)0x0,&local_28,length);
  local_28 = *pp;
  iVar1 = sk_num(st);
  if (iVar1 == 6) {
    local_30 = 0x74;
LAB_08140dbf:
    sk_pop_free(st,ASN1_TYPE_free);
    local_24 = *pp;
    if ((a == (EVP_PKEY **)0x0) || (pkey = *a, pkey == (EVP_PKEY *)0x0)) {
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0xd,0x9a,6,"d2i_pr.c",0x4f);
        pEVar4 = (EVP_PKEY *)0x0;
        goto LAB_08140ef4;
      }
    }
    else if (pkey->engine != (ENGINE *)0x0) {
      ENGINE_finish(pkey->engine);
      pkey->engine = (ENGINE *)0x0;
    }
    iVar1 = EVP_PKEY_set_type(pkey,local_30);
    if (iVar1 == 0) {
      ERR_put_error(0xd,0x9a,0xa3,"d2i_pr.c",0x5d);
    }
    else {
      pEVar2 = pkey->ameth;
      if (*(code **)(pEVar2 + 0x5c) != (code *)0x0) {
        iVar1 = (**(code **)(pEVar2 + 0x5c))(pkey,&local_24,length);
        pEVar4 = pkey;
        if (iVar1 == 0) {
          pEVar2 = pkey->ameth;
          goto LAB_08140e3d;
        }
LAB_08140e92:
        *pp = local_24;
joined_r0x08140e9a:
        if (a != (EVP_PKEY **)0x0) {
          *a = pEVar4;
        }
        goto LAB_08140ef4;
      }
LAB_08140e3d:
      if (*(int *)(pEVar2 + 0x24) == 0) {
        ERR_put_error(0xd,0x9a,0xd,"d2i_pr.c",0x70);
      }
      else {
        pPVar3 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,&local_24,length);
        if (pPVar3 != (PKCS8_PRIV_KEY_INFO *)0x0) {
          pEVar4 = EVP_PKCS82PKEY(pPVar3);
          PKCS8_PRIV_KEY_INFO_free(pPVar3);
          if (pEVar4 != (EVP_PKEY *)0x0) {
            EVP_PKEY_free(pkey);
            goto LAB_08140e92;
          }
        }
      }
    }
    if ((a == (EVP_PKEY **)0x0) || (pkey != *a)) {
      EVP_PKEY_free(pkey);
      pEVar4 = (EVP_PKEY *)0x0;
      goto LAB_08140ef4;
    }
  }
  else {
    iVar1 = sk_num(st);
    if (iVar1 == 4) {
      local_30 = 0x198;
      goto LAB_08140dbf;
    }
    iVar1 = sk_num(st);
    local_30 = 6;
    if (iVar1 != 3) goto LAB_08140dbf;
    pPVar3 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,&local_28,length);
    sk_pop_free(st,ASN1_TYPE_free);
    if (pPVar3 == (PKCS8_PRIV_KEY_INFO *)0x0) {
      ERR_put_error(0xd,0xcf,0xa7,"d2i_pr.c",0xa1);
      pEVar4 = (EVP_PKEY *)0x0;
      goto LAB_08140ef4;
    }
    pEVar4 = EVP_PKCS82PKEY(pPVar3);
    PKCS8_PRIV_KEY_INFO_free(pPVar3);
    if (pEVar4 != (EVP_PKEY *)0x0) {
      *pp = local_28;
      goto joined_r0x08140e9a;
    }
  }
  pEVar4 = (EVP_PKEY *)0x0;
LAB_08140ef4:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pEVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

