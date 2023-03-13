
int CMS_verify_receipt(CMS_ContentInfo *rcms,CMS_ContentInfo *ocms,stack_st_X509 *certs,
                      X509_STORE *store,uint flags)

{
  bool bVar1;
  ASN1_OCTET_STRING **ppAVar2;
  _STACK *p_Var3;
  int iVar4;
  int iVar5;
  BIO *chain;
  CMS_SignerInfo *pCVar6;
  _STACK *p_Var7;
  _STACK *p_Var8;
  int iVar9;
  int in_GS_OFFSET;
  _STACK *local_38;
  X509 *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ppAVar2 = CMS_get0_content(rcms);
  if ((ppAVar2 == (ASN1_OCTET_STRING **)0x0) || (*ppAVar2 == (ASN1_OCTET_STRING *)0x0)) {
    ERR_put_error(0x2e,99,0x7f,"cms_smime.c",0x77);
    iVar4 = 0;
    goto LAB_0818c7f0;
  }
  p_Var3 = (_STACK *)CMS_get0_SignerInfos(rcms);
  iVar4 = sk_num(p_Var3);
  if (iVar4 < 1) {
    ERR_put_error(0x2e,0x9d,0x87,"cms_smime.c",0x13d);
  }
  else {
    iVar9 = 0;
    for (iVar4 = 0; iVar5 = sk_num(p_Var3), iVar4 < iVar5; iVar4 = iVar4 + 1) {
      pCVar6 = (CMS_SignerInfo *)sk_value(p_Var3,iVar4);
      CMS_SignerInfo_get0_algs
                (pCVar6,(EVP_PKEY **)0x0,&local_24,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0);
      iVar9 = (iVar9 + 1) - (uint)(local_24 == (X509 *)0x0);
    }
    iVar4 = sk_num(p_Var3);
    if (iVar9 != iVar4) {
      iVar4 = CMS_set1_signers_certs(rcms,certs,flags & 0xffffffbe);
      iVar4 = iVar9 + iVar4;
    }
    iVar9 = sk_num(p_Var3);
    if (iVar9 == iVar4) {
      local_38 = (_STACK *)0x0;
      p_Var7 = (_STACK *)(flags & 0x20);
      p_Var8 = (_STACK *)0x0;
      if (p_Var7 == (_STACK *)0x0) {
        local_38 = (_STACK *)CMS_get1_certs(rcms);
        if ((flags & 0x2000) == 0) {
          p_Var7 = (_STACK *)CMS_get1_crls(rcms);
        }
        for (iVar4 = 0; iVar9 = sk_num(p_Var3), p_Var8 = p_Var7, iVar4 < iVar9; iVar4 = iVar4 + 1) {
          sk_value(p_Var3,iVar4);
          iVar9 = cms_signerinfo_verify_cert_isra_1(p_Var7);
          if (iVar9 == 0) goto LAB_0818c9e0;
        }
      }
      iVar4 = 0;
      p_Var7 = p_Var8;
      if ((flags & 8) == 0) {
        for (; iVar9 = sk_num(p_Var3), iVar4 < iVar9; iVar4 = iVar4 + 1) {
          pCVar6 = (CMS_SignerInfo *)sk_value(p_Var3,iVar4);
          iVar9 = CMS_signed_get_attr_count(pCVar6);
          if ((-1 < iVar9) && (iVar9 = CMS_SignerInfo_verify(pCVar6), iVar9 < 1)) goto LAB_0818c9e0;
        }
      }
      bVar1 = false;
      chain = CMS_dataInit(rcms,(BIO *)0x0);
      if (((chain != (BIO *)0x0) && (iVar4 = cms_copy_content(), iVar4 != 0)) &&
         (bVar1 = true, (flags & 4) == 0)) {
        for (iVar4 = 0; iVar9 = sk_num(p_Var3), iVar4 < iVar9; iVar4 = iVar4 + 1) {
          pCVar6 = (CMS_SignerInfo *)sk_value(p_Var3,iVar4);
          iVar9 = CMS_SignerInfo_verify_content(pCVar6,chain);
          if (iVar9 < 1) {
            bVar1 = false;
            ERR_put_error(0x2e,0x9d,0x6d,"cms_smime.c",0x188);
            goto LAB_0818c870;
          }
        }
        bVar1 = true;
      }
      goto LAB_0818c870;
    }
    ERR_put_error(0x2e,0x9d,0x8a,"cms_smime.c",0x14c);
  }
  BIO_free_all((BIO *)0x0);
  iVar4 = 0;
LAB_0818c7f0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
LAB_0818c9e0:
  chain = (BIO *)0x0;
  bVar1 = false;
LAB_0818c870:
  BIO_free_all(chain);
  if (local_38 != (_STACK *)0x0) {
    sk_pop_free(local_38,X509_free);
  }
  if (p_Var7 != (_STACK *)0x0) {
    sk_pop_free(p_Var7,X509_CRL_free);
  }
  if (bVar1) {
    iVar4 = cms_Receipt_verify(rcms,ocms);
  }
  else {
    iVar4 = 0;
  }
  goto LAB_0818c7f0;
}

