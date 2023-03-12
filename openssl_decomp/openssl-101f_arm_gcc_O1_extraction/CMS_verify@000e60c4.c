
int CMS_verify(CMS_ContentInfo *cms,stack_st_X509 *certs,X509_STORE *store,BIO *dcont,BIO *out,
              uint flags)

{
  _STACK *p_Var1;
  int iVar2;
  int iVar3;
  CMS_SignerInfo *pCVar4;
  BIO *pBVar5;
  BIO *pBVar6;
  ASN1_OCTET_STRING **ppAVar7;
  void *pvVar8;
  long len;
  int iVar9;
  BIO *pBVar10;
  uint uVar11;
  _STACK *st;
  int iVar12;
  uint uVar13;
  _STACK *st_00;
  X509 *local_30;
  void *local_2c [2];
  
  if ((dcont == (BIO *)0x0) &&
     ((ppAVar7 = CMS_get0_content(cms), ppAVar7 == (ASN1_OCTET_STRING **)0x0 ||
      (*ppAVar7 == (ASN1_OCTET_STRING *)0x0)))) {
    ERR_put_error(0x2e,99,0x7f,"cms_smime.c",0x7f);
    return 0;
  }
  p_Var1 = (_STACK *)CMS_get0_SignerInfos(cms);
  iVar2 = sk_num(p_Var1);
  if (iVar2 < 1) {
    uVar13 = count_leading_zeroes(dcont);
    iVar9 = 0x150;
    iVar2 = 0x87;
  }
  else {
    iVar9 = 0;
    iVar2 = 0;
    while( true ) {
      iVar3 = sk_num(p_Var1);
      iVar12 = iVar2 + 1;
      if (iVar3 <= iVar2) break;
      pCVar4 = (CMS_SignerInfo *)sk_value(p_Var1,iVar2);
      CMS_SignerInfo_get0_algs
                (pCVar4,(EVP_PKEY **)0x0,&local_30,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0);
      iVar2 = iVar12;
      if (local_30 != (X509 *)0x0) {
        iVar9 = iVar9 + 1;
      }
    }
    iVar2 = sk_num(p_Var1);
    if (iVar9 != iVar2) {
      iVar2 = CMS_set1_signers_certs(cms,certs,flags);
      iVar9 = iVar9 + iVar2;
    }
    iVar2 = sk_num(p_Var1);
    if (iVar2 == iVar9) {
      st = (_STACK *)(flags & 0x20);
      if (st == (_STACK *)0x0) {
        st_00 = (_STACK *)CMS_get1_certs(cms);
        if (-1 < (int)(flags << 0x12)) {
          st = (_STACK *)CMS_get1_crls(cms);
        }
        iVar2 = 0;
        do {
          iVar9 = sk_num(p_Var1);
          if (iVar9 <= iVar2) goto LAB_000e61c8;
          pvVar8 = sk_value(p_Var1,iVar2);
          iVar9 = cms_signerinfo_verify_cert_isra_1(pvVar8,store,st_00);
          iVar2 = iVar2 + 1;
        } while (iVar9 != 0);
      }
      else {
        st = (_STACK *)0x0;
        st_00 = st;
LAB_000e61c8:
        uVar13 = flags & 8;
        if ((flags & 8) != 0) {
LAB_000e6208:
          if ((dcont == (BIO *)0x0) || (iVar2 = BIO_method_type(dcont), iVar2 != 0x401)) {
            uVar13 = 1;
            pBVar10 = dcont;
          }
          else {
            len = BIO_ctrl(dcont,3,0,local_2c);
            pBVar10 = BIO_new_mem_buf(local_2c[0],len);
            if (pBVar10 == (BIO *)0x0) {
              ERR_put_error(0x2e,0x9d,0x41,"cms_smime.c",0x192);
              return 0;
            }
            uVar13 = count_leading_zeroes((int)dcont - (int)pBVar10);
            uVar13 = uVar13 >> 5;
          }
          pBVar10 = CMS_dataInit(cms,pBVar10);
          pBVar6 = pBVar10;
          if ((pBVar10 != (BIO *)0x0) &&
             (pBVar6 = (BIO *)cms_copy_content(out,pBVar10,flags), pBVar6 != (BIO *)0x0)) {
            uVar11 = flags & 4;
            if ((flags & 4) == 0) {
              do {
                iVar2 = sk_num(p_Var1);
                if (iVar2 <= (int)uVar11) goto LAB_000e6246;
                pCVar4 = (CMS_SignerInfo *)sk_value(p_Var1,uVar11);
                iVar2 = CMS_SignerInfo_verify_content(pCVar4,pBVar10);
                uVar11 = uVar11 + 1;
              } while (0 < iVar2);
              pBVar6 = (BIO *)0x0;
              ERR_put_error(0x2e,0x9d,0x6d,"cms_smime.c",0x1a9);
            }
            else {
LAB_000e6246:
              pBVar6 = (BIO *)0x1;
            }
          }
          goto LAB_000e6162;
        }
        do {
          iVar2 = sk_num(p_Var1);
          uVar11 = uVar13 + 1;
          if (iVar2 <= (int)uVar13) goto LAB_000e6208;
          pCVar4 = (CMS_SignerInfo *)sk_value(p_Var1,uVar13);
          iVar2 = CMS_signed_get_attr_count(pCVar4);
          uVar13 = uVar11;
        } while ((iVar2 < 0) || (iVar2 = CMS_SignerInfo_verify(pCVar4), 0 < iVar2));
      }
      uVar13 = count_leading_zeroes(dcont);
      pBVar10 = (BIO *)0x0;
      uVar13 = uVar13 >> 5;
      pBVar6 = pBVar10;
      goto LAB_000e6162;
    }
    uVar13 = count_leading_zeroes(dcont);
    iVar9 = 0x161;
    iVar2 = 0x8a;
  }
  ERR_put_error(0x2e,0x9d,iVar2,"cms_smime.c",iVar9);
  pBVar10 = (BIO *)0x0;
  uVar13 = uVar13 >> 5;
  st = (_STACK *)0x0;
  st_00 = (_STACK *)0x0;
  pBVar6 = (BIO *)0x0;
LAB_000e6162:
  if (dcont == (BIO *)0x0) {
    uVar13 = 0;
  }
  else {
    uVar13 = uVar13 & 1;
  }
  if (uVar13 == 0) {
    BIO_free_all(pBVar10);
  }
  else {
    do {
      pBVar5 = BIO_pop(pBVar10);
      BIO_free(pBVar10);
      pBVar10 = pBVar5;
    } while (dcont != pBVar5);
  }
  if (st_00 != (_STACK *)0x0) {
    sk_pop_free(st_00,X509_free + 1);
  }
  if (st != (_STACK *)0x0) {
    sk_pop_free(st,X509_CRL_free + 1);
  }
  return (int)pBVar6;
}

