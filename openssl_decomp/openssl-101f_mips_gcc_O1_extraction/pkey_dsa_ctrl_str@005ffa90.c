
undefined4 pkey_dsa_ctrl_str(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = (*(code *)PTR_strcmp_006aac20)(param_2,"dsa_paramgen_bits");
  if (iVar1 == 0) {
    uVar2 = (*(code *)PTR_strtol_006aaa68)(param_3,0,10);
    uVar3 = 0x1001;
  }
  else {
    iVar1 = (*(code *)PTR_strcmp_006aac20)(param_2,"dsa_paramgen_q_bits");
    if (iVar1 != 0) {
      iVar1 = (*(code *)PTR_strcmp_006aac20)(param_2,"dsa_paramgen_md");
      if (iVar1 == 0) {
        uVar2 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(param_3);
        uVar2 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(param_1,0x74,2,0x1003,0,uVar2);
      }
      else {
        uVar2 = 0xfffffffe;
      }
      return uVar2;
    }
    uVar2 = (*(code *)PTR_strtol_006aaa68)(param_3,0,10);
    uVar3 = 0x1002;
  }
  uVar2 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(param_1,0x74,2,uVar3,uVar2,0);
  return uVar2;
}

