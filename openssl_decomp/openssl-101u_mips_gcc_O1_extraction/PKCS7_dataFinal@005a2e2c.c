
int PKCS7_dataFinal(PKCS7 *p7,BIO *bio)

{
  undefined *puVar1;
  undefined4 uVar2;
  PKCS7_SIGNER_INFO *si;
  int iVar3;
  ASN1_OCTET_STRING *pAVar4;
  int iVar5;
  BIO *pBVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  long lVar10;
  undefined4 uVar11;
  pkcs7_st *ppVar12;
  stack_st_X509_ATTRIBUTE *psVar13;
  stack_st_PKCS7_SIGNER_INFO *local_ac;
  undefined *local_a8;
  ASN1_OCTET_STRING *local_9c;
  int local_8c;
  int local_88;
  undefined auStack_84 [24];
  uchar auStack_6c [64];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (p7 == (PKCS7 *)0x0) {
    uVar11 = 0x8f;
    uVar2 = 0x2f4;
LAB_005a3610:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x80,uVar11,"pk7_doit.c",uVar2);
    iVar9 = 0;
    goto LAB_005a3034;
  }
  if ((p7->d).ptr == (char *)0x0) {
    uVar11 = 0x7a;
    uVar2 = 0x2f9;
    goto LAB_005a3610;
  }
  local_a8 = auStack_84;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(local_a8);
  uVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
  p7->state = 0;
  switch(uVar2) {
  case 0x15:
    local_9c = (p7->d).data;
    goto LAB_005a31ac;
  case 0x16:
    ppVar12 = ((p7->d).sign)->contents;
    local_ac = ((p7->d).sign)->signer_info;
    iVar9 = (*(code *)PTR_OBJ_obj2nid_006a712c)(ppVar12->type);
    if (iVar9 == 0x15) {
      local_9c = (ppVar12->d).data;
    }
    else {
      iVar9 = (*(code *)PTR_OBJ_obj2nid_006a712c)(ppVar12->type);
      if (((iVar9 - 0x15U < 6) || (pAVar4 = (ppVar12->d).data, pAVar4 == (ASN1_OCTET_STRING *)0x0))
         || (pAVar4->length != 4)) {
        local_9c = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        local_9c = (ASN1_OCTET_STRING *)pAVar4->type;
      }
    }
    iVar9 = (*(code *)PTR_OBJ_obj2nid_006a712c)(((p7->d).sign)->contents->type);
    if ((iVar9 == 0x15) && (p7->detached != 0)) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(local_9c);
      local_9c = (ASN1_OCTET_STRING *)0x0;
      (((p7->d).sign)->contents->d).ptr = (char *)0x0;
    }
    break;
  case 0x17:
    local_9c = (ASN1_OCTET_STRING *)(((p7->d).sign)->cert->stack).sorted;
    if (local_9c == (ASN1_OCTET_STRING *)0x0) {
      local_9c = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(4);
      if (local_9c == (ASN1_OCTET_STRING *)0x0) goto LAB_005a37a4;
      (((p7->d).sign)->cert->stack).sorted = (int)local_9c;
    }
    goto LAB_005a31ac;
  case 0x18:
    local_ac = ((p7->d).sign)->signer_info;
    local_9c = (ASN1_OCTET_STRING *)((p7->d).sign)->contents->state;
    if (local_9c == (ASN1_OCTET_STRING *)0x0) {
      local_9c = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(4);
      if (local_9c == (ASN1_OCTET_STRING *)0x0) {
        uVar11 = 0x41;
        uVar2 = 0x30c;
        goto LAB_005a35e8;
      }
      ((p7->d).sign)->contents->state = (int)local_9c;
    }
    break;
  case 0x19:
    ppVar12 = ((p7->d).digest)->contents;
    iVar9 = (*(code *)PTR_OBJ_obj2nid_006a712c)(ppVar12->type);
    if (iVar9 == 0x15) {
      local_9c = (ppVar12->d).data;
    }
    else {
      iVar9 = (*(code *)PTR_OBJ_obj2nid_006a712c)(ppVar12->type);
      if (((iVar9 - 0x15U < 6) || (pAVar4 = (ppVar12->d).data, pAVar4 == (ASN1_OCTET_STRING *)0x0))
         || (pAVar4->length != 4)) {
        local_9c = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        local_9c = (ASN1_OCTET_STRING *)pAVar4->type;
      }
    }
    iVar9 = (*(code *)PTR_OBJ_obj2nid_006a712c)((((p7->d).sign)->cert->stack).comp);
    if ((iVar9 == 0x15) && (p7->detached != 0)) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(local_9c);
      local_9c = (ASN1_OCTET_STRING *)0x0;
      (((p7->d).digest)->contents->d).ptr = (char *)0x0;
    }
    iVar9 = (*(code *)PTR_OBJ_obj2nid_006a712c)((((p7->d).sign)->md_algs->stack).num);
    pBVar6 = bio;
    while (iVar7 = (*(code *)PTR_BIO_find_type_006a8320)(pBVar6,0x208), iVar7 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar7,0x78,0,&local_8c);
      if (local_8c == 0) goto LAB_005a3510;
      uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
      iVar5 = (*(code *)PTR_EVP_MD_type_006a73cc)(uVar2);
      if (iVar9 == iVar5) {
        iVar9 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(local_8c,auStack_6c,&local_88);
        if (iVar9 == 0) goto LAB_005a301c;
        (*(code *)PTR_ASN1_STRING_set_006a7d1c)(((p7->d).data)->flags,auStack_6c,local_88);
        goto LAB_005a31ac;
      }
      pBVar6 = (BIO *)(*(code *)PTR_BIO_next_006a9154)(iVar7);
    }
