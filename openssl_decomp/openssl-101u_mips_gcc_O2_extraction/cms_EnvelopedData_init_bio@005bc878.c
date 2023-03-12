
int cms_EnvelopedData_init_bio(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 local_124;
  undefined auStack_120 [244];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar10 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  iVar2 = cms_EncryptedContent_init_bio(iVar10);
  iVar5 = iVar2;
  if (iVar2 == 0) {
    iVar5 = 0;
  }
  else if (*(int *)(iVar10 + 0xc) != 0) {
    uVar11 = *(undefined4 *)(*(int *)(param_1 + 4) + 8);
    for (iVar9 = 0; iVar3 = (*(code *)PTR_sk_num_006a6e2c)(uVar11), iVar9 < iVar3; iVar9 = iVar9 + 1
        ) {
      piVar4 = (int *)(*(code *)PTR_sk_value_006a6e24)(uVar11,iVar9);
      iVar3 = *piVar4;
      if (iVar3 == 2) {
        iVar6 = piVar4[1];
        iVar3 = *(int *)(*(int *)(param_1 + 4) + 0xc);
        if (*(int *)(iVar6 + 0x10) != 0) {
          iVar7 = (*(code *)PTR_AES_set_encrypt_key_006a79ec)
                            (*(int *)(iVar6 + 0x10),*(int *)(iVar6 + 0x14) << 3,auStack_120);
          if (iVar7 == 0) {
            iVar7 = (*(code *)PTR_CRYPTO_malloc_006a7008)
                              (*(int *)(iVar3 + 0x14) + 8,"cms_env.c",0x274);
            if (iVar7 == 0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x88,0x41,"cms_env.c",0x277);
              goto LAB_005bcafc;
            }
            iVar8 = (*(code *)PTR_AES_wrap_key_006a93e4)
                              (auStack_120,0,iVar7,*(undefined4 *)(iVar3 + 0x10),
                               *(undefined4 *)(iVar3 + 0x14));
            if (iVar8 < 1) {
              iVar3 = 0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x88,0x9f,"cms_env.c",0x27e);
              (*(code *)PTR_CRYPTO_free_006a6e88)(iVar7);
            }
            else {
              iVar3 = 1;
              (*(code *)PTR_ASN1_STRING_set0_006a9144)(*(undefined4 *)(iVar6 + 0xc),iVar7,iVar8);
            }
          }
          else {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x88,0x73,"cms_env.c",0x270);
LAB_005bcafc:
            iVar3 = 0;
          }
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_120,0xf4);
          goto LAB_005bca1c;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x88,0x82,"cms_env.c",0x26a);
LAB_005bccb0:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7d,0x74,"cms_env.c",0x31a);
LAB_005bc980:
        *(undefined4 *)(iVar10 + 0xc) = 0;
        if (*(int *)(iVar10 + 0x10) != 0) {
          (*(code *)PTR_OPENSSL_cleanse_006a7074)
                    (*(int *)(iVar10 + 0x10),*(undefined4 *)(iVar10 + 0x14));
          (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(iVar10 + 0x10));
          *(undefined4 *)(iVar10 + 0x10) = 0;
          *(undefined4 *)(iVar10 + 0x14) = 0;
        }
        (*(code *)PTR_BIO_free_006a6e70)(iVar2);
        iVar5 = 0;
        goto LAB_005bc9c8;
      }
      if (iVar3 != 3) {
        if (iVar3 == 0) {
          iVar6 = piVar4[1];
          iVar3 = *(int *)(*(int *)(param_1 + 4) + 0xc);
          iVar7 = (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(*(undefined4 *)(iVar6 + 0x14),0);
          if (iVar7 == 0) goto LAB_005bccb0;
          iVar8 = (*(code *)PTR_EVP_PKEY_encrypt_init_006a7cec)(iVar7);
          if (iVar8 < 1) {
LAB_005bcc74:
            iVar3 = 0;
          }
          else {
            iVar8 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(iVar7,0xffffffff,0x100,9,0,piVar4);
            if (iVar8 < 1) {
              iVar3 = 0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x8d,0x6e,"cms_env.c",0x139);
            }
            else {
              iVar8 = (*(code *)PTR_EVP_PKEY_encrypt_006a7d14)
                                (iVar7,0,&local_124,*(undefined4 *)(iVar3 + 0x10),
                                 *(undefined4 *)(iVar3 + 0x14));
              if (iVar8 < 1) goto LAB_005bcc74;
              iVar8 = (*(code *)PTR_CRYPTO_malloc_006a7008)(local_124,"cms_env.c",0x140);
              if (iVar8 == 0) {
                iVar3 = 0;
                (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x8d,0x41,"cms_env.c",0x143);
              }
              else {
                iVar3 = (*(code *)PTR_EVP_PKEY_encrypt_006a7d14)
                                  (iVar7,iVar8,&local_124,*(undefined4 *)(iVar3 + 0x10),
                                   *(undefined4 *)(iVar3 + 0x14));
                if (iVar3 < 1) {
                  (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar7);
                  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar8);
                  goto LAB_005bccb0;
                }
                iVar3 = 1;
                (*(code *)PTR_ASN1_STRING_set0_006a9144)
                          (*(undefined4 *)(iVar6 + 0xc),iVar8,local_124);
              }
            }
          }
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar7);
          goto LAB_005bca1c;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7d,0x9a,"cms_env.c",0x314);
        goto LAB_005bc980;
      }
      iVar3 = cms_RecipientInfo_pwri_crypt(param_1,piVar4,1);
LAB_005bca1c:
      if (iVar3 < 1) goto LAB_005bccb0;
    }
    *(undefined4 *)(iVar10 + 0xc) = 0;
    if (*(int *)(iVar10 + 0x10) != 0) goto LAB_005bcdc8;
  }
LAB_005bc9c8:
  while (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005bcdc8:
    (*(code *)PTR_OPENSSL_cleanse_006a7074)();
    (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(iVar10 + 0x10));
    *(undefined4 *)(iVar10 + 0x10) = 0;
    *(undefined4 *)(iVar10 + 0x14) = 0;
    iVar5 = iVar2;
  }
  return iVar5;
}

