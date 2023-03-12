
int PKCS7_signatureVerify(BIO *bio,PKCS7 *p7,PKCS7_SIGNER_INFO *si,X509 *x509)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  stack_st_X509_ATTRIBUTE *psVar10;
  ASN1_OCTET_STRING *pAVar11;
  int local_90;
  undefined4 local_8c;
  int local_88;
  undefined auStack_84 [24];
  undefined auStack_6c [64];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_84);
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
  if ((iVar2 == 0x16) || (iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type), iVar2 == 0x18)) {
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(si->digest_alg->algorithm);
    if (bio != (BIO *)0x0) {
      do {
        iVar9 = (*(code *)PTR_BIO_find_type_006a943c)(bio,0x208);
        if (iVar9 == 0) break;
        (*(code *)PTR_BIO_ctrl_006a7f18)(iVar9,0x78,0,&local_90);
        if (local_90 == 0) {
          uVar8 = 0x44;
          uVar7 = 0x41a;
          goto LAB_005a65bc;
        }
        uVar7 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
        iVar3 = (*(code *)PTR_EVP_MD_type_006a84cc)(uVar7);
        if (iVar2 == iVar3) {
LAB_005a65d4:
          iVar9 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a922c)(auStack_84,local_90);
          if (iVar9 == 0) goto LAB_005a6554;
          psVar10 = si->auth_attr;
          if ((psVar10 == (stack_st_X509_ATTRIBUTE *)0x0) ||
             (iVar9 = (*(code *)PTR_sk_num_006a7f2c)(psVar10), iVar9 == 0)) goto LAB_005a6608;
          local_8c = 0;
          iVar9 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_84,auStack_6c,&local_88);
          if (iVar9 == 0) goto LAB_005a6554;
          iVar9 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x33);
          if (iVar9 == 0) goto LAB_005a673c;
          iVar3 = 0;
          goto LAB_005a6720;
        }
        uVar7 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(local_90);
        iVar3 = (*(code *)PTR_EVP_MD_pkey_type_006aa27c)(uVar7);
        if (iVar2 == iVar3) goto LAB_005a65d4;
        bio = (BIO *)(*(code *)PTR_BIO_next_006aa270)(iVar9);
      } while (bio != (BIO *)0x0);
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x71,0x6c,"pk7_doit.c",0x413);
    goto LAB_005a6554;
  }
  uVar8 = 0x72;
  uVar7 = 0x406;
LAB_005a65bc:
  (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x71,uVar8,"pk7_doit.c",uVar7);
LAB_005a6554:
  iVar9 = 0;
LAB_005a6558:
  while( true ) {
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_84);
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005a686c:
    uVar8 = 0xd;
    uVar7 = 0x455;
LAB_005a6670:
    iVar9 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x71,uVar8,"pk7_doit.c",uVar7);
  }
  return iVar9;
LAB_005a6720:
  iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar10);
  if (iVar5 <= iVar3) goto LAB_005a673c;
  puVar4 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(psVar10,iVar3);
  iVar5 = (*(code *)PTR_OBJ_cmp_006a9de4)(*puVar4,iVar9);
  if (iVar5 == 0) {
    if ((((puVar4[1] == 0) && (iVar9 = (*(code *)PTR_sk_num_006a7f2c)(puVar4[2]), iVar9 != 0)) &&
        (iVar9 = (*(code *)PTR_sk_value_006a7f24)(puVar4[2],0), iVar9 != 0)) &&
       (piVar6 = *(int **)(iVar9 + 4), piVar6 != (int *)0x0)) {
      if ((*piVar6 != local_88) ||
         (iVar9 = (*(code *)PTR_memcmp_006aabd8)(piVar6[2],auStack_6c), iVar9 != 0)) {
        uVar8 = 0x65;
        uVar7 = 0x449;
        goto LAB_005a6670;
      }
      uVar7 = (*(code *)PTR_OBJ_nid2sn_006a819c)(iVar2);
      uVar7 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar7);
      iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_84,uVar7,0);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_ASN1_item_i2d_006a979c)
                          (psVar10,&local_8c,PTR_PKCS7_ATTR_VERIFY_it_006aa280);
        if (iVar2 < 1) goto LAB_005a686c;
        iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_84,local_8c,iVar2);
        if (iVar2 != 0) {
          (*(code *)PTR_CRYPTO_free_006a7f88)(local_8c);
LAB_005a6608:
          pAVar11 = si->enc_digest;
          iVar2 = (*(code *)PTR_X509_get_pubkey_006a8008)(x509);
          if (iVar2 == 0) {
            iVar9 = -1;
          }
          else {
            iVar3 = (*(code *)PTR_EVP_VerifyFinal_006a907c)
                              (auStack_84,pAVar11->data,pAVar11->length,iVar2);
            iVar9 = 1;
            (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar2);
            if (iVar3 < 1) {
              uVar8 = 0x69;
              uVar7 = 0x46c;
              goto LAB_005a6670;
            }
          }
          goto LAB_005a6558;
        }
      }
      goto LAB_005a6554;
    }
    goto LAB_005a673c;
  }
  iVar3 = iVar3 + 1;
  goto LAB_005a6720;
LAB_005a673c:
  uVar8 = 0x6c;
  uVar7 = 0x43a;
  goto LAB_005a65bc;
}

