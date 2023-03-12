
size_t aes_ccm_cipher(int param_1,void *param_2,int param_3,size_t param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_GS_OFFSET;
  undefined local_30 [16];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = *(int *)(param_1 + 0x60);
  iVar3 = iVar1 + 0x10c;
  if (((*(int *)(iVar1 + 0xf8) != 0) || (*(int *)(iVar1 + 0xf4) != 0)) &&
     ((iVar4 = *(int *)(param_1 + 8), iVar4 != 0 || (*(int *)(iVar1 + 0xfc) != 0)))) {
    if (param_2 == (void *)0x0) {
      if (param_3 == 0) {
        iVar3 = CRYPTO_ccm128_setiv(iVar3,param_1 + 0x20,0xf - *(int *)(iVar1 + 0x104),param_4);
        if (iVar3 == 0) {
          *(undefined4 *)(iVar1 + 0x100) = 1;
          goto LAB_0812ed21;
        }
      }
      else if ((*(int *)(iVar1 + 0x100) != 0) || (param_4 == 0)) {
        CRYPTO_ccm128_aad(iVar3,param_3,param_4);
        goto LAB_0812ed21;
      }
    }
    else {
      if (param_3 == 0) {
        param_4 = 0;
        goto LAB_0812ed21;
      }
      if (*(int *)(iVar1 + 0x100) == 0) {
        iVar4 = CRYPTO_ccm128_setiv(iVar3,param_1 + 0x20,0xf - *(int *)(iVar1 + 0x104),param_4);
        if (iVar4 != 0) goto LAB_0812ed4e;
        *(undefined4 *)(iVar1 + 0x100) = 1;
        iVar4 = *(int *)(param_1 + 8);
      }
      iVar2 = *(int *)(iVar1 + 0x13c);
      if (iVar4 == 0) {
        if (iVar2 == 0) {
          iVar4 = CRYPTO_ccm128_decrypt(iVar3,param_3,param_2,param_4);
        }
        else {
          iVar4 = CRYPTO_ccm128_decrypt_ccm64(iVar3,param_3,param_2,param_4,iVar2);
        }
        if (iVar4 == 0) {
          iVar3 = CRYPTO_ccm128_tag(iVar3,local_30,*(undefined4 *)(iVar1 + 0x108));
          if (((iVar3 == 0) ||
              (iVar3 = memcmp(local_30,(void *)(param_1 + 0x30),*(size_t *)(iVar1 + 0x108)),
              iVar3 != 0)) || (param_4 == 0xffffffff)) goto LAB_0812ed80;
        }
        else {
LAB_0812ed80:
          OPENSSL_cleanse(param_2,param_4);
          param_4 = 0xffffffff;
        }
        *(undefined4 *)(iVar1 + 0xf8) = 0;
        *(undefined4 *)(iVar1 + 0xfc) = 0;
        *(undefined4 *)(iVar1 + 0x100) = 0;
        goto LAB_0812ed21;
      }
      if (iVar2 == 0) {
        iVar3 = CRYPTO_ccm128_encrypt(iVar3,param_3,param_2,param_4);
      }
      else {
        iVar3 = CRYPTO_ccm128_encrypt_ccm64(iVar3,param_3,param_2,param_4,iVar2);
      }
      if (iVar3 == 0) {
        *(undefined4 *)(iVar1 + 0xfc) = 1;
        goto LAB_0812ed21;
      }
    }
  }
LAB_0812ed4e:
  param_4 = 0xffffffff;
LAB_0812ed21:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}

