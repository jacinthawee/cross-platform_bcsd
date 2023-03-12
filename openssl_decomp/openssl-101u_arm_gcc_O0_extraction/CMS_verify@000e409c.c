
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
  _STACK *st;
  _STACK *st_00;
  int iVar10;
  BIO *pBVar11;
  uint uVar12;
  uint uVar13;
  X509 *local_30;
  void *local_2c [2];
  
  if ((dcont == (BIO *)0x0) &&
     ((ppAVar7 = CMS_get0_content(cms), ppAVar7 == (ASN1_OCTET_STRING **)0x0 ||
      (*ppAVar7 == (ASN1_OCTET_STRING *)0x0)))) {
    ERR_put_error(0x2e,99,0x7f,"cms_smime.c",0x77);
    return 0;
  }
  p_Var1 = (_STACK *)CMS_get0_SignerInfos(cms);
  iVar2 = sk_num(p_Var1);
  if (iVar2 < 1) {
    uVar12 = count_leading_zeroes(dcont);
    iVar9 = 0x13d;
    iVar2 = 0x87;
  }
  else {
    iVar9 = 0;
    iVar2 = 0;
    while( true ) {
      iVar3 = sk_num(p_Var1);
      iVar10 = iVar2 + 1;
      if (iVar3 <= iVar2) break;
      pCVar4 = (CMS_SignerInfo *)sk_value(p_Var1,iVar2);
      CMS_SignerInfo_get0_algs
                (pCVar4,(EVP_PKEY **)0x0,&local_30,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0);
      iVar2 = iVar10;
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
          if (iVar9 <= iVar2) goto LAB_000e41a2;
          pvVar8 = sk_value(p_Var1,iVar2);
          iVar9 = cms_signerinfo_verify_cert_isra_1(pvVar8,store,st_00);
          iVar2 = iVar2 + 1;
        } while (iVar9 != 0);
      }
      else {
        st = (_STACK *)0x0;
        st_00 = st;
LAB_000e41a2:
        uVar12 = flags & 8;
        if ((flags & 8) != 0) {
LAB_000e41e4:
          if ((dcont == (BIO *)0x0) || (iVar2 = BIO_method_type(dcont), iVar2 != 0x401)) {
            uVar12 = 1;
            pBVar11 = dcont;
          }
          else {
            len = BIO_ctrl(dcont,3,0,local_2c);
            pBVar11 = BIO_new_mem_buf(local_2c[0],len);
            if (pBVar11 == (BIO *)0x0) {
              ERR_put_error(0x2e,0x9d,0x41,"cms_smime.c",0x177);
              return 0;
            }
            uVar12 = count_leading_zeroes((int)dcont - (int)pBVar11);
            uVar12 = uVar12 >> 5;
          }
          pBVar11 = CMS_dataInit(cms,pBVar11);
          pBVar6 = pBVar11;
          if ((pBVar11 != (BIO *)0x0) &&
             (pBVar6 = (BIO *)cms_copy_content(out,pBVar11,flags), pBVar6 != (BIO *)0x0)) {
            uVar13 = flags & 4;
            if ((flags & 4) == 0) {
              do {
                iVar2 = sk_num(p_Var1);
                if (iVar2 <= (int)uVar13) goto LAB_000e4222;
                pCVar4 = (CMS_SignerInfo *)sk_value(p_Var1,uVar13);
                iVar2 = CMS_SignerInfo_verify_content(pCVar4,pBVar11);
                uVar13 = uVar13 + 1;
              } while (0 < iVar2);
              pBVar6 = (BIO *)0x0;
              ERR_put_error(0x2e,0x9d,0x6d,"cms_smime.c",0x188);
            }
            else {
LAB_000e4222:
              pBVar6 = (BIO *)0x1;
            }
          }
          goto LAB_000e413c;
        }
        do {
          iVar2 = sk_num(p_Var1);
          uVar13 = uVar12 + 1;
          if (iVar2 <= (int)uVar12) goto LAB_000e41e4;
          pCVar4 = (CMS_SignerInfo *)sk_value(p_Var1,uVar12);
          iVar2 = CMS_signed_get_attr_count(pCVar4);
          uVar12 = uVar13;
        } while ((iVar2 < 0) || (iVar2 = CMS_SignerInfo_verify(pCVar4), 0 < iVar2));
      }
      uVar12 = count_leading_zeroes(dcont);
      pBVar11 = (BIO *)0x0;
      uVar12 = uVar12 >> 5;
      pBVar6 = (BIO *)0x0;
      goto LAB_000e413c;
    }
    uVar12 = count_leading_zeroes(dcont);
    iVar9 = 0x14c;
    iVar2 = 0x8a;
  }
  ERR_put_error(0x2e,0x9d,iVar2,"cms_smime.c",iVar9);
  pBVar11 = (BIO *)0x0;
  uVar12 = uVar12 >> 5;
  st = (_STACK *)0x0;
  st_00 = (_STACK *)0x0;
  pBVar6 = (BIO *)0x0;
LAB_000e413c:
  if (dcont == (BIO *)0x0) {
    uVar12 = 0;
  }
  else {
    uVar12 = uVar12 & 1;
  }
  if (uVar12 == 0) {
    BIO_free_all(pBVar11);
  }
  else {
    do {
      pBVar5 = BIO_pop(pBVar11);
      BIO_free(pBVar11);
      pBVar11 = pBVar5;
    } while (dcont != pBVar5 && pBVar5 != (BIO *)0x0);
  }
  if (st_00 != (_STACK *)0x0) {
    sk_pop_free(st_00,X509_free + 1);
  }
  if (st != (_STACK *)0x0) {
    sk_pop_free(st,X509_CRL_free + 1);
  }
  return (int)pBVar6;
}

