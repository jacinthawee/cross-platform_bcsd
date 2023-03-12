
undefined4 gost_sign_keygen(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = (*(code *)PTR_BN_new_006a82b4)();
  puVar1 = PTR_BN_rand_range_006a97b0;
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  (*(code *)puVar1)(uVar2,*(undefined4 *)(param_1 + 0x10));
  uVar2 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (*(int *)(param_1 + 0x14) != 0) {
    uVar3 = (*(code *)PTR_BN_new_006a82b4)();
    puVar1 = PTR_BN_mod_exp_006a8a48;
    *(undefined4 *)(param_1 + 0x18) = uVar3;
    (*(code *)puVar1)(uVar3,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x1c),
                      *(undefined4 *)(param_1 + 0xc),uVar2);
    (*(code *)PTR_BN_CTX_free_006a8a40)(uVar2);
    return 1;
  }
  (*(code *)PTR_ERR_GOST_error_006aa6f0)(0x6e,0x71,"gost_sign.c",200);
  return 0;
}

