
BIO * PKCS7_dataDecode(PKCS7 *p7,EVP_PKEY *pkey,BIO *in_bio,X509 *pcert)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  BIO *pBVar4;
  PKCS7_SIGN_ENVELOPE *pPVar5;
  undefined4 *puVar6;
  PKCS7_ENC_CONTENT *pPVar7;
  long lVar8;
  ASN1_OCTET_STRING *pAVar9;
  char **ppcVar10;
  undefined4 uVar11;
  BIO *pBVar12;
  BIO *pBVar13;
  int iVar14;
  BIO *pBVar15;
  pkcs7_st *ppVar16;
  stack_st_X509_ALGOR *unaff_s3;
  stack_st_X509_ALGOR *psVar17;
  char **ppcVar18;
  stack_st_PKCS7_RECIP_INFO *unaff_s5;
  X509 *unaff_s6;
  EVP_PKEY *unaff_s8;
  ASN1_OCTET_STRING *local_48;
  BIO *local_44;
  int local_40;
  X509_ALGOR *local_3c;
  undefined4 local_38;
  stack_st_X509_ALGOR *local_34;
  char **local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_38 = 0;
  local_34 = (stack_st_X509_ALGOR *)0x0;
  local_30 = (char **)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_44 = in_bio;
  if (p7 == (PKCS7 *)0x0) {
    uVar11 = 0x8f;
    uVar3 = 0x1b2;
LAB_005a24b8:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x70,uVar11,"pk7_doit.c",uVar3);
    pcert = unaff_s6;
    pkey = unaff_s8;
    goto LAB_005a24cc;
  }
  if ((p7->d).ptr == (char *)0x0) {
    uVar11 = 0x7a;
    uVar3 = 0x1b7;
    goto LAB_005a24b8;
  }
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
  p7->state = 0;
  if (iVar2 == 0x17) {
    pPVar7 = ((p7->d).enveloped)->enc_data;
    unaff_s5 = ((p7->d).enveloped)->recipientinfo;
    local_3c = pPVar7->algorithm;
    local_48 = pPVar7->enc_data;
    uVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(local_3c->algorithm);
    uVar3 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar3);
    local_40 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar3);
    if (local_40 == 0) {
      uVar11 = 0x6f;
      uVar3 = 0x1e3;
      goto LAB_005a2220;
    }
    if ((local_48 == (ASN1_OCTET_STRING *)0x0) && (in_bio == (BIO *)0x0)) goto LAB_005a2540;
    pBVar15 = (BIO *)0x0;
    goto LAB_005a25d4;
  }
  if (iVar2 == 0x18) {
    pPVar5 = (p7->d).signed_and_enveloped;
    unaff_s5 = pPVar5->recipientinfo;
    unaff_s3 = pPVar5->md_algs;
    local_3c = pPVar5->enc_data->algorithm;
    local_48 = pPVar5->enc_data->enc_data;
    uVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(local_3c->algorithm);
    uVar3 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar3);
    local_40 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar3);
    if (local_40 == 0) {
      uVar11 = 0x6f;
      uVar3 = 0x1d7;
      goto LAB_005a2220;
    }
    goto LAB_005a2370;
  }
  if (iVar2 != 0x16) {
    uVar11 = 0x70;
    uVar3 = 0x1e8;
    goto LAB_005a2220;
  }
  ppVar16 = ((p7->d).sign)->contents;
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(ppVar16->type);
  if (iVar2 == 0x15) {
    local_48 = (ASN1_OCTET_STRING *)(ppVar16->d).ptr;
LAB_005a2840:
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
    if (iVar2 != 0x16) {
LAB_005a2858:
      if (local_48 == (ASN1_OCTET_STRING *)0x0) {
LAB_005a2a58:
        uVar11 = 0x9b;
        uVar3 = 0x1c9;
        goto LAB_005a2220;
      }
      goto LAB_005a2864;
    }
LAB_005a25a4:
    lVar8 = PKCS7_ctrl(p7,2,0,(char *)0x0);
    if (lVar8 == 0) goto LAB_005a2858;
    pAVar9 = (p7->d).data;
  }
  else {
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(ppVar16->type);
    if (iVar2 - 0x15U < 6) {
      iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
      if (iVar2 != 0x16) goto LAB_005a2a58;
      local_48 = (ASN1_OCTET_STRING *)0x0;
      goto LAB_005a25a4;
    }
    pAVar9 = (ppVar16->d).data;
    if ((pAVar9 != (ASN1_OCTET_STRING *)0x0) && (pAVar9->length == 4)) {
      local_48 = (ASN1_OCTET_STRING *)pAVar9->type;
      goto LAB_005a2840;
    }
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
    if ((iVar2 != 0x16) || (lVar8 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar8 == 0)) goto LAB_005a2a58;
    local_48 = (ASN1_OCTET_STRING *)0x0;
LAB_005a2864:
    pAVar9 = (p7->d).data;
  }
  unaff_s5 = (stack_st_PKCS7_RECIP_INFO *)0x0;
  local_3c = (X509_ALGOR *)0x0;
  local_40 = 0;
  unaff_s3 = (stack_st_X509_ALGOR *)pAVar9->type;
