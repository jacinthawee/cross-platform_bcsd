
int PKCS7_SIGNER_INFO_sign(PKCS7_SIGNER_INFO *si)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  PKCS7_SIGNER_INFO *si_00;
  int iVar5;
  PKCS7_SIGNED *pPVar6;
  int iVar7;
  int iVar8;
  ASN1_OCTET_STRING *pAVar9;
  long lVar10;
  PKCS7 *p7;
  char *in_a1;
  undefined4 *puVar11;
  undefined4 uVar12;
  pkcs7_st *ppVar13;
  undefined *unaff_s1;
  stack_st_X509_ATTRIBUTE *psVar14;
  undefined4 *unaff_s3;
  char *unaff_s4;
  stack_st_PKCS7_SIGNER_INFO *psStack_10c;
  ASN1_OCTET_STRING *pAStack_f8;
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
  
  puStack_80 = PTR___stack_chk_guard_006aabf0;
  local_3c = (undefined4 *)0x0;
  local_1c = *(PKCS7 **)PTR___stack_chk_guard_006aabf0;
  uVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(si->digest_alg->algorithm);
  uVar2 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar2);
  puVar3 = (undefined4 *)(*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar2);
  if (puVar3 == (undefined4 *)0x0) {
    iVar4 = 0;
  }
  else {
    unaff_s1 = auStack_34;
    (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(unaff_s1);
    puVar11 = &local_40;
    iVar4 = (*(code *)PTR_EVP_DigestSignInit_006a7f20)(unaff_s1,puVar11,puVar3,0);
    if (iVar4 < 1) {
LAB_005a5a00:
      in_a1 = (char *)puVar11;
      if (local_3c != (undefined4 *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
        in_a1 = (char *)puVar11;
      }
    }
    else {
      iVar4 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(local_40,0xffffffff,8,5);
      if (iVar4 < 1) {
        puVar11 = (undefined4 *)&DAT_0000008b;
        (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x8b,0x98,"pk7_doit.c");
        goto LAB_005a5a00;
      }
      uVar2 = (*(code *)PTR_ASN1_item_i2d_006a979c)
                        (si->auth_attr,&local_3c,PTR_PKCS7_ATTR_SIGN_it_006aa26c);
      in_a1 = (char *)local_3c;
      if (local_3c != (undefined4 *)0x0) {
        puVar11 = local_3c;
        iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(unaff_s1,local_3c,uVar2);
        if (0 < iVar4) {
          puVar3 = &local_38;
          (*(code *)PTR_CRYPTO_free_006a7f88)(local_3c);
          puVar11 = (undefined4 *)0x0;
          iVar4 = (*(code *)PTR_EVP_DigestSignFinal_006a85cc)(unaff_s1,0,puVar3);
          if (0 < iVar4) {
            unaff_s4 = "7 datafinal";
            in_a1 = "pk7_doit.c";
            puVar11 = (undefined4 *)
                      (*(code *)PTR_CRYPTO_malloc_006a8108)(local_38,"pk7_doit.c",0x3a5);
            local_3c = puVar11;
            if (puVar11 == (undefined4 *)0x0) goto LAB_005a5a18;
            iVar4 = (*(code *)PTR_EVP_DigestSignFinal_006a85cc)(unaff_s1,puVar11,puVar3);
            if (0 < iVar4) {
              iVar4 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(local_40,0xffffffff,8,5);
              if (0 < iVar4) {
                (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(unaff_s1);
                in_a1 = (char *)local_3c;
                (*(code *)PTR_ASN1_STRING_set0_006aa260)(si->enc_digest,local_3c,local_38);
                iVar4 = 1;
                unaff_s3 = puVar3;
                goto LAB_005a5a2c;
              }
              puVar11 = (undefined4 *)&DAT_0000008b;
              (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x8b,0x98,"pk7_doit.c");
            }
          }
        }
        goto LAB_005a5a00;
      }
    }
LAB_005a5a18:
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(unaff_s1);
    iVar4 = 0;
    unaff_s3 = puVar3;
  }
LAB_005a5a2c:
  if (local_1c == *(PKCS7 **)puStack_80) {
    return iVar4;
  }
  p7 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_8c = *(int *)PTR___stack_chk_guard_006aabf0;
  pPStack_88 = si;
  puStack_84 = unaff_s1;
  puStack_7c = unaff_s3;
  pcStack_78 = unaff_s4;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_e4);
  uVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
  p7->state = 0;
  switch(uVar2) {
  case 0x15:
    pAStack_f8 = (p7->d).data;
    goto LAB_005a5e08;
  case 0x16:
    ppVar13 = ((p7->d).sign)->contents;
    psStack_10c = ((p7->d).sign)->signer_info;
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ppVar13->type);
    if (iVar4 == 0x15) {
      pAStack_f8 = (ppVar13->d).data;
    }
    else {
      iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ppVar13->type);
      if (((iVar4 - 0x15U < 6) || (pAVar9 = (ppVar13->d).data, pAVar9 == (ASN1_OCTET_STRING *)0x0))
         || (pAVar9->length != 4)) {
        pAStack_f8 = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        pAStack_f8 = (ASN1_OCTET_STRING *)pAVar9->type;
      }
    }
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(((p7->d).sign)->contents->type);
    if ((iVar4 == 0x15) && (p7->detached != 0)) {
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAStack_f8);
      (((p7->d).sign)->contents->d).ptr = (char *)0x0;
    }
    break;
  case 0x17:
    pAStack_f8 = (ASN1_OCTET_STRING *)(((p7->d).sign)->cert->stack).sorted;
    if (pAStack_f8 == (ASN1_OCTET_STRING *)0x0) {
      pAStack_f8 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(4);
      if (pAStack_f8 == (ASN1_OCTET_STRING *)0x0) {
        uVar12 = 0x41;
        uVar2 = 0x30e;
        goto LAB_005a6238;
      }
      (((p7->d).sign)->cert->stack).sorted = (int)pAStack_f8;
    }
    goto LAB_005a5e08;
  case 0x18:
    psStack_10c = ((p7->d).sign)->signer_info;
    pAStack_f8 = (ASN1_OCTET_STRING *)((p7->d).sign)->contents->state;
    if (pAStack_f8 == (ASN1_OCTET_STRING *)0x0) {
      pAStack_f8 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(4);
      if (pAStack_f8 == (ASN1_OCTET_STRING *)0x0) goto LAB_005a63b0;
      ((p7->d).sign)->contents->state = (int)pAStack_f8;
    }
    break;
  case 0x19:
    ppVar13 = ((p7->d).digest)->contents;
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ppVar13->type);
    if (iVar4 == 0x15) {
      pAStack_f8 = (ppVar13->d).data;
    }
    else {
      iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ppVar13->type);
      if (((iVar4 - 0x15U < 6) || (pPVar6 = (ppVar13->d).sign, pPVar6 == (PKCS7_SIGNED *)0x0)) ||
         (pPVar6->version != (ASN1_INTEGER *)0x4)) {
        pAStack_f8 = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        pAStack_f8 = (ASN1_OCTET_STRING *)pPVar6->md_algs;
      }
    }
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)((((p7->d).sign)->cert->stack).comp);
    if ((iVar4 == 0x15) && (p7->detached != 0)) {
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAStack_f8);
      (((p7->d).digest)->contents->d).ptr = (char *)0x0;
    }
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)((((p7->d).sign)->md_algs->stack).num);
    puVar3 = (undefined4 *)in_a1;
    while (iVar8 = (*(code *)PTR_BIO_find_type_006a943c)(puVar3,0x208), iVar8 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar8,0x78,0,&iStack_ec);
      if (iStack_ec == 0) goto LAB_005a6160;
      uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
      iVar7 = (*(code *)PTR_EVP_MD_type_006a84cc)(uVar2);
      if (iVar4 == iVar7) {
        iVar4 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(iStack_ec,auStack_cc,&iStack_e8);
        if (iVar4 == 0) goto LAB_005a5c78;
        (*(code *)PTR_ASN1_STRING_set_006a8e0c)(((p7->d).data)->flags,auStack_cc,iStack_e8);
        goto LAB_005a5e08;
      }
      puVar3 = (undefined4 *)(*(code *)PTR_BIO_next_006aa270)(iVar8);
    }
