
undefined4
ec_GF2m_simple_points_make_affine(int *param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == 0) {
    return 1;
  }
  iVar3 = 0;
  do {
    uVar2 = *param_3;
    iVar3 = iVar3 + 1;
    param_3 = param_3 + 1;
    iVar1 = (**(code **)(*param_1 + 0x70))(param_1,uVar2,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  } while (param_2 != iVar3);
  return 1;
}

