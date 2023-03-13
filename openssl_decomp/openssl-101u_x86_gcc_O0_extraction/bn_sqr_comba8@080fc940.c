
/* WARNING: Removing unreachable block (ram,0x080fd190) */
/* WARNING: Removing unreachable block (ram,0x080fd2c0) */
/* WARNING: Removing unreachable block (ram,0x080fd1c0) */
/* WARNING: Removing unreachable block (ram,0x080fd1f0) */
/* WARNING: Removing unreachable block (ram,0x080fd230) */
/* WARNING: Removing unreachable block (ram,0x080fd398) */
/* WARNING: Removing unreachable block (ram,0x080fd3e0) */
/* WARNING: Removing unreachable block (ram,0x080fd420) */
/* WARNING: Removing unreachable block (ram,0x080fd310) */
/* WARNING: Removing unreachable block (ram,0x080fd350) */
/* WARNING: Removing unreachable block (ram,0x080fd140) */
/* WARNING: Removing unreachable block (ram,0x080fd330) */
/* WARNING: Removing unreachable block (ram,0x080fd440) */
/* WARNING: Removing unreachable block (ram,0x080fd400) */
/* WARNING: Removing unreachable block (ram,0x080fd3c0) */
/* WARNING: Removing unreachable block (ram,0x080fd250) */
/* WARNING: Removing unreachable block (ram,0x080fd210) */
/* WARNING: Removing unreachable block (ram,0x080fd2f0) */
/* WARNING: Removing unreachable block (ram,0x080fd2e0) */
/* WARNING: Removing unreachable block (ram,0x080fd2a0) */
/* WARNING: Removing unreachable block (ram,0x080fd170) */

void bn_sqr_comba8(undefined4 *param_1,uint *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  uint local_24;
  int local_1c;
  
  lVar1 = (ulonglong)*param_2 * (ulonglong)*param_2;
  uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
  *param_1 = (int)lVar1;
  uVar8 = 1;
  uVar6 = (uint)((ulonglong)*param_2 * (ulonglong)param_2[1] >> 0x20);
  uVar3 = (uint)((ulonglong)*param_2 * (ulonglong)param_2[1]);
  uVar7 = uVar6 << 1 | uVar3 >> 0x1f;
  uVar9 = uVar3 * 2;
  if (uVar6 <= uVar7) {
    if (uVar6 < uVar7) {
      uVar8 = 0;
    }
    else if (uVar3 <= uVar9) {
      uVar8 = 0;
    }
  }
  iVar4 = uVar9 + uVar5;
  if ((CARRY4(uVar9,uVar5)) && (uVar7 = uVar7 + 1, uVar7 == 0)) {
    uVar8 = uVar8 + 1;
    param_1[1] = iVar4;
    lVar1 = (ulonglong)param_2[1] * (ulonglong)param_2[1];
  }
  else {
    param_1[1] = iVar4;
    lVar1 = (ulonglong)param_2[1] * (ulonglong)param_2[1] + (ulonglong)uVar7;
  }
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  local_24 = uVar9 + uVar8;
  uVar5 = (uint)CARRY4(uVar9,uVar8);
  uVar2 = (ulonglong)*param_2 * (ulonglong)param_2[2];
  uVar3 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    uVar5 = uVar5 + 1;
  }
  if ((CARRY4((uint)lVar1,uVar9)) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    uVar5 = uVar5 + 1;
  }
  else {
    bVar11 = CARRY4(local_24,uVar3);
    local_24 = local_24 + uVar3;
    uVar5 = uVar5 + bVar11;
  }
  iVar4 = 1;
  param_1[2] = (uint)lVar1 + uVar9;
  uVar6 = (uint)((ulonglong)*param_2 * (ulonglong)param_2[3] >> 0x20);
  uVar3 = (uint)((ulonglong)*param_2 * (ulonglong)param_2[3]);
  uVar7 = uVar6 << 1 | uVar3 >> 0x1f;
  uVar9 = uVar3 * 2;
  if (uVar6 <= uVar7) {
    if (uVar6 < uVar7) {
      iVar4 = 0;
    }
    else if (uVar3 <= uVar9) {
      iVar4 = 0;
    }
  }
  if (CARRY4(uVar9,local_24)) {
    uVar7 = uVar7 + 1;
    iVar10 = iVar4 + 1;
    if (uVar7 == 0) goto LAB_080fca37;
  }
  bVar11 = CARRY4(uVar5,uVar7);
  uVar5 = uVar5 + uVar7;
  iVar10 = iVar4 + 1;
  if (!bVar11) {
    iVar10 = iVar4;
  }
