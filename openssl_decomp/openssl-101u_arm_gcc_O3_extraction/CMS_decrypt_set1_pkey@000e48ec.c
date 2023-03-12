
/* WARNING: Removing unreachable block (ram,0x000e49d0) */

int CMS_decrypt_set1_pkey(CMS_ContentInfo *cms,EVP_PKEY *pk,X509 *cert)

{
  _STACK *p_Var1;
  _STACK *p_Var2;
  int iVar3;
  CMS_RecipientInfo *pCVar4;
  int iVar5;
  _STACK *p_Var6;
  int iVar7;
  X509 *pXVar8;
  _STACK *p_Var9;
  
  p_Var2 = (_STACK *)CMS_get0_RecipientInfos(cms);
  p_Var9 = p_Var2;
  if (p_Var2 != (_STACK *)0x0) {
    p_Var9 = *(_STACK **)(*(int *)(*(int *)(cms + 4) + 0xc) + 0x18);
  }
  pXVar8 = cert;
  if (cert == (X509 *)0x0) {
    while (iVar5 = sk_num(p_Var2), (int)cert < iVar5) {
      pCVar4 = (CMS_RecipientInfo *)sk_value(p_Var2,(int)cert);
      iVar5 = CMS_RecipientInfo_type(pCVar4);
      if (iVar5 == 0) {
        CMS_RecipientInfo_set0_pkey(pCVar4,pk);
        p_Var6 = (_STACK *)CMS_RecipientInfo_decrypt(cms,pCVar4);
        CMS_RecipientInfo_set0_pkey(pCVar4,(EVP_PKEY *)0x0);
        p_Var1 = p_Var9;
        if (p_Var9 != (_STACK *)0x0) {
          p_Var1 = p_Var6;
        }
        pXVar8 = (X509 *)0x1;
        if ((p_Var9 != (_STACK *)0x0 && p_Var6 != (_STACK *)0x0) && -1 < (int)p_Var1) {
          return 1;
        }
        cert = (X509 *)((int)&cert->cert_info + 1);
      }
      else {
        cert = (X509 *)((int)&cert->cert_info + 1);
      }
    }
    if (pXVar8 != (X509 *)0x0) {
      pXVar8 = (X509 *)0x1;
    }
    if ((pXVar8 != (X509 *)0x0) && (p_Var9 == (_STACK *)0x0)) goto LAB_000e49fc;
LAB_000e49da:
    iVar3 = 0;
    ERR_put_error(0x2e,0x72,0x84,"cms_smime.c",0x26d);
  }
  else {
    iVar5 = 0;
    do {
      iVar3 = sk_num(p_Var2);
      iVar7 = iVar5 + 1;
      if (iVar3 <= iVar5) goto LAB_000e49da;
      pCVar4 = (CMS_RecipientInfo *)sk_value(p_Var2,iVar5);
      iVar3 = CMS_RecipientInfo_type(pCVar4);
      iVar5 = iVar7;
    } while ((iVar3 != 0) || (iVar3 = CMS_RecipientInfo_ktri_cert_cmp(pCVar4,cert), iVar3 != 0));
    CMS_RecipientInfo_set0_pkey(pCVar4,pk);
    iVar5 = CMS_RecipientInfo_decrypt(cms,pCVar4);
    CMS_RecipientInfo_set0_pkey(pCVar4,(EVP_PKEY *)0x0);
    if (p_Var9 == (_STACK *)0x0) {
LAB_000e49fc:
      ERR_clear_error();
      return 1;
    }
    if (0 < iVar5) {
      return 1;
    }
    ERR_put_error(0x2e,0x72,0x70,"cms_smime.c",0x25b);
  }
  return iVar3;
}

