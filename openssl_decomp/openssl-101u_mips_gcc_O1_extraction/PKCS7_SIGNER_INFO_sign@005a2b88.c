
int PKCS7_SIGNER_INFO_sign(PKCS7_SIGNER_INFO *si)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  PKCS7_SIGNER_INFO *si_00;
  int iVar5;
  ASN1_OCTET_STRING *pAVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  PKCS7 *p7;
  char *in_a1;
  undefined4 *puVar10;
  undefined4 uVar11;
  pkcs7_st *ppVar12;
  undefined *unaff_s1;
  stack_st_X509_ATTRIBUTE *psVar13;
  undefined4 *unaff_s3;
  char *unaff_s4;
  stack_st_PKCS7_SIGNER_INFO *psStack_10c;
  undefined *puStack_108;
  ASN1_OCTET_STRING *pAStack_fc;
  int iStack_ec;
  int iStack_e8;
  undefined auStack_e4 [24];
  uchar auStack_cc [64];
  int iStack_8c;
  PKCS7_SIGNER_INFO *pPStack_88;
  undefined *puStack_84;
  undefined *puStack_80;
  undefined4 *puStack_7c;
  char *pcStack_78;
  undefined4 local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  undefined auStack_34 [24];
  PKCS7 *local_1c;
  
  puStack_80 = PTR___stack_chk_guard_006a9ae8;
  local_3c = (undefined4 *)0x0;
  local_1c = *(PKCS7 **)PTR___stack_chk_guard_006a9ae8;
  uVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(si->digest_alg->algorithm);
  uVar2 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar2);
  puVar3 = (undefined4 *)(*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar2);
  if (puVar3 == (undefined4 *)0x0) {
    iVar4 = 0;
  }
  else {
    unaff_s1 = auStack_34;
    (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(unaff_s1);
    puVar10 = &local_40;
    iVar4 = (*(code *)PTR_EVP_DigestSignInit_006a6e20)(unaff_s1,puVar10,puVar3,0);
    if (iVar4 < 1) {
LAB_005a2d98:
      in_a1 = (char *)puVar10;
      if (local_3c != (undefined4 *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
        in_a1 = (char *)puVar10;
      }
    }
    else {
      iVar4 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(local_40,0xffffffff,8,5);
      if (iVar4 < 1) {
        puVar10 = (undefined4 *)0x8b;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x8b,0x98,"pk7_doit.c");
        goto LAB_005a2d98;
      }
      uVar2 = (*(code *)PTR_ASN1_item_i2d_006a8678)
                        (si->auth_attr,&local_3c,PTR_PKCS7_ATTR_SIGN_it_006a9150);
      in_a1 = (char *)local_3c;
      if (local_3c != (undefined4 *)0x0) {
        puVar10 = local_3c;
        iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s1,local_3c,uVar2);
        if (0 < iVar4) {
          puVar3 = &local_38;
          (*(code *)PTR_CRYPTO_free_006a6e88)(local_3c);
          puVar10 = (undefined4 *)0x0;
          local_3c = (undefined4 *)0x0;
          iVar4 = (*(code *)PTR_EVP_DigestSignFinal_006a74d0)(unaff_s1,0,puVar3);
          if (0 < iVar4) {
            unaff_s4 = "encrypt";
            in_a1 = "pk7_doit.c";
            puVar10 = (undefined4 *)
                      (*(code *)PTR_CRYPTO_malloc_006a7008)(local_38,"pk7_doit.c",0x3b0);
            local_3c = puVar10;
            if (puVar10 == (undefined4 *)0x0) goto LAB_005a2db0;
            iVar4 = (*(code *)PTR_EVP_DigestSignFinal_006a74d0)(unaff_s1,puVar10,puVar3);
            if (0 < iVar4) {
              iVar4 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(local_40,0xffffffff,8,5);
              if (0 < iVar4) {
                (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(unaff_s1);
                in_a1 = (char *)local_3c;
                (*(code *)PTR_ASN1_STRING_set0_006a9144)(si->enc_digest,local_3c,local_38);
                iVar4 = 1;
                unaff_s3 = puVar3;
                goto LAB_005a2dc4;
              }
              puVar10 = (undefined4 *)0x8b;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x8b,0x98,"pk7_doit.c");
            }
          }
        }
        goto LAB_005a2d98;
      }
    }
LAB_005a2db0:
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(unaff_s1);
    iVar4 = 0;
    unaff_s3 = puVar3;
  }
