
undefined4
SSL_set_srp_server_param
          (int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 != 0) {
    if (*(int *)(param_1 + 0x1a8) == 0) {
      uVar2 = (*(code *)PTR_BN_dup_006a8218)(param_2);
      *(undefined4 *)(param_1 + 0x1a8) = uVar2;
    }
    else {
      iVar1 = (*(code *)PTR_BN_copy_006a8450)();
      if (iVar1 == 0) {
        (*(code *)PTR_BN_free_006a701c)(*(undefined4 *)(param_1 + 0x1a8));
        *(undefined4 *)(param_1 + 0x1a8) = 0;
      }
    }
  }
  if (param_3 != 0) {
    if (*(int *)(param_1 + 0x1ac) == 0) {
      uVar2 = (*(code *)PTR_BN_dup_006a8218)(param_3);
      *(undefined4 *)(param_1 + 0x1ac) = uVar2;
    }
    else {
      iVar1 = (*(code *)PTR_BN_copy_006a8450)(*(int *)(param_1 + 0x1ac),param_3);
      if (iVar1 == 0) {
        (*(code *)PTR_BN_free_006a701c)(*(undefined4 *)(param_1 + 0x1ac));
        *(undefined4 *)(param_1 + 0x1ac) = 0;
      }
    }
  }
  if (param_4 != 0) {
    if (*(int *)(param_1 + 0x1b0) == 0) {
      uVar2 = (*(code *)PTR_BN_dup_006a8218)(param_4);
      *(undefined4 *)(param_1 + 0x1b0) = uVar2;
    }
    else {
      iVar1 = (*(code *)PTR_BN_copy_006a8450)(*(int *)(param_1 + 0x1b0),param_4);
      if (iVar1 == 0) {
        (*(code *)PTR_BN_free_006a701c)(*(undefined4 *)(param_1 + 0x1b0));
        *(undefined4 *)(param_1 + 0x1b0) = 0;
      }
    }
  }
  if (param_5 != 0) {
    if (*(int *)(param_1 + 0x1c4) == 0) {
      uVar2 = (*(code *)PTR_BN_dup_006a8218)(param_5);
      *(undefined4 *)(param_1 + 0x1c4) = uVar2;
    }
    else {
      iVar1 = (*(code *)PTR_BN_copy_006a8450)(*(int *)(param_1 + 0x1c4),param_5);
      if (iVar1 == 0) {
        (*(code *)PTR_BN_free_006a701c)(*(undefined4 *)(param_1 + 0x1c4));
        *(undefined4 *)(param_1 + 0x1c4) = 0;
      }
    }
  }
  *(undefined4 *)(param_1 + 0x1c8) = param_6;
  if (*(int *)(param_1 + 0x1a8) != 0) {
    if (*(int *)(param_1 + 0x1ac) == 0) {
      return 0xffffffff;
    }
    if (*(int *)(param_1 + 0x1b0) != 0) {
      if (*(int *)(param_1 + 0x1c4) != 0) {
        return 1;
      }
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

