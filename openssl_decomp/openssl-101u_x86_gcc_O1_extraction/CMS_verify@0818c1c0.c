
int CMS_verify(CMS_ContentInfo *cms,stack_st_X509 *certs,X509_STORE *store,BIO *dcont,BIO *out,
              uint flags)

{
  _STACK *p_Var1;
  int iVar2;
  int iVar3;
  BIO *pBVar4;
  CMS_SignerInfo *pCVar5;
  ASN1_OCTET_STRING **ppAVar6;
  long len;
  BIO *chain;
  _STACK *p_Var7;
  _STACK *st;
  int iVar8;
  int in_GS_OFFSET;
  bool bVar9;
  _STACK *local_3c;
  BIO *local_38;
  X509 *local_28;
  void *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((dcont == (BIO *)0x0) &&
     ((ppAVar6 = CMS_get0_content(cms), ppAVar6 == (ASN1_OCTET_STRING **)0x0 ||
      (*ppAVar6 == (ASN1_OCTET_STRING *)0x0)))) {
    local_38 = (BIO *)0x0;
    ERR_put_error(0x2e,99,0x7f,"cms_smime.c",0x77);
    goto LAB_0818c362;
  }
  p_Var1 = (_STACK *)CMS_get0_SignerInfos(cms);
  iVar2 = sk_num(p_Var1);
  if (iVar2 < 1) {
    iVar8 = 0x13d;
    iVar2 = 0x87;
LAB_0818c2bc:
    ERR_put_error(0x2e,0x9d,iVar2,"cms_smime.c",iVar8);
    local_3c = (_STACK *)0x0;
    bVar9 = dcont == (BIO *)0x0;
    chain = (BIO *)0x0;
    local_38 = (BIO *)0x0;
    p_Var7 = (_STACK *)0x0;
    goto LAB_0818c2e4;
  }
  iVar8 = 0;
  for (iVar2 = 0; iVar3 = sk_num(p_Var1), iVar2 < iVar3; iVar2 = iVar2 + 1) {
    pCVar5 = (CMS_SignerInfo *)sk_value(p_Var1,iVar2);
    CMS_SignerInfo_get0_algs
              (pCVar5,(EVP_PKEY **)0x0,&local_28,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0);
    iVar8 = (iVar8 + 1) - (uint)(local_28 == (X509 *)0x0);
  }
  iVar2 = sk_num(p_Var1);
  if (iVar8 != iVar2) {
    iVar2 = CMS_set1_signers_certs(cms,certs,flags);
    iVar2 = iVar8 + iVar2;
  }
  iVar8 = sk_num(p_Var1);
  if (iVar2 != iVar8) {
    iVar8 = 0x14c;
    iVar2 = 0x8a;
    goto LAB_0818c2bc;
  }
  local_3c = (_STACK *)0x0;
  p_Var7 = (_STACK *)(flags & 0x20);
  st = (_STACK *)0x0;
  if (p_Var7 == (_STACK *)0x0) {
    local_3c = (_STACK *)CMS_get1_certs(cms);
    if ((flags & 0x2000) == 0) {
      p_Var7 = (_STACK *)CMS_get1_crls(cms);
    }
    for (iVar2 = 0; iVar8 = sk_num(p_Var1), st = p_Var7, iVar2 < iVar8; iVar2 = iVar2 + 1) {
      sk_value(p_Var1,iVar2);
      iVar8 = cms_signerinfo_verify_cert_isra_1(p_Var7);
      if (iVar8 == 0) goto LAB_0818c5a6;
    }
  }
  iVar2 = 0;
  p_Var7 = st;
  if ((flags & 8) == 0) {
    for (; iVar8 = sk_num(p_Var1), iVar2 < iVar8; iVar2 = iVar2 + 1) {
      pCVar5 = (CMS_SignerInfo *)sk_value(p_Var1,iVar2);
      iVar8 = CMS_signed_get_attr_count(pCVar5);
      if ((-1 < iVar8) && (iVar8 = CMS_SignerInfo_verify(pCVar5), iVar8 < 1)) goto LAB_0818c5a6;
    }
  }
  if (dcont == (BIO *)0x0) {
    chain = CMS_dataInit(cms,(BIO *)0x0);
    if (chain == (BIO *)0x0) {
      local_38 = (BIO *)0x0;
    }
    else {
      iVar2 = cms_copy_content();
      if (iVar2 != 0) {
LAB_0818c400:
        bVar9 = true;
        goto LAB_0818c405;
      }
      local_38 = (BIO *)0x0;
    }
    goto LAB_0818c4c8;
  }
  iVar2 = BIO_method_type(dcont);
  if (iVar2 == 0x401) {
    len = BIO_ctrl(dcont,3,0,&local_24);
    local_38 = BIO_new_mem_buf(local_24,len);
    if (local_38 == (BIO *)0x0) {
      ERR_put_error(0x2e,0x9d,0x41,"cms_smime.c",0x177);
      goto LAB_0818c362;
    }
    chain = CMS_dataInit(cms,local_38);
    bVar9 = dcont == local_38;
    if ((chain == (BIO *)0x0) || (iVar2 = cms_copy_content(), iVar2 == 0)) {
      local_38 = (BIO *)0x0;
      goto LAB_0818c2e4;
    }
LAB_0818c405:
    local_38 = (BIO *)0x1;
    if ((flags & 4) == 0) {
      for (iVar2 = 0; iVar8 = sk_num(p_Var1), iVar2 < iVar8; iVar2 = iVar2 + 1) {
        pCVar5 = (CMS_SignerInfo *)sk_value(p_Var1,iVar2);
        iVar8 = CMS_SignerInfo_verify_content(pCVar5,chain);
        if (iVar8 < 1) {
          local_38 = (BIO *)0x0;
          ERR_put_error(0x2e,0x9d,0x6d,"cms_smime.c",0x188);
          goto LAB_0818c2e4;
        }
      }
      local_38 = (BIO *)0x1;
    }
    goto LAB_0818c2e4;
  }
  chain = CMS_dataInit(cms,dcont);
  if (chain == (BIO *)0x0) {
    local_38 = (BIO *)0x0;
  }
  else {
    local_38 = (BIO *)0x0;
    iVar2 = cms_copy_content();
    if (iVar2 != 0) goto LAB_0818c400;
  }
LAB_0818c314:
  do {
    pBVar4 = BIO_pop(chain);
    BIO_free(chain);
    if (pBVar4 == (BIO *)0x0) break;
    chain = pBVar4;
  } while (dcont != pBVar4);
LAB_0818c334:
  if (local_3c != (_STACK *)0x0) {
    sk_pop_free(local_3c,X509_free);
  }
  if (st != (_STACK *)0x0) {
    sk_pop_free(st,X509_CRL_free);
  }
LAB_0818c362:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)local_38;
LAB_0818c5a6:
  bVar9 = dcont == (BIO *)0x0;
  chain = (BIO *)0x0;
  local_38 = (BIO *)0x0;
LAB_0818c2e4:
  st = p_Var7;
  if ((dcont != (BIO *)0x0) && (bVar9)) goto LAB_0818c314;
LAB_0818c4c8:
  BIO_free_all(chain);
  goto LAB_0818c334;
}

