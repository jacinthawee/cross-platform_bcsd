
undefined4 pkey_dh_ctrl_str(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = (*(code *)PTR_strcmp_006a9b18)(param_2,"dh_paramgen_prime_len");
  if (iVar1 == 0) {
    uVar2 = (*(code *)PTR_strtol_006a9958)(param_3,0,10);
    uVar3 = 0x1001;
  }
  else {
    iVar1 = (*(code *)PTR_strcmp_006a9b18)(param_2,"dh_paramgen_generator");
    if (iVar1 != 0) {
      return 0xfffffffe;
    }
    uVar2 = (*(code *)PTR_strtol_006a9958)(param_3,0,10);
    uVar3 = 0x1002;
  }
  uVar2 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(param_1,0x1c,2,uVar3,uVar2,0);
  return uVar2;
}