LAB_005a2370:
  if (local_48 == (ASN1_OCTET_STRING *)0x0) goto LAB_005a2b78;
LAB_005a237c:
  pBVar12 = (BIO *)0x0;
  if (unaff_s3 != (stack_st_X509_ALGOR *)0x0) {
    iVar14 = 0;
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s3);
    pBVar15 = pBVar12;
    if (0 < iVar2) {
      do {
        puVar6 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(unaff_s3,iVar14);
        uVar3 = (*(code *)PTR_BIO_f_md_006a74d8)();
        pBVar12 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar3);
        if (pBVar12 == (BIO *)0x0) {
          pBVar13 = (BIO *)0x0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x70,0x20,"pk7_doit.c",0x1f7);
          ppcVar18 = (char **)0x0;
          goto LAB_005a28e4;
        }
        uVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar6);
        uVar3 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar3);
        iVar2 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar3);
        if (iVar2 == 0) {
          ppcVar18 = (char **)0x0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x70,0x6d,"pk7_doit.c",0x1ff);
          pBVar13 = (BIO *)0x0;
          goto LAB_005a28e4;
        }
        (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar12,0x6f,0,iVar2);
        if (pBVar15 != (BIO *)0x0) {
          (*(code *)PTR_BIO_push_006a74c4)(pBVar15,pBVar12);
          pBVar12 = pBVar15;
        }
        iVar14 = iVar14 + 1;
        iVar2 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s3);
        pBVar15 = pBVar12;
      } while (iVar14 < iVar2);
    }
  }
  pBVar15 = pBVar12;
  if (local_40 == 0) {
    ppcVar18 = (char **)0x0;
    pBVar4 = pBVar12;
LAB_005a2470:
    if (local_44 != (BIO *)0x0) {
LAB_005a247c:
      (*(code *)PTR_BIO_push_006a74c4)(pBVar4,local_44);
      goto LAB_005a22dc;
    }
    if (local_48->length < 1) {
      uVar3 = (*(code *)PTR_BIO_s_mem_006a7c18)();
      local_44 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar3);
      if (local_44 != (BIO *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a6e18)(local_44,0x82,0,0);
        goto LAB_005a247c;
      }
    }
    else {
      local_44 = (BIO *)(*(code *)PTR_BIO_new_mem_buf_006a9148)(local_48->data);
      if (local_44 != (BIO *)0x0) goto LAB_005a247c;
    }
    pBVar13 = (BIO *)0x0;
    pBVar12 = (BIO *)0x0;
    pBVar15 = pBVar4;
  }
  else {
LAB_005a25d4:
    uVar3 = (*(code *)PTR_BIO_f_cipher_006a7558)();
    pBVar13 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar3);
    if (pBVar13 == (BIO *)0x0) {
      pBVar12 = (BIO *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x70,0x20,"pk7_doit.c",0x217);
      ppcVar18 = (char **)0x0;
      goto LAB_005a28e4;
    }
    iVar2 = 0;
    if (pcert != (X509 *)0x0) {
      for (; iVar14 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s5), iVar2 < iVar14; iVar2 = iVar2 + 1) {
        unaff_s3 = (stack_st_X509_ALGOR *)(*(code *)PTR_sk_value_006a6e24)(unaff_s5,iVar2);
        iVar14 = (*(code *)PTR_X509_NAME_cmp_006a8030)
                           (*(unaff_s3->stack).data,pcert->cert_info->issuer);
        if ((iVar14 == 0) &&
           (iVar14 = (*(code *)PTR_ASN1_STRING_cmp_006a7148)
                               (pcert->cert_info->serialNumber,(unaff_s3->stack).data[1]),
           iVar14 == 0)) {
          iVar2 = pkcs7_decrypt_rinfo(&local_34,&local_30,unaff_s3,pkey);
          if (iVar2 < 0) goto LAB_005a28dc;
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
          goto LAB_005a26a4;
        }
      }
      ppcVar18 = (char **)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x70,0x73,"pk7_doit.c",0x22e);
      pBVar12 = (BIO *)0x0;
      goto LAB_005a28e4;
    }
    unaff_s3 = (stack_st_X509_ALGOR *)&local_34;
    for (; iVar14 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s5), iVar2 < iVar14; iVar2 = iVar2 + 1) {
      uVar3 = (*(code *)PTR_sk_value_006a6e24)(unaff_s5,iVar2);
      iVar14 = pkcs7_decrypt_rinfo(unaff_s3,&local_30,uVar3,pkey);
      if (iVar14 < 0) goto LAB_005a28dc;
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
LAB_005a26a4:
    local_38 = 0;
    (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar13,0x81,0,&local_38);
    iVar2 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)(local_38,local_40,0,0,0,0);
    if ((iVar2 < 1) ||
       (iVar2 = (*(code *)PTR_EVP_CIPHER_asn1_to_param_006a8c8c)(local_38,local_3c->parameter),
       iVar2 < 0)) {
LAB_005a28dc:
      ppcVar18 = (char **)0x0;
    }
    else {
      ppcVar18 = (char **)(*(code *)PTR_EVP_CIPHER_CTX_key_length_006a8a00)(local_38);
      unaff_s3 = (stack_st_X509_ALGOR *)
                 (*(code *)PTR_CRYPTO_malloc_006a7008)(ppcVar18,"pk7_doit.c",0x24f);
      if (unaff_s3 != (stack_st_X509_ALGOR *)0x0) {
        iVar2 = (*(code *)PTR_EVP_CIPHER_CTX_rand_key_006a9140)(local_38,unaff_s3);
        if (iVar2 < 1) {
          pBVar12 = (BIO *)0x0;
          if (local_34 == (stack_st_X509_ALGOR *)0x0) goto LAB_005a2278;
          goto LAB_005a2254;
        }
        psVar17 = unaff_s3;
        if (local_34 == (stack_st_X509_ALGOR *)0x0) {
          psVar17 = (stack_st_X509_ALGOR *)0x0;
          local_34 = unaff_s3;
          local_30 = ppcVar18;
        }
        ppcVar10 = (char **)(*(code *)PTR_EVP_CIPHER_CTX_key_length_006a8a00)(local_38);
        unaff_s3 = psVar17;
        if ((ppcVar10 != local_30) &&
           (iVar2 = (*(code *)PTR_EVP_CIPHER_CTX_set_key_length_006a8a8c)(local_38), iVar2 == 0)) {
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_34,local_30);
          (*(code *)PTR_CRYPTO_free_006a6e88)(local_34);
          unaff_s3 = (stack_st_X509_ALGOR *)0x0;
          local_34 = psVar17;
          local_30 = ppcVar18;
        }
        (*(code *)PTR_ERR_clear_error_006a6ee0)();
        iVar2 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)(local_38,0,0,local_34,0,0);
        if (iVar2 < 1) {
          pBVar12 = (BIO *)0x0;
          if (local_34 != (stack_st_X509_ALGOR *)0x0) goto LAB_005a2254;
          goto LAB_005a2270;
        }
        if (local_34 != (stack_st_X509_ALGOR *)0x0) {
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_34,local_30);
          (*(code *)PTR_CRYPTO_free_006a6e88)(local_34);
          local_34 = (stack_st_X509_ALGOR *)0x0;
        }
        if (unaff_s3 != (stack_st_X509_ALGOR *)0x0) {
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(unaff_s3,ppcVar18);
          (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s3);
        }
        pBVar4 = pBVar13;
        if (pBVar15 != (BIO *)0x0) {
          (*(code *)PTR_BIO_push_006a74c4)(pBVar15,pBVar13);
          pBVar4 = pBVar15;
        }
        goto LAB_005a2470;
      }
    }
    pBVar12 = (BIO *)0x0;
  }