LAB_005a2dc4:
  if (local_1c == *(PKCS7 **)puStack_80) {
    return iVar4;
  }
  p7 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_8c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pPStack_88 = si;
  puStack_84 = unaff_s1;
  puStack_7c = unaff_s3;
  pcStack_78 = unaff_s4;
  if (p7 == (PKCS7 *)0x0) {
    uVar11 = 0x8f;
    uVar2 = 0x2f4;
LAB_005a3610:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x80,uVar11,"pk7_doit.c",uVar2);
    iVar4 = 0;
    goto LAB_005a3034;
  }
  if ((p7->d).ptr == (char *)0x0) {
    uVar11 = 0x7a;
    uVar2 = 0x2f9;
    goto LAB_005a3610;
  }
  puStack_108 = auStack_e4;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_108);
  uVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
  p7->state = 0;
  switch(uVar2) {
  case 0x15:
    pAStack_fc = (p7->d).data;
    goto LAB_005a31ac;
  case 0x16:
    ppVar12 = ((p7->d).sign)->contents;
    psStack_10c = ((p7->d).sign)->signer_info;
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(ppVar12->type);
    if (iVar4 == 0x15) {
      pAStack_fc = (ppVar12->d).data;
    }
    else {
      iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(ppVar12->type);
      if (((iVar4 - 0x15U < 6) || (pAVar6 = (ppVar12->d).data, pAVar6 == (ASN1_OCTET_STRING *)0x0))
         || (pAVar6->length != 4)) {
        pAStack_fc = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        pAStack_fc = (ASN1_OCTET_STRING *)pAVar6->type;
      }
    }
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(((p7->d).sign)->contents->type);
    if ((iVar4 == 0x15) && (p7->detached != 0)) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(pAStack_fc);
      pAStack_fc = (ASN1_OCTET_STRING *)0x0;
      (((p7->d).sign)->contents->d).ptr = (char *)0x0;
    }
    break;
  case 0x17:
    pAStack_fc = (ASN1_OCTET_STRING *)(((p7->d).sign)->cert->stack).sorted;
    if (pAStack_fc == (ASN1_OCTET_STRING *)0x0) {
      pAStack_fc = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(4);
      if (pAStack_fc == (ASN1_OCTET_STRING *)0x0) goto LAB_005a37a4;
      (((p7->d).sign)->cert->stack).sorted = (int)pAStack_fc;
    }
    goto LAB_005a31ac;
  case 0x18:
    psStack_10c = ((p7->d).sign)->signer_info;
    pAStack_fc = (ASN1_OCTET_STRING *)((p7->d).sign)->contents->state;
    if (pAStack_fc == (ASN1_OCTET_STRING *)0x0) {
      pAStack_fc = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(4);
      if (pAStack_fc == (ASN1_OCTET_STRING *)0x0) {
        uVar11 = 0x41;
        uVar2 = 0x30c;
        goto LAB_005a35e8;
      }
      ((p7->d).sign)->contents->state = (int)pAStack_fc;
    }
    break;
  case 0x19:
    ppVar12 = ((p7->d).digest)->contents;
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(ppVar12->type);
    if (iVar4 == 0x15) {
      pAStack_fc = (ppVar12->d).data;
    }
    else {
      iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(ppVar12->type);
      if (((iVar4 - 0x15U < 6) || (pAVar6 = (ppVar12->d).data, pAVar6 == (ASN1_OCTET_STRING *)0x0))
         || (pAVar6->length != 4)) {
        pAStack_fc = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        pAStack_fc = (ASN1_OCTET_STRING *)pAVar6->type;
      }
    }
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)((((p7->d).sign)->cert->stack).comp);
    if ((iVar4 == 0x15) && (p7->detached != 0)) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(pAStack_fc);
      pAStack_fc = (ASN1_OCTET_STRING *)0x0;
      (((p7->d).digest)->contents->d).ptr = (char *)0x0;
    }
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)((((p7->d).sign)->md_algs->stack).num);
    puVar3 = (undefined4 *)in_a1;
    while (iVar8 = (*(code *)PTR_BIO_find_type_006a8320)(puVar3,0x208), iVar8 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar8,0x78,0,&iStack_ec);
      if (iStack_ec == 0) goto LAB_005a3510;
      uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
      iVar7 = (*(code *)PTR_EVP_MD_type_006a73cc)(uVar2);
      if (iVar4 == iVar7) {
        iVar4 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(iStack_ec,auStack_cc,&iStack_e8);
        if (iVar4 == 0) goto LAB_005a301c;
        (*(code *)PTR_ASN1_STRING_set_006a7d1c)(((p7->d).data)->flags,auStack_cc,iStack_e8);
        goto LAB_005a31ac;
      }
      puVar3 = (undefined4 *)(*(code *)PTR_BIO_next_006a9154)(iVar8);
    }
LAB_005a2ff8:
    uVar11 = 0x6c;
    uVar2 = 699;
