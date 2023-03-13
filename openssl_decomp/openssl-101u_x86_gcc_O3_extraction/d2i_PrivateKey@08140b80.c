
EVP_PKEY * d2i_PrivateKey(int type,EVP_PKEY **a,uchar **pp,long length)

{
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  PKCS8_PRIV_KEY_INFO *p8;
  EVP_PKEY *pEVar3;
  EVP_PKEY *pkey;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = *pp;
  if ((a == (EVP_PKEY **)0x0) || (pkey = *a, pkey == (EVP_PKEY *)0x0)) {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0xd,0x9a,6,"d2i_pr.c",0x4f);
      pEVar3 = (EVP_PKEY *)0x0;
      goto LAB_08140cac;
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
    pEVar2 = pkey->ameth;
    if (*(code **)(pEVar2 + 0x5c) != (code *)0x0) {
      iVar1 = (**(code **)(pEVar2 + 0x5c))(pkey,&local_24,length);
      pEVar3 = pkey;
      if (iVar1 == 0) {
        pEVar2 = pkey->ameth;
        goto LAB_08140c08;
      }
LAB_08140c5d:
      *pp = local_24;
      if (a != (EVP_PKEY **)0x0) {
        *a = pEVar3;
      }
      goto LAB_08140cac;
    }
LAB_08140c08:
    if (*(int *)(pEVar2 + 0x24) == 0) {
      ERR_put_error(0xd,0x9a,0xd,"d2i_pr.c",0x70);
    }
    else {
      p8 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,&local_24,length);
      if (p8 != (PKCS8_PRIV_KEY_INFO *)0x0) {
        pEVar3 = EVP_PKCS82PKEY(p8);
        PKCS8_PRIV_KEY_INFO_free(p8);
        if (pEVar3 != (EVP_PKEY *)0x0) {
          EVP_PKEY_free(pkey);
          goto LAB_08140c5d;
        }
      }
    }
  }
  if ((a == (EVP_PKEY **)0x0) || (pkey != *a)) {
    EVP_PKEY_free(pkey);
    pEVar3 = (EVP_PKEY *)0x0;
  }
  else {
    pEVar3 = (EVP_PKEY *)0x0;
  }
LAB_08140cac:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pEVar3;
}