LAB_005a5c54:
    uVar12 = 0x6c;
    uVar2 = 0x2af;
LAB_005a5c64:
    (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x7f,uVar12,"pk7_doit.c",uVar2);
    goto LAB_005a5c78;
  default:
    uVar12 = 0x70;
    uVar2 = 0x329;
    goto LAB_005a6238;
  }
  if (psStack_10c != (stack_st_PKCS7_SIGNER_INFO *)0x0) {
    iVar4 = 0;
    while (iVar8 = (*(code *)PTR_sk_num_006a7f2c)(psStack_10c), iVar4 < iVar8) {
      si_00 = (PKCS7_SIGNER_INFO *)(*(code *)PTR_sk_value_006a7f24)(psStack_10c,iVar4);
      if (si_00->pkey == (EVP_PKEY *)0x0) {
LAB_005a604c:
        iVar4 = iVar4 + 1;
      }
      else {
        iVar8 = (*(code *)PTR_OBJ_obj2nid_006a822c)(si_00->digest_alg->algorithm);
        puVar3 = (undefined4 *)in_a1;
        while( true ) {
          iVar7 = (*(code *)PTR_BIO_find_type_006a943c)(puVar3,0x208);
          if (iVar7 == 0) goto LAB_005a5c54;
          (*(code *)PTR_BIO_ctrl_006a7f18)(iVar7,0x78,0,&iStack_ec);
          if (iStack_ec == 0) goto LAB_005a6160;
          uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
          iVar5 = (*(code *)PTR_EVP_MD_type_006a84cc)(uVar2);
          if (iVar8 == iVar5) break;
          puVar3 = (undefined4 *)(*(code *)PTR_BIO_next_006aa270)(iVar7);
        }
        iVar8 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a922c)(auStack_e4,iStack_ec);
        if (iVar8 == 0) goto LAB_005a5c78;
        iVar8 = (*(code *)PTR_sk_num_006a7f2c)(si_00->auth_attr);
        if (iVar8 < 1) {
          iStack_e8 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(si_00->pkey);
          iVar8 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iStack_e8,"pk7_doit.c",0x351);
          if (iVar8 == 0) goto LAB_005a5c78;
          iVar7 = (*(code *)PTR_EVP_SignFinal_006a9094)(auStack_e4,iVar8,&iStack_e8,si_00->pkey);
          if (iVar7 == 0) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x80,6,"pk7_doit.c",0x359);
            goto LAB_005a5c78;
          }
          (*(code *)PTR_ASN1_STRING_set0_006aa260)(si_00->enc_digest,iVar8,iStack_e8);
          goto LAB_005a604c;
        }
        psVar14 = si_00->auth_attr;
        iVar8 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x34);
        if ((iVar8 != 0) && (psVar14 != (stack_st_X509_ATTRIBUTE *)0x0)) {
          for (iVar7 = 0; iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar14), iVar7 < iVar5;
              iVar7 = iVar7 + 1) {
            puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(psVar14,iVar7);
            iVar5 = (*(code *)PTR_OBJ_cmp_006a9de4)(*puVar3,iVar8);
            if (iVar5 == 0) {
              if (((puVar3[1] == 0) &&
                  (iVar8 = (*(code *)PTR_sk_num_006a7f2c)(puVar3[2]), iVar8 != 0)) &&
                 (iVar8 = (*(code *)PTR_sk_value_006a7f24)(puVar3[2],0), iVar8 != 0)) {
                iVar8 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_e4,auStack_cc,&iStack_e8)
                ;
                goto joined_r0x005a61c0;
              }
              break;
            }
          }
        }
        iVar8 = PKCS7_add0_attrib_signing_time(si_00,(ASN1_TIME *)0x0);
        if (iVar8 == 0) {
          uVar12 = 0x41;
          uVar2 = 0x2ca;
LAB_005a61dc:
          (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x88,uVar12,"pk7_doit.c",uVar2);
          goto LAB_005a5c78;
        }
        iVar8 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_e4,auStack_cc,&iStack_e8);
