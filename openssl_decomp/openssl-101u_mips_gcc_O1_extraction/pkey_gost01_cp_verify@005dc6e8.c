
undefined4
pkey_gost01_cp_verify
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006a95d4)();
  iVar2 = unpack_cp_signature(param_2,param_3);
  if (iVar2 != 0) {
    if (iVar1 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(iVar1);
      uVar3 = (*(code *)PTR_gost2001_do_verify_006a95ec)(param_4,param_5,iVar2,uVar3);
    }
    (*(code *)PTR_DSA_SIG_free_006a8758)(iVar2);
    return uVar3;
  }
  return 0;
}

