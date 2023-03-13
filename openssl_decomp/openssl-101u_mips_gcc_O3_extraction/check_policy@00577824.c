
uint check_policy(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x7c) != 0) {
    return 1;
  }
  iVar1 = (*(code *)PTR_X509_policy_check_006a8ee8)
                    (param_1 + 0x58,param_1 + 0x5c,*(undefined4 *)(param_1 + 0x54),
                     *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x1c),
                     *(undefined4 *)(*(int *)(param_1 + 0x14) + 0xc));
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x91,0x41,"x509_vfy.c",0x631);
    uVar2 = 0;
    *(undefined4 *)(param_1 + 100) = 0x11;
  }
  else if (iVar1 == -1) {
    iVar1 = 1;
    do {
      do {
        iVar3 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(param_1 + 0x54));
        if (iVar3 <= iVar1) goto LAB_005778b0;
        iVar4 = iVar1 + 1;
        iVar3 = (*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(param_1 + 0x54),iVar1);
        iVar1 = iVar4;
      } while ((*(uint *)(iVar3 + 0x28) & 0x800) == 0);
      *(int *)(param_1 + 0x68) = iVar3;
      *(undefined4 *)(param_1 + 100) = 0x2a;
      uVar2 = (**(code **)(param_1 + 0x20))(0,param_1);
    } while (uVar2 != 0);
  }
  else {
    if (iVar1 == -2) {
      *(undefined4 *)(param_1 + 0x68) = 0;
      *(undefined4 *)(param_1 + 100) = 0x2b;
                    /* WARNING: Could not recover jumptable at 0x005779a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(param_1 + 0x20))(0,param_1);
      return uVar2;
    }
    if ((*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 0x800) == 0) {
LAB_005778b0:
      uVar2 = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x68) = 0;
      iVar1 = (**(code **)(param_1 + 0x20))(2,param_1);
      uVar2 = (uint)(iVar1 != 0);
    }
  }
  return uVar2;
}

