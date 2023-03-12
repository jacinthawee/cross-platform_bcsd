
undefined4
SSL_set_srp_server_param_pw(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = (*(code *)PTR_SRP_get_default_gN_006a901c)(param_4);
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = (*(code *)PTR_BN_dup_006a9100)(*(undefined4 *)(iVar2 + 8));
    puVar1 = PTR_BN_dup_006a9100;
    uVar4 = *(undefined4 *)(iVar2 + 4);
    *(undefined4 *)(param_1 + 0x1a8) = uVar3;
    uVar3 = (*(code *)puVar1)(uVar4);
    *(undefined4 *)(param_1 + 0x1ac) = uVar3;
    if (*(int *)(param_1 + 0x1c4) != 0) {
      (*(code *)PTR_BN_clear_free_006a9130)();
      *(undefined4 *)(param_1 + 0x1c4) = 0;
    }
    if (*(int *)(param_1 + 0x1b0) != 0) {
      (*(code *)PTR_BN_clear_free_006a9130)();
      *(undefined4 *)(param_1 + 0x1b0) = 0;
    }
    iVar2 = (*(code *)PTR_SRP_create_verifier_BN_006a956c)
                      (param_2,param_3,param_1 + 0x1b0,param_1 + 0x1c4,*(undefined4 *)(iVar2 + 8),
                       *(undefined4 *)(iVar2 + 4));
    uVar3 = 0xffffffff;
    if (iVar2 != 0) {
      uVar3 = 1;
    }
  }
  return uVar3;
}

