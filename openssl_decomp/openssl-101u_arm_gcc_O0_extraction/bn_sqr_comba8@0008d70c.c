
void bn_sqr_comba8(undefined4 *param_1,uint *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  
  lVar1 = (ulonglong)*param_2 * (ulonglong)*param_2;
  uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
  *param_1 = (int)lVar1;
  uVar2 = (ulonglong)*param_2 * (ulonglong)param_2[1];
  uVar7 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[1] * (ulonglong)*param_2 +
          ((ulonglong)uVar7 << 0x20 | uVar2 & 0xffffffff);
  uVar8 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar7 <= uVar9;
  if (uVar9 == uVar7) {
    bVar12 = (uint)uVar2 <= uVar8;
  }
  uVar7 = (uint)!bVar12;
  param_1[1] = uVar5 + uVar8;
  if ((CARRY4(uVar5,uVar8) == false) || (uVar9 = uVar9 + 1, uVar9 != 0)) {
    uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[1];
    uVar5 = uVar9 + (uint)uVar2;
    uVar3 = uVar2 & 0xffffffff00000000 | (ulonglong)uVar5;
    if (CARRY4(uVar9,(uint)uVar2) != false) {
      uVar3 = CONCAT44((int)(uVar2 >> 0x20) + 1,uVar5);
    }
  }
  else {
    uVar7 = uVar7 + 1;
    uVar3 = (ulonglong)param_2[1] * (ulonglong)param_2[1];
  }
  uVar5 = (uint)(uVar3 >> 0x20);
  uVar11 = uVar7 + uVar5;
  uVar9 = (uint)(CARRY4(uVar7,uVar5) != false);
  uVar2 = (ulonglong)*param_2 * (ulonglong)param_2[2];
  uVar7 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[2] * (ulonglong)*param_2 +
          ((ulonglong)uVar7 << 0x20 | uVar2 & 0xffffffff);
  uVar8 = (uint)lVar1;
  uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar7 <= uVar5;
  if (uVar5 == uVar7) {
    bVar12 = (uint)uVar2 <= uVar8;
  }
  if (!bVar12) {
    uVar9 = uVar9 + 1;
  }
  if (((CARRY4((uint)uVar3,uVar8) != false) && (uVar5 = uVar5 + 1, uVar5 == 0)) ||
     (bVar12 = CARRY4(uVar11,uVar5), uVar11 = uVar11 + uVar5, bVar12 != false)) {
    uVar9 = uVar9 + 1;
  }
  param_1[2] = (uint)uVar3 + uVar8;
  uVar2 = (ulonglong)*param_2 * (ulonglong)param_2[3];
  uVar7 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[3] * (ulonglong)*param_2 +
          ((ulonglong)uVar7 << 0x20 | uVar2 & 0xffffffff);
  uVar8 = (uint)lVar1;
  uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar7 <= uVar5;
  if (uVar5 == uVar7) {
    bVar12 = (uint)uVar2 <= uVar8;
  }
  uVar7 = (uint)!bVar12;
  if (((CARRY4(uVar11,uVar8) != false) && (uVar5 = uVar5 + 1, uVar5 == 0)) ||
     (bVar12 = CARRY4(uVar9,uVar5), uVar9 = uVar9 + uVar5, bVar12 != false)) {
    uVar7 = uVar7 + 1;
  }
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[2];
  uVar6 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[2] * (ulonglong)param_2[1] +
          ((ulonglong)uVar6 << 0x20 | uVar2 & 0xffffffff);
  uVar10 = (uint)lVar1;
  uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar6 <= uVar5;
  if (uVar5 == uVar6) {
    bVar12 = (uint)uVar2 <= uVar10;
  }
  if (!bVar12) {
    uVar7 = uVar7 + 1;
  }
  if (((CARRY4(uVar11 + uVar8,uVar10) != false) && (uVar5 = uVar5 + 1, uVar5 == 0)) ||
     (bVar12 = CARRY4(uVar9,uVar5), uVar9 = uVar9 + uVar5, bVar12 != false)) {
    uVar7 = uVar7 + 1;
  }
  param_1[3] = uVar11 + uVar8 + uVar10;
  lVar1 = (ulonglong)param_2[2] * (ulonglong)param_2[2];
  uVar5 = (uint)lVar1;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar11 = uVar9 + uVar5;
  if (CARRY4(uVar9,uVar5) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar6 = uVar8 + uVar7;
  uVar5 = (uint)(CARRY4(uVar8,uVar7) != false);
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[3];
  uVar9 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[3] * (ulonglong)param_2[1] +
          ((ulonglong)uVar9 << 0x20 | uVar2 & 0xffffffff);
  uVar8 = (uint)lVar1;
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar9 <= uVar7;
  if (uVar7 == uVar9) {
    bVar12 = (uint)uVar2 <= uVar8;
  }
  if (!bVar12) {
    uVar5 = uVar5 + 1;
  }
  uVar9 = uVar11 + uVar8;
  if (((CARRY4(uVar11,uVar8) != false) && (uVar7 = uVar7 + 1, uVar7 == 0)) ||
     (bVar12 = CARRY4(uVar6,uVar7), uVar6 = uVar6 + uVar7, bVar12 != false)) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = (ulonglong)*param_2 * (ulonglong)param_2[4];
  uVar7 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[4] * (ulonglong)*param_2 +
          ((ulonglong)uVar7 << 0x20 | uVar2 & 0xffffffff);
  uVar11 = (uint)lVar1;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar7 <= uVar8;
  if (uVar8 == uVar7) {
    bVar12 = (uint)uVar2 <= uVar11;
  }
  if (!bVar12) {
    uVar5 = uVar5 + 1;
  }
  if (((CARRY4(uVar9,uVar11) != false) && (uVar8 = uVar8 + 1, uVar8 == 0)) ||
     (bVar12 = CARRY4(uVar6,uVar8), uVar6 = uVar6 + uVar8, bVar12 != false)) {
    uVar5 = uVar5 + 1;
  }
  param_1[4] = uVar9 + uVar11;
  uVar2 = (ulonglong)*param_2 * (ulonglong)param_2[5];
  uVar9 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[5] * (ulonglong)*param_2 +
          ((ulonglong)uVar9 << 0x20 | uVar2 & 0xffffffff);
  uVar8 = (uint)lVar1;
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar9 <= uVar7;
  if (uVar7 == uVar9) {
    bVar12 = (uint)uVar2 <= uVar8;
  }
  uVar9 = (uint)!bVar12;
  if (((CARRY4(uVar6,uVar8) != false) && (uVar7 = uVar7 + 1, uVar7 == 0)) ||
     (bVar12 = CARRY4(uVar5,uVar7), uVar5 = uVar5 + uVar7, bVar12 != false)) {
    uVar9 = uVar9 + 1;
  }
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[4];
  uVar11 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[4] * (ulonglong)param_2[1] +
          ((ulonglong)uVar11 << 0x20 | uVar2 & 0xffffffff);
  uVar10 = (uint)lVar1;
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar11 <= uVar7;
  if (uVar7 == uVar11) {
    bVar12 = (uint)uVar2 <= uVar10;
  }
  if (!bVar12) {
    uVar9 = uVar9 + 1;
  }
  uVar11 = uVar6 + uVar8 + uVar10;
  if (((CARRY4(uVar6 + uVar8,uVar10) != false) && (uVar7 = uVar7 + 1, uVar7 == 0)) ||
     (bVar12 = CARRY4(uVar5,uVar7), uVar5 = uVar5 + uVar7, bVar12 != false)) {
    uVar9 = uVar9 + 1;
  }
  uVar2 = (ulonglong)param_2[2] * (ulonglong)param_2[3];
  uVar6 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[3] * (ulonglong)param_2[2] +
          ((ulonglong)uVar6 << 0x20 | uVar2 & 0xffffffff);
  uVar7 = (uint)lVar1;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar6 <= uVar8;
  if (uVar8 == uVar6) {
    bVar12 = (uint)uVar2 <= uVar7;
  }
  if (!bVar12) {
    uVar9 = uVar9 + 1;
  }
  if (((CARRY4(uVar11,uVar7) != false) && (uVar8 = uVar8 + 1, uVar8 == 0)) ||
     (bVar12 = CARRY4(uVar5,uVar8), uVar5 = uVar5 + uVar8, bVar12 != false)) {
    uVar9 = uVar9 + 1;
  }
  param_1[5] = uVar11 + uVar7;
  lVar1 = (ulonglong)param_2[3] * (ulonglong)param_2[3];
  uVar7 = (uint)lVar1;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar11 = uVar5 + uVar7;
  if (CARRY4(uVar5,uVar7) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar7 = uVar8 + uVar9;
  uVar5 = (uint)(CARRY4(uVar8,uVar9) != false);
  uVar2 = (ulonglong)param_2[2] * (ulonglong)param_2[4];
  uVar9 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[4] * (ulonglong)param_2[2] +
          ((ulonglong)uVar9 << 0x20 | uVar2 & 0xffffffff);
  uVar8 = (uint)lVar1;
  uVar6 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar9 <= uVar6;
  if (uVar6 == uVar9) {
    bVar12 = (uint)uVar2 <= uVar8;
  }
  if (!bVar12) {
    uVar5 = uVar5 + 1;
  }
  uVar9 = uVar11 + uVar8;
  if (((CARRY4(uVar11,uVar8) != false) && (uVar6 = uVar6 + 1, uVar6 == 0)) ||
     (bVar12 = CARRY4(uVar7,uVar6), uVar7 = uVar7 + uVar6, bVar12 != false)) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[5];
  uVar11 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[1] +
          ((ulonglong)uVar11 << 0x20 | uVar2 & 0xffffffff);
  uVar6 = (uint)lVar1;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar11 <= uVar8;
  if (uVar8 == uVar11) {
    bVar12 = (uint)uVar2 <= uVar6;
  }
  if (!bVar12) {
    uVar5 = uVar5 + 1;
  }
  uVar11 = uVar9 + uVar6;
  if (((CARRY4(uVar9,uVar6) != false) && (uVar8 = uVar8 + 1, uVar8 == 0)) ||
     (bVar12 = CARRY4(uVar7,uVar8), uVar7 = uVar7 + uVar8, bVar12 != false)) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = (ulonglong)*param_2 * (ulonglong)param_2[6];
  uVar8 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[6] * (ulonglong)*param_2 +
          ((ulonglong)uVar8 << 0x20 | uVar2 & 0xffffffff);
  uVar6 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar8 <= uVar9;
  if (uVar9 == uVar8) {
    bVar12 = (uint)uVar2 <= uVar6;
  }
  if (!bVar12) {
    uVar5 = uVar5 + 1;
  }
  if (((CARRY4(uVar11,uVar6) != false) && (uVar9 = uVar9 + 1, uVar9 == 0)) ||
     (bVar12 = CARRY4(uVar7,uVar9), uVar7 = uVar7 + uVar9, bVar12 != false)) {
    uVar5 = uVar5 + 1;
  }
  param_1[6] = uVar11 + uVar6;
  uVar2 = (ulonglong)*param_2 * (ulonglong)param_2[7];
  uVar8 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[7] * (ulonglong)*param_2 +
          ((ulonglong)uVar8 << 0x20 | uVar2 & 0xffffffff);
  uVar11 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar8 <= uVar9;
  if (uVar9 == uVar8) {
    bVar12 = (uint)uVar2 <= uVar11;
  }
  uVar8 = (uint)!bVar12;
  if (((CARRY4(uVar7,uVar11) != false) && (uVar9 = uVar9 + 1, uVar9 == 0)) ||
     (bVar12 = CARRY4(uVar5,uVar9), uVar5 = uVar5 + uVar9, bVar12 != false)) {
    uVar8 = uVar8 + 1;
  }
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[6];
  uVar6 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[1] +
          ((ulonglong)uVar6 << 0x20 | uVar2 & 0xffffffff);
  uVar10 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar6 <= uVar9;
  if (uVar9 == uVar6) {
    bVar12 = (uint)uVar2 <= uVar10;
  }
  if (!bVar12) {
    uVar8 = uVar8 + 1;
  }
  uVar6 = uVar7 + uVar11 + uVar10;
  if (((CARRY4(uVar7 + uVar11,uVar10) != false) && (uVar9 = uVar9 + 1, uVar9 == 0)) ||
     (bVar12 = CARRY4(uVar5,uVar9), uVar5 = uVar5 + uVar9, bVar12 != false)) {
    uVar8 = uVar8 + 1;
  }
  uVar2 = (ulonglong)param_2[2] * (ulonglong)param_2[5];
  uVar9 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[2] +
          ((ulonglong)uVar9 << 0x20 | uVar2 & 0xffffffff);
  uVar11 = (uint)lVar1;
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar9 <= uVar7;
  if (uVar7 == uVar9) {
    bVar12 = (uint)uVar2 <= uVar11;
  }
  if (!bVar12) {
    uVar8 = uVar8 + 1;
  }
  uVar9 = uVar6 + uVar11;
  if (((CARRY4(uVar6,uVar11) != false) && (uVar7 = uVar7 + 1, uVar7 == 0)) ||
     (bVar12 = CARRY4(uVar5,uVar7), uVar5 = uVar5 + uVar7, bVar12 != false)) {
    uVar8 = uVar8 + 1;
  }
  uVar2 = (ulonglong)param_2[3] * (ulonglong)param_2[4];
  uVar7 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[4] * (ulonglong)param_2[3] +
          ((ulonglong)uVar7 << 0x20 | uVar2 & 0xffffffff);
  uVar6 = (uint)lVar1;
  uVar11 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar7 <= uVar11;
  if (uVar11 == uVar7) {
    bVar12 = (uint)uVar2 <= uVar6;
  }
  if (!bVar12) {
    uVar8 = uVar8 + 1;
  }
  if (((CARRY4(uVar9,uVar6) != false) && (uVar11 = uVar11 + 1, uVar11 == 0)) ||
     (bVar12 = CARRY4(uVar5,uVar11), uVar5 = uVar5 + uVar11, bVar12 != false)) {
    uVar8 = uVar8 + 1;
  }
  param_1[7] = uVar9 + uVar6;
  lVar1 = (ulonglong)param_2[4] * (ulonglong)param_2[4];
  uVar7 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar11 = uVar5 + uVar7;
  if (CARRY4(uVar5,uVar7) != false) {
    uVar9 = uVar9 + 1;
  }
  uVar7 = uVar9 + uVar8;
  uVar5 = (uint)(CARRY4(uVar9,uVar8) != false);
  uVar2 = (ulonglong)param_2[3] * (ulonglong)param_2[5];
  uVar9 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[3] +
          ((ulonglong)uVar9 << 0x20 | uVar2 & 0xffffffff);
  uVar8 = (uint)lVar1;
  uVar6 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar9 <= uVar6;
  if (uVar6 == uVar9) {
    bVar12 = (uint)uVar2 <= uVar8;
  }
  if (!bVar12) {
    uVar5 = uVar5 + 1;
  }
  uVar9 = uVar11 + uVar8;
  if (((CARRY4(uVar11,uVar8) != false) && (uVar6 = uVar6 + 1, uVar6 == 0)) ||
     (bVar12 = CARRY4(uVar7,uVar6), uVar7 = uVar7 + uVar6, bVar12 != false)) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = (ulonglong)param_2[2] * (ulonglong)param_2[6];
  uVar11 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[2] +
          ((ulonglong)uVar11 << 0x20 | uVar2 & 0xffffffff);
  uVar6 = (uint)lVar1;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar11 <= uVar8;
  if (uVar8 == uVar11) {
    bVar12 = (uint)uVar2 <= uVar6;
  }
  if (!bVar12) {
    uVar5 = uVar5 + 1;
  }
  uVar11 = uVar9 + uVar6;
  if (((CARRY4(uVar9,uVar6) != false) && (uVar8 = uVar8 + 1, uVar8 == 0)) ||
     (bVar12 = CARRY4(uVar7,uVar8), uVar7 = uVar7 + uVar8, bVar12 != false)) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = (ulonglong)param_2[1] * (ulonglong)param_2[7];
  uVar8 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[1] +
          ((ulonglong)uVar8 << 0x20 | uVar2 & 0xffffffff);
  uVar6 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar8 <= uVar9;
  if (uVar9 == uVar8) {
    bVar12 = (uint)uVar2 <= uVar6;
  }
  if (!bVar12) {
    uVar5 = uVar5 + 1;
  }
  if (((CARRY4(uVar11,uVar6) != false) && (uVar9 = uVar9 + 1, uVar9 == 0)) ||
     (bVar12 = CARRY4(uVar7,uVar9), uVar7 = uVar7 + uVar9, bVar12 != false)) {
    uVar5 = uVar5 + 1;
  }
  param_1[8] = uVar11 + uVar6;
  uVar2 = (ulonglong)param_2[2] * (ulonglong)param_2[7];
  uVar8 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[2] +
          ((ulonglong)uVar8 << 0x20 | uVar2 & 0xffffffff);
  uVar11 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar8 <= uVar9;
  if (uVar9 == uVar8) {
    bVar12 = (uint)uVar2 <= uVar11;
  }
  uVar8 = (uint)!bVar12;
  if (((CARRY4(uVar7,uVar11) != false) && (uVar9 = uVar9 + 1, uVar9 == 0)) ||
     (bVar12 = CARRY4(uVar5,uVar9), uVar5 = uVar5 + uVar9, bVar12 != false)) {
    uVar8 = uVar8 + 1;
  }
  uVar2 = (ulonglong)param_2[3] * (ulonglong)param_2[6];
  uVar6 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[3] +
          ((ulonglong)uVar6 << 0x20 | uVar2 & 0xffffffff);
  uVar10 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar6 <= uVar9;
  if (uVar9 == uVar6) {
    bVar12 = (uint)uVar2 <= uVar10;
  }
  if (!bVar12) {
    uVar8 = uVar8 + 1;
  }
  uVar6 = uVar7 + uVar11 + uVar10;
  if (((CARRY4(uVar7 + uVar11,uVar10) != false) && (uVar9 = uVar9 + 1, uVar9 == 0)) ||
     (bVar12 = CARRY4(uVar5,uVar9), uVar5 = uVar5 + uVar9, bVar12 != false)) {
    uVar8 = uVar8 + 1;
  }
  uVar2 = (ulonglong)param_2[4] * (ulonglong)param_2[5];
  uVar7 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[4] +
          ((ulonglong)uVar7 << 0x20 | uVar2 & 0xffffffff);
  uVar11 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar7 <= uVar9;
  if (uVar9 == uVar7) {
    bVar12 = (uint)uVar2 <= uVar11;
  }
  if (!bVar12) {
    uVar8 = uVar8 + 1;
  }
  if (((CARRY4(uVar6,uVar11) != false) && (uVar9 = uVar9 + 1, uVar9 == 0)) ||
     (bVar12 = CARRY4(uVar5,uVar9), uVar5 = uVar5 + uVar9, bVar12 != false)) {
    uVar8 = uVar8 + 1;
  }
  param_1[9] = uVar6 + uVar11;
  lVar1 = (ulonglong)param_2[5] * (ulonglong)param_2[5];
  uVar7 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar11 = uVar5 + uVar7;
  if (CARRY4(uVar5,uVar7) != false) {
    uVar9 = uVar9 + 1;
  }
  uVar6 = uVar9 + uVar8;
  uVar5 = (uint)(CARRY4(uVar9,uVar8) != false);
  uVar2 = (ulonglong)param_2[4] * (ulonglong)param_2[6];
  uVar9 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[4] +
          ((ulonglong)uVar9 << 0x20 | uVar2 & 0xffffffff);
  uVar8 = (uint)lVar1;
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar9 <= uVar7;
  if (uVar7 == uVar9) {
    bVar12 = (uint)uVar2 <= uVar8;
  }
  if (!bVar12) {
    uVar5 = uVar5 + 1;
  }
  uVar9 = uVar11 + uVar8;
  if (((CARRY4(uVar11,uVar8) != false) && (uVar7 = uVar7 + 1, uVar7 == 0)) ||
     (bVar12 = CARRY4(uVar6,uVar7), uVar6 = uVar6 + uVar7, bVar12 != false)) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = (ulonglong)param_2[3] * (ulonglong)param_2[7];
  uVar8 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[3] +
          ((ulonglong)uVar8 << 0x20 | uVar2 & 0xffffffff);
  uVar11 = (uint)lVar1;
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar8 <= uVar7;
  if (uVar7 == uVar8) {
    bVar12 = (uint)uVar2 <= uVar11;
  }
  if (!bVar12) {
    uVar5 = uVar5 + 1;
  }
  if (((CARRY4(uVar9,uVar11) != false) && (uVar7 = uVar7 + 1, uVar7 == 0)) ||
     (bVar12 = CARRY4(uVar6,uVar7), uVar6 = uVar6 + uVar7, bVar12 != false)) {
    uVar5 = uVar5 + 1;
  }
  param_1[10] = uVar9 + uVar11;
  uVar2 = (ulonglong)param_2[4] * (ulonglong)param_2[7];
  uVar9 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[4] +
          ((ulonglong)uVar9 << 0x20 | uVar2 & 0xffffffff);
  uVar8 = (uint)lVar1;
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar9 <= uVar7;
  if (uVar7 == uVar9) {
    bVar12 = (uint)uVar2 <= uVar8;
  }
  uVar9 = (uint)!bVar12;
  if (((CARRY4(uVar6,uVar8) != false) && (uVar7 = uVar7 + 1, uVar7 == 0)) ||
     (bVar12 = CARRY4(uVar5,uVar7), uVar5 = uVar5 + uVar7, bVar12 != false)) {
    uVar9 = uVar9 + 1;
  }
  uVar2 = (ulonglong)param_2[5] * (ulonglong)param_2[6];
  uVar11 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[5] +
          ((ulonglong)uVar11 << 0x20 | uVar2 & 0xffffffff);
  uVar10 = (uint)lVar1;
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar11 <= uVar7;
  if (uVar7 == uVar11) {
    bVar12 = (uint)uVar2 <= uVar10;
  }
  if (!bVar12) {
    uVar9 = uVar9 + 1;
  }
  if (((CARRY4(uVar6 + uVar8,uVar10) != false) && (uVar7 = uVar7 + 1, uVar7 == 0)) ||
     (bVar12 = CARRY4(uVar5,uVar7), uVar5 = uVar5 + uVar7, bVar12 != false)) {
    uVar9 = uVar9 + 1;
  }
  param_1[0xb] = uVar6 + uVar8 + uVar10;
  lVar1 = (ulonglong)param_2[6] * (ulonglong)param_2[6];
  uVar7 = (uint)lVar1;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar11 = uVar5 + uVar7;
  if (CARRY4(uVar5,uVar7) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar6 = uVar8 + uVar9;
  uVar9 = (uint)(CARRY4(uVar8,uVar9) != false);
  uVar2 = (ulonglong)param_2[5] * (ulonglong)param_2[7];
  uVar7 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[5] +
          ((ulonglong)uVar7 << 0x20 | uVar2 & 0xffffffff);
  uVar8 = (uint)lVar1;
  uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar7 <= uVar5;
  if (uVar5 == uVar7) {
    bVar12 = (uint)uVar2 <= uVar8;
  }
  if (!bVar12) {
    uVar9 = uVar9 + 1;
  }
  if (((CARRY4(uVar11,uVar8) != false) && (uVar5 = uVar5 + 1, uVar5 == 0)) ||
     (bVar12 = CARRY4(uVar6,uVar5), uVar6 = uVar6 + uVar5, bVar12 != false)) {
    uVar9 = uVar9 + 1;
  }
  param_1[0xc] = uVar11 + uVar8;
  uVar2 = (ulonglong)param_2[6] * (ulonglong)param_2[7];
  uVar5 = (uint)(uVar2 >> 0x20);
  lVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[6] +
          ((ulonglong)uVar5 << 0x20 | uVar2 & 0xffffffff);
  uVar8 = (uint)lVar1;
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar12 = uVar5 <= uVar7;
  if (uVar7 == uVar5) {
    bVar12 = (uint)uVar2 <= uVar8;
  }
  uVar5 = (uint)!bVar12;
  if (((CARRY4(uVar6,uVar8) != false) && (uVar7 = uVar7 + 1, uVar7 == 0)) ||
     (bVar12 = CARRY4(uVar9,uVar7), uVar9 = uVar9 + uVar7, bVar12 != false)) {
    uVar5 = uVar5 + 1;
  }
  param_1[0xd] = uVar6 + uVar8;
  lVar1 = (ulonglong)param_2[7] * (ulonglong)param_2[7];
  uVar7 = (uint)lVar1;
  iVar4 = (int)((ulonglong)lVar1 >> 0x20);
  param_1[0xe] = uVar9 + uVar7;
  if (CARRY4(uVar9,uVar7) != false) {
    iVar4 = iVar4 + 1;
  }
  param_1[0xf] = uVar5 + iVar4;
  return;
}

