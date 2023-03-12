
void aes_ccm_cipher(int param_1,void *param_2,size_t param_3,size_t param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined auStack_34 [16];
  int local_24;
  
  iVar5 = *(int *)(param_1 + 0x60);
  iVar6 = iVar5 + 0x110;
  local_24 = __TMC_END__;
  if (((*(int *)(iVar5 + 0xf8) != 0) || (*(int *)(iVar5 + 0xf4) != 0)) &&
     ((iVar3 = *(int *)(param_1 + 8), iVar3 != 0 || (*(int *)(iVar5 + 0xfc) != 0)))) {
    if (param_2 == (void *)0x0) {
      if (param_3 == 0) {
        iVar6 = CRYPTO_ccm128_setiv(iVar6,param_1 + 0x20,0xf - *(int *)(iVar5 + 0x104),param_4);
        if (iVar6 == 0) {
          *(undefined4 *)(iVar5 + 0x100) = 1;
          param_3 = param_4;
          goto LAB_000acd26;
        }
      }
      else if ((*(int *)(iVar5 + 0x100) != 0) || (param_4 == 0)) {
        CRYPTO_ccm128_aad(iVar6,param_3,param_4);
        param_3 = param_4;
        goto LAB_000acd26;
      }
    }
    else {
      if (param_3 == 0) goto LAB_000acd26;
      if (*(int *)(iVar5 + 0x100) == 0) {
        iVar3 = CRYPTO_ccm128_setiv(iVar6,param_1 + 0x20,0xf - *(int *)(iVar5 + 0x104),param_4);
        if (iVar3 != 0) goto LAB_000acd3e;
        iVar3 = *(int *)(param_1 + 8);
        *(undefined4 *)(iVar5 + 0x100) = 1;
      }
      iVar4 = *(int *)(iVar5 + 0x140);
      if (iVar3 == 0) {
        if (iVar4 == 0) {
          uVar1 = CRYPTO_ccm128_decrypt(iVar6,param_3,param_2,param_4);
          uVar2 = count_leading_zeroes(uVar1);
        }
        else {
          uVar1 = CRYPTO_ccm128_decrypt_ccm64(iVar6,param_3,param_2,param_4,iVar4);
          uVar2 = count_leading_zeroes(uVar1);
        }
        if ((((uVar2 >> 5 == 0) ||
             (iVar6 = CRYPTO_ccm128_tag(iVar6,auStack_34,*(undefined4 *)(iVar5 + 0x108)), iVar6 == 0
             )) || (iVar6 = memcmp(auStack_34,(void *)(param_1 + 0x30),*(size_t *)(iVar5 + 0x108)),
                   iVar6 != 0)) || (param_4 == 0xffffffff)) {
          OPENSSL_cleanse(param_2,param_4);
          param_4 = 0xffffffff;
        }
        *(undefined4 *)(iVar5 + 0xf8) = 0;
        *(undefined4 *)(iVar5 + 0xfc) = 0;
        *(undefined4 *)(iVar5 + 0x100) = 0;
        param_3 = param_4;
        goto LAB_000acd26;
      }
      if (iVar4 == 0) {
        iVar6 = CRYPTO_ccm128_encrypt(iVar6,param_3,param_2,param_4);
        if (iVar6 != 0) {
          iVar6 = 1;
        }
      }
      else {
        iVar6 = CRYPTO_ccm128_encrypt_ccm64(iVar6,param_3,param_2,param_4,iVar4);
        if (iVar6 != 0) {
          iVar6 = 1;
        }
      }
      if (iVar6 == 0) {
        *(undefined4 *)(iVar5 + 0xfc) = 1;
        param_3 = param_4;
        goto LAB_000acd26;
      }
    }
  }
LAB_000acd3e:
  param_3 = 0xffffffff;
LAB_000acd26:
  if (local_24 != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_3);
  }
  return;
}

