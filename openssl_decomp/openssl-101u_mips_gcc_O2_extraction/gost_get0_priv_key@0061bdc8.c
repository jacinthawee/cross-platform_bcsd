
undefined4 gost_get0_priv_key(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
  if (iVar1 == 0x32b) {
    iVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_1);
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0061be60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar1);
      return uVar2;
    }
  }
  else if ((iVar1 == 0x32c) && (iVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_1), iVar1 != 0))
  {
    return *(undefined4 *)(iVar1 + 0x1c);
  }
  return 0;
}

