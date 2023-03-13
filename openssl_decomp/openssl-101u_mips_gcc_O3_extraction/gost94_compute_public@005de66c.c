
undefined4 gost94_compute_public(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar1 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_GOST_error_006a95e4)(0x6e,0x41,"gost_sign.c",0xee);
      uVar3 = 0;
    }
    else {
      iVar2 = (*(code *)PTR_BN_new_006a71b4)();
      *(int *)(param_1 + 0x18) = iVar2;
      if (iVar2 == 0) {
        (*(code *)PTR_ERR_GOST_error_006a95e4)(0x6e,0x41,"gost_sign.c",0xf4);
        (*(code *)PTR_BN_CTX_free_006a7954)(iVar1);
        uVar3 = 0;
      }
      else {
        (*(code *)PTR_BN_mod_exp_006a795c)
                  (iVar2,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x1c),
                   *(undefined4 *)(param_1 + 0xc),iVar1);
        (*(code *)PTR_BN_CTX_free_006a7954)(iVar1);
        uVar3 = 1;
      }
    }
    return uVar3;
  }
  (*(code *)PTR_ERR_GOST_error_006a95e4)(0x6e,0x71,"gost_sign.c",0xe9);
  return 0;
}

