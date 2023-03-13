
undefined4 aes_ctr_cipher(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int in_GS_OFFSET;
  undefined4 local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = *(undefined4 *)(param_1 + 0x50);
  iVar1 = *(int *)(param_1 + 0x60);
  if (*(int *)(iVar1 + 0xf8) == 0) {
    CRYPTO_ctr128_encrypt
              (param_3,param_2,param_4,iVar1,param_1 + 0x20,param_1 + 0x30,&local_14,
               *(undefined4 *)(iVar1 + 0xf4));
  }
  else {
    CRYPTO_ctr128_encrypt_ctr32
              (param_3,param_2,param_4,iVar1,param_1 + 0x20,param_1 + 0x30,&local_14,
               *(int *)(iVar1 + 0xf8));
  }
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  *(undefined4 *)(param_1 + 0x50) = local_14;
  if (local_10 == iVar1) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

