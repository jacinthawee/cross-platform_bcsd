
int CMS_verify(CMS_ContentInfo *cms,stack_st_X509 *certs,X509_STORE *store,BIO *dcont,BIO *out,
              uint flags)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ASN1_OCTET_STRING **ppAVar6;
  undefined4 uVar7;
  CMS_SignerInfo *pCVar8;
  stack_st_X509_LOOKUP *cms_00;
  X509_STORE *pXVar9;
  X509_STORE *certs_00;
  undefined4 uVar10;
  char *pcVar11;
  stack_st_CMS_SignerInfo *unaff_s0;
  stack_st_CMS_SignerInfo *psVar12;
  BIO *chain;
  X509_STORE *unaff_s2;
  X509_STORE *pXVar13;
  X509_STORE *unaff_s4;
  uint flags_00;
  X509_STORE *pXVar14;
  stack_st_X509_CRL *psVar15;
  stack_st_X509 *psVar16;
  X509_STORE *unaff_s8;
  X509 *pXStack_90;
  int iStack_8c;
  stack_st_CMS_SignerInfo *psStack_88;
  BIO *pBStack_84;
  X509_STORE *pXStack_80;
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
  
  puStack_74 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(stack_st_X509_LOOKUP **)PTR___stack_chk_guard_006aabf0;
  certs_00 = store;
  pcVar11 = (char *)dcont;
  if ((dcont != (BIO *)0x0) ||
     ((ppAVar6 = CMS_get0_content(cms), ppAVar6 != (ASN1_OCTET_STRING **)0x0 &&
      (*ppAVar6 != (ASN1_OCTET_STRING *)0x0)))) {
    psStack_88 = CMS_get0_SignerInfos(cms);
    iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psStack_88);
    if (iVar3 < 1) {
      certs_00 = (X509_STORE *)0x87;
      in_stack_ffffffb0 = 0x150;
LAB_005b91d0:
      pcVar11 = "cms_smime.c";
      pXVar9 = (X509_STORE *)&DAT_0000009d;
      unaff_s2 = (X509_STORE *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x9d,certs_00,"cms_smime.c");
      cms = (CMS_ContentInfo *)0x0;
      psVar12 = (stack_st_CMS_SignerInfo *)0x0;
      certs = (stack_st_X509 *)0x0;
      unaff_s4 = (X509_STORE *)0x0;
      goto joined_r0x005b95dc;
    }
    unaff_s8 = (X509_STORE *)&local_34;
    iVar3 = 0;
    iVar5 = 0;
    while (iVar4 = (*(code *)PTR_sk_num_006a7f2c)(psStack_88), iVar5 < iVar4) {
      iVar4 = iVar5 + 1;
      pCVar8 = (CMS_SignerInfo *)(*(code *)PTR_sk_value_006a7f24)(psStack_88,iVar5);
      pcVar11 = (char *)0x0;
      in_stack_ffffffb0 = 0;
      certs_00 = unaff_s8;
      CMS_SignerInfo_get0_algs
                (pCVar8,(EVP_PKEY **)0x0,(X509 **)unaff_s8,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0);
      iVar5 = iVar4;
      if (local_34 != 0) {
        iVar3 = iVar3 + 1;
      }
    }
    iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psStack_88);
    if (iVar3 != iVar5) {
      certs_00 = (X509_STORE *)flags;
      iVar5 = CMS_set1_signers_certs(cms,certs,flags);
      iVar5 = iVar3 + iVar5;
    }
    iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psStack_88);
    if (iVar5 != iVar3) {
      certs_00 = (X509_STORE *)0x8a;
      in_stack_ffffffb0 = 0x161;
      goto LAB_005b91d0;
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
      for (iVar3 = 0; iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psStack_88), iVar3 < iVar5;
          iVar3 = iVar3 + 1) {
        uVar7 = (*(code *)PTR_sk_value_006a7f24)(psStack_88,iVar3);
        pXVar9 = store;
        certs_00 = unaff_s4;
        pcVar11 = (char *)certs;
        iVar5 = cms_signerinfo_verify_cert_isra_1(uVar7,store,unaff_s4,certs);
        if (iVar5 == 0) goto LAB_005b94bc;
      }
    }
    else {
      unaff_s4 = (X509_STORE *)0x0;
    }
    pXVar13 = (X509_STORE *)0x0;
    if ((flags & 8) == 0) {
      for (; iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psStack_88), (int)pXVar13 < iVar3;
          pXVar13 = (X509_STORE *)((int)&pXVar13->cache + 1)) {
        pXVar9 = pXVar13;
        store = (X509_STORE *)(*(code *)PTR_sk_value_006a7f24)(psStack_88,pXVar13);
        iVar3 = (*(code *)PTR_CMS_signed_get_attr_count_006aa440)(store);
        if ((-1 < iVar3) && (iVar3 = CMS_SignerInfo_verify((CMS_SignerInfo *)store), iVar3 < 1))
        goto LAB_005b94bc;
      }
    }
    if (dcont != (BIO *)0x0) {
      iVar3 = (*(code *)PTR_BIO_method_type_006a9444)(dcont);
      if (iVar3 == 0x401) {
        pcVar11 = (char *)&local_30;
        certs_00 = (X509_STORE *)0x0;
        uVar7 = (*(code *)PTR_BIO_ctrl_006a7f18)(dcont,3,0,pcVar11);
        unaff_s2 = (X509_STORE *)(*(code *)PTR_BIO_new_mem_buf_006aa264)(local_30,uVar7);
        if (unaff_s2 == (X509_STORE *)0x0) {
          certs_00 = (X509_STORE *)&DAT_00000041;
          pcVar11 = "cms_smime.c";
          in_stack_ffffffb0 = 0x192;
          pXVar9 = (X509_STORE *)&DAT_0000009d;
          (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x9d,0x41,"cms_smime.c");
          psVar12 = (stack_st_CMS_SignerInfo *)0x0;
          goto LAB_005b9248;
        }
        pXVar9 = unaff_s2;
        cms = (CMS_ContentInfo *)CMS_dataInit(cms,(BIO *)unaff_s2);
        if ((X509_STORE *)cms != (X509_STORE *)0x0) goto LAB_005b9380;
        psVar12 = (stack_st_CMS_SignerInfo *)0x0;
        goto LAB_005b91fc;
      }
      pXVar9 = (X509_STORE *)dcont;
      cms = (CMS_ContentInfo *)CMS_dataInit(cms,dcont);
      unaff_s2 = (X509_STORE *)dcont;
      if ((X509_STORE *)cms != (X509_STORE *)0x0) {
LAB_005b9380:
        pXVar9 = (X509_STORE *)cms;
        certs_00 = (X509_STORE *)flags;
        iVar3 = cms_copy_content(out,cms);
        if (iVar3 != 0) goto LAB_005b93d8;
        psVar12 = (stack_st_CMS_SignerInfo *)0x0;
        goto LAB_005b91fc;
      }
      psVar12 = (stack_st_CMS_SignerInfo *)0x0;
      pXVar14 = (X509_STORE *)cms;
      goto LAB_005b92e8;
    }
    pXVar9 = (X509_STORE *)0x0;
    cms = (CMS_ContentInfo *)CMS_dataInit(cms,(BIO *)0x0);
    if (((X509_STORE *)cms != (X509_STORE *)0x0) &&
       (pXVar9 = (X509_STORE *)cms, certs_00 = (X509_STORE *)flags,
       iVar3 = cms_copy_content(out,cms), iVar3 != 0)) {
      unaff_s2 = (X509_STORE *)0x0;
LAB_005b93d8:
      if ((flags & 4) == 0) {
        for (store = (X509_STORE *)0x0; iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psStack_88),
            (int)store < iVar3; store = (X509_STORE *)((int)&store->cache + 1)) {
          pCVar8 = (CMS_SignerInfo *)(*(code *)PTR_sk_value_006a7f24)(psStack_88,store);
          pXVar9 = (X509_STORE *)cms;
          iVar3 = CMS_SignerInfo_verify_content(pCVar8,(BIO *)cms);
          if (iVar3 < 1) {
            certs_00 = (X509_STORE *)&DAT_0000006d;
            pcVar11 = "cms_smime.c";
            in_stack_ffffffb0 = 0x1a9;
            pXVar9 = (X509_STORE *)&DAT_0000009d;
            psVar12 = (stack_st_CMS_SignerInfo *)0x0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x9d,0x6d,"cms_smime.c");
            goto joined_r0x005b95dc;
          }
        }
      }
      psVar12 = (stack_st_CMS_SignerInfo *)0x1;
      goto joined_r0x005b95dc;
    }
    psVar12 = (stack_st_CMS_SignerInfo *)0x0;
    goto LAB_005b9208;
  }
  certs_00 = (X509_STORE *)0x7f;
  pcVar11 = "cms_smime.c";
  in_stack_ffffffb0 = 0x7f;
  pXVar9 = (X509_STORE *)0x63;
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,99,0x7f,"cms_smime.c");
  psVar12 = (stack_st_CMS_SignerInfo *)0x0;
  psStack_88 = unaff_s0;
