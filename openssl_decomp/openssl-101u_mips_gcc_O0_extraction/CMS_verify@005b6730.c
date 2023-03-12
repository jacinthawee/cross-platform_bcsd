
int CMS_verify(CMS_ContentInfo *cms,stack_st_X509 *certs,X509_STORE *store,BIO *dcont,BIO *out,
              uint flags)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  X509_STORE *pXVar5;
  X509_STORE *pXVar6;
  ASN1_OCTET_STRING **ppAVar7;
  int iVar8;
  undefined4 uVar9;
  CMS_SignerInfo *pCVar10;
  stack_st_X509_LOOKUP *cms_00;
  X509_STORE *certs_00;
  undefined4 uVar11;
  char *pcVar12;
  stack_st_CMS_SignerInfo *unaff_s0;
  stack_st_CMS_SignerInfo *psVar13;
  X509_STORE *unaff_s1;
  X509_STORE *pXVar14;
  BIO *chain;
  X509_STORE *unaff_s4;
  uint flags_00;
  stack_st_X509_CRL *psVar15;
  stack_st_X509 *psVar16;
  X509_STORE *unaff_s8;
  X509 *pXStack_90;
  int iStack_8c;
  stack_st_CMS_SignerInfo *psStack_88;
  X509_STORE *pXStack_84;
  BIO *pBStack_80;
  BIO *pBStack_7c;
  X509_STORE *pXStack_78;
  undefined *puStack_74;
  X509_STORE *pXStack_70;
  X509_STORE *pXStack_6c;
  X509_STORE *pXStack_68;
  code *pcStack_64;
  uint in_stack_ffffffb0;
  int local_34;
  BIO_METHOD *local_30;
  stack_st_X509_LOOKUP *local_2c;
  
  puStack_74 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(stack_st_X509_LOOKUP **)PTR___stack_chk_guard_006a9ae8;
  certs_00 = store;
  pcVar12 = (char *)dcont;
  if ((dcont != (BIO *)0x0) ||
     ((ppAVar7 = CMS_get0_content(cms), ppAVar7 != (ASN1_OCTET_STRING **)0x0 &&
      (*ppAVar7 != (ASN1_OCTET_STRING *)0x0)))) {
    psStack_88 = CMS_get0_SignerInfos(cms);
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psStack_88);
    if (iVar3 < 1) {
      certs_00 = (X509_STORE *)0x87;
      in_stack_ffffffb0 = 0x13d;
LAB_005b6884:
      pcVar12 = "cms_smime.c";
      pXVar5 = (X509_STORE *)0x9d;
      unaff_s1 = (X509_STORE *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x9d,certs_00,"cms_smime.c");
      cms = (CMS_ContentInfo *)0x0;
      psVar13 = (stack_st_CMS_SignerInfo *)0x0;
      certs = (stack_st_X509 *)0x0;
      unaff_s4 = (X509_STORE *)0x0;
      goto joined_r0x005b6cb0;
    }
    unaff_s8 = (X509_STORE *)&local_34;
    pXVar14 = (X509_STORE *)0x0;
    iVar3 = 0;
    while (iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psStack_88), iVar3 < iVar4) {
      iVar4 = iVar3 + 1;
      pCVar10 = (CMS_SignerInfo *)(*(code *)PTR_sk_value_006a6e24)(psStack_88,iVar3);
      pcVar12 = (char *)0x0;
      in_stack_ffffffb0 = 0;
      certs_00 = unaff_s8;
      CMS_SignerInfo_get0_algs
                (pCVar10,(EVP_PKEY **)0x0,(X509 **)unaff_s8,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0);
      iVar3 = iVar4;
      if (local_34 != 0) {
        pXVar14 = (X509_STORE *)((int)&pXVar14->cache + 1);
      }
    }
    pXVar5 = (X509_STORE *)(*(code *)PTR_sk_num_006a6e2c)(psStack_88);
    if (pXVar14 != pXVar5) {
      certs_00 = (X509_STORE *)flags;
      iVar3 = CMS_set1_signers_certs(cms,certs,flags);
      pXVar5 = (X509_STORE *)((int)&pXVar14->cache + iVar3);
    }
    pXVar6 = (X509_STORE *)(*(code *)PTR_sk_num_006a6e2c)(psStack_88);
    if (pXVar5 != pXVar6) {
      certs_00 = (X509_STORE *)0x8a;
      in_stack_ffffffb0 = 0x14c;
      goto LAB_005b6884;
    }
    certs = (stack_st_X509 *)0x0;
    if ((flags & 0x20) == 0) {
      unaff_s4 = (X509_STORE *)CMS_get1_certs(cms);
      if ((flags & 0x2000) == 0) {
        certs = (stack_st_X509 *)CMS_get1_crls(cms);
      }
      else {
        certs = (stack_st_X509 *)0x0;
      }
      for (pXVar14 = (X509_STORE *)0x0; iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psStack_88),
          (int)pXVar14 < iVar3; pXVar14 = (X509_STORE *)((int)&pXVar14->cache + 1)) {
        uVar9 = (*(code *)PTR_sk_value_006a6e24)(psStack_88,pXVar14);
        pXVar5 = store;
        certs_00 = unaff_s4;
        pcVar12 = (char *)certs;
        iVar3 = cms_signerinfo_verify_cert_isra_1(uVar9,store,unaff_s4,certs);
        if (iVar3 == 0) goto LAB_005b6b90;
      }
    }
    else {
      unaff_s4 = (X509_STORE *)0x0;
    }
    if ((flags & 8) == 0) {
      pXVar14 = (X509_STORE *)0x0;
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psStack_88);
      if (0 < iVar3) {
        do {
          pXVar5 = pXVar14;
          store = (X509_STORE *)(*(code *)PTR_sk_value_006a6e24)(psStack_88,pXVar14);
          iVar3 = (*(code *)PTR_CMS_signed_get_attr_count_006a9334)(store);
          if ((-1 < iVar3) && (iVar3 = CMS_SignerInfo_verify((CMS_SignerInfo *)store), iVar3 < 1))
          goto LAB_005b6b90;
          pXVar14 = (X509_STORE *)((int)&pXVar14->cache + 1);
          iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psStack_88);
        } while ((int)pXVar14 < iVar3);
      }
    }
    if (dcont != (BIO *)0x0) {
      iVar3 = (*(code *)PTR_BIO_method_type_006a8328)(dcont);
      if (iVar3 == 0x401) {
        pcVar12 = (char *)&local_30;
        certs_00 = (X509_STORE *)0x0;
        uVar9 = (*(code *)PTR_BIO_ctrl_006a6e18)(dcont,3,0,pcVar12);
        unaff_s1 = (X509_STORE *)(*(code *)PTR_BIO_new_mem_buf_006a9148)(local_30,uVar9);
        if (unaff_s1 == (X509_STORE *)0x0) {
          certs_00 = (X509_STORE *)&DAT_00000041;
          pcVar12 = "cms_smime.c";
          in_stack_ffffffb0 = 0x177;
          pXVar5 = (X509_STORE *)0x9d;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x9d,0x41,"cms_smime.c");
          psVar13 = (stack_st_CMS_SignerInfo *)0x0;
          goto LAB_005b68fc;
        }
        pXVar5 = unaff_s1;
        cms = (CMS_ContentInfo *)CMS_dataInit(cms,(BIO *)unaff_s1);
        if ((X509_STORE *)cms != (X509_STORE *)0x0) goto LAB_005b6a44;
        psVar13 = (stack_st_CMS_SignerInfo *)0x0;
        goto LAB_005b68b0;
      }
      pXVar5 = (X509_STORE *)dcont;
      cms = (CMS_ContentInfo *)CMS_dataInit(cms,dcont);
      unaff_s1 = (X509_STORE *)dcont;
      if ((X509_STORE *)cms != (X509_STORE *)0x0) {
LAB_005b6a44:
        pXVar5 = (X509_STORE *)cms;
        certs_00 = (X509_STORE *)flags;
        iVar3 = cms_copy_content(out,cms);
        if (iVar3 != 0) goto LAB_005b6aa4;
        psVar13 = (stack_st_CMS_SignerInfo *)0x0;
        goto LAB_005b68b0;
      }
      psVar13 = (stack_st_CMS_SignerInfo *)0x0;
      pXVar6 = (X509_STORE *)cms;
      goto LAB_005b6944;
    }
    pXVar5 = (X509_STORE *)0x0;
    cms = (CMS_ContentInfo *)CMS_dataInit(cms,(BIO *)0x0);
    if (((X509_STORE *)cms != (X509_STORE *)0x0) &&
       (pXVar5 = (X509_STORE *)cms, certs_00 = (X509_STORE *)flags,
       iVar3 = cms_copy_content(out,cms), iVar3 != 0)) {
      unaff_s1 = (X509_STORE *)0x0;
LAB_005b6aa4:
      if ((flags & 4) == 0) {
        for (store = (X509_STORE *)0x0; iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psStack_88),
            (int)store < iVar3; store = (X509_STORE *)((int)&store->cache + 1)) {
          pCVar10 = (CMS_SignerInfo *)(*(code *)PTR_sk_value_006a6e24)(psStack_88,store);
          pXVar5 = (X509_STORE *)cms;
          iVar3 = CMS_SignerInfo_verify_content(pCVar10,(BIO *)cms);
          if (iVar3 < 1) {
            certs_00 = (X509_STORE *)&DAT_0000006d;
            pcVar12 = "cms_smime.c";
            in_stack_ffffffb0 = 0x188;
            pXVar5 = (X509_STORE *)0x9d;
            psVar13 = (stack_st_CMS_SignerInfo *)0x0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x9d,0x6d,"cms_smime.c");
            goto joined_r0x005b6cb0;
          }
        }
      }
      psVar13 = (stack_st_CMS_SignerInfo *)0x1;
      goto joined_r0x005b6cb0;
    }
    psVar13 = (stack_st_CMS_SignerInfo *)0x0;
    goto LAB_005b68bc;
  }
  certs_00 = (X509_STORE *)0x7f;
  pcVar12 = "cms_smime.c";
  in_stack_ffffffb0 = 0x77;
  pXVar5 = (X509_STORE *)&DAT_00000063;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,99,0x7f,"cms_smime.c");
  psVar13 = (stack_st_CMS_SignerInfo *)0x0;
  psStack_88 = unaff_s0;