LAB_005a3008:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x7f,uVar11,"pk7_doit.c",uVar2);
    goto LAB_005a301c;
  default:
    uVar11 = 0x70;
    uVar2 = 0x334;
    goto LAB_005a35e8;
  }
  if (psStack_10c != (stack_st_PKCS7_SIGNER_INFO *)0x0) {
    iVar4 = 0;
    while (iVar8 = (*(code *)PTR_sk_num_006a6e2c)(psStack_10c), iVar4 < iVar8) {
      si_00 = (PKCS7_SIGNER_INFO *)(*(code *)PTR_sk_value_006a6e24)(psStack_10c,iVar4);
      if (si_00->pkey == (EVP_PKEY *)0x0) {
LAB_005a33fc:
        iVar4 = iVar4 + 1;
      }
      else {
        iVar8 = (*(code *)PTR_OBJ_obj2nid_006a712c)(si_00->digest_alg->algorithm);
        puVar3 = (undefined4 *)in_a1;
        while( true ) {
          iVar7 = (*(code *)PTR_BIO_find_type_006a8320)(puVar3,0x208);
          if (iVar7 == 0) goto LAB_005a2ff8;
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar7,0x78,0,&iStack_ec);
          if (iStack_ec == 0) goto LAB_005a3510;
          uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
          iVar5 = (*(code *)PTR_EVP_MD_type_006a73cc)(uVar2);
          if (iVar8 == iVar5) break;
          puVar3 = (undefined4 *)(*(code *)PTR_BIO_next_006a9154)(iVar7);
        }
        iVar8 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a8104)(puStack_108,iStack_ec);
        if (iVar8 == 0) goto LAB_005a301c;
        iVar8 = (*(code *)PTR_sk_num_006a6e2c)(si_00->auth_attr);
        if (iVar8 < 1) {
          iStack_e8 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(si_00->pkey);
          iVar8 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iStack_e8,"pk7_doit.c",0x35a);
          if (iVar8 == 0) goto LAB_005a301c;
          iVar7 = (*(code *)PTR_EVP_SignFinal_006a7f70)(puStack_108,iVar8,&iStack_e8,si_00->pkey);
          if (iVar7 == 0) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x80,6,"pk7_doit.c",0x35f);
            goto LAB_005a301c;
          }
          (*(code *)PTR_ASN1_STRING_set0_006a9144)(si_00->enc_digest,iVar8,iStack_e8);
          goto LAB_005a33fc;
        }
        psVar13 = si_00->auth_attr;
        iVar8 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x34);
        if ((iVar8 != 0) && (psVar13 != (stack_st_X509_ATTRIBUTE *)0x0)) {
          for (iVar7 = 0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(psVar13), iVar7 < iVar5;
              iVar7 = iVar7 + 1) {
            puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(psVar13,iVar7);
            iVar5 = (*(code *)PTR_OBJ_cmp_006a8cc4)(*puVar3,iVar8);
            if (iVar5 == 0) {
              if (((puVar3[1] == 0) &&
                  (iVar8 = (*(code *)PTR_sk_num_006a6e2c)(puVar3[2]), iVar8 != 0)) &&
                 (iVar8 = (*(code *)PTR_sk_value_006a6e24)(puVar3[2],0), iVar8 != 0)) {
                iVar8 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)
                                  (puStack_108,auStack_cc,&iStack_e8);
                goto joined_r0x005a3570;
              }
              break;
            }
          }
        }
        iVar8 = PKCS7_add0_attrib_signing_time(si_00,(ASN1_TIME *)0x0);
        if (iVar8 == 0) {
          uVar11 = 0x41;
          uVar2 = 0x2d2;
LAB_005a358c:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x88,uVar11,"pk7_doit.c",uVar2);
          goto LAB_005a301c;
        }
        iVar8 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(puStack_108,auStack_cc,&iStack_e8);
joined_r0x005a3570:
        if (iVar8 == 0) {
          uVar11 = 6;
          uVar2 = 0x2d9;
          goto LAB_005a358c;
        }
        iVar8 = PKCS7_add1_attrib_digest(si_00,auStack_cc,iStack_e8);
        if (iVar8 == 0) {
          uVar11 = 0x41;
          uVar2 = 0x2dd;
          goto LAB_005a358c;
        }
        iVar8 = PKCS7_SIGNER_INFO_sign(si_00);
        if (iVar8 == 0) goto LAB_005a301c;
        iVar4 = iVar4 + 1;
      }
    }
  }
LAB_005a31ac:
  iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
  if ((iVar4 == 0x16) && (lVar9 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar9 != 0)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
    if (pAStack_fc != (ASN1_OCTET_STRING *)0x0) {
      if ((pAStack_fc->flags & 0x10U) == 0) {
        iVar4 = (*(code *)PTR_BIO_find_type_006a8320)(in_a1,0x401);
        if (iVar4 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x80,0x6b,"pk7_doit.c",0x37c);
        }
        else {
          uVar2 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar4,3,0,&iStack_e8);
          (*(code *)PTR_BIO_set_flags_006a7570)(iVar4,0x200);
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar4,0x82,0,0);
          (*(code *)PTR_ASN1_STRING_set0_006a9144)(pAStack_fc,iStack_e8,uVar2);
          iVar4 = 1;
        }
      }
      else {
        iVar4 = 1;
      }
    }
  }
  while( true ) {
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(puStack_108);
LAB_005a3034:
    if (iStack_8c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005a37a4:
    uVar11 = 0x41;
    uVar2 = 0x318;
LAB_005a35e8:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x80,uVar11,"pk7_doit.c",uVar2);
LAB_005a301c:
    iVar4 = 0;
  }
  return iVar4;
LAB_005a3510:
  uVar11 = 0x44;
  uVar2 = 0x2c0;
  goto LAB_005a3008;
}