LAB_005b9248:
  if (local_2c == *(stack_st_X509_LOOKUP **)puStack_74) {
    return (int)psVar12;
  }
  pcStack_64 = CMS_verify_receipt;
  cms_00 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_8c = *(int *)PTR___stack_chk_guard_006aabf0;
  pBStack_84 = dcont;
  pXStack_80 = unaff_s2;
  pBStack_7c = (BIO *)certs;
  pXStack_78 = unaff_s4;
  pXStack_70 = (X509_STORE *)cms;
  pXStack_6c = store;
  pXStack_68 = unaff_s8;
  ppAVar6 = CMS_get0_content((CMS_ContentInfo *)cms_00);
  if ((ppAVar6 == (ASN1_OCTET_STRING **)0x0) || (*ppAVar6 == (ASN1_OCTET_STRING *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,99,0x7f,"cms_smime.c",0x7f);
    iVar3 = 0;
  }
  else {
    psVar12 = CMS_get0_SignerInfos((CMS_ContentInfo *)cms_00);
    iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar12);
    if (iVar3 < 1) {
      uVar10 = 0x87;
      uVar7 = 0x150;
    }
    else {
      iVar3 = 0;
      iVar5 = 0;
      while (iVar4 = (*(code *)PTR_sk_num_006a7f2c)(psVar12), iVar5 < iVar4) {
        iVar4 = iVar5 + 1;
        pCVar8 = (CMS_SignerInfo *)(*(code *)PTR_sk_value_006a7f24)(psVar12,iVar5);
        CMS_SignerInfo_get0_algs
                  (pCVar8,(EVP_PKEY **)0x0,&pXStack_90,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0);
        iVar5 = iVar4;
        if (pXStack_90 != (X509 *)0x0) {
          iVar3 = iVar3 + 1;
        }
      }
      flags_00 = in_stack_ffffffb0 & 0xffffffbe;
      iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar12);
      if (iVar3 != iVar5) {
        iVar5 = CMS_set1_signers_certs((CMS_ContentInfo *)cms_00,(stack_st_X509 *)certs_00,flags_00)
        ;
        iVar5 = iVar3 + iVar5;
      }
      iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar12);
      if (iVar3 == iVar5) {
        psVar15 = (stack_st_X509_CRL *)0x0;
        if ((in_stack_ffffffb0 & 0x20) == 0) {
          psVar16 = CMS_get1_certs((CMS_ContentInfo *)cms_00);
          if ((in_stack_ffffffb0 & 0x2000) == 0) {
            psVar15 = CMS_get1_crls((CMS_ContentInfo *)cms_00);
          }
          else {
            psVar15 = (stack_st_X509_CRL *)0x0;
          }
          for (iVar3 = 0; iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar12), iVar3 < iVar5;
              iVar3 = iVar3 + 1) {
            uVar7 = (*(code *)PTR_sk_value_006a7f24)(psVar12,iVar3);
            iVar5 = cms_signerinfo_verify_cert_isra_1(uVar7,pcVar11,psVar16,psVar15);
            if (iVar5 == 0) goto LAB_005b9924;
          }
        }
        else {
          psVar16 = (stack_st_X509 *)0x0;
        }
        if ((in_stack_ffffffb0 & 8) == 0) {
          for (iVar3 = 0; iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar12), iVar3 < iVar5;
              iVar3 = iVar3 + 1) {
            pCVar8 = (CMS_SignerInfo *)(*(code *)PTR_sk_value_006a7f24)(psVar12,iVar3);
            iVar5 = (*(code *)PTR_CMS_signed_get_attr_count_006aa440)(pCVar8);
            if ((-1 < iVar5) && (iVar5 = CMS_SignerInfo_verify(pCVar8), iVar5 < 1))
            goto LAB_005b9924;
          }
        }
        chain = CMS_dataInit((CMS_ContentInfo *)cms_00,(BIO *)0x0);
        if ((chain == (BIO *)0x0) || (iVar3 = cms_copy_content(0,chain,flags_00), iVar3 == 0)) {
LAB_005b9928:
          bVar1 = false;
        }
        else {
          if ((in_stack_ffffffb0 & 4) == 0) {
            for (iVar3 = 0; iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar12), iVar3 < iVar5;
                iVar3 = iVar3 + 1) {
              pCVar8 = (CMS_SignerInfo *)(*(code *)PTR_sk_value_006a7f24)(psVar12,iVar3);
              iVar5 = CMS_SignerInfo_verify_content(pCVar8,chain);
              if (iVar5 < 1) {
                bVar1 = false;
                (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x9d,0x6d,"cms_smime.c",0x1a9);
                goto LAB_005b992c;
              }
            }
          }
          bVar1 = true;
        }
