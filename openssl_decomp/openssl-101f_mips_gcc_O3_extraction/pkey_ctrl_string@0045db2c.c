
undefined4 pkey_ctrl_string(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  iVar1 = (*(code *)PTR_BUF_strdup_006a80dc)(param_2);
  if (iVar1 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    puVar2 = (undefined *)(*(code *)PTR_strchr_006aab34)(iVar1,0x3a);
    if (puVar2 != (undefined *)0x0) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    uVar3 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_str_006a8d08)(param_1,iVar1,puVar2);
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar1);
  }
  return uVar3;
}

