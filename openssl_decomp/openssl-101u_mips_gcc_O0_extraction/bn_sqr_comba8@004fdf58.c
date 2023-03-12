
/* WARNING: Removing unreachable block (ram,0x004feb34) */
/* WARNING: Removing unreachable block (ram,0x004feb5c) */
/* WARNING: Removing unreachable block (ram,0x004feb84) */
/* WARNING: Removing unreachable block (ram,0x004febac) */
/* WARNING: Removing unreachable block (ram,0x004febd4) */
/* WARNING: Removing unreachable block (ram,0x004febfc) */
/* WARNING: Removing unreachable block (ram,0x004fec24) */
/* WARNING: Removing unreachable block (ram,0x004fec4c) */
/* WARNING: Removing unreachable block (ram,0x004fec74) */
/* WARNING: Removing unreachable block (ram,0x004fec9c) */
/* WARNING: Removing unreachable block (ram,0x004fecb0) */
/* WARNING: Removing unreachable block (ram,0x004fec88) */
/* WARNING: Removing unreachable block (ram,0x004fec60) */
/* WARNING: Removing unreachable block (ram,0x004fec38) */
/* WARNING: Removing unreachable block (ram,0x004fec10) */
/* WARNING: Removing unreachable block (ram,0x004febe8) */
/* WARNING: Removing unreachable block (ram,0x004febc0) */
/* WARNING: Removing unreachable block (ram,0x004feb98) */
/* WARNING: Removing unreachable block (ram,0x004feb70) */
/* WARNING: Removing unreachable block (ram,0x004feb48) */
/* WARNING: Removing unreachable block (ram,0x004feb20) */