LAB_005b992c:
        (*(code *)PTR_BIO_free_all_006a7f74)(chain);
        if (psVar16 != (stack_st_X509 *)0x0) {
          (*(code *)PTR_sk_pop_free_006a8158)(psVar16,PTR_X509_free_006a7f90);
        }
        if (psVar15 != (stack_st_X509_CRL *)0x0) {
          (*(code *)PTR_sk_pop_free_006a8158)(psVar15,PTR_X509_CRL_free_006a8160);
        }
        if (!bVar1) goto LAB_005b9a90;
        iVar3 = cms_Receipt_verify(cms_00,pXVar9);
        goto LAB_005b97bc;
      }
      uVar10 = 0x8a;
      uVar7 = 0x161;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x9d,uVar10,"cms_smime.c",uVar7);
    (*(code *)PTR_BIO_free_all_006a7f74)(0);
    iVar3 = 0;
  }
LAB_005b97bc:
  while (iStack_8c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005b9a90:
    iVar3 = 0;
  }
  return iVar3;
LAB_005b94bc:
  unaff_s2 = (X509_STORE *)0x0;
  cms = (CMS_ContentInfo *)0x0;
  psVar12 = (stack_st_CMS_SignerInfo *)0x0;
joined_r0x005b95dc:
  pXVar13 = unaff_s2;
  if (dcont == (BIO *)0x0) {
LAB_005b9208:
    (*(code *)PTR_BIO_free_all_006a7f74)(cms);
    unaff_s2 = pXVar13;
  }
  else {
LAB_005b91fc:
    pXVar13 = unaff_s2;
    pXVar14 = (X509_STORE *)cms;
    if ((X509_STORE *)dcont != unaff_s2) goto LAB_005b9208;
LAB_005b92e8:
    do {
      cms = (CMS_ContentInfo *)(*(code *)PTR_BIO_pop_006a8ab4)(pXVar14);
      (*(code *)PTR_BIO_free_006a7f70)(pXVar14);
      unaff_s2 = pXVar13;
      pXVar14 = (X509_STORE *)cms;
    } while ((BIO *)cms != dcont);
  }
  if (unaff_s4 != (X509_STORE *)0x0) {
    pXVar9 = (X509_STORE *)PTR_X509_free_006a7f90;
    (*(code *)PTR_sk_pop_free_006a8158)(unaff_s4,PTR_X509_free_006a7f90);
  }
  psStack_88 = psVar12;
  if ((BIO *)certs != (BIO *)0x0) {
    pXVar9 = (X509_STORE *)PTR_X509_CRL_free_006a8160;
    (*(code *)PTR_sk_pop_free_006a8158)(certs,PTR_X509_CRL_free_006a8160);
  }
  goto LAB_005b9248;
LAB_005b9924:
  chain = (BIO *)0x0;
  goto LAB_005b9928;
}

