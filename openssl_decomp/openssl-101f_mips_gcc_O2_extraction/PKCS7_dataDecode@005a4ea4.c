
BIO * PKCS7_dataDecode(PKCS7 *p7,EVP_PKEY *pkey,BIO *in_bio,X509 *pcert)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  ASN1_OCTET_STRING *pAVar4;
  PKCS7_SIGN_ENVELOPE *pPVar5;
  undefined4 *puVar6;
  PKCS7_ENC_CONTENT *pPVar7;
  int iVar8;
  long lVar9;
  undefined4 uVar10;
  BIO *pBVar11;
  pkcs7_st *ppVar12;
  BIO *pBVar13;
  int iVar14;
  BIO *pBVar15;
  BIO *pBVar16;
  stack_st_X509_ALGOR *psVar17;
  int unaff_s4;
  stack_st_PKCS7_RECIP_INFO *psVar18;
  BIO *local_48;
  int local_44;
  ASN1_OCTET_STRING *local_40;
  X509_ALGOR *local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
  p7->state = 0;
  local_48 = in_bio;
  if (iVar2 == 0x17) {
    pBVar16 = (BIO *)0x0;
    pPVar7 = ((p7->d).enveloped)->enc_data;
    psVar18 = ((p7->d).enveloped)->recipientinfo;
    local_3c = pPVar7->algorithm;
    local_40 = pPVar7->enc_data;
    uVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(local_3c->algorithm);
    uVar3 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar3);
    local_44 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar3);
    if (local_44 == 0) {
      uVar10 = 0x6f;
      uVar3 = 0x1d0;
      goto LAB_005a4f48;
    }
  }
  else {
    if (iVar2 == 0x18) {
      pPVar5 = (p7->d).signed_and_enveloped;
      psVar18 = pPVar5->recipientinfo;
      psVar17 = pPVar5->md_algs;
      local_3c = pPVar5->enc_data->algorithm;
      local_40 = pPVar5->enc_data->enc_data;
      uVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(local_3c->algorithm);
      uVar3 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar3);
      local_44 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar3);
      if (local_44 == 0) {
        uVar10 = 0x6f;
        uVar3 = 0x1c5;
        goto LAB_005a4f48;
      }
      if (psVar17 == (stack_st_X509_ALGOR *)0x0) {
        pBVar16 = (BIO *)0x0;
        goto LAB_005a51cc;
      }
    }
    else {
      if (iVar2 != 0x16) {
        uVar10 = 0x70;
        uVar3 = 0x1d5;
LAB_005a4f48:
        (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x70,uVar10,"pk7_doit.c",uVar3);
        if (local_34 == 0) {
          pBVar15 = (BIO *)0x0;
          goto LAB_005a52e0;
        }
        unaff_s4 = 0;
        iVar2 = 0;
        pBVar13 = (BIO *)0x0;
        pBVar11 = (BIO *)0x0;
        pBVar16 = (BIO *)0x0;
        goto LAB_005a5540;
      }
      ppVar12 = ((p7->d).sign)->contents;
      iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ppVar12->type);
      if (iVar2 == 0x15) {
        local_40 = (ppVar12->d).data;
      }
      else {
        iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ppVar12->type);
        if (((iVar2 - 0x15U < 6) || (pAVar4 = (ppVar12->d).data, pAVar4 == (ASN1_OCTET_STRING *)0x0)
            ) || (pAVar4->length != 4)) {
          local_40 = (ASN1_OCTET_STRING *)0x0;
        }
        else {
          local_40 = (ASN1_OCTET_STRING *)pAVar4->type;
        }
      }
      psVar17 = (stack_st_X509_ALGOR *)((p7->d).data)->type;
      unaff_s4 = 0;
      if (psVar17 == (stack_st_X509_ALGOR *)0x0) goto LAB_005a57e4;
      psVar18 = (stack_st_PKCS7_RECIP_INFO *)0x0;
      local_3c = (X509_ALGOR *)0x0;
      local_44 = 0;
    }
    iVar14 = 0;
    pBVar16 = (BIO *)0x0;
    iVar2 = (*(code *)PTR_sk_num_006a7f2c)(psVar17);
    pBVar15 = pBVar16;
    if (0 < iVar2) {
      do {
        puVar6 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(psVar17,iVar14);
        uVar3 = (*(code *)PTR_BIO_f_md_006a85d4)();
        pBVar16 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar3);
        pBVar11 = pBVar16;
        if (pBVar16 == (BIO *)0x0) {
          pBVar13 = (BIO *)0x0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x70,0x20,"pk7_doit.c",0x1e1);
          unaff_s4 = 0;
          pBVar16 = pBVar15;
          goto joined_r0x005a5298;
        }
        uVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar6);
        uVar3 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar3);
        iVar2 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar3);
        if (iVar2 == 0) {
          unaff_s4 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x70,0x6d,"pk7_doit.c",0x1e9);
          pBVar13 = (BIO *)0x0;
          pBVar16 = pBVar15;
          goto joined_r0x005a5298;
        }
        (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar16,0x6f,0,iVar2);
        if (pBVar15 != (BIO *)0x0) {
          (*(code *)PTR_BIO_push_006a85c0)(pBVar15,pBVar16);
          pBVar16 = pBVar15;
        }
        iVar14 = iVar14 + 1;
        iVar2 = (*(code *)PTR_sk_num_006a7f2c)(psVar17);
        pBVar15 = pBVar16;
      } while (iVar14 < iVar2);
    }
    unaff_s4 = 0;
    pBVar15 = pBVar16;
    if (local_44 == 0) goto LAB_005a5128;
  }