void bn_sqr_comba8(undefined4 *param_1,uint *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  lVar1 = (ulonglong)*param_2 * (ulonglong)*param_2;
  *param_1 = (int)lVar1;
  uVar9 = (uint)((ulonglong)param_2[1] * (ulonglong)*param_2);
  uVar8 = (uint)((ulonglong)param_2[1] * (ulonglong)*param_2 >> 0x20);
  uVar4 = uVar9 * 2;
  uVar5 = (uint)(uVar4 < uVar9) + uVar8 * 2;
  iVar6 = 1;
  if (uVar8 <= uVar5) {
    if (uVar5 == uVar8) {
      if (uVar9 <= uVar4) {
        iVar6 = 0;
      }
    }
    else {
      iVar6 = 0;
    }
  }
  uVar8 = uVar4 + (int)((ulonglong)lVar1 >> 0x20);
  param_1[1] = uVar8;
  if ((uVar8 < uVar4) && (uVar5 = uVar5 + 1, uVar5 == 0)) {
    iVar6 = iVar6 + 1;
    lVar1 = (ulonglong)param_2[1] * (ulonglong)param_2[1];
  }
  else {
    lVar1 = (ulonglong)param_2[1] * (ulonglong)param_2[1] + (ulonglong)uVar5;
  }
  uVar4 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar5 = uVar4 + iVar6;
  uVar2 = (ulonglong)param_2[2] * (ulonglong)*param_2;
  uVar8 = (uint)uVar2 * 2;
  uVar9 = (uint)(uVar8 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  uVar4 = (uint)(uVar5 < uVar4);
  if (CONCAT44(uVar9,uVar8) < uVar2) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = uVar8 + (int)lVar1;
  if ((uVar3 < uVar8) && (uVar9 = uVar9 + 1, uVar9 == 0)) {
    uVar4 = uVar4 + 1;
  }
  else {
    uVar5 = uVar5 + uVar9;
    uVar4 = uVar4 + (uVar5 < uVar9);
  }
  param_1[2] = uVar3;
  uVar10 = (uint)((ulonglong)param_2[3] * (ulonglong)*param_2);
  uVar3 = (uint)((ulonglong)param_2[3] * (ulonglong)*param_2 >> 0x20);
  uVar8 = uVar10 * 2;
  uVar9 = (uint)(uVar8 < uVar10) + uVar3 * 2;
  iVar6 = 1;
  if (uVar3 <= uVar9) {
    if (uVar9 == uVar3) {
      if (uVar10 <= uVar8) {
        iVar6 = 0;
      }
    }
    else {
      iVar6 = 0;
    }
  }
  if ((uVar8 + uVar5 < uVar8) && (uVar9 = uVar9 + 1, uVar9 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar4 = uVar4 + uVar9;
    iVar6 = iVar6 + (uint)(uVar4 < uVar9);
  }
  uVar2 = (ulonglong)param_2[2] * (ulonglong)param_2[1];
  uVar9 = (uint)uVar2 * 2;
  uVar3 = (uint)(uVar9 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar5 = uVar8 + uVar5 + uVar9;
  if ((uVar5 < uVar9) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar4 = uVar4 + uVar3;
    iVar6 = iVar6 + (uint)(uVar4 < uVar3);
  }
  param_1[3] = uVar5;
  uVar2 = (ulonglong)param_2[3] * (ulonglong)param_2[1];
  lVar1 = (ulonglong)param_2[2] * (ulonglong)param_2[2] + (ulonglong)uVar4;
  uVar4 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar8 = (uint)uVar2 * 2;
  uVar9 = (uint)(uVar8 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  uVar5 = uVar4 + iVar6;
  uVar4 = (uint)(uVar5 < uVar4);
  if (CONCAT44(uVar9,uVar8) < uVar2) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = (int)lVar1 + uVar8;
  if ((uVar3 < uVar8) && (uVar9 = uVar9 + 1, uVar9 == 0)) {
    iVar6 = uVar4 + 1;
  }
  else {
    uVar5 = uVar5 + uVar9;
    iVar6 = uVar4 + (uVar5 < uVar9);
  }
  uVar2 = (ulonglong)param_2[4] * (ulonglong)*param_2;
  uVar4 = (uint)uVar2 * 2;
  uVar8 = (uint)(uVar4 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar8,uVar4) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar3 = uVar3 + uVar4;
  if ((uVar3 < uVar4) && (uVar8 = uVar8 + 1, uVar8 == 0)) {
    uVar4 = iVar6 + 1;
  }
  else {
    uVar5 = uVar5 + uVar8;
    uVar4 = iVar6 + (uint)(uVar5 < uVar8);
  }
  param_1[4] = uVar3;
  uVar10 = (uint)((ulonglong)param_2[5] * (ulonglong)*param_2);
  uVar3 = (uint)((ulonglong)param_2[5] * (ulonglong)*param_2 >> 0x20);
  uVar8 = uVar10 * 2;
  uVar9 = (uint)(uVar8 < uVar10) + uVar3 * 2;
  iVar6 = 1;
  if (uVar3 <= uVar9) {
    if (uVar9 == uVar3) {
      if (uVar10 <= uVar8) {
        iVar6 = 0;
      }
    }
    else {
      iVar6 = 0;
    }
  }
  if ((uVar8 + uVar5 < uVar8) && (uVar9 = uVar9 + 1, uVar9 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar4 = uVar4 + uVar9;
    iVar6 = iVar6 + (uint)(uVar4 < uVar9);
  }
  uVar2 = (ulonglong)param_2[4] * (ulonglong)param_2[1];
  uVar9 = (uint)uVar2 * 2;
  uVar3 = (uint)(uVar9 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar5 = uVar8 + uVar5 + uVar9;
  if ((uVar5 < uVar9) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar4 = uVar4 + uVar3;
    iVar6 = iVar6 + (uint)(uVar4 < uVar3);
  }
  uVar2 = (ulonglong)param_2[3] * (ulonglong)param_2[2];
  uVar8 = (uint)uVar2 * 2;
  uVar9 = (uint)(uVar8 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar9,uVar8) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar5 = uVar5 + uVar8;
  if ((uVar5 < uVar8) && (uVar9 = uVar9 + 1, uVar9 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar4 = uVar4 + uVar9;
    iVar6 = iVar6 + (uint)(uVar4 < uVar9);
  }
  param_1[5] = uVar5;
  uVar2 = (ulonglong)param_2[4] * (ulonglong)param_2[2];
  lVar1 = (ulonglong)param_2[3] * (ulonglong)param_2[3] + (ulonglong)uVar4;
  uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar8 = (uint)uVar2 * 2;
  uVar9 = (uint)(uVar8 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  uVar4 = uVar5 + iVar6;
  uVar5 = (uint)(uVar4 < uVar5);
  if (CONCAT44(uVar9,uVar8) < uVar2) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = (int)lVar1 + uVar8;
  if ((uVar3 < uVar8) && (uVar9 = uVar9 + 1, uVar9 == 0)) {
    iVar6 = uVar5 + 1;
  }
  else {
    uVar4 = uVar4 + uVar9;
    iVar6 = uVar5 + (uVar4 < uVar9);
  }
  uVar2 = (ulonglong)param_2[5] * (ulonglong)param_2[1];
  uVar5 = (uint)uVar2 * 2;
  uVar8 = (uint)(uVar5 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar8,uVar5) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar3 = uVar3 + uVar5;
  if ((uVar3 < uVar5) && (uVar8 = uVar8 + 1, uVar8 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar4 = uVar4 + uVar8;
    iVar6 = iVar6 + (uint)(uVar4 < uVar8);
  }
  uVar2 = (ulonglong)param_2[6] * (ulonglong)*param_2;
  uVar5 = (uint)uVar2 * 2;
  uVar8 = (uint)(uVar5 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar8,uVar5) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar3 = uVar3 + uVar5;
  if ((uVar3 < uVar5) && (uVar8 = uVar8 + 1, uVar8 == 0)) {
    uVar5 = iVar6 + 1;
  }
  else {
    uVar4 = uVar4 + uVar8;
    uVar5 = iVar6 + (uint)(uVar4 < uVar8);
  }
  param_1[6] = uVar3;
  uVar10 = (uint)((ulonglong)param_2[7] * (ulonglong)*param_2);
  uVar3 = (uint)((ulonglong)param_2[7] * (ulonglong)*param_2 >> 0x20);
  uVar8 = uVar10 * 2;
  uVar9 = (uint)(uVar8 < uVar10) + uVar3 * 2;
  iVar6 = 1;
  if (uVar3 <= uVar9) {
    if (uVar9 == uVar3) {
      if (uVar10 <= uVar8) {
        iVar6 = 0;
      }
    }
    else {
      iVar6 = 0;
    }
  }
  if ((uVar8 + uVar4 < uVar8) && (uVar9 = uVar9 + 1, uVar9 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar5 = uVar5 + uVar9;
    iVar6 = iVar6 + (uint)(uVar5 < uVar9);
  }
  uVar2 = (ulonglong)param_2[6] * (ulonglong)param_2[1];
  uVar9 = (uint)uVar2 * 2;
  uVar3 = (uint)(uVar9 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar4 = uVar8 + uVar4 + uVar9;
  if ((uVar4 < uVar9) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar5 = uVar5 + uVar3;
    iVar6 = iVar6 + (uint)(uVar5 < uVar3);
  }
  uVar2 = (ulonglong)param_2[5] * (ulonglong)param_2[2];
  uVar8 = (uint)uVar2 * 2;
  uVar9 = (uint)(uVar8 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar9,uVar8) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar4 = uVar4 + uVar8;
  if ((uVar4 < uVar8) && (uVar9 = uVar9 + 1, uVar9 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar5 = uVar5 + uVar9;
    iVar6 = iVar6 + (uint)(uVar5 < uVar9);
  }
  uVar2 = (ulonglong)param_2[4] * (ulonglong)param_2[3];
  uVar8 = (uint)uVar2 * 2;
  uVar9 = (uint)(uVar8 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar9,uVar8) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar4 = uVar4 + uVar8;
  if ((uVar4 < uVar8) && (uVar9 = uVar9 + 1, uVar9 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar5 = uVar5 + uVar9;
    iVar6 = iVar6 + (uint)(uVar5 < uVar9);
  }
  param_1[7] = uVar4;
  uVar2 = (ulonglong)param_2[5] * (ulonglong)param_2[3];
  lVar1 = (ulonglong)param_2[4] * (ulonglong)param_2[4] + (ulonglong)uVar5;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar9 = (uint)uVar2 * 2;
  uVar4 = (uint)(uVar9 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  uVar5 = uVar8 + iVar6;
  uVar8 = (uint)(uVar5 < uVar8);
  if (CONCAT44(uVar4,uVar9) < uVar2) {
    uVar8 = uVar8 + 1;
  }
  uVar3 = (int)lVar1 + uVar9;
  if ((uVar3 < uVar9) && (uVar4 = uVar4 + 1, uVar4 == 0)) {
    iVar6 = uVar8 + 1;
  }
  else {
    uVar5 = uVar5 + uVar4;
    iVar6 = uVar8 + (uVar5 < uVar4);
  }
  uVar2 = (ulonglong)param_2[6] * (ulonglong)param_2[2];
  uVar4 = (uint)uVar2 * 2;
  uVar8 = (uint)(uVar4 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar8,uVar4) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar3 = uVar3 + uVar4;
  if ((uVar3 < uVar4) && (uVar8 = uVar8 + 1, uVar8 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar5 = uVar5 + uVar8;
    iVar6 = iVar6 + (uint)(uVar5 < uVar8);
  }
  uVar2 = (ulonglong)param_2[7] * (ulonglong)param_2[1];
  uVar4 = (uint)uVar2 * 2;
  uVar8 = (uint)(uVar4 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar8,uVar4) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar3 = uVar3 + uVar4;
  if ((uVar3 < uVar4) && (uVar8 = uVar8 + 1, uVar8 == 0)) {
    uVar4 = iVar6 + 1;
  }
  else {
    uVar5 = uVar5 + uVar8;
    uVar4 = iVar6 + (uint)(uVar5 < uVar8);
  }
  param_1[8] = uVar3;
  uVar10 = (uint)((ulonglong)param_2[7] * (ulonglong)param_2[2]);
  uVar3 = (uint)((ulonglong)param_2[7] * (ulonglong)param_2[2] >> 0x20);
  uVar8 = uVar10 * 2;
  uVar9 = (uint)(uVar8 < uVar10) + uVar3 * 2;
  iVar6 = 1;
  if (uVar3 <= uVar9) {
    if (uVar9 == uVar3) {
      if (uVar10 <= uVar8) {
        iVar6 = 0;
      }
    }
    else {
      iVar6 = 0;
    }
  }
  if ((uVar8 + uVar5 < uVar8) && (uVar9 = uVar9 + 1, uVar9 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar4 = uVar4 + uVar9;
    iVar6 = iVar6 + (uint)(uVar4 < uVar9);
  }
  uVar2 = (ulonglong)param_2[6] * (ulonglong)param_2[3];
  uVar9 = (uint)uVar2 * 2;
  uVar3 = (uint)(uVar9 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar3,uVar9) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar5 = uVar8 + uVar5 + uVar9;
  if ((uVar5 < uVar9) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar4 = uVar4 + uVar3;
    iVar6 = iVar6 + (uint)(uVar4 < uVar3);
  }
  uVar2 = (ulonglong)param_2[5] * (ulonglong)param_2[4];
  uVar8 = (uint)uVar2 * 2;
  uVar9 = (uint)(uVar8 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar9,uVar8) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar5 = uVar5 + uVar8;
  if ((uVar5 < uVar8) && (uVar9 = uVar9 + 1, uVar9 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar4 = uVar4 + uVar9;
    iVar6 = iVar6 + (uint)(uVar4 < uVar9);
  }
  param_1[9] = uVar5;
  uVar2 = (ulonglong)param_2[6] * (ulonglong)param_2[4];
  lVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[5] + (ulonglong)uVar4;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar9 = (uint)uVar2 * 2;
  uVar5 = (uint)(uVar9 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  uVar4 = uVar8 + iVar6;
  uVar8 = (uint)(uVar4 < uVar8);
  if (CONCAT44(uVar5,uVar9) < uVar2) {
    uVar8 = uVar8 + 1;
  }
  uVar3 = (int)lVar1 + uVar9;
  if ((uVar3 < uVar9) && (uVar5 = uVar5 + 1, uVar5 == 0)) {
    iVar6 = uVar8 + 1;
  }
  else {
    uVar4 = uVar4 + uVar5;
    iVar6 = uVar8 + (uVar4 < uVar5);
  }
  uVar2 = (ulonglong)param_2[7] * (ulonglong)param_2[3];
  uVar8 = (uint)uVar2 * 2;
  uVar5 = (uint)(uVar8 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar5,uVar8) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar3 = uVar3 + uVar8;
  if ((uVar3 < uVar8) && (uVar5 = uVar5 + 1, uVar5 == 0)) {
    uVar5 = iVar6 + 1;
  }
  else {
    uVar4 = uVar4 + uVar5;
    uVar5 = iVar6 + (uint)(uVar4 < uVar5);
  }
  param_1[10] = uVar3;
  uVar10 = (uint)((ulonglong)param_2[7] * (ulonglong)param_2[4]);
  uVar3 = (uint)((ulonglong)param_2[7] * (ulonglong)param_2[4] >> 0x20);
  uVar9 = uVar10 * 2;
  uVar8 = (uint)(uVar9 < uVar10) + uVar3 * 2;
  iVar6 = 1;
  if (uVar3 <= uVar8) {
    if (uVar8 == uVar3) {
      if (uVar10 <= uVar9) {
        iVar6 = 0;
      }
    }
    else {
      iVar6 = 0;
    }
  }
  if ((uVar9 + uVar4 < uVar9) && (uVar8 = uVar8 + 1, uVar8 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar5 = uVar5 + uVar8;
    iVar6 = iVar6 + (uint)(uVar5 < uVar8);
  }
  uVar2 = (ulonglong)param_2[6] * (ulonglong)param_2[5];
  uVar8 = (uint)uVar2 * 2;
  uVar3 = (uint)(uVar8 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  if (CONCAT44(uVar3,uVar8) < uVar2) {
    iVar6 = iVar6 + 1;
  }
  uVar4 = uVar9 + uVar4 + uVar8;
  if ((uVar4 < uVar8) && (uVar3 = uVar3 + 1, uVar3 == 0)) {
    iVar6 = iVar6 + 1;
  }
  else {
    uVar5 = uVar5 + uVar3;
    iVar6 = iVar6 + (uint)(uVar5 < uVar3);
  }
  param_1[0xb] = uVar4;
  uVar2 = (ulonglong)param_2[7] * (ulonglong)param_2[5];
  lVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[6] + (ulonglong)uVar5;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar4 = (uint)uVar2 * 2;
  uVar8 = (uint)(uVar4 < (uint)uVar2) + (int)(uVar2 >> 0x20) * 2;
  uVar5 = uVar9 + iVar6;
  uVar9 = (uint)(uVar5 < uVar9);
  if (CONCAT44(uVar8,uVar4) < uVar2) {
    uVar9 = uVar9 + 1;
  }
  uVar3 = (int)lVar1 + uVar4;
  if ((uVar3 < uVar4) && (uVar8 = uVar8 + 1, uVar8 == 0)) {
    iVar6 = uVar9 + 1;
  }
  else {
    uVar5 = uVar5 + uVar8;
    iVar6 = uVar9 + (uVar5 < uVar8);
  }
  param_1[0xc] = uVar3;
  uVar3 = (uint)((ulonglong)param_2[7] * (ulonglong)param_2[6]);
  uVar9 = (uint)((ulonglong)param_2[7] * (ulonglong)param_2[6] >> 0x20);
  uVar8 = uVar3 * 2;
  uVar4 = (uint)(uVar8 < uVar3) + uVar9 * 2;
  iVar7 = 1;
  if (uVar9 <= uVar4) {
    if (uVar4 == uVar9) {
      if (uVar3 <= uVar8) {
        iVar7 = 0;
      }
    }
    else {
      iVar7 = 0;
    }
  }
  uVar5 = uVar8 + uVar5;
  if ((uVar5 < uVar8) && (uVar4 = uVar4 + 1, uVar4 == 0)) {
    param_1[0xd] = uVar5;
    lVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[7] + CONCAT44(iVar7 + 1,iVar6);
    param_1[0xe] = (int)lVar1;
    param_1[0xf] = (int)((ulonglong)lVar1 >> 0x20);
    return;
  }
  param_1[0xd] = uVar5;
  lVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[7] +
          CONCAT44(iVar7 + (uint)(iVar6 + uVar4 < uVar4),iVar6 + uVar4);
  param_1[0xe] = (int)lVar1;
  param_1[0xf] = (int)((ulonglong)lVar1 >> 0x20);
  return;
}

