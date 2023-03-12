
void ssl3_cleanup_key_block(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if (*(int *)(iVar1 + 0x378) != 0) {
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(*(int *)(iVar1 + 0x378),*(undefined4 *)(iVar1 + 0x374));
    (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x378));
    iVar1 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iVar1 + 0x378) = 0;
    *(undefined4 *)(iVar1 + 0x374) = 0;
    return;
  }
  *(undefined4 *)(iVar1 + 0x374) = 0;
  return;
}

