
int CMS_verify_receipt(CMS_ContentInfo *rcms,CMS_ContentInfo *ocms,stack_st_X509 *certs,
                      X509_STORE *store,uint flags)

{
  ASN1_OCTET_STRING **ppAVar1;
  _STACK *p_Var2;
  int iVar3;
  int iVar4;
  CMS_SignerInfo *pCVar5;
  BIO *chain;
  BIO *pBVar6;
  _STACK *st;
  void *pvVar7;
  int iVar8;
  _STACK *st_00;
  int iVar9;
  uint uVar10;
  uint uVar11;
  X509 *local_2c [2];
  
  ppAVar1 = CMS_get0_content(rcms);
  if ((ppAVar1 == (ASN1_OCTET_STRING **)0x0) || (*ppAVar1 == (ASN1_OCTET_STRING *)0x0)) {
    ERR_put_error(0x2e,99,0x7f,"cms_smime.c",0x77);
    return 0;
  }
  p_Var2 = (_STACK *)CMS_get0_SignerInfos(rcms);
  iVar3 = sk_num(p_Var2);
  if (iVar3 < 1) {
    ERR_put_error(0x2e,0x9d,0x87,"cms_smime.c",0x13d);
  }
  else {
    iVar8 = 0;
    iVar3 = 0;
    while( true ) {
      iVar4 = sk_num(p_Var2);
      iVar9 = iVar3 + 1;
      if (iVar4 <= iVar3) break;
      pCVar5 = (CMS_SignerInfo *)sk_value(p_Var2,iVar3);
      CMS_SignerInfo_get0_algs
                (pCVar5,(EVP_PKEY **)0x0,local_2c,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0);
      iVar3 = iVar9;
      if (local_2c[0] != (X509 *)0x0) {
        iVar8 = iVar8 + 1;
      }
    }
    iVar3 = sk_num(p_Var2);
    if (iVar8 != iVar3) {
      iVar3 = CMS_set1_signers_certs(rcms,certs,flags & 0xffffffbe);
      iVar8 = iVar8 + iVar3;
    }
    iVar3 = sk_num(p_Var2);
    if (iVar3 == iVar8) {
      st_00 = (_STACK *)(flags & 0x20);
      if (st_00 == (_STACK *)0x0) {
        st = (_STACK *)CMS_get1_certs(rcms);
        if (-1 < (int)(flags << 0x12)) {
          st_00 = (_STACK *)CMS_get1_crls(rcms);
        }
        iVar3 = 0;
        do {
          iVar8 = sk_num(p_Var2);
          if (iVar8 <= iVar3) goto LAB_000e43ec;
          pvVar7 = sk_value(p_Var2,iVar3);
          pBVar6 = (BIO *)cms_signerinfo_verify_cert_isra_1(pvVar7,store,st,st_00);
          iVar3 = iVar3 + 1;
          chain = pBVar6;
        } while (pBVar6 != (BIO *)0x0);
      }
      else {
        st_00 = (_STACK *)0x0;
        st = st_00;
LAB_000e43ec:
        uVar10 = flags & 8;
        if ((flags & 8) == 0) {
          do {
            iVar3 = sk_num(p_Var2);
            uVar11 = uVar10 + 1;
            if (iVar3 <= (int)uVar10) goto LAB_000e4480;
            pCVar5 = (CMS_SignerInfo *)sk_value(p_Var2,uVar10);
            iVar3 = CMS_signed_get_attr_count(pCVar5);
            uVar10 = uVar11;
          } while ((iVar3 < 0) || (iVar3 = CMS_SignerInfo_verify(pCVar5), 0 < iVar3));
          pBVar6 = (BIO *)0x0;
          chain = (BIO *)0x0;
        }
        else {
LAB_000e4480:
          chain = CMS_dataInit(rcms,(BIO *)0x0);
          pBVar6 = chain;
          if ((chain != (BIO *)0x0) &&
             (pBVar6 = (BIO *)cms_copy_content(0,chain,flags & 0xffffffbe), pBVar6 != (BIO *)0x0)) {
            uVar10 = flags & 4;
            if ((flags & 4) == 0) {
              do {
                iVar3 = sk_num(p_Var2);
                if (iVar3 <= (int)uVar10) goto LAB_000e44a4;
                pCVar5 = (CMS_SignerInfo *)sk_value(p_Var2,uVar10);
                iVar3 = CMS_SignerInfo_verify_content(pCVar5,chain);
                uVar10 = uVar10 + 1;
              } while (0 < iVar3);
              ERR_put_error(0x2e,0x9d,0x6d,"cms_smime.c",0x188);
              pBVar6 = (BIO *)0x0;
            }
            else {
LAB_000e44a4:
              pBVar6 = (BIO *)0x1;
            }
          }
        }
      }
      BIO_free_all(chain);
      if (st != (_STACK *)0x0) {
        sk_pop_free(st,X509_free + 1);
      }
      if (st_00 != (_STACK *)0x0) {
        sk_pop_free(st_00,X509_CRL_free + 1);
      }
      if (pBVar6 == (BIO *)0x0) {
        return 0;
      }
      iVar3 = cms_Receipt_verify(rcms,ocms);
      return iVar3;
    }
    ERR_put_error(0x2e,0x9d,0x8a,"cms_smime.c",0x14c);
  }
  BIO_free_all((BIO *)0x0);
  return 0;
}