LAB_005a51cc:
  uVar3 = (*(code *)PTR_BIO_f_cipher_006a8648)();
  pBVar13 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar3);
  if (pBVar13 == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x70,0x20,"pk7_doit.c",0x203);
    unaff_s4 = 0;
    pBVar11 = (BIO *)0x0;
  }
  else {
    iVar2 = 0;
    if (pcert == (X509 *)0x0) {
      for (; iVar14 = (*(code *)PTR_sk_num_006a7f2c)(psVar18), iVar2 < iVar14; iVar2 = iVar2 + 1) {
        uVar3 = (*(code *)PTR_sk_value_006a7f24)(psVar18,iVar2);
        iVar14 = pkcs7_decrypt_rinfo(&local_34,&local_30,uVar3,pkey);
        if (iVar14 < 0) goto LAB_005a5624;
        (*(code *)PTR_ERR_clear_error_006a7fe0)();
      }
LAB_005a536c:
      local_38 = 0;
      (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar13,0x81,0,&local_38);
      iVar2 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)(local_38,local_44,0,0,0,0);
      if ((iVar2 < 1) ||
         (iVar2 = (*(code *)PTR_EVP_CIPHER_asn1_to_param_006a9dac)(local_38,local_3c->parameter),
         iVar2 < 0)) {
LAB_005a5624:
        unaff_s4 = 0;
      }
      else {
        unaff_s4 = (*(code *)PTR_EVP_CIPHER_CTX_key_length_006a90b8)(local_38);
        iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(unaff_s4,"pk7_doit.c",0x240);
        if (iVar2 != 0) {
          iVar14 = (*(code *)PTR_EVP_CIPHER_CTX_rand_key_006aa25c)(local_38,iVar2);
          if (iVar14 < 1) {
            pBVar11 = (BIO *)0x0;
            if (local_34 != 0) goto LAB_005a5540;
            goto LAB_005a5568;
          }
          iVar14 = iVar2;
          if (local_34 == 0) {
            iVar14 = 0;
            local_34 = iVar2;
            local_30 = unaff_s4;
          }
          iVar8 = (*(code *)PTR_EVP_CIPHER_CTX_key_length_006a90b8)(local_38);
          iVar2 = iVar14;
          if ((iVar8 != local_30) &&
             (iVar8 = (*(code *)PTR_EVP_CIPHER_CTX_set_key_length_006a9ba8)(local_38), iVar8 == 0))
          {
            (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_34,local_30);
            (*(code *)PTR_CRYPTO_free_006a7f88)(local_34);
            iVar2 = 0;
            local_34 = iVar14;
            local_30 = unaff_s4;
          }
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
          iVar14 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)(local_38,0,0,local_34,0,0);
          if (0 < iVar14) {
            if (local_34 != 0) {
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_34,local_30);
              (*(code *)PTR_CRYPTO_free_006a7f88)(local_34);
              local_34 = 0;
            }
            if (iVar2 != 0) {
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar2,unaff_s4);
              (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
            }
            pBVar15 = pBVar13;
            if (pBVar16 == (BIO *)0x0) goto LAB_005a5128;
            (*(code *)PTR_BIO_push_006a85c0)(pBVar16,pBVar13);
            pBVar15 = pBVar16;
            goto LAB_005a5128;
          }
          pBVar11 = (BIO *)0x0;
          if (local_34 != 0) goto LAB_005a5540;
          goto LAB_005a5560;
        }
      }
      pBVar11 = (BIO *)0x0;
    }
    else {
      iVar14 = (*(code *)PTR_sk_num_006a7f2c)(psVar18);
      if (0 < iVar14) {
        do {
          iVar14 = (*(code *)PTR_sk_value_006a7f24)(psVar18,iVar2);
          iVar8 = (*(code *)PTR_X509_NAME_cmp_006a918c)
                            (**(undefined4 **)(iVar14 + 4),pcert->cert_info->issuer);
          if ((iVar8 == 0) &&
             (iVar8 = (*(code *)PTR_ASN1_STRING_cmp_006a8248)
                                (pcert->cert_info->serialNumber,
                                 *(undefined4 *)(*(int *)(iVar14 + 4) + 4)), iVar8 == 0)) {
            iVar2 = pkcs7_decrypt_rinfo(&local_34,&local_30,iVar14,pkey);
            if (iVar2 < 0) goto LAB_005a5624;
            (*(code *)PTR_ERR_clear_error_006a7fe0)();
            goto LAB_005a536c;
          }
          iVar2 = iVar2 + 1;
          iVar14 = (*(code *)PTR_sk_num_006a7f2c)(psVar18);
        } while (iVar2 < iVar14);
      }
      unaff_s4 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x70,0x73,"pk7_doit.c",0x21a);
      pBVar11 = (BIO *)0x0;
    }
  }
