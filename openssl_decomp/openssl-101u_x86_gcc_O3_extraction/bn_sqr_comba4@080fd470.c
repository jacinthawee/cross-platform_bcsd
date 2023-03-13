
/* WARNING: Removing unreachable block (ram,0x080fd6d0) */
/* WARNING: Removing unreachable block (ram,0x080fd710) */
/* WARNING: Removing unreachable block (ram,0x080fd6b8) */

void bn_sqr_comba4(undefined4 *param_1,uint *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  uint local_20;
  int local_1c;
  
  uVar8 = 1;
  lVar1 = (ulonglong)*param_2 * (ulonglong)*param_2;
  *param_1 = (int)lVar1;
  uVar5 = (uint)((ulonglong)*param_2 * (ulonglong)param_2[1] >> 0x20);
  uVar3 = (uint)((ulonglong)*param_2 * (ulonglong)param_2[1]);
  uVar6 = uVar5 << 1 | uVar3 >> 0x1f;
  uVar4 = uVar3 * 2;
  if (uVar5 <= uVar6) {
    if (uVar5 < uVar6) {
      uVar8 = 0;
    }
    else if (uVar3 <= uVar4) {
      uVar8 = 0;
    }
  }
  local_20 = (uint)((ulonglong)lVar1 >> 0x20);
  if ((CARRY4(uVar4,local_20)) && (uVar6 = uVar6 + 1, uVar6 == 0)) {
    uVar8 = uVar8 + 1;
    param_1[1] = uVar4 + local_20;
    lVar1 = (ulonglong)param_2[1] * (ulonglong)param_2[1];
  }
  else {
    param_1[1] = uVar4 + local_20;
    lVar1 = (ulonglong)param_2[1] * (ulonglong)param_2[1] + (ulonglong)uVar6;
  }
  uVar3 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar4 = uVar3 + uVar8;
  uVar6 = (uint)CARRY4(uVar3,uVar8);
  uVar2 = (ulonglong)*param_2 * (ulonglong)param_2[2];
  uVar5 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar3 = (uint)uVar2 * 2;
  if (CONCAT44(uVar5,uVar3) < uVar2) {
    uVar6 = uVar6 + 1;
  }
  if ((CARRY4((uint)lVar1,uVar3)) && (uVar5 = uVar5 + 1, uVar5 == 0)) {
    uVar6 = uVar6 + 1;
  }
  else {
    bVar11 = CARRY4(uVar4,uVar5);
    uVar4 = uVar4 + uVar5;
    uVar6 = uVar6 + bVar11;
  }
  iVar9 = 1;
  param_1[2] = (uint)lVar1 + uVar3;
  uVar8 = (uint)((ulonglong)*param_2 * (ulonglong)param_2[3] >> 0x20);
  uVar5 = (uint)((ulonglong)*param_2 * (ulonglong)param_2[3]);
  uVar7 = uVar8 << 1 | uVar5 >> 0x1f;
  uVar3 = uVar5 * 2;
  if (uVar8 <= uVar7) {
    if (uVar8 < uVar7) {
      iVar9 = 0;
    }
    else if (uVar5 <= uVar3) {
      iVar9 = 0;
    }
  }
  if (CARRY4(uVar3,uVar4)) {
    uVar7 = uVar7 + 1;
    iVar10 = iVar9 + 1;
    if (uVar7 == 0) goto LAB_080fd567;
  }
  bVar11 = CARRY4(uVar6,uVar7);
  uVar6 = uVar6 + uVar7;
  iVar10 = iVar9 + 1;
  if (!bVar11) {
    iVar10 = iVar9;
  }
LAB_080fd567:
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[2];
  uVar8 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar5 = (uint)uVar2 * 2;
  if (CONCAT44(uVar8,uVar5) < uVar2) {
    iVar10 = iVar10 + 1;
  }
  if ((CARRY4(uVar3 + uVar4,uVar5)) && (uVar8 = uVar8 + 1, uVar8 == 0)) {
    uVar8 = iVar10 + 1;
  }
  else {
    bVar11 = CARRY4(uVar6,uVar8);
    uVar6 = uVar6 + uVar8;
    uVar8 = iVar10 + (uint)bVar11;
  }
  param_1[3] = uVar3 + uVar4 + uVar5;
  lVar1 = (ulonglong)param_2[2] * (ulonglong)param_2[2] + (ulonglong)uVar6;
  uVar7 = (uint)lVar1;
  uVar3 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar4 = uVar3 + uVar8;
  uVar5 = (uint)CARRY4(uVar3,uVar8);
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[3];
  uVar6 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar3 = (uint)uVar2 * 2;
  if (CONCAT44(uVar6,uVar3) < uVar2) {
    uVar5 = uVar5 + 1;
  }
  if ((CARRY4(uVar7,uVar3)) && (uVar6 = uVar6 + 1, uVar6 == 0)) {
    uVar5 = uVar5 + 1;
  }
  else {
    bVar11 = CARRY4(uVar4,uVar6);
    uVar4 = uVar4 + uVar6;
    uVar5 = uVar5 + bVar11;
  }
  local_1c = 1;
  param_1[4] = uVar7 + uVar3;
  uVar8 = (uint)((ulonglong)param_2[2] * (ulonglong)param_2[3] >> 0x20);
  uVar6 = (uint)((ulonglong)param_2[2] * (ulonglong)param_2[3]);
  uVar7 = uVar8 << 1 | uVar6 >> 0x1f;
  uVar3 = uVar6 * 2;
  if (uVar8 <= uVar7) {
    if (uVar8 < uVar7) {
      local_1c = 0;
    }
    else if (uVar6 <= uVar3) {
      local_1c = 0;
    }
  }
  if ((CARRY4(uVar4,uVar3)) && (uVar7 = uVar7 + 1, uVar7 == 0)) {
    local_1c = local_1c + 1;
  }
  else {
    bVar11 = CARRY4(uVar5,uVar7);
    uVar5 = uVar5 + uVar7;
    if (bVar11) {
      local_1c = local_1c + 1;
    }
  }
  param_1[5] = uVar4 + uVar3;
  *(ulonglong *)(param_1 + 6) =
       (ulonglong)param_2[3] * (ulonglong)param_2[3] + CONCAT44(local_1c,uVar5);
  return;
}

