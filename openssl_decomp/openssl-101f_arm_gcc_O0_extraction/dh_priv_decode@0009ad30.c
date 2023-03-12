
undefined4 dh_priv_decode(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  int iVar1;
  ASN1_INTEGER *ai;
  BIGNUM *pBVar2;
  DH *dh;
  uchar *puStack_28;
  uchar *local_24;
  long local_20;
  int local_1c;
  long *local_18;
  X509_ALGOR *local_14;
  
  iVar1 = PKCS8_pkey_get0((ASN1_OBJECT **)0x0,&puStack_28,&local_20,&local_14,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_1c,&local_18,local_14);
  if ((local_1c == 0x10) &&
     (ai = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&puStack_28,local_20), ai != (ASN1_INTEGER *)0x0))
  {
    local_24 = (uchar *)local_18[2];
    dh = d2i_DHparams((DH **)0x0,&local_24,*local_18);
    if (dh != (DH *)0x0) {
      pBVar2 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
      dh->priv_key = pBVar2;
      if (pBVar2 == (BIGNUM *)0x0) {
        ERR_put_error(5,0x6e,0x6a,"dh_ameth.c",0xd8);
      }
      else {
        iVar1 = DH_generate_key(dh);
        if (iVar1 != 0) {
          EVP_PKEY_assign(param_1,0x1c,dh);
          ASN1_INTEGER_free(ai);
          return 1;
        }
      }
      goto LAB_0009ad74;
    }
  }
  dh = (DH *)0x0;
  ERR_put_error(5,0x6e,0x72,"dh_ameth.c",0xe6);
LAB_0009ad74:
  DH_free(dh);
  return 0;
}

