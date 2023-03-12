
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
        (*(code *)PTR_CRYPTO_gcm128_tag_006a8a28)((int)pvVar4 + 0x100,param_1->buf,0x10);
        *(undefined4 *)((int)pvVar4 + 0xf8) = 0;
        *(undefined4 *)((int)pvVar4 + 0x280) = 0x10;
        return 0;
      }
      if (-1 < *(int *)((int)pvVar4 + 0x280)) {
        uVar3 = (*(code *)PTR_CRYPTO_gcm128_finish_006a8a2c)((int)pvVar4 + 0x100,param_1->buf);
        if (uVar3 == 0) {
          *(undefined4 *)((int)pvVar4 + 0xf8) = 0;
          return 0;
        }
        return 0xffffffff;
      }
      return 0xffffffff;
    }
    if (param_2 == (void *)0x0) {
      iVar1 = (*(code *)PTR_CRYPTO_gcm128_aad_006a7ac8)((int)pvVar4 + 0x100,param_3,param_4);
    }
    else {
      if (param_1->encrypt == 0) {
        pcVar7 = (code *)PTR_CRYPTO_gcm128_decrypt_006a8a30;
        if (*(int *)((int)pvVar4 + 0x28c) != 0) {
          iVar1 = (*(code *)PTR_CRYPTO_gcm128_decrypt_ctr32_006a8a24)
                            ((int)pvVar4 + 0x100,param_3,param_2,param_4,
                             *(int *)((int)pvVar4 + 0x28c));
          goto joined_r0x0053b2a8;
        }
      }
      else {
        pcVar7 = (code *)PTR_CRYPTO_gcm128_encrypt_006a8a34;
        if (*(int *)((int)pvVar4 + 0x28c) != 0) {
          iVar1 = (*(code *)PTR_CRYPTO_gcm128_encrypt_ctr32_006a8a20)
                            ((int)pvVar4 + 0x100,param_3,param_2,param_4,
                             *(int *)((int)pvVar4 + 0x28c));
          goto joined_r0x0053b2a8;
        }
      }
      iVar1 = (*pcVar7)((int)pvVar4 + 0x100,param_3,param_2);
    }
joined_r0x0053b2a8:
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
    iVar1 = (*(code *)PTR_CRYPTO_gcm128_aad_006a7ac8)
                      (iVar5,puVar6,*(undefined4 *)((int)pvVar4 + 0x288));
    if (iVar1 == 0) {
      iVar1 = (int)param_2 + 8;
      uVar3 = param_4 - 0x18;
      if (param_1->encrypt == 0) {
        if (*(int *)((int)pvVar4 + 0x28c) == 0) {
          iVar2 = (*(code *)PTR_CRYPTO_gcm128_decrypt_006a8a30)(iVar5,iVar1,iVar1,uVar3);
        }
        else {
          iVar2 = (*(code *)PTR_CRYPTO_gcm128_decrypt_ctr32_006a8a24)
                            (iVar5,iVar1,iVar1,uVar3,*(int *)((int)pvVar4 + 0x28c));
        }
        if (iVar2 == 0) {
          (*(code *)PTR_CRYPTO_gcm128_tag_006a8a28)(iVar5,puVar6,0x10);
          iVar5 = (*(code *)PTR_CRYPTO_memcmp_006a8128)(puVar6,iVar1 + uVar3,0x10);
          if (iVar5 == 0) goto LAB_0053b258;
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar1,uVar3);
        }
      }
      else {
        if (*(int *)((int)pvVar4 + 0x28c) == 0) {
          iVar2 = (*(code *)PTR_CRYPTO_gcm128_encrypt_006a8a34)(iVar5,iVar1,iVar1,uVar3);
        }
        else {
          iVar2 = (*(code *)PTR_CRYPTO_gcm128_encrypt_ctr32_006a8a20)
                            (iVar5,iVar1,iVar1,uVar3,*(int *)((int)pvVar4 + 0x28c));
        }
        if (iVar2 == 0) {
          (*(code *)PTR_CRYPTO_gcm128_tag_006a8a28)(iVar5,iVar1 + uVar3,0x10);
          uVar3 = param_4;
          goto LAB_0053b258;
        }
      }
    }
  }
  uVar3 = 0xffffffff;
LAB_0053b258:
  *(undefined4 *)((int)pvVar4 + 0xf8) = 0;
  *(undefined4 *)((int)pvVar4 + 0x288) = 0xffffffff;
  return uVar3;
}

