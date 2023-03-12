
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar10 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  iVar2 = cms_EncryptedContent_init_bio(iVar10);
  iVar5 = iVar2;
  if (iVar2 == 0) {
    iVar5 = 0;
  }
  else if (*(int *)(iVar10 + 0xc) != 0) {
    uVar11 = *(undefined4 *)(*(int *)(param_1 + 4) + 8);
    for (iVar9 = 0; iVar3 = (*(code *)PTR_sk_num_006a7f2c)(uVar11), iVar9 < iVar3; iVar9 = iVar9 + 1
        ) {
      piVar4 = (int *)(*(code *)PTR_sk_value_006a7f24)(uVar11,iVar9);
      iVar3 = *piVar4;
      if (iVar3 == 2) {
        iVar6 = piVar4[1];
        iVar3 = *(int *)(*(int *)(param_1 + 4) + 0xc);
        if (*(int *)(iVar6 + 0x10) != 0) {
          iVar7 = (*(code *)PTR_AES_set_encrypt_key_006a8adc)
                            (*(int *)(iVar6 + 0x10),*(int *)(iVar6 + 0x14) << 3,auStack_120);
          if (iVar7 == 0) {
            iVar7 = (*(code *)PTR_CRYPTO_malloc_006a8108)
                              (*(int *)(iVar3 + 0x14) + 8,"cms_env.c",0x2a2);
            if (iVar7 == 0) {
              (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x88,0x41,"cms_env.c",0x2a7);
              goto LAB_005bf46c;
            }
            iVar8 = (*(code *)PTR_AES_wrap_key_006aa4f0)
                              (auStack_120,0,iVar7,*(undefined4 *)(iVar3 + 0x10),
                               *(undefined4 *)(iVar3 + 0x14));
            if (iVar8 < 1) {
              iVar3 = 0;
              (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x88,0x9f,"cms_env.c",0x2af);
              (*(code *)PTR_CRYPTO_free_006a7f88)(iVar7);
            }
            else {
              iVar3 = 1;
              (*(code *)PTR_ASN1_STRING_set0_006aa260)(*(undefined4 *)(iVar6 + 0xc),iVar7,iVar8);
            }
          }
          else {
            (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x88,0x73,"cms_env.c",0x29e);
LAB_005bf46c:
            iVar3 = 0;
          }
          (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_120,0xf4);
          goto LAB_005bf38c;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x88,0x82,"cms_env.c",0x297);
LAB_005bf620:
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x7d,0x74,"cms_env.c",0x357);
LAB_005bf2f0:
        *(undefined4 *)(iVar10 + 0xc) = 0;
        if (*(int *)(iVar10 + 0x10) != 0) {
          (*(code *)PTR_OPENSSL_cleanse_006a8174)
                    (*(int *)(iVar10 + 0x10),*(undefined4 *)(iVar10 + 0x14));
          (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar10 + 0x10));
          *(undefined4 *)(iVar10 + 0x10) = 0;
          *(undefined4 *)(iVar10 + 0x14) = 0;
        }
        (*(code *)PTR_BIO_free_006a7f70)(iVar2);
        iVar5 = 0;
        goto LAB_005bf338;
      }
      if (iVar3 != 3) {
        if (iVar3 == 0) {
          iVar6 = piVar4[1];
          iVar3 = *(int *)(*(int *)(param_1 + 4) + 0xc);
          iVar7 = (*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(*(undefined4 *)(iVar6 + 0x14),0);
          if (iVar7 == 0) goto LAB_005bf620;
          iVar8 = (*(code *)PTR_EVP_PKEY_encrypt_init_006a8ddc)(iVar7);
          if (iVar8 < 1) {
LAB_005bf5e4:
            iVar3 = 0;
          }
          else {
            iVar8 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(iVar7,0xffffffff,0x100,9,0,piVar4);
            if (iVar8 < 1) {
              iVar3 = 0;
              (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x8d,0x6e,"cms_env.c",0x14a);
            }
            else {
              iVar8 = (*(code *)PTR_EVP_PKEY_encrypt_006a8e04)
                                (iVar7,0,&local_124,*(undefined4 *)(iVar3 + 0x10),
                                 *(undefined4 *)(iVar3 + 0x14));
              if (iVar8 < 1) goto LAB_005bf5e4;
              iVar8 = (*(code *)PTR_CRYPTO_malloc_006a8108)(local_124,"cms_env.c",0x151);
              if (iVar8 == 0) {
                iVar3 = 0;
                (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x8d,0x41,"cms_env.c",0x156);
              }
              else {
                iVar3 = (*(code *)PTR_EVP_PKEY_encrypt_006a8e04)
                                  (iVar7,iVar8,&local_124,*(undefined4 *)(iVar3 + 0x10),
                                   *(undefined4 *)(iVar3 + 0x14));
                if (iVar3 < 1) {
                  (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(iVar7);
                  (*(code *)PTR_CRYPTO_free_006a7f88)(iVar8);
                  goto LAB_005bf620;
                }
                iVar3 = 1;
                (*(code *)PTR_ASN1_STRING_set0_006aa260)
                          (*(undefined4 *)(iVar6 + 0xc),iVar8,local_124);
              }
            }
          }
          (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(iVar7);
          goto LAB_005bf38c;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x7d,0x9a,"cms_env.c",0x350);
        goto LAB_005bf2f0;
      }
      iVar3 = cms_RecipientInfo_pwri_crypt(param_1,piVar4,1);
LAB_005bf38c:
      if (iVar3 < 1) goto LAB_005bf620;
    }
    *(undefined4 *)(iVar10 + 0xc) = 0;
    if (*(int *)(iVar10 + 0x10) != 0) goto LAB_005bf738;
  }
LAB_005bf338:
  while (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005bf738:
    (*(code *)PTR_OPENSSL_cleanse_006a8174)();
    (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar10 + 0x10));
    *(undefined4 *)(iVar10 + 0x10) = 0;
    *(undefined4 *)(iVar10 + 0x14) = 0;
    iVar5 = iVar2;
  }
  return iVar5;
}