LAB_005a28e4:
  if (local_34 != (stack_st_X509_ALGOR *)0x0) {
    unaff_s3 = (stack_st_X509_ALGOR *)0x0;
    goto LAB_005a2254;
  }
  do {
    if (pBVar15 != (BIO *)0x0) {
      (*(code *)PTR_BIO_free_all_006a6e74)(pBVar15);
    }
    if (pBVar12 != (BIO *)0x0) {
      (*(code *)PTR_BIO_free_all_006a6e74)(pBVar12);
    }
    if (pBVar13 == (BIO *)0x0) goto LAB_005a24cc;
    (*(code *)PTR_BIO_free_all_006a6e74)(pBVar13);
    pBVar4 = (BIO *)0x0;
LAB_005a22dc:
    while( true ) {
      if (local_2c == *(int *)puVar1) {
        return pBVar4;
      }
      in_bio = (BIO *)(*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005a2b78:
      if (in_bio != (BIO *)0x0) goto LAB_005a237c;
LAB_005a2540:
      uVar11 = 0x7a;
      uVar3 = 0x1ee;
LAB_005a2220:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x70,uVar11,"pk7_doit.c",uVar3);
      if (local_34 != (stack_st_X509_ALGOR *)0x0) break;
LAB_005a24cc:
      pBVar4 = (BIO *)0x0;
    }
    ppcVar18 = (char **)0x0;
    unaff_s3 = (stack_st_X509_ALGOR *)0x0;
    pBVar13 = (BIO *)0x0;
    pBVar12 = (BIO *)0x0;
    pBVar15 = (BIO *)0x0;
LAB_005a2254:
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_34,local_30);
    (*(code *)PTR_CRYPTO_free_006a6e88)(local_34);
LAB_005a2270:
    if (unaff_s3 != (stack_st_X509_ALGOR *)0x0) {
LAB_005a2278:
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(unaff_s3,ppcVar18);
      (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s3);
    }
  } while( true );
}

