
int PKCS7_dataFinal(PKCS7 *p7,BIO *bio)

{
  undefined *puVar1;
  undefined4 uVar2;
  PKCS7_SIGNER_INFO *si;
  int iVar3;
  int iVar4;
  PKCS7_SIGNED *pPVar5;
  int iVar6;
  BIO *pBVar7;
  int iVar8;
  ASN1_OCTET_STRING *pAVar9;
  undefined4 *puVar10;
  long lVar11;
  undefined4 uVar12;
  pkcs7_st *ppVar13;
  stack_st_X509_ATTRIBUTE *psVar14;
  stack_st_PKCS7_SIGNER_INFO *local_ac;
  ASN1_OCTET_STRING *local_98;
  int local_8c;
  int local_88;
  undefined auStack_84 [24];
  uchar auStack_6c [64];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_84);
  uVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
  p7->state = 0;
  switch(uVar2) {
  case 0x15:
    local_98 = (p7->d).data;
    goto LAB_005a5e08;
  case 0x16:
    ppVar13 = ((p7->d).sign)->contents;
    local_ac = ((p7->d).sign)->signer_info;
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ppVar13->type);
    if (iVar4 == 0x15) {
      local_98 = (ppVar13->d).data;
    }
    else {
      iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ppVar13->type);
      if (((iVar4 - 0x15U < 6) || (pAVar9 = (ppVar13->d).data, pAVar9 == (ASN1_OCTET_STRING *)0x0))
         || (pAVar9->length != 4)) {
        local_98 = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        local_98 = (ASN1_OCTET_STRING *)pAVar9->type;
      }
    }
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(((p7->d).sign)->contents->type);
    if ((iVar4 == 0x15) && (p7->detached != 0)) {
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(local_98);
      (((p7->d).sign)->contents->d).ptr = (char *)0x0;
    }
    break;
  case 0x17:
    local_98 = (ASN1_OCTET_STRING *)(((p7->d).sign)->cert->stack).sorted;
    if (local_98 == (ASN1_OCTET_STRING *)0x0) {
      local_98 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(4);
      if (local_98 == (ASN1_OCTET_STRING *)0x0) {
        uVar12 = 0x41;
        uVar2 = 0x30e;
        goto LAB_005a6238;
      }
      (((p7->d).sign)->cert->stack).sorted = (int)local_98;
    }
    goto LAB_005a5e08;
  case 0x18:
    local_ac = ((p7->d).sign)->signer_info;
    local_98 = (ASN1_OCTET_STRING *)((p7->d).sign)->contents->state;
    if (local_98 == (ASN1_OCTET_STRING *)0x0) {
      local_98 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(4);
      if (local_98 == (ASN1_OCTET_STRING *)0x0) goto LAB_005a63b0;
      ((p7->d).sign)->contents->state = (int)local_98;
    }
    break;
  case 0x19:
    ppVar13 = ((p7->d).digest)->contents;
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ppVar13->type);
    if (iVar4 == 0x15) {
      local_98 = (ppVar13->d).data;
    }
    else {
      iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ppVar13->type);
      if (((iVar4 - 0x15U < 6) || (pPVar5 = (ppVar13->d).sign, pPVar5 == (PKCS7_SIGNED *)0x0)) ||
         (pPVar5->version != (ASN1_INTEGER *)0x4)) {
        local_98 = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        local_98 = (ASN1_OCTET_STRING *)pPVar5->md_algs;
      }
    }
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)((((p7->d).sign)->cert->stack).comp);
    if ((iVar4 == 0x15) && (p7->detached != 0)) {
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(local_98);
      (((p7->d).digest)->contents->d).ptr = (char *)0x0;
    }
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)((((p7->d).sign)->md_algs->stack).num);
    pBVar7 = bio;
    while (iVar8 = (*(code *)PTR_BIO_find_type_006a943c)(pBVar7,0x208), iVar8 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar8,0x78,0,&local_8c);
      if (local_8c == 0) goto LAB_005a6160;
      uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
      iVar6 = (*(code *)PTR_EVP_MD_type_006a84cc)(uVar2);
      if (iVar4 == iVar6) {
        iVar4 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(local_8c,auStack_6c,&local_88);
        if (iVar4 == 0) goto LAB_005a5c78;
        (*(code *)PTR_ASN1_STRING_set_006a8e0c)(((p7->d).data)->flags,auStack_6c,local_88);
        goto LAB_005a5e08;
      }
      pBVar7 = (BIO *)(*(code *)PTR_BIO_next_006aa270)(iVar8);
    }
