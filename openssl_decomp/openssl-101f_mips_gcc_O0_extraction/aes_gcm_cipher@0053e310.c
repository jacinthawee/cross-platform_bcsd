
/* WARNING: Type propagation algorithm not settling */

uint aes_gcm_cipher(EVP_CIPHER_CTX *param_1,void *param_2,void *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  uchar *puVar6;
  code *pcVar7;
  
  pvVar4 = param_1->cipher_data;
  if (*(int *)((int)pvVar4 + 0xf4) == 0) {
    return 0xffffffff;
  }
  if (*(int *)((int)pvVar4 + 0x288) < 0) {
    if (*(int *)((int)pvVar4 + 0xf8) == 0) {
      return 0xffffffff;
    }
    if (param_3 == (void *)0x0) {
      if (param_1->encrypt != 0) {
        (*(code *)PTR_CRYPTO_gcm128_tag_006a9b44)((int)pvVar4 + 0x100,param_1->buf,0x10);
        *(undefined4 *)((int)pvVar4 + 0xf8) = 0;
        *(undefined4 *)((int)pvVar4 + 0x280) = 0x10;
        return 0;
      }
      if (-1 < *(int *)((int)pvVar4 + 0x280)) {
        uVar3 = (*(code *)PTR_CRYPTO_gcm128_finish_006a9b48)((int)pvVar4 + 0x100,param_1->buf);
        if (uVar3 == 0) {
          *(undefined4 *)((int)pvVar4 + 0xf8) = 0;
          return 0;
        }
        return 0xffffffff;
      }
      return 0xffffffff;
    }
    if (param_2 == (void *)0x0) {
      iVar1 = (*(code *)PTR_CRYPTO_gcm128_aad_006a8b98)((int)pvVar4 + 0x100,param_3,param_4);
    }
    else {
      if (param_1->encrypt == 0) {
        pcVar7 = (code *)PTR_CRYPTO_gcm128_decrypt_006a9b4c;
        if (*(int *)((int)pvVar4 + 0x28c) != 0) {
          iVar1 = (*(code *)PTR_CRYPTO_gcm128_decrypt_ctr32_006a9b40)
                            ((int)pvVar4 + 0x100,param_3,param_2,param_4,
                             *(int *)((int)pvVar4 + 0x28c));
          goto joined_r0x0053e510;
        }
      }
      else {
        pcVar7 = (code *)PTR_CRYPTO_gcm128_encrypt_006a9b50;
        if (*(int *)((int)pvVar4 + 0x28c) != 0) {
          iVar1 = (*(code *)PTR_CRYPTO_gcm128_encrypt_ctr32_006a9b3c)
                            ((int)pvVar4 + 0x100,param_3,param_2,param_4,
                             *(int *)((int)pvVar4 + 0x28c));
          goto joined_r0x0053e510;
        }
      }
      iVar1 = (*pcVar7)((int)pvVar4 + 0x100,param_3,param_2);
    }
joined_r0x0053e510:
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    return param_4;
  }
  if (param_2 != param_3) {
    return 0xffffffff;
  }
  if (param_4 < 0x18) {
    return 0xffffffff;
  }
  iVar1 = 0x18;
  if (param_1->encrypt != 0) {
    iVar1 = 0x13;
  }
  iVar1 = EVP_CIPHER_CTX_ctrl(param_1,iVar1,8,param_2);
  if (0 < iVar1) {
    iVar5 = (int)pvVar4 + 0x100;
    puVar6 = param_1->buf;
    iVar1 = (*(code *)PTR_CRYPTO_gcm128_aad_006a8b98)
                      (iVar5,puVar6,*(undefined4 *)((int)pvVar4 + 0x288));
    if (iVar1 == 0) {
      iVar1 = (int)param_2 + 8;
      uVar3 = param_4 - 0x18;
      if (param_1->encrypt == 0) {
        if (*(int *)((int)pvVar4 + 0x28c) == 0) {
          iVar2 = (*(code *)PTR_CRYPTO_gcm128_decrypt_006a9b4c)(iVar5,iVar1,iVar1,uVar3);
        }
        else {
          iVar2 = (*(code *)PTR_CRYPTO_gcm128_decrypt_ctr32_006a9b40)
                            (iVar5,iVar1,iVar1,uVar3,*(int *)((int)pvVar4 + 0x28c));
        }
        if (iVar2 == 0) {
          (*(code *)PTR_CRYPTO_gcm128_tag_006a9b44)(iVar5,puVar6,0x10);
          iVar5 = (*(code *)PTR_memcmp_006aabd8)(puVar6,iVar1 + uVar3,0x10);
          if (iVar5 == 0) goto LAB_0053e4c0;
          (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar1,uVar3);
        }
      }
      else {
        if (*(int *)((int)pvVar4 + 0x28c) == 0) {
          iVar2 = (*(code *)PTR_CRYPTO_gcm128_encrypt_006a9b50)(iVar5,iVar1,iVar1,uVar3);
        }
        else {
          iVar2 = (*(code *)PTR_CRYPTO_gcm128_encrypt_ctr32_006a9b3c)
                            (iVar5,iVar1,iVar1,uVar3,*(int *)((int)pvVar4 + 0x28c));
        }
        if (iVar2 == 0) {
          (*(code *)PTR_CRYPTO_gcm128_tag_006a9b44)(iVar5,iVar1 + uVar3,0x10);
          uVar3 = param_4;
          goto LAB_0053e4c0;
        }
      }
    }
  }
  uVar3 = 0xffffffff;
LAB_0053e4c0:
  *(undefined4 *)((int)pvVar4 + 0xf8) = 0;
  *(undefined4 *)((int)pvVar4 + 0x288) = 0xffffffff;
  return uVar3;
}

