
int CMS_RecipientInfo_decrypt(CMS_ContentInfo *cms,CMS_RecipientInfo *ri)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined *unaff_s3;
  int unaff_s4;
  char *unaff_s5;
  undefined4 *unaff_s6;
  char *unaff_s7;
  undefined4 uStack_26c;
  undefined auStack_268 [244];
  int iStack_174;
  int iStack_170;
  undefined *puStack_16c;
  CMS_RecipientInfo *pCStack_168;
  undefined *puStack_164;
  int iStack_160;
  char *pcStack_15c;
  undefined4 *puStack_158;
  char *pcStack_154;
  undefined4 local_124;
  undefined auStack_120 [244];
  int local_2c;
  
  puStack_16c = PTR___stack_chk_guard_006a9ae8;
  iStack_170 = *(int *)ri;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (iStack_170 != 2) {
    if (iStack_170 == 3) {
      iStack_170 = cms_RecipientInfo_pwri_crypt(cms,ri,0);
    }
    else if (iStack_170 == 0) {
      unaff_s4 = *(int *)(ri + 4);
      unaff_s5 = *(char **)(*(int *)(cms + 4) + 0xc);
      if (*(int *)(unaff_s4 + 0x14) == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x8c,0x85,"cms_env.c");
      }
      else {
        unaff_s3 = (undefined *)
                   (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(*(int *)(unaff_s4 + 0x14),0);
        if (unaff_s3 != (undefined *)0x0) {
          iVar2 = (*(code *)PTR_EVP_PKEY_decrypt_init_006a7ce4)(unaff_s3);
          if (0 < iVar2) {
            iVar2 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(unaff_s3,0xffffffff,0x200,10);
            if (iVar2 < 1) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x8c,0x6e,"cms_env.c");
            }
            else {
              unaff_s6 = &local_124;
              iVar2 = (*(code *)PTR_EVP_PKEY_decrypt_006a7d0c)
                                (unaff_s3,0,unaff_s6,*(undefined4 *)(*(int *)(unaff_s4 + 0xc) + 8));
              if (0 < iVar2) {
                unaff_s7 = "encrypt";
                ri = (CMS_RecipientInfo *)
                     (*(code *)PTR_CRYPTO_malloc_006a7008)(local_124,"cms_env.c",0x17c);
                if (ri != (CMS_RecipientInfo *)0x0) {
                  iVar2 = (*(code *)PTR_EVP_PKEY_decrypt_006a7d0c)
                                    (unaff_s3,ri,unaff_s6,
                                     *(undefined4 *)(*(int *)(unaff_s4 + 0xc) + 8));
                  if (iVar2 < 1) {
                    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x8c,0x68,"cms_env.c");
                    (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(unaff_s3);
                    (*(code *)PTR_CRYPTO_free_006a6e88)(ri);
                  }
                  else {
                    if (*(int *)(unaff_s5 + 0x10) != 0) {
                      (*(code *)PTR_OPENSSL_cleanse_006a7074)
                                (*(int *)(unaff_s5 + 0x10),*(undefined4 *)(unaff_s5 + 0x14));
                      (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(unaff_s5 + 0x10));
                    }
                    puVar1 = PTR_EVP_PKEY_CTX_free_006a6e7c;
                    iStack_170 = 1;
                    *(CMS_RecipientInfo **)(unaff_s5 + 0x10) = ri;
                    *(undefined4 *)(unaff_s5 + 0x14) = local_124;
                    (*(code *)puVar1)(unaff_s3);
                  }
                  goto LAB_005bc400;
                }
                (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x8c,0x41,"cms_env.c");
              }
            }
          }
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(unaff_s3);
        }
      }
    }
    else {
      iStack_170 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x86,0x9b,"cms_env.c");
    }
    goto LAB_005bc400;
  }
  iVar2 = *(int *)(ri + 4);
  ri = *(CMS_RecipientInfo **)(*(int *)(cms + 4) + 0xc);
  if (*(int *)(iVar2 + 0x10) == 0) {
    uVar12 = 0x82;
  }
  else {
    iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(**(undefined4 **)(iVar2 + 8));
    if (iVar3 - 0x314U < 3) {
      iVar3 = *(int *)(CSWTCH_8 + (iVar3 - 0x314U) * 4);
    }
    else {
      iVar3 = 0;
    }
    if (*(int *)(iVar2 + 0x14) == iVar3) {
      if (**(int **)(iVar2 + 0xc) < 0x10) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x87,0x75,"cms_env.c");
LAB_005bc608:
        iStack_170 = 0;
      }
      else {
        iVar3 = (*(code *)PTR_AES_set_decrypt_key_006a8a1c)
                          (*(undefined4 *)(iVar2 + 0x10),iVar3 << 3,auStack_120);
        if (iVar3 != 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x87,0x73,"cms_env.c");
          goto LAB_005bc608;
        }
        unaff_s5 = "encrypt";
        unaff_s4 = (*(code *)PTR_CRYPTO_malloc_006a7008)
                             (**(int **)(iVar2 + 0xc) + -8,"cms_env.c",0x2ba);
        if (unaff_s4 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x87,0x41,"cms_env.c");
          goto LAB_005bc608;
        }
        iVar2 = (*(code *)PTR_AES_unwrap_key_006a93dc)
                          (auStack_120,0,unaff_s4,*(undefined4 *)(*(int *)(iVar2 + 0xc) + 8));
        if (iVar2 < 1) {
          iStack_170 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x87,0x9d,"cms_env.c");
          (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s4);
        }
        else {
          iStack_170 = 1;
          *(int *)(ri + 0x10) = unaff_s4;
          *(int *)(ri + 0x14) = iVar2;
        }
      }
      unaff_s3 = auStack_120;
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(unaff_s3,0xf4);
      goto LAB_005bc400;
    }
    uVar12 = 0x76;
  }
  iStack_170 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x87,uVar12,"cms_env.c");