joined_r0x005a5298:
  if (local_34 != 0) {
    iVar2 = 0;
LAB_005a5540:
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_34,local_30);
    (*(code *)PTR_CRYPTO_free_006a7f88)(local_34);
LAB_005a5560:
    if (iVar2 != 0) {
LAB_005a5568:
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar2,unaff_s4);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
    }
  }
  if (pBVar16 != (BIO *)0x0) {
    (*(code *)PTR_BIO_free_all_006a7f74)(pBVar16);
  }
  if (pBVar11 != (BIO *)0x0) {
    (*(code *)PTR_BIO_free_all_006a7f74)(pBVar11);
  }
  pBVar15 = pBVar13;
  if (pBVar13 != (BIO *)0x0) {
    pBVar15 = (BIO *)0x0;
    (*(code *)PTR_BIO_free_all_006a7f74)(pBVar13);
  }
LAB_005a52e0:
  do {
    if (local_2c == *(int *)puVar1) {
      return pBVar15;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005a57e4:
    pBVar15 = (BIO *)0x0;
LAB_005a5128:
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
    if (((iVar2 != 0x16) || (lVar9 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar9 == 0)) &&
       (local_48 == (BIO *)0x0)) {
      if (local_40->length < 1) {
        uVar3 = (*(code *)PTR_BIO_s_mem_006a8d04)();
        local_48 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar3);
        (*(code *)PTR_BIO_ctrl_006a7f18)(local_48,0x82,0,0);
      }
      else {
        local_48 = (BIO *)(*(code *)PTR_BIO_new_mem_buf_006aa264)(local_40->data);
      }
      if (local_48 == (BIO *)0x0) break;
    }
    (*(code *)PTR_BIO_push_006a85c0)(pBVar15,local_48);
  } while( true );
  pBVar13 = (BIO *)0x0;
  pBVar11 = (BIO *)0x0;
  pBVar16 = pBVar15;
  goto joined_r0x005a5298;
}

