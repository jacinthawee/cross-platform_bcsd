
undefined4
ec_GF2m_simple_points_make_affine(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 != 0) {
    do {
      iVar1 = (**(code **)(*param_1 + 0x70))(param_1,*(undefined4 *)(param_3 + iVar2 * 4),param_4);
      if (iVar1 == 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (param_2 != iVar2);
  }
  return 1;
}