LAB_005bc400:
  if (local_2c == *(int *)puStack_16c) {
    return iStack_170;
  }
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_174 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar11 = *(int *)(*(int *)(iVar3 + 4) + 0xc);
  pCStack_168 = ri;
  puStack_164 = unaff_s3;
  iStack_160 = unaff_s4;
  pcStack_15c = unaff_s5;
  puStack_158 = unaff_s6;
  pcStack_154 = unaff_s7;
  iVar4 = cms_EncryptedContent_init_bio(iVar11);
  iVar2 = iVar4;
  if (iVar4 == 0) {
    iVar2 = 0;
  }
  else if (*(int *)(iVar11 + 0xc) != 0) {
    uVar12 = *(undefined4 *)(*(int *)(iVar3 + 4) + 8);
    for (iVar10 = 0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uVar12), iVar10 < iVar5;
        iVar10 = iVar10 + 1) {
      piVar6 = (int *)(*(code *)PTR_sk_value_006a6e24)(uVar12,iVar10);
      iVar5 = *piVar6;
      if (iVar5 == 2) {
        iVar7 = piVar6[1];
        iVar5 = *(int *)(*(int *)(iVar3 + 4) + 0xc);
        if (*(int *)(iVar7 + 0x10) != 0) {
          iVar8 = (*(code *)PTR_AES_set_encrypt_key_006a79ec)
                            (*(int *)(iVar7 + 0x10),*(int *)(iVar7 + 0x14) << 3,auStack_268);
          if (iVar8 == 0) {
            iVar8 = (*(code *)PTR_CRYPTO_malloc_006a7008)
                              (*(int *)(iVar5 + 0x14) + 8,"cms_env.c",0x274);
            if (iVar8 == 0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x88,0x41,"cms_env.c",0x277);
              goto LAB_005bcafc;
            }
            iVar9 = (*(code *)PTR_AES_wrap_key_006a93e4)
                              (auStack_268,0,iVar8,*(undefined4 *)(iVar5 + 0x10),
                               *(undefined4 *)(iVar5 + 0x14));
            if (iVar9 < 1) {
              iVar5 = 0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x88,0x9f,"cms_env.c",0x27e);
              (*(code *)PTR_CRYPTO_free_006a6e88)(iVar8);
            }
            else {
              iVar5 = 1;
              (*(code *)PTR_ASN1_STRING_set0_006a9144)(*(undefined4 *)(iVar7 + 0xc),iVar8,iVar9);
            }
          }
          else {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x88,0x73,"cms_env.c",0x270);
LAB_005bcafc:
            iVar5 = 0;
          }
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_268,0xf4);
          goto LAB_005bca1c;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x88,0x82,"cms_env.c",0x26a);