LAB_005b68fc:
  if (local_2c == *(stack_st_X509_LOOKUP **)puStack_74) {
    return (int)psVar13;
  }
  pcStack_64 = CMS_verify_receipt;
  cms_00 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iStack_8c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pXStack_84 = unaff_s1;
  pBStack_80 = dcont;
  pBStack_7c = (BIO *)certs;
  pXStack_78 = unaff_s4;
  pXStack_70 = (X509_STORE *)cms;
  pXStack_6c = store;
  pXStack_68 = unaff_s8;
  ppAVar7 = CMS_get0_content((CMS_ContentInfo *)cms_00);
  if ((ppAVar7 == (ASN1_OCTET_STRING **)0x0) || (*ppAVar7 == (ASN1_OCTET_STRING *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,99,0x7f,"cms_smime.c",0x77);
    iVar3 = 0;
  }
  else {
    psVar13 = CMS_get0_SignerInfos((CMS_ContentInfo *)cms_00);
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar13);
    if (iVar3 < 1) {
      uVar11 = 0x87;
      uVar9 = 0x13d;
    }
    else {
      iVar3 = 0;
      iVar4 = 0;
      while (iVar8 = (*(code *)PTR_sk_num_006a6e2c)(psVar13), iVar4 < iVar8) {
        iVar8 = iVar4 + 1;
        pCVar10 = (CMS_SignerInfo *)(*(code *)PTR_sk_value_006a6e24)(psVar13,iVar4);
        CMS_SignerInfo_get0_algs
                  (pCVar10,(EVP_PKEY **)0x0,&pXStack_90,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0);
        iVar4 = iVar8;
        if (pXStack_90 != (X509 *)0x0) {
          iVar3 = iVar3 + 1;
        }
      }
      flags_00 = in_stack_ffffffb0 & 0xffffffbe;
      iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar13);
      if (iVar3 != iVar4) {
        iVar4 = CMS_set1_signers_certs((CMS_ContentInfo *)cms_00,(stack_st_X509 *)certs_00,flags_00)
        ;
        iVar4 = iVar3 + iVar4;
      }
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar13);
      if (iVar3 == iVar4) {
        psVar15 = (stack_st_X509_CRL *)0x0;
        if ((in_stack_ffffffb0 & 0x20) == 0) {
          psVar16 = CMS_get1_certs((CMS_ContentInfo *)cms_00);
          if ((in_stack_ffffffb0 & 0x2000) == 0) {
            psVar15 = CMS_get1_crls((CMS_ContentInfo *)cms_00);
          }
          else {
            psVar15 = (stack_st_X509_CRL *)0x0;
          }
          for (iVar3 = 0; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar13), iVar3 < iVar4;
              iVar3 = iVar3 + 1) {
            uVar9 = (*(code *)PTR_sk_value_006a6e24)(psVar13,iVar3);
            iVar4 = cms_signerinfo_verify_cert_isra_1(uVar9,pcVar12,psVar16,psVar15);
            if (iVar4 == 0) goto LAB_005b6ff8;
          }
        }
        else {
          psVar16 = (stack_st_X509 *)0x0;
        }
        if ((in_stack_ffffffb0 & 8) == 0) {
          for (iVar3 = 0; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar13), iVar3 < iVar4;
              iVar3 = iVar3 + 1) {
            pCVar10 = (CMS_SignerInfo *)(*(code *)PTR_sk_value_006a6e24)(psVar13,iVar3);
            iVar4 = (*(code *)PTR_CMS_signed_get_attr_count_006a9334)(pCVar10);
            if ((-1 < iVar4) && (iVar4 = CMS_SignerInfo_verify(pCVar10), iVar4 < 1))
            goto LAB_005b6ff8;
          }
        }
        chain = CMS_dataInit((CMS_ContentInfo *)cms_00,(BIO *)0x0);
        if ((chain == (BIO *)0x0) || (iVar3 = cms_copy_content(0,chain,flags_00), iVar3 == 0)) {
LAB_005b6ffc:
          bVar1 = false;
        }
        else {
          if ((in_stack_ffffffb0 & 4) == 0) {
            for (iVar3 = 0; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar13), iVar3 < iVar4;
                iVar3 = iVar3 + 1) {
              pCVar10 = (CMS_SignerInfo *)(*(code *)PTR_sk_value_006a6e24)(psVar13,iVar3);
              iVar4 = CMS_SignerInfo_verify_content(pCVar10,chain);
              if (iVar4 < 1) {
                bVar1 = false;
                (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x9d,0x6d,"cms_smime.c",0x188);
                goto LAB_005b7000;
              }
            }
          }
          bVar1 = true;
        }