LAB_005a2ff8:
    uVar11 = 0x6c;
    uVar2 = 699;
    goto LAB_005a3008;
  default:
    uVar11 = 0x70;
    uVar2 = 0x334;
    goto LAB_005a35e8;
  }
  if (local_ac != (stack_st_PKCS7_SIGNER_INFO *)0x0) {
    iVar9 = 0;
    while (iVar7 = (*(code *)PTR_sk_num_006a6e2c)(local_ac), iVar9 < iVar7) {
      si = (PKCS7_SIGNER_INFO *)(*(code *)PTR_sk_value_006a6e24)(local_ac,iVar9);
      if (si->pkey == (EVP_PKEY *)0x0) {
LAB_005a33fc:
        iVar9 = iVar9 + 1;
      }
      else {
        iVar7 = (*(code *)PTR_OBJ_obj2nid_006a712c)(si->digest_alg->algorithm);
        pBVar6 = bio;
        while( true ) {
          iVar5 = (*(code *)PTR_BIO_find_type_006a8320)(pBVar6,0x208);
          if (iVar5 == 0) goto LAB_005a2ff8;
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar5,0x78,0,&local_8c);
          if (local_8c == 0) goto LAB_005a3510;
          uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
          iVar3 = (*(code *)PTR_EVP_MD_type_006a73cc)(uVar2);
          if (iVar7 == iVar3) break;
          pBVar6 = (BIO *)(*(code *)PTR_BIO_next_006a9154)(iVar5);
        }
        iVar7 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a8104)(local_a8,local_8c);
        if (iVar7 == 0) goto LAB_005a301c;
        iVar7 = (*(code *)PTR_sk_num_006a6e2c)(si->auth_attr);
        if (iVar7 < 1) {
          local_88 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(si->pkey);
          iVar7 = (*(code *)PTR_CRYPTO_malloc_006a7008)(local_88,"pk7_doit.c",0x35a);
          if (iVar7 == 0) goto LAB_005a301c;
          iVar5 = (*(code *)PTR_EVP_SignFinal_006a7f70)(local_a8,iVar7,&local_88,si->pkey);
          if (iVar5 == 0) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x80,6,"pk7_doit.c",0x35f);
            goto LAB_005a301c;
          }
          (*(code *)PTR_ASN1_STRING_set0_006a9144)(si->enc_digest,iVar7,local_88);
          goto LAB_005a33fc;
        }
        psVar13 = si->auth_attr;
        iVar7 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x34);
        if ((iVar7 != 0) && (psVar13 != (stack_st_X509_ATTRIBUTE *)0x0)) {
          for (iVar5 = 0; iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar13), iVar5 < iVar3;
              iVar5 = iVar5 + 1) {
            puVar8 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(psVar13,iVar5);
            iVar3 = (*(code *)PTR_OBJ_cmp_006a8cc4)(*puVar8,iVar7);
            if (iVar3 == 0) {
              if (((puVar8[1] == 0) &&
                  (iVar7 = (*(code *)PTR_sk_num_006a6e2c)(puVar8[2]), iVar7 != 0)) &&
                 (iVar7 = (*(code *)PTR_sk_value_006a6e24)(puVar8[2],0), iVar7 != 0)) {
                iVar7 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(local_a8,auStack_6c,&local_88);
                goto joined_r0x005a3570;
              }
              break;
            }
          }
        }
        iVar7 = PKCS7_add0_attrib_signing_time(si,(ASN1_TIME *)0x0);
        if (iVar7 == 0) {
          uVar11 = 0x41;
          uVar2 = 0x2d2;
LAB_005a358c:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x88,uVar11,"pk7_doit.c",uVar2);
          goto LAB_005a301c;
        }
        iVar7 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(local_a8,auStack_6c,&local_88);
joined_r0x005a3570:
        if (iVar7 == 0) {
          uVar11 = 6;
          uVar2 = 0x2d9;
          goto LAB_005a358c;
        }
        iVar7 = PKCS7_add1_attrib_digest(si,auStack_6c,local_88);
        if (iVar7 == 0) {
          uVar11 = 0x41;
          uVar2 = 0x2dd;
          goto LAB_005a358c;
        }
        iVar7 = PKCS7_SIGNER_INFO_sign(si);
        if (iVar7 == 0) goto LAB_005a301c;
        iVar9 = iVar9 + 1;
      }
    }
  }
LAB_005a31ac:
  iVar9 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
  if ((iVar9 == 0x16) && (lVar10 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar10 != 0)) {
    iVar9 = 1;
  }
  else {
    iVar9 = 0;
    if (local_9c != (ASN1_OCTET_STRING *)0x0) {
      if ((local_9c->flags & 0x10U) == 0) {
        iVar9 = (*(code *)PTR_BIO_find_type_006a8320)(bio,0x401);
        if (iVar9 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x80,0x6b,"pk7_doit.c",0x37c);
        }
        else {
          uVar2 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar9,3,0,&local_88);
          (*(code *)PTR_BIO_set_flags_006a7570)(iVar9,0x200);
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar9,0x82,0,0);
          (*(code *)PTR_ASN1_STRING_set0_006a9144)(local_9c,local_88,uVar2);
          iVar9 = 1;
        }
      }
      else {
        iVar9 = 1;
      }
    }
  }
  while( true ) {
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(local_a8);
LAB_005a3034:
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005a37a4:
    uVar11 = 0x41;
    uVar2 = 0x318;
LAB_005a35e8:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x80,uVar11,"pk7_doit.c",uVar2);
LAB_005a301c:
    iVar9 = 0;
  }
  return iVar9;
LAB_005a3510:
  uVar11 = 0x44;
  uVar2 = 0x2c0;
LAB_005a3008:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x7f,uVar11,"pk7_doit.c",uVar2);
  goto LAB_005a301c;
}