LAB_005bccb0:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7d,0x74,"cms_env.c",0x31a);
LAB_005bc980:
        *(undefined4 *)(iVar11 + 0xc) = 0;
        if (*(int *)(iVar11 + 0x10) != 0) {
          (*(code *)PTR_OPENSSL_cleanse_006a7074)
                    (*(int *)(iVar11 + 0x10),*(undefined4 *)(iVar11 + 0x14));
          (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(iVar11 + 0x10));
          *(undefined4 *)(iVar11 + 0x10) = 0;
          *(undefined4 *)(iVar11 + 0x14) = 0;
        }
        (*(code *)PTR_BIO_free_006a6e70)(iVar4);
        iVar2 = 0;
        goto LAB_005bc9c8;
      }
      if (iVar5 != 3) {
        if (iVar5 == 0) {
          iVar7 = piVar6[1];
          iVar5 = *(int *)(*(int *)(iVar3 + 4) + 0xc);
          iVar8 = (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(*(undefined4 *)(iVar7 + 0x14),0);
          if (iVar8 == 0) goto LAB_005bccb0;
          iVar9 = (*(code *)PTR_EVP_PKEY_encrypt_init_006a7cec)(iVar8);
          if (iVar9 < 1) {
LAB_005bcc74:
            iVar5 = 0;
          }
          else {
            iVar9 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(iVar8,0xffffffff,0x100,9,0,piVar6);
            if (iVar9 < 1) {
              iVar5 = 0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x8d,0x6e,"cms_env.c",0x139);
            }
            else {
              iVar9 = (*(code *)PTR_EVP_PKEY_encrypt_006a7d14)
                                (iVar8,0,&uStack_26c,*(undefined4 *)(iVar5 + 0x10),
                                 *(undefined4 *)(iVar5 + 0x14));
              if (iVar9 < 1) goto LAB_005bcc74;
              iVar9 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uStack_26c,"cms_env.c",0x140);
              if (iVar9 == 0) {
                iVar5 = 0;
                (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x8d,0x41,"cms_env.c",0x143);
              }
              else {
                iVar5 = (*(code *)PTR_EVP_PKEY_encrypt_006a7d14)
                                  (iVar8,iVar9,&uStack_26c,*(undefined4 *)(iVar5 + 0x10),
                                   *(undefined4 *)(iVar5 + 0x14));
                if (iVar5 < 1) {
                  (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar8);
                  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar9);
                  goto LAB_005bccb0;
                }
                iVar5 = 1;
                (*(code *)PTR_ASN1_STRING_set0_006a9144)
                          (*(undefined4 *)(iVar7 + 0xc),iVar9,uStack_26c);
              }
            }
          }
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar8);
          goto LAB_005bca1c;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7d,0x9a,"cms_env.c",0x314);
        goto LAB_005bc980;
      }
      iVar5 = cms_RecipientInfo_pwri_crypt(iVar3,piVar6,1);
LAB_005bca1c:
      if (iVar5 < 1) goto LAB_005bccb0;
    }
    *(undefined4 *)(iVar11 + 0xc) = 0;
    if (*(int *)(iVar11 + 0x10) != 0) goto LAB_005bcdc8;
  }
LAB_005bc9c8:
  while (iStack_174 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005bcdc8:
    (*(code *)PTR_OPENSSL_cleanse_006a7074)();
    (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(iVar11 + 0x10));
    *(undefined4 *)(iVar11 + 0x10) = 0;
    *(undefined4 *)(iVar11 + 0x14) = 0;
    iVar2 = iVar4;
  }
  return iVar2;
}