LAB_080fca37:
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[2];
  uVar6 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar3 = (uint)uVar2 * 2;
  if (CONCAT44(uVar6,uVar3) < uVar2) {
    iVar10 = iVar10 + 1;
  }
  if ((CARRY4(uVar9 + local_24,uVar3)) && (uVar6 = uVar6 + 1, uVar6 == 0)) {
    uVar6 = iVar10 + 1;
  }
  else {
    bVar11 = CARRY4(uVar5,uVar6);
    uVar5 = uVar5 + uVar6;
    uVar6 = iVar10 + (uint)bVar11;
  }
  param_1[3] = uVar9 + local_24 + uVar3;
  lVar1 = (ulonglong)param_2[2] * (ulonglong)param_2[2] + (ulonglong)uVar5;
  uVar3 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar7 = uVar9 + uVar6;
  local_24 = (uint)CARRY4(uVar9,uVar6);
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[3];
  uVar5 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar5,uVar9) < uVar2) {
    local_24 = local_24 + 1;
  }
  uVar6 = uVar9 + uVar3;
  if ((CARRY4(uVar9,uVar3)) && (uVar5 = uVar5 + 1, uVar5 == 0)) {
    local_24 = local_24 + 1;
  }
  else {
    bVar11 = CARRY4(uVar7,uVar5);
    uVar7 = uVar7 + uVar5;
    local_24 = local_24 + bVar11;
  }
  uVar2 = (ulonglong)*param_2 * (ulonglong)param_2[4];
  uVar3 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    local_24 = local_24 + 1;
  }
  if ((CARRY4(uVar6,uVar9)) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    local_24 = local_24 + 1;
  }
  else {
    bVar11 = CARRY4(uVar7,uVar3);
    uVar7 = uVar7 + uVar3;
    local_24 = local_24 + bVar11;
  }
  iVar4 = 1;
  param_1[4] = uVar6 + uVar9;
  uVar5 = (uint)((ulonglong)*param_2 * (ulonglong)param_2[5] >> 0x20);
  uVar3 = (uint)((ulonglong)*param_2 * (ulonglong)param_2[5]);
  uVar6 = uVar5 << 1 | uVar3 >> 0x1f;
  uVar9 = uVar3 * 2;
  if (uVar5 <= uVar6) {
    if (uVar5 < uVar6) {
      iVar4 = 0;
    }
    else if (uVar3 <= uVar9) {
      iVar4 = 0;
    }
  }
  if ((CARRY4(uVar9,uVar7)) && (uVar6 = uVar6 + 1, uVar6 == 0)) {
    iVar10 = iVar4 + 1;
  }
  else {
    bVar11 = CARRY4(local_24,uVar6);
    local_24 = local_24 + uVar6;
    iVar10 = iVar4 + 1;
    if (!bVar11) {
      iVar10 = iVar4;
    }
  }
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[4];
  uVar5 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar3 = (uint)uVar2 * 2;
  if (CONCAT44(uVar5,uVar3) < uVar2) {
    iVar10 = iVar10 + 1;
  }
  uVar6 = uVar9 + uVar7 + uVar3;
  if ((CARRY4(uVar9 + uVar7,uVar3)) && (uVar5 = uVar5 + 1, uVar5 == 0)) {
    iVar10 = iVar10 + 1;
  }
  else {
    bVar11 = CARRY4(local_24,uVar5);
    local_24 = local_24 + uVar5;
    iVar10 = iVar10 + (uint)bVar11;
  }
  uVar2 = (ulonglong)param_2[2] * (ulonglong)param_2[3];
  uVar3 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    iVar10 = iVar10 + 1;
  }
  if ((CARRY4(uVar6,uVar9)) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    uVar3 = iVar10 + 1;
  }
  else {
    bVar11 = CARRY4(local_24,uVar3);
    local_24 = local_24 + uVar3;
    uVar3 = iVar10 + (uint)bVar11;
  }
  param_1[5] = uVar6 + uVar9;
  lVar1 = (ulonglong)param_2[3] * (ulonglong)param_2[3] + (ulonglong)local_24;
  uVar5 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar7 = uVar9 + uVar3;
  uVar6 = (uint)CARRY4(uVar9,uVar3);
  uVar2 = (ulonglong)param_2[2] * (ulonglong)param_2[4];
  uVar3 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    uVar6 = uVar6 + 1;
  }
  uVar8 = uVar9 + uVar5;
  if ((CARRY4(uVar9,uVar5)) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    iVar4 = uVar6 + 1;
  }
  else {
    bVar11 = CARRY4(uVar7,uVar3);
    uVar7 = uVar7 + uVar3;
    iVar4 = uVar6 + bVar11;
  }
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[5];
  uVar3 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    iVar4 = iVar4 + 1;
  }
  uVar5 = uVar9 + uVar8;
  if ((CARRY4(uVar9,uVar8)) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    iVar4 = iVar4 + 1;
  }
  else {
    bVar11 = CARRY4(uVar7,uVar3);
    uVar7 = uVar7 + uVar3;
    iVar4 = iVar4 + (uint)bVar11;
  }
  uVar2 = (ulonglong)*param_2 * (ulonglong)param_2[6];
  uVar3 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    iVar4 = iVar4 + 1;
  }
  if ((CARRY4(uVar5,uVar9)) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    uVar3 = iVar4 + 1;
  }
  else {
    bVar11 = CARRY4(uVar7,uVar3);
    uVar7 = uVar7 + uVar3;
    uVar3 = iVar4 + (uint)bVar11;
  }
  local_24 = 1;
  param_1[6] = uVar5 + uVar9;
  uVar6 = (uint)((ulonglong)*param_2 * (ulonglong)param_2[7] >> 0x20);
  uVar5 = (uint)((ulonglong)*param_2 * (ulonglong)param_2[7]);
  uVar8 = uVar6 << 1 | uVar5 >> 0x1f;
  uVar9 = uVar5 * 2;
  if (uVar6 <= uVar8) {
    if (uVar6 < uVar8) {
      local_24 = 0;
    }
    else if (uVar5 <= uVar9) {
      local_24 = 0;
    }
  }
  if ((CARRY4(uVar9,uVar7)) && (uVar8 = uVar8 + 1, uVar8 == 0)) {
    iVar4 = local_24 + 1;
  }
  else {
    bVar11 = CARRY4(uVar3,uVar8);
    uVar3 = uVar3 + uVar8;
    iVar4 = local_24 + 1;
    if (!bVar11) {
      iVar4 = local_24;
    }
  }
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[6];
  uVar6 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar5 = (uint)uVar2 * 2;
  if (CONCAT44(uVar6,uVar5) < uVar2) {
    iVar4 = iVar4 + 1;
  }
  uVar8 = uVar5 + uVar9 + uVar7;
  if ((CARRY4(uVar5,uVar9 + uVar7)) && (uVar6 = uVar6 + 1, uVar6 == 0)) {
    iVar4 = iVar4 + 1;
  }
  else {
    bVar11 = CARRY4(uVar3,uVar6);
    uVar3 = uVar3 + uVar6;
    iVar4 = iVar4 + (uint)bVar11;
  }
  uVar2 = (ulonglong)param_2[2] * (ulonglong)param_2[5];
  uVar5 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar5,uVar9) < uVar2) {
    iVar4 = iVar4 + 1;
  }
  uVar6 = uVar9 + uVar8;
  if ((CARRY4(uVar9,uVar8)) && (uVar5 = uVar5 + 1, uVar5 == 0)) {
    iVar4 = iVar4 + 1;
  }
  else {
    bVar11 = CARRY4(uVar3,uVar5);
    uVar3 = uVar3 + uVar5;
    iVar4 = iVar4 + (uint)bVar11;
  }
  uVar2 = (ulonglong)param_2[3] * (ulonglong)param_2[4];
  uVar5 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar5,uVar9) < uVar2) {
    iVar4 = iVar4 + 1;
  }
  if ((CARRY4(uVar6,uVar9)) && (uVar5 = uVar5 + 1, uVar5 == 0)) {
    uVar5 = iVar4 + 1;
  }
  else {
    bVar11 = CARRY4(uVar3,uVar5);
    uVar3 = uVar3 + uVar5;
    uVar5 = iVar4 + (uint)bVar11;
  }
  param_1[7] = uVar6 + uVar9;
  lVar1 = (ulonglong)param_2[4] * (ulonglong)param_2[4] + (ulonglong)uVar3;
  uVar3 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar6 = uVar9 + uVar5;
  local_24 = (uint)CARRY4(uVar9,uVar5);
  uVar2 = (ulonglong)param_2[3] * (ulonglong)param_2[5];
  uVar5 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar5,uVar9) < uVar2) {
    local_24 = local_24 + 1;
  }
  uVar7 = uVar9 + uVar3;
  if ((CARRY4(uVar9,uVar3)) && (uVar5 = uVar5 + 1, uVar5 == 0)) {
    local_24 = local_24 + 1;
  }
  else {
    bVar11 = CARRY4(uVar6,uVar5);
    uVar6 = uVar6 + uVar5;
    local_24 = local_24 + bVar11;
  }
  uVar2 = (ulonglong)param_2[2] * (ulonglong)param_2[6];
  uVar3 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    local_24 = local_24 + 1;
  }
  uVar5 = uVar9 + uVar7;
  if ((CARRY4(uVar9,uVar7)) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    local_24 = local_24 + 1;
  }
  else {
    bVar11 = CARRY4(uVar6,uVar3);
    uVar6 = uVar6 + uVar3;
    local_24 = local_24 + bVar11;
  }
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[7];
  uVar3 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    local_24 = local_24 + 1;
  }
  if ((CARRY4(uVar5,uVar9)) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    local_24 = local_24 + 1;
  }
  else {
    bVar11 = CARRY4(uVar6,uVar3);
    uVar6 = uVar6 + uVar3;
    local_24 = local_24 + bVar11;
  }
  iVar4 = 1;
  param_1[8] = uVar5 + uVar9;
  uVar5 = (uint)((ulonglong)param_2[2] * (ulonglong)param_2[7] >> 0x20);
  uVar3 = (uint)((ulonglong)param_2[2] * (ulonglong)param_2[7]);
  uVar7 = uVar5 << 1 | uVar3 >> 0x1f;
  uVar9 = uVar3 * 2;
  if (uVar5 <= uVar7) {
    if (uVar5 < uVar7) {
      iVar4 = 0;
    }
    else if (uVar3 <= uVar9) {
      iVar4 = 0;
    }
  }
  if ((CARRY4(uVar9,uVar6)) && (uVar7 = uVar7 + 1, uVar7 == 0)) {
    iVar10 = iVar4 + 1;
  }
  else {
    bVar11 = CARRY4(local_24,uVar7);
    local_24 = local_24 + uVar7;
    iVar10 = iVar4 + 1;
    if (!bVar11) {
      iVar10 = iVar4;
    }
  }
  uVar2 = (ulonglong)param_2[3] * (ulonglong)param_2[6];
  uVar5 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar3 = (uint)uVar2 * 2;
  if (CONCAT44(uVar5,uVar3) < uVar2) {
    iVar10 = iVar10 + 1;
  }
  uVar7 = uVar9 + uVar6 + uVar3;
  if ((CARRY4(uVar9 + uVar6,uVar3)) && (uVar5 = uVar5 + 1, uVar5 == 0)) {
    iVar10 = iVar10 + 1;
  }
  else {
    bVar11 = CARRY4(local_24,uVar5);
    local_24 = local_24 + uVar5;
    iVar10 = iVar10 + (uint)bVar11;
  }
  uVar2 = (ulonglong)param_2[4] * (ulonglong)param_2[5];
  uVar3 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    iVar10 = iVar10 + 1;
  }
  if ((CARRY4(uVar7,uVar9)) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    uVar3 = iVar10 + 1;
  }
  else {
    bVar11 = CARRY4(local_24,uVar3);
    local_24 = local_24 + uVar3;
    uVar3 = iVar10 + (uint)bVar11;
  }
  param_1[9] = uVar7 + uVar9;
  lVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[5] + (ulonglong)local_24;
  uVar5 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar7 = uVar9 + uVar3;
  uVar6 = (uint)CARRY4(uVar9,uVar3);
  uVar2 = (ulonglong)param_2[4] * (ulonglong)param_2[6];
  uVar3 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    uVar6 = uVar6 + 1;
  }
  uVar8 = uVar9 + uVar5;
  if ((CARRY4(uVar9,uVar5)) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    iVar4 = uVar6 + 1;
  }
  else {
    bVar11 = CARRY4(uVar7,uVar3);
    uVar7 = uVar7 + uVar3;
    iVar4 = uVar6 + bVar11;
  }
  uVar2 = (ulonglong)param_2[3] * (ulonglong)param_2[7];
  uVar3 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    iVar4 = iVar4 + 1;
  }
  if ((CARRY4(uVar8,uVar9)) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    uVar3 = iVar4 + 1;
  }
  else {
    bVar11 = CARRY4(uVar7,uVar3);
    uVar7 = uVar7 + uVar3;
    uVar3 = iVar4 + (uint)bVar11;
  }
  local_24 = 1;
  param_1[10] = uVar8 + uVar9;
  uVar6 = (uint)((ulonglong)param_2[4] * (ulonglong)param_2[7] >> 0x20);
  uVar5 = (uint)((ulonglong)param_2[4] * (ulonglong)param_2[7]);
  uVar8 = uVar6 << 1 | uVar5 >> 0x1f;
  uVar9 = uVar5 * 2;
  if (uVar6 <= uVar8) {
    if (uVar6 < uVar8) {
      local_24 = 0;
    }
    else if (uVar5 <= uVar9) {
      local_24 = 0;
    }
  }
  if ((CARRY4(uVar9,uVar7)) && (uVar8 = uVar8 + 1, uVar8 == 0)) {
    iVar4 = local_24 + 1;
  }
  else {
    bVar11 = CARRY4(uVar3,uVar8);
    uVar3 = uVar3 + uVar8;
    iVar4 = local_24 + 1;
    if (!bVar11) {
      iVar4 = local_24;
    }
  }
  uVar2 = (ulonglong)param_2[5] * (ulonglong)param_2[6];
  uVar6 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar5 = (uint)uVar2 * 2;
  if (CONCAT44(uVar6,uVar5) < uVar2) {
    iVar4 = iVar4 + 1;
  }
  if ((CARRY4(uVar9 + uVar7,uVar5)) && (uVar6 = uVar6 + 1, uVar6 == 0)) {
    uVar6 = iVar4 + 1;
  }
  else {
    bVar11 = CARRY4(uVar3,uVar6);
    uVar3 = uVar3 + uVar6;
    uVar6 = iVar4 + (uint)bVar11;
  }
  param_1[0xb] = uVar9 + uVar7 + uVar5;
  lVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[6] + (ulonglong)uVar3;
  uVar7 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  local_24 = uVar9 + uVar6;
  uVar3 = (uint)CARRY4(uVar9,uVar6);
  uVar2 = (ulonglong)param_2[5] * (ulonglong)param_2[7];
  uVar5 = (int)(uVar2 >> 0x20) << 1 | (uint)uVar2 >> 0x1f;
  uVar9 = (uint)uVar2 * 2;
  if (CONCAT44(uVar5,uVar9) < uVar2) {
    uVar3 = uVar3 + 1;
  }
  if ((CARRY4(uVar7,uVar9)) && (uVar5 = uVar5 + 1, uVar5 == 0)) {
    uVar3 = uVar3 + 1;
  }
  else {
    bVar11 = CARRY4(local_24,uVar5);
    local_24 = local_24 + uVar5;
    uVar3 = uVar3 + bVar11;
  }
  local_1c = 1;
  param_1[0xc] = uVar7 + uVar9;
  uVar6 = (uint)((ulonglong)param_2[6] * (ulonglong)param_2[7] >> 0x20);
  uVar5 = (uint)((ulonglong)param_2[6] * (ulonglong)param_2[7]);
  uVar7 = uVar6 << 1 | uVar5 >> 0x1f;
  uVar9 = uVar5 * 2;
  if (uVar6 <= uVar7) {
    if (uVar6 < uVar7) {
      local_1c = 0;
    }
    else if (uVar5 <= uVar9) {
      local_1c = 0;
    }
  }
  if ((CARRY4(local_24,uVar9)) && (uVar7 = uVar7 + 1, uVar7 == 0)) {
    local_1c = local_1c + 1;
  }
  else {
    bVar11 = CARRY4(uVar3,uVar7);
    uVar3 = uVar3 + uVar7;
    if (bVar11) {
      local_1c = local_1c + 1;
    }
  }
  param_1[0xd] = local_24 + uVar9;
  *(ulonglong *)(param_1 + 0xe) =
       (ulonglong)param_2[7] * (ulonglong)param_2[7] + CONCAT44(local_1c,uVar3);
  return;
}