LAB_005a5c54:
    uVar12 = 0x6c;
    uVar2 = 0x2af;
    goto LAB_005a5c64;
  default:
    uVar12 = 0x70;
    uVar2 = 0x329;
    goto LAB_005a6238;
  }
  if (local_ac != (stack_st_PKCS7_SIGNER_INFO *)0x0) {
    iVar4 = 0;
    while (iVar8 = (*(code *)PTR_sk_num_006a7f2c)(local_ac), iVar4 < iVar8) {
      si = (PKCS7_SIGNER_INFO *)(*(code *)PTR_sk_value_006a7f24)(local_ac,iVar4);
      if (si->pkey == (EVP_PKEY *)0x0) {
LAB_005a604c:
        iVar4 = iVar4 + 1;
      }
      else {
        iVar8 = (*(code *)PTR_OBJ_obj2nid_006a822c)(si->digest_alg->algorithm);
        pBVar7 = bio;
        while( true ) {
          iVar6 = (*(code *)PTR_BIO_find_type_006a943c)(pBVar7,0x208);
          if (iVar6 == 0) goto LAB_005a5c54;
          (*(code *)PTR_BIO_ctrl_006a7f18)(iVar6,0x78,0,&local_8c);
          if (local_8c == 0) goto LAB_005a6160;
          uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
          iVar3 = (*(code *)PTR_EVP_MD_type_006a84cc)(uVar2);
          if (iVar8 == iVar3) break;
          pBVar7 = (BIO *)(*(code *)PTR_BIO_next_006aa270)(iVar6);
        }
        iVar8 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a922c)(auStack_84,local_8c);
        if (iVar8 == 0) goto LAB_005a5c78;
        iVar8 = (*(code *)PTR_sk_num_006a7f2c)(si->auth_attr);
        if (iVar8 < 1) {
          local_88 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(si->pkey);
          iVar8 = (*(code *)PTR_CRYPTO_malloc_006a8108)(local_88,"pk7_doit.c",0x351);
          if (iVar8 == 0) goto LAB_005a5c78;
          iVar6 = (*(code *)PTR_EVP_SignFinal_006a9094)(auStack_84,iVar8,&local_88,si->pkey);
          if (iVar6 == 0) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x80,6,"pk7_doit.c",0x359);
            goto LAB_005a5c78;
          }
          (*(code *)PTR_ASN1_STRING_set0_006aa260)(si->enc_digest,iVar8,local_88);
          goto LAB_005a604c;
        }
        psVar14 = si->auth_attr;
        iVar8 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x34);
        if ((iVar8 != 0) && (psVar14 != (stack_st_X509_ATTRIBUTE *)0x0)) {
          for (iVar6 = 0; iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar14), iVar6 < iVar3;
              iVar6 = iVar6 + 1) {
            puVar10 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(psVar14,iVar6);
            iVar3 = (*(code *)PTR_OBJ_cmp_006a9de4)(*puVar10,iVar8);
            if (iVar3 == 0) {
              if (((puVar10[1] == 0) &&
                  (iVar8 = (*(code *)PTR_sk_num_006a7f2c)(puVar10[2]), iVar8 != 0)) &&
                 (iVar8 = (*(code *)PTR_sk_value_006a7f24)(puVar10[2],0), iVar8 != 0)) {
                iVar8 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_84,auStack_6c,&local_88);
                goto joined_r0x005a61c0;
              }
              break;
            }
          }
        }
        iVar8 = PKCS7_add0_attrib_signing_time(si,(ASN1_TIME *)0x0);
        if (iVar8 == 0) {
          uVar12 = 0x41;
          uVar2 = 0x2ca;
LAB_005a61dc:
          (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x88,uVar12,"pk7_doit.c",uVar2);
          goto LAB_005a5c78;
        }
        iVar8 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_84,auStack_6c,&local_88);
joined_r0x005a61c0:
        if (iVar8 == 0) {
          uVar12 = 6;
          uVar2 = 0x2d2;
          goto LAB_005a61dc;
        }
        iVar8 = PKCS7_add1_attrib_digest(si,auStack_6c,local_88);
        if (iVar8 == 0) {
          uVar12 = 0x41;
          uVar2 = 0x2d7;
          goto LAB_005a61dc;
        }
        iVar8 = PKCS7_SIGNER_INFO_sign(si);
        if (iVar8 == 0) goto LAB_005a5c78;
        iVar4 = iVar4 + 1;
      }
    }
  }
LAB_005a5e08:
  iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
  if ((iVar4 == 0x16) && (lVar11 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar11 != 0)) {
    iVar4 = 1;
  }
  else if ((local_98->flags & 0x10U) == 0) {
    iVar4 = (*(code *)PTR_BIO_find_type_006a943c)(bio,0x401);
    if (iVar4 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x80,0x6b,"pk7_doit.c",0x373);
    }
    else {
      uVar2 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar4,3,0,&local_88);
      (*(code *)PTR_BIO_set_flags_006a8660)(iVar4,0x200);
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar4,0x82,0,0);
      (*(code *)PTR_ASN1_STRING_set0_006aa260)(local_98,local_88,uVar2);
      iVar4 = 1;
    }
  }
  else {
    iVar4 = 1;
  }
  while( true ) {
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_84);
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005a63b0:
    uVar12 = 0x41;
    uVar2 = 0x300;
LAB_005a6238:
    (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x80,uVar12,"pk7_doit.c",uVar2);
LAB_005a5c78:
    iVar4 = 0;
  }
  return iVar4;
LAB_005a6160:
  uVar12 = 0x44;
  uVar2 = 0x2b5;
LAB_005a5c64:
  (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x7f,uVar12,"pk7_doit.c",uVar2);
  goto LAB_005a5c78;
}

