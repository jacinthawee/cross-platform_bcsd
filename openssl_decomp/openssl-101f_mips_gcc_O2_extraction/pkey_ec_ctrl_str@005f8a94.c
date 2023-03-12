
undefined4 pkey_ec_ctrl_str(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_strcmp_006aac20)(param_2,"ec_paramgen_curve");
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_OBJ_sn2nid_006a82a4)(param_3);
    if (iVar1 == 0) {
      iVar1 = (*(code *)PTR_OBJ_ln2nid_006aa7ec)(param_3);
      if (iVar1 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xc6,0x8d,"ec_pmeth.c",0x104);
        return 0;
      }
    }
    uVar2 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(param_1,0x198,2,0x1001,iVar1,0);
  }
  else {
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}

