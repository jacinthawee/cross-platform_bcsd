
int aes_ccm_cipher(int param_1,int param_2,int param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined auStack_34 [16];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar6 = *(int *)(param_1 + 0x60);
  iVar7 = iVar6 + 0x110;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar5 = param_3;
  if ((*(int *)(iVar6 + 0xf8) == 0) && (iVar2 = -1, *(int *)(iVar6 + 0xf4) == 0)) goto LAB_0053b890;
  iVar3 = *(int *)(param_1 + 8);
  iVar4 = param_2;
  if ((iVar3 != 0) || (*(int *)(iVar6 + 0xfc) != 0)) {
    iVar2 = param_4;
    if (param_2 == 0) {
      if (param_3 == 0) {
        param_2 = param_1 + 0x20;
        iVar5 = 0xf - *(int *)(iVar6 + 0x104);
        iVar7 = (*(code *)PTR_CRYPTO_ccm128_setiv_006a8a4c)(iVar7,param_2,iVar5,param_4);
        iVar4 = param_2;
        if (iVar7 == 0) {
          *(undefined4 *)(iVar6 + 0x100) = 1;
          goto LAB_0053b890;
        }
      }
      else if ((*(int *)(iVar6 + 0x100) != 0) || (iVar5 = 0xf, param_4 == 0)) {
        iVar5 = param_4;
        (*(code *)PTR_CRYPTO_ccm128_aad_006a8a50)(iVar7);
        param_2 = param_3;
        goto LAB_0053b890;
      }
    }
    else {
      iVar2 = 0;
      if (param_3 == 0) goto LAB_0053b890;
      if (*(int *)(iVar6 + 0x100) == 0) {
        iVar4 = param_1 + 0x20;
        iVar5 = 0xf - *(int *)(iVar6 + 0x104);
        iVar2 = (*(code *)PTR_CRYPTO_ccm128_setiv_006a8a4c)(iVar7,iVar4,iVar5,param_4);
        if (iVar2 != 0) goto LAB_0053b8d0;
        iVar3 = *(int *)(param_1 + 8);
        *(undefined4 *)(iVar6 + 0x100) = 1;
      }
      iVar2 = *(int *)(iVar6 + 0x140);
      if (iVar3 == 0) {
        iVar5 = param_2;
        if (iVar2 == 0) {
          iVar2 = (*(code *)PTR_CRYPTO_ccm128_decrypt_006a8a58)(iVar7,param_3,param_2,param_4);
        }
        else {
          iVar2 = (*(code *)PTR_CRYPTO_ccm128_decrypt_ccm64_006a8a48)
                            (iVar7,param_3,param_2,param_4,iVar2);
        }
        if (iVar2 == 0) {
          iVar5 = *(int *)(iVar6 + 0x108);
          iVar7 = (*(code *)PTR_CRYPTO_ccm128_tag_006a8a40)(iVar7,auStack_34);
          if (iVar7 == 0) goto LAB_0053b90c;
          param_1 = param_1 + 0x30;
          iVar5 = *(int *)(iVar6 + 0x108);
          iVar7 = (*(code *)PTR_CRYPTO_memcmp_006a8128)(auStack_34);
          if ((iVar7 != 0) || (param_4 == -1)) goto LAB_0053b90c;
        }
        else {
LAB_0053b90c:
          param_1 = param_4;
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(param_2);
          param_4 = -1;
        }
        *(undefined4 *)(iVar6 + 0xf8) = 0;
        *(undefined4 *)(iVar6 + 0xfc) = 0;
        *(undefined4 *)(iVar6 + 0x100) = 0;
        iVar2 = param_4;
        param_2 = param_1;
        goto LAB_0053b890;
      }
      if (iVar2 == 0) {
        iVar7 = (*(code *)PTR_CRYPTO_ccm128_encrypt_006a8a54)(iVar7,param_3,param_2,param_4);
        iVar5 = param_2;
      }
      else {
        iVar7 = (*(code *)PTR_CRYPTO_ccm128_encrypt_ccm64_006a8a44)
                          (iVar7,param_3,param_2,param_4,iVar2);
        iVar5 = param_2;
      }
      iVar4 = param_3;
      if (iVar7 == 0) {
        *(undefined4 *)(iVar6 + 0xfc) = 1;
        iVar2 = param_4;
        param_2 = param_3;
        goto LAB_0053b890;
      }
    }
  }
LAB_0053b8d0:
  iVar2 = -1;
  param_2 = iVar4;
LAB_0053b890:
  if (local_24 == *(int *)puVar1) {
    return iVar2;
  }
  iVar6 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar7 = *(int *)(iVar6 + 0x60);
  if (iVar5 == 0) {
    if (param_2 != 0) {
      (*(code *)PTR_AES_set_encrypt_key_006a79ec)(param_2,*(int *)(iVar6 + 0x58) << 3,iVar7);
      (*(code *)PTR_CRYPTO_ccm128_init_006a8a5c)
                (iVar7 + 0x110,*(undefined4 *)(iVar7 + 0x108),*(undefined4 *)(iVar7 + 0x104),iVar7,
                 PTR_AES_encrypt_006a7ac0);
      *(undefined4 *)(iVar7 + 0xf4) = 1;
      *(undefined4 *)(iVar7 + 0x140) = 0;
      return 1;
    }
  }
  else {
    if (param_2 != 0) {
      (*(code *)PTR_AES_set_encrypt_key_006a79ec)(param_2,*(int *)(iVar6 + 0x58) << 3,iVar7);
      (*(code *)PTR_CRYPTO_ccm128_init_006a8a5c)
                (iVar7 + 0x110,*(undefined4 *)(iVar7 + 0x108),*(undefined4 *)(iVar7 + 0x104),iVar7,
                 PTR_AES_encrypt_006a7ac0);
      *(undefined4 *)(iVar7 + 0x140) = 0;
      *(undefined4 *)(iVar7 + 0xf4) = 1;
    }
    (*(code *)PTR_memcpy_006a9aec)(iVar6 + 0x20,iVar5,0xf - *(int *)(iVar7 + 0x104));
    *(undefined4 *)(iVar7 + 0xf8) = 1;
  }
  return 1;
}

