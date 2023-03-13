
int CMS_decrypt_set1_pkey(CMS_ContentInfo *cms,EVP_PKEY *pk,X509 *cert)

{
  bool bVar1;
  _STACK *p_Var2;
  int iVar3;
  CMS_RecipientInfo *pCVar4;
  int iVar5;
  int local_20;
  
  p_Var2 = (_STACK *)CMS_get0_RecipientInfos(cms);
  if (p_Var2 == (_STACK *)0x0) {
    local_20 = 0;
  }
  else {
    local_20 = *(int *)(*(int *)(*(int *)(cms + 4) + 0xc) + 0x18);
  }
  iVar5 = 0;
  bVar1 = false;
  if (cert == (X509 *)0x0) {
    for (; iVar3 = sk_num(p_Var2), iVar5 < iVar3; iVar5 = iVar5 + 1) {
      pCVar4 = (CMS_RecipientInfo *)sk_value(p_Var2,iVar5);
      iVar3 = CMS_RecipientInfo_type(pCVar4);
      if (iVar3 == 0) {
        CMS_RecipientInfo_set0_pkey(pCVar4,pk);
        iVar3 = CMS_RecipientInfo_decrypt(cms,pCVar4);
        CMS_RecipientInfo_set0_pkey(pCVar4,(EVP_PKEY *)0x0);
        if ((0 < iVar3) && (local_20 != 0)) {
          return 1;
        }
        bVar1 = true;
      }
    }
    if ((bVar1) && (local_20 == 0)) {
LAB_0818d1d7:
      ERR_clear_error();
      return 1;
    }
  }
  else {
    iVar3 = sk_num(p_Var2);
    if (0 < iVar3) {
      do {
        pCVar4 = (CMS_RecipientInfo *)sk_value(p_Var2,iVar5);
        iVar3 = CMS_RecipientInfo_type(pCVar4);
        if ((iVar3 == 0) && (iVar3 = CMS_RecipientInfo_ktri_cert_cmp(pCVar4,cert), iVar3 == 0)) {
          CMS_RecipientInfo_set0_pkey(pCVar4,pk);
          iVar5 = CMS_RecipientInfo_decrypt(cms,pCVar4);
          CMS_RecipientInfo_set0_pkey(pCVar4,(EVP_PKEY *)0x0);
          if (local_20 != 0) {
            if (iVar5 < 1) {
              ERR_put_error(0x2e,0x72,0x70,"cms_smime.c",0x25b);
              return 0;
            }
            return 1;
          }
          goto LAB_0818d1d7;
        }
        iVar5 = iVar5 + 1;
        iVar3 = sk_num(p_Var2);
      } while (iVar5 < iVar3);
    }
  }
  ERR_put_error(0x2e,0x72,0x84,"cms_smime.c",0x26d);
  return 0;
}

