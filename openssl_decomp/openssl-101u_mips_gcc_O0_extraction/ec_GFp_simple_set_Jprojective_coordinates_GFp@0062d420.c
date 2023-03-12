
undefined4
ec_GFp_simple_set_Jprojective_coordinates_GFp
          (int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  
  iVar4 = 0;
  if ((param_6 == 0) &&
     (param_6 = (*(code *)PTR_BN_CTX_new_006a794c)(), iVar4 = param_6, param_6 == 0)) {
    return 0;
  }
  if (param_3 == 0) {
LAB_0062d4f4:
    if (param_4 != 0) {
      iVar5 = param_2 + 0x18;
      iVar1 = (*(code *)PTR_BN_nnmod_006a8548)(iVar5,param_4,param_1 + 0x12,param_6);
      if ((iVar1 == 0) ||
         ((*(code **)(*param_1 + 0x90) != (code *)0x0 &&
          (iVar1 = (**(code **)(*param_1 + 0x90))(param_1,iVar5,iVar5,param_6), iVar1 == 0))))
      goto LAB_0062d4b4;
    }
    if (param_5 == 0) {
      uVar3 = 1;
      goto joined_r0x0062d598;
    }
    iVar5 = param_2 + 0x2c;
    iVar1 = (*(code *)PTR_BN_nnmod_006a8548)(iVar5,param_5,param_1 + 0x12,param_6);
    if (iVar1 != 0) {
      if (((*(int *)(param_2 + 0x30) == 1) && (**(int **)(param_2 + 0x2c) == 1)) &&
         (*(int *)(param_2 + 0x38) == 0)) {
        pcVar2 = *(code **)(*param_1 + 0x90);
        uVar3 = 1;
        if (pcVar2 != (code *)0x0) {
          pcVar6 = *(code **)(*param_1 + 0x98);
          if (pcVar6 == (code *)0x0) goto LAB_0062d5f4;
          iVar1 = (*pcVar6)(param_1,iVar5,param_6);
          if (iVar1 == 0) goto LAB_0062d4b4;
        }
        *(undefined4 *)(param_2 + 0x40) = 1;
      }
      else {
        pcVar2 = *(code **)(*param_1 + 0x90);
        uVar3 = 0;
        if (pcVar2 != (code *)0x0) {
LAB_0062d5f4:
          iVar1 = (*pcVar2)(param_1,iVar5,iVar5,param_6);
          if (iVar1 == 0) {
            uVar3 = 0;
            goto joined_r0x0062d598;
          }
        }
        *(undefined4 *)(param_2 + 0x40) = uVar3;
      }
      uVar3 = 1;
      goto joined_r0x0062d598;
    }
  }
  else {
    iVar5 = param_2 + 4;
    iVar1 = (*(code *)PTR_BN_nnmod_006a8548)(iVar5,param_3,param_1 + 0x12,param_6);
    if ((iVar1 != 0) &&
       ((*(code **)(*param_1 + 0x90) == (code *)0x0 ||
        (iVar1 = (**(code **)(*param_1 + 0x90))(param_1,iVar5,iVar5,param_6), iVar1 != 0))))
    goto LAB_0062d4f4;
  }
LAB_0062d4b4:
  uVar3 = 0;
joined_r0x0062d598:
  if (iVar4 != 0) {
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar4);
    return uVar3;
  }
  return uVar3;
}

