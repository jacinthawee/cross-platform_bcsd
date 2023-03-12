
/* WARNING: Removing unreachable block (ram,0x005017d0) */
/* WARNING: Removing unreachable block (ram,0x005017e4) */
/* WARNING: Removing unreachable block (ram,0x005017bc) */

void bn_sqr_comba4(undefined4 *param_1,uint *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  lVar1 = (ulonglong)*param_2 * (ulonglong)*param_2;
  *param_1 = (int)lVar1;
  uVar9 = (uint)((ulonglong)param_2[1] * (ulonglong)*param_2);
  uVar8 = (uint)((ulonglong)param_2[1] * (ulonglong)*param_2 >> 0x20);
  uVar5 = uVar9 * 2;
  uVar6 = (uint)(uVar5 < uVar9) + uVar8 * 2;
  iVar7 = 1;
  if (uVar8 <= uVar6) {
    if (uVar6 == uVar8) {
      if (uVar9 <= uVar5) {
        iVar7 = 0;
      }
    }
    else {
      iVar7 = 0;
    }
  }
  uVar8 = uVar5 + (int)((ulonglong)lVar1 >> 0x20);
  param_1[1] = uVar8;
  if ((uVar8 < uVar5) && (uVar6 = uVar6 + 1, uVar6 == 0)) {
    iVar7 = iVar7 + 1;
    lVar1 = (ulonglong)param_2[1] * (ulonglong)param_2[1];
  }
  else {
    lVar1 = (ulonglong)param_2[1] * (ulonglong)param_2[1] + (ulonglong)uVar6;
  }
  uVar6 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar5 = uVar6 + iVar7;
  uVar2 = (ulonglong)param_2[2] * (ulonglong)*param_2;
  uVar8 = (uint)uVar2 * 2;
  uVar9 = (uint)(uVar8 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  uVar6 = (uint)(uVar5 < uVar6);
  if (CONCAT44(uVar9,uVar8) < uVar2) {
    uVar6 = uVar6 + 1;
  }
  uVar4 = uVar8 + (int)lVar1;
  if ((uVar4 < uVar8) && (uVar9 = uVar9 + 1, uVar9 == 0)) {
    uVar6 = uVar6 + 1;
  }
  else {
    uVar5 = uVar5 + uVar9;
    uVar6 = uVar6 + (uVar5 < uVar9);
  }
  param_1[2] = uVar4;
  uVar10 = (uint)((ulonglong)param_2[3] * (ulonglong)*param_2);
  uVar4 = (uint)((ulonglong)param_2[3] * (ulonglong)*param_2 >> 0x20);
  uVar9 = uVar10 * 2;
  uVar8 = (uint)(uVar9 < uVar10) + uVar4 * 2;
  iVar7 = 1;
  if (uVar4 <= uVar8) {
    if (uVar8 == uVar4) {
      if (uVar10 <= uVar9) {
        iVar7 = 0;
      }
    }
    else {
      iVar7 = 0;
    }
  }
  if ((uVar9 + uVar5 < uVar9) && (uVar8 = uVar8 + 1, uVar8 == 0)) {
    iVar7 = iVar7 + 1;
  }
  else {
    uVar6 = uVar6 + uVar8;
    iVar7 = iVar7 + (uint)(uVar6 < uVar8);
  }
  uVar2 = (ulonglong)param_2[2] * (ulonglong)param_2[1];
  uVar4 = (uint)uVar2 * 2;
  uVar8 = (uint)(uVar4 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar8,uVar4) < uVar2) {
    iVar7 = iVar7 + 1;
  }
  uVar5 = uVar9 + uVar5 + uVar4;
  if ((uVar5 < uVar4) && (uVar8 = uVar8 + 1, uVar8 == 0)) {
    iVar7 = iVar7 + 1;
  }
  else {
    uVar6 = uVar6 + uVar8;
    iVar7 = iVar7 + (uint)(uVar6 < uVar8);
  }
  param_1[3] = uVar5;
  uVar2 = (ulonglong)param_2[3] * (ulonglong)param_2[1];
  lVar1 = (ulonglong)param_2[2] * (ulonglong)param_2[2] + (ulonglong)uVar6;
  uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar9 = (uint)uVar2 * 2;
  uVar8 = (uint)(uVar9 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  uVar6 = uVar5 + iVar7;
  uVar5 = (uint)(uVar6 < uVar5);
  if (CONCAT44(uVar8,uVar9) < uVar2) {
    uVar5 = uVar5 + 1;
  }
  uVar4 = (int)lVar1 + uVar9;
  if ((uVar4 < uVar9) && (uVar8 = uVar8 + 1, uVar8 == 0)) {
    iVar7 = uVar5 + 1;
  }
  else {
    uVar6 = uVar6 + uVar8;
    iVar7 = uVar5 + (uVar6 < uVar8);
  }
  param_1[4] = uVar4;
  uVar4 = (uint)((ulonglong)param_2[3] * (ulonglong)param_2[2]);
  uVar9 = (uint)((ulonglong)param_2[3] * (ulonglong)param_2[2] >> 0x20);
  uVar8 = uVar4 * 2;
  uVar5 = (uint)(uVar8 < uVar4) + uVar9 * 2;
  iVar3 = 1;
  if (uVar9 <= uVar5) {
    if (uVar5 == uVar9) {
      if (uVar4 <= uVar8) {
        iVar3 = 0;
      }
    }
    else {
      iVar3 = 0;
    }
  }
  uVar6 = uVar8 + uVar6;
  if (uVar6 < uVar8) {
    uVar5 = uVar5 + 1;
    if (uVar5 == 0) {
      param_1[5] = uVar6;
      lVar1 = (ulonglong)param_2[3] * (ulonglong)param_2[3] + CONCAT44(iVar3 + 1,iVar7);
      param_1[6] = (int)lVar1;
      param_1[7] = (int)((ulonglong)lVar1 >> 0x20);
      return;
    }
  }
  param_1[5] = uVar6;
  lVar1 = (ulonglong)param_2[3] * (ulonglong)param_2[3] +
          CONCAT44(iVar3 + (uint)(iVar7 + uVar5 < uVar5),iVar7 + uVar5);
  param_1[6] = (int)lVar1;
  param_1[7] = (int)((ulonglong)lVar1 >> 0x20);
  return;
}

