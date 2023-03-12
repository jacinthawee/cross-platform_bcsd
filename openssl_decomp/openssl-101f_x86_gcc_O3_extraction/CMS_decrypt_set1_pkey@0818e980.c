
int CMS_decrypt_set1_pkey(CMS_ContentInfo *cms,EVP_PKEY *pk,X509 *cert)

{
  _STACK *p_Var1;
  int iVar2;
  CMS_RecipientInfo *pCVar3;
  int iVar4;
  int local_20;
  
  p_Var1 = (_STACK *)CMS_get0_RecipientInfos(cms);
  if (p_Var1 == (_STACK *)0x0) {
    local_20 = 0;
  }
  else {
    local_20 = *(int *)(*(int *)(*(int *)(cms + 4) + 0xc) + 0x18);
  }
  iVar4 = 0;
  if (cert == (X509 *)0x0) {
    for (; iVar2 = sk_num(p_Var1), iVar4 < iVar2; iVar4 = iVar4 + 1) {
      pCVar3 = (CMS_RecipientInfo *)sk_value(p_Var1,iVar4);
      iVar2 = CMS_RecipientInfo_type(pCVar3);
      if (iVar2 == 0) {
        CMS_RecipientInfo_set0_pkey(pCVar3,pk);
        iVar2 = CMS_RecipientInfo_decrypt(cms,pCVar3);
        CMS_RecipientInfo_set0_pkey(pCVar3,(EVP_PKEY *)0x0);
        if ((0 < iVar2) && (local_20 != 0)) goto LAB_0818ea4a;
      }
    }
    if (local_20 == 0) {
LAB_0818eb19:
      ERR_clear_error();
      return 1;
    }
  }
  else {
    iVar2 = sk_num(p_Var1);
    if (0 < iVar2) {
      do {
        pCVar3 = (CMS_RecipientInfo *)sk_value(p_Var1,iVar4);
        iVar2 = CMS_RecipientInfo_type(pCVar3);
        if ((iVar2 == 0) && (iVar2 = CMS_RecipientInfo_ktri_cert_cmp(pCVar3,cert), iVar2 == 0)) {
          CMS_RecipientInfo_set0_pkey(pCVar3,pk);
          iVar4 = CMS_RecipientInfo_decrypt(cms,pCVar3);
          CMS_RecipientInfo_set0_pkey(pCVar3,(EVP_PKEY *)0x0);
          if (local_20 != 0) {
            if (iVar4 < 1) {
              ERR_put_error(0x2e,0x72,0x70,"cms_smime.c",0x285);
            }
            else {
LAB_0818ea4a:
              iVar2 = 1;
            }
            return iVar2;
          }
          goto LAB_0818eb19;
        }
        iVar4 = iVar4 + 1;
        iVar2 = sk_num(p_Var1);
      } while (iVar4 < iVar2);
    }
  }
  ERR_put_error(0x2e,0x72,0x84,"cms_smime.c",0x298);
  return 0;
}

