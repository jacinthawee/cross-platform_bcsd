
int added_obj_LHASH_COMP(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = *param_1;
  if (iVar1 - *param_2 != 0) {
    return iVar1 - *param_2;
  }
  piVar2 = (int *)param_1[1];
  piVar3 = (int *)param_2[1];
  if (iVar1 == 1) {
    if (*piVar2 == 0) {
      return -1;
    }
    if (*piVar3 == 0) {
      return 1;
    }
LAB_004c2308:
    iVar1 = (*(code *)PTR_strcmp_006a9b18)();
    return iVar1;
  }
  if (iVar1 < 2) {
    if (iVar1 == 0) {
      if (piVar2[3] - piVar3[3] != 0) {
        return piVar2[3] - piVar3[3];
      }
                    /* WARNING: Could not recover jumptable at 0x004c2350. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*(code *)PTR_memcmp_006a9ad0)(piVar2[4],piVar3[4]);
      return iVar1;
    }
  }
  else {
    if (iVar1 == 2) {
      if (piVar2[1] == 0) {
        return -1;
      }
      if (piVar3[1] == 0) {
        return 1;
      }
      goto LAB_004c2308;
    }
    if (iVar1 == 3) {
      return piVar2[2] - piVar3[2];
    }
  }
  return 0;
}