joined_r0x005a61c0:
        if (iVar8 == 0) {
          uVar12 = 6;
          uVar2 = 0x2d2;
          goto LAB_005a61dc;
        }
        iVar8 = PKCS7_add1_attrib_digest(si_00,auStack_cc,iStack_e8);
        if (iVar8 == 0) {
          uVar12 = 0x41;
          uVar2 = 0x2d7;
          goto LAB_005a61dc;
        }
        iVar8 = PKCS7_SIGNER_INFO_sign(si_00);
        if (iVar8 == 0) goto LAB_005a5c78;
        iVar4 = iVar4 + 1;
      }
    }
  }
LAB_005a5e08:
  iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
  if ((iVar4 == 0x16) && (lVar10 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar10 != 0)) {
    iVar4 = 1;
  }
  else if ((pAStack_f8->flags & 0x10U) == 0) {
    iVar4 = (*(code *)PTR_BIO_find_type_006a943c)(in_a1,0x401);
    if (iVar4 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x80,0x6b,"pk7_doit.c",0x373);
    }
    else {
      uVar2 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar4,3,0,&iStack_e8);
      (*(code *)PTR_BIO_set_flags_006a8660)(iVar4,0x200);
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar4,0x82,0,0);
      (*(code *)PTR_ASN1_STRING_set0_006aa260)(pAStack_f8,iStack_e8,uVar2);
      iVar4 = 1;
    }
  }
  else {
    iVar4 = 1;
  }
  while( true ) {
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_e4);
    if (iStack_8c == *(int *)puVar1) break;
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
  goto LAB_005a5c64;
}