LAB_005b7000:
        (*(code *)PTR_BIO_free_all_006a6e74)(chain);
        if (psVar16 != (stack_st_X509 *)0x0) {
          (*(code *)PTR_sk_pop_free_006a7058)(psVar16,PTR_X509_free_006a6e90);
        }
        if (psVar15 != (stack_st_X509_CRL *)0x0) {
          (*(code *)PTR_sk_pop_free_006a7058)(psVar15,PTR_X509_CRL_free_006a7060);
        }
        if (!bVar1) goto LAB_005b7164;
        iVar3 = cms_Receipt_verify(cms_00,pXVar5);
        goto LAB_005b6e90;
      }
      uVar11 = 0x8a;
      uVar9 = 0x14c;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x9d,uVar11,"cms_smime.c",uVar9);
    (*(code *)PTR_BIO_free_all_006a6e74)(0);
    iVar3 = 0;
  }
LAB_005b6e90:
  while (iStack_8c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005b7164:
    iVar3 = 0;
  }
  return iVar3;
LAB_005b6b90:
  unaff_s1 = (X509_STORE *)0x0;
  cms = (CMS_ContentInfo *)0x0;
  psVar13 = (stack_st_CMS_SignerInfo *)0x0;
joined_r0x005b6cb0:
  pXVar14 = unaff_s1;
  if (dcont == (BIO *)0x0) {
LAB_005b68bc:
    (*(code *)PTR_BIO_free_all_006a6e74)(cms);
    unaff_s1 = pXVar14;
  }
  else {
LAB_005b68b0:
    pXVar14 = unaff_s1;
    pXVar6 = (X509_STORE *)cms;
    if ((X509_STORE *)dcont != unaff_s1) goto LAB_005b68bc;
LAB_005b6944:
    do {
      cms = (CMS_ContentInfo *)(*(code *)PTR_BIO_pop_006a79c8)(pXVar6);
      (*(code *)PTR_BIO_free_006a6e70)(pXVar6);
      unaff_s1 = pXVar14;
      if ((X509_STORE *)cms == (X509_STORE *)0x0) break;
      pXVar6 = (X509_STORE *)cms;
    } while ((BIO *)cms != dcont);
  }
  if (unaff_s4 != (X509_STORE *)0x0) {
    pXVar5 = (X509_STORE *)PTR_X509_free_006a6e90;
    (*(code *)PTR_sk_pop_free_006a7058)(unaff_s4,PTR_X509_free_006a6e90);
  }
  psStack_88 = psVar13;
  if ((BIO *)certs != (BIO *)0x0) {
    pXVar5 = (X509_STORE *)PTR_X509_CRL_free_006a7060;
    (*(code *)PTR_sk_pop_free_006a7058)(certs,PTR_X509_CRL_free_006a7060);
  }
  goto LAB_005b68fc;
LAB_005b6ff8:
  chain = (BIO *)0x0;
  goto LAB_005b6ffc;
}

