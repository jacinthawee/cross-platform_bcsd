
void bn_mul_comba8(undefined4 *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = (uint)((ulonglong)*param_2 * (ulonglong)*param_3 >> 0x20);
  *param_1 = (int)((ulonglong)*param_2 * (ulonglong)*param_3);
  uVar5 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[1]);
  uVar6 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[1] >> 0x20);
  uVar8 = uVar3 + uVar5;
  uVar2 = (uint)((ulonglong)param_2[1] * (ulonglong)*param_3);
  uVar4 = (uint)((ulonglong)param_2[1] * (ulonglong)*param_3 >> 0x20);
  if (CARRY4(uVar3,uVar5) != false) {
    uVar6 = uVar6 + 1;
  }
  param_1[1] = uVar8 + uVar2;
  if (CARRY4(uVar8,uVar2) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar5 = (uint)(CARRY4(uVar4,uVar6) != false);
  uVar3 = (uint)((ulonglong)param_2[2] * (ulonglong)*param_3);
  uVar2 = (uint)((ulonglong)param_2[2] * (ulonglong)*param_3 >> 0x20);
  uVar8 = uVar4 + uVar6 + uVar3;
  if (CARRY4(uVar4 + uVar6,uVar3) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar6 = uVar2 + uVar5;
  uVar4 = (uint)(CARRY4(uVar2,uVar5) != false);
  uVar2 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[1]);
  uVar3 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[1] >> 0x20);
  uVar5 = uVar8 + uVar2;
  if (CARRY4(uVar8,uVar2) != false) {
    uVar3 = uVar3 + 1;
  }
  uVar2 = uVar3 + uVar6;
  if (CARRY4(uVar3,uVar6) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[2]);
  uVar6 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[2] >> 0x20);
  param_1[2] = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar6 = uVar6 + 1;
  }
  uVar3 = uVar6 + uVar2;
  if (CARRY4(uVar6,uVar2) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[3]);
  uVar5 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[3] >> 0x20);
  uVar6 = uVar3 + uVar2;
  if (CARRY4(uVar3,uVar2) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = (uint)(CARRY4(uVar5,uVar4) != false);
  uVar3 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[2]);
  uVar8 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[2] >> 0x20);
  uVar7 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar3 = uVar8 + uVar5 + uVar4;
  if (CARRY4(uVar8,uVar5 + uVar4) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[1]);
  uVar5 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[1] >> 0x20);
  uVar6 = uVar7 + uVar4;
  if (CARRY4(uVar7,uVar4) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar4 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[3] * (ulonglong)*param_3);
  uVar5 = (uint)((ulonglong)param_2[3] * (ulonglong)*param_3 >> 0x20);
  param_1[3] = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar4;
  if (CARRY4(uVar5,uVar4) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[4] * (ulonglong)*param_3);
  uVar5 = (uint)((ulonglong)param_2[4] * (ulonglong)*param_3 >> 0x20);
  uVar6 = uVar3 + uVar4;
  if (CARRY4(uVar3,uVar4) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar4 = (uint)(CARRY4(uVar5,uVar2) != false);
  uVar3 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[1]);
  uVar8 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[1] >> 0x20);
  uVar7 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar3 = uVar8 + uVar5 + uVar2;
  if (CARRY4(uVar8,uVar5 + uVar2) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[2]);
  uVar5 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[2] >> 0x20);
  uVar6 = uVar7 + uVar2;
  if (CARRY4(uVar7,uVar2) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[3]);
  uVar5 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[3] >> 0x20);
  uVar8 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar2;
  if (CARRY4(uVar5,uVar2) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[4]);
  uVar5 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[4] >> 0x20);
  param_1[4] = uVar8 + uVar2;
  if (CARRY4(uVar8,uVar2) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[5]);
  uVar5 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[5] >> 0x20);
  uVar6 = uVar2 + uVar3;
  if (CARRY4(uVar2,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = (uint)(CARRY4(uVar5,uVar4) != false);
  uVar3 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[4]);
  uVar8 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[4] >> 0x20);
  uVar7 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar3 = uVar8 + uVar5 + uVar4;
  if (CARRY4(uVar8,uVar5 + uVar4) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[3]);
  uVar5 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[3] >> 0x20);
  uVar6 = uVar7 + uVar4;
  if (CARRY4(uVar7,uVar4) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar4 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[2]);
  uVar5 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[2] >> 0x20);
  uVar8 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar4;
  if (CARRY4(uVar5,uVar4) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[1]);
  uVar5 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[1] >> 0x20);
  uVar6 = uVar8 + uVar4;
  if (CARRY4(uVar8,uVar4) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar4 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[5] * (ulonglong)*param_3);
  uVar5 = (uint)((ulonglong)param_2[5] * (ulonglong)*param_3 >> 0x20);
  param_1[5] = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar4;
  if (CARRY4(uVar5,uVar4) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[6] * (ulonglong)*param_3);
  uVar5 = (uint)((ulonglong)param_2[6] * (ulonglong)*param_3 >> 0x20);
  uVar6 = uVar3 + uVar4;
  if (CARRY4(uVar3,uVar4) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar4 = (uint)(CARRY4(uVar5,uVar2) != false);
  uVar3 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[1]);
  uVar8 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[1] >> 0x20);
  uVar7 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar3 = uVar8 + uVar5 + uVar2;
  if (CARRY4(uVar8,uVar5 + uVar2) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[2]);
  uVar5 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[2] >> 0x20);
  uVar6 = uVar7 + uVar2;
  if (CARRY4(uVar7,uVar2) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[3]);
  uVar5 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[3] >> 0x20);
  uVar8 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar2;
  if (CARRY4(uVar5,uVar2) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[4]);
  uVar5 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[4] >> 0x20);
  uVar6 = uVar8 + uVar2;
  if (CARRY4(uVar8,uVar2) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[5]);
  uVar5 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[5] >> 0x20);
  uVar8 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar2;
  if (CARRY4(uVar5,uVar2) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[6]);
  uVar5 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[6] >> 0x20);
  param_1[6] = uVar8 + uVar2;
  if (CARRY4(uVar8,uVar2) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[7]);
  uVar5 = (uint)((ulonglong)*param_2 * (ulonglong)param_3[7] >> 0x20);
  uVar6 = uVar2 + uVar3;
  if (CARRY4(uVar2,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = (uint)(CARRY4(uVar5,uVar4) != false);
  uVar3 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[6]);
  uVar8 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[6] >> 0x20);
  uVar7 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar3 = uVar8 + uVar5 + uVar4;
  if (CARRY4(uVar8,uVar5 + uVar4) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[5]);
  uVar5 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[5] >> 0x20);
  uVar6 = uVar7 + uVar4;
  if (CARRY4(uVar7,uVar4) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar4 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[4]);
  uVar5 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[4] >> 0x20);
  uVar8 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar4;
  if (CARRY4(uVar5,uVar4) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[3]);
  uVar5 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[3] >> 0x20);
  uVar6 = uVar8 + uVar4;
  if (CARRY4(uVar8,uVar4) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar4 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[2]);
  uVar5 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[2] >> 0x20);
  uVar8 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar4;
  if (CARRY4(uVar5,uVar4) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[1]);
  uVar5 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[1] >> 0x20);
  uVar6 = uVar8 + uVar4;
  if (CARRY4(uVar8,uVar4) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar4 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[7] * (ulonglong)*param_3);
  uVar5 = (uint)((ulonglong)param_2[7] * (ulonglong)*param_3 >> 0x20);
  param_1[7] = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar4;
  if (CARRY4(uVar5,uVar4) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[7] * (ulonglong)param_3[1]);
  uVar5 = (uint)((ulonglong)param_2[7] * (ulonglong)param_3[1] >> 0x20);
  uVar6 = uVar3 + uVar4;
  if (CARRY4(uVar3,uVar4) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar4 = (uint)(CARRY4(uVar5,uVar2) != false);
  uVar3 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[2]);
  uVar8 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[2] >> 0x20);
  uVar7 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar3 = uVar8 + uVar5 + uVar2;
  if (CARRY4(uVar8,uVar5 + uVar2) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[3]);
  uVar5 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[3] >> 0x20);
  uVar6 = uVar7 + uVar2;
  if (CARRY4(uVar7,uVar2) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[4]);
  uVar5 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[4] >> 0x20);
  uVar8 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar2;
  if (CARRY4(uVar5,uVar2) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[5]);
  uVar5 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[5] >> 0x20);
  uVar6 = uVar8 + uVar2;
  if (CARRY4(uVar8,uVar2) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[6]);
  uVar5 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[6] >> 0x20);
  uVar8 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar2;
  if (CARRY4(uVar5,uVar2) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[7]);
  uVar5 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[7] >> 0x20);
  param_1[8] = uVar8 + uVar2;
  if (CARRY4(uVar8,uVar2) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[7]);
  uVar5 = (uint)((ulonglong)param_2[2] * (ulonglong)param_3[7] >> 0x20);
  uVar6 = uVar2 + uVar3;
  if (CARRY4(uVar2,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = (uint)(CARRY4(uVar5,uVar4) != false);
  uVar3 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[6]);
  uVar8 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[6] >> 0x20);
  uVar7 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar3 = uVar8 + uVar5 + uVar4;
  if (CARRY4(uVar8,uVar5 + uVar4) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[5]);
  uVar5 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[5] >> 0x20);
  uVar6 = uVar7 + uVar4;
  if (CARRY4(uVar7,uVar4) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar4 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[4]);
  uVar5 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[4] >> 0x20);
  uVar8 = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar4;
  if (CARRY4(uVar5,uVar4) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[3]);
  uVar5 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[3] >> 0x20);
  uVar6 = uVar8 + uVar4;
  if (CARRY4(uVar8,uVar4) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar4 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[7] * (ulonglong)param_3[2]);
  uVar5 = (uint)((ulonglong)param_2[7] * (ulonglong)param_3[2] >> 0x20);
  param_1[9] = uVar6 + uVar3;
  if (CARRY4(uVar6,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar4;
  if (CARRY4(uVar5,uVar4) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[7] * (ulonglong)param_3[3]);
  uVar5 = (uint)((ulonglong)param_2[7] * (ulonglong)param_3[3] >> 0x20);
  uVar6 = uVar3 + uVar4;
  if (CARRY4(uVar3,uVar4) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar8 = (uint)(CARRY4(uVar5,uVar2) != false);
  uVar4 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[4]);
  uVar3 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[4] >> 0x20);
  uVar7 = uVar6 + uVar4;
  if (CARRY4(uVar6,uVar4) != false) {
    uVar3 = uVar3 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[5]);
  uVar6 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[5] >> 0x20);
  uVar9 = uVar3 + uVar5 + uVar2;
  if (CARRY4(uVar3,uVar5 + uVar2) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar2 = uVar7 + uVar4;
  if (CARRY4(uVar7,uVar4) != false) {
    uVar6 = uVar6 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[6]);
  uVar3 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[6] >> 0x20);
  uVar5 = uVar6 + uVar9;
  if (CARRY4(uVar6,uVar9) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar6 = uVar2 + uVar4;
  if (CARRY4(uVar2,uVar4) != false) {
    uVar3 = uVar3 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[7]);
  uVar2 = (uint)((ulonglong)param_2[3] * (ulonglong)param_3[7] >> 0x20);
  uVar7 = uVar3 + uVar5;
  if (CARRY4(uVar3,uVar5) != false) {
    uVar8 = uVar8 + 1;
  }
  param_1[10] = uVar6 + uVar4;
  if (CARRY4(uVar6,uVar4) != false) {
    uVar2 = uVar2 + 1;
  }
  uVar5 = uVar2 + uVar7;
  uVar4 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[7]);
  uVar3 = (uint)((ulonglong)param_2[4] * (ulonglong)param_3[7] >> 0x20);
  if (CARRY4(uVar2,uVar7) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar2 = uVar5 + uVar4;
  if (CARRY4(uVar5,uVar4) != false) {
    uVar3 = uVar3 + 1;
  }
  uVar4 = (uint)(CARRY4(uVar3,uVar8) != false);
  uVar5 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[6]);
  uVar6 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[6] >> 0x20);
  uVar7 = uVar2 + uVar5;
  if (CARRY4(uVar2,uVar5) != false) {
    uVar6 = uVar6 + 1;
  }
  uVar2 = uVar6 + uVar3 + uVar8;
  if (CARRY4(uVar6,uVar3 + uVar8) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[5]);
  uVar5 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[5] >> 0x20);
  uVar6 = uVar7 + uVar3;
  if (CARRY4(uVar7,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 + uVar2;
  if (CARRY4(uVar5,uVar2) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = (uint)((ulonglong)param_2[7] * (ulonglong)param_3[4]);
  uVar5 = (uint)((ulonglong)param_2[7] * (ulonglong)param_3[4] >> 0x20);
  param_1[0xb] = uVar6 + uVar2;
  if (CARRY4(uVar6,uVar2) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar2 = uVar5 + uVar3;
  if (CARRY4(uVar5,uVar3) != false) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[7] * (ulonglong)param_3[5]);
  uVar5 = (uint)((ulonglong)param_2[7] * (ulonglong)param_3[5] >> 0x20);
  uVar6 = uVar2 + uVar3;
  if (CARRY4(uVar2,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar8 = (uint)(CARRY4(uVar5,uVar4) != false);
  uVar2 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[6]);
  uVar3 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[6] >> 0x20);
  uVar7 = uVar6 + uVar2;
  if (CARRY4(uVar6,uVar2) != false) {
    uVar3 = uVar3 + 1;
  }
  uVar2 = uVar3 + uVar5 + uVar4;
  if (CARRY4(uVar3,uVar5 + uVar4) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar4 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[7]);
  uVar3 = (uint)((ulonglong)param_2[5] * (ulonglong)param_3[7] >> 0x20);
  param_1[0xc] = uVar7 + uVar4;
  if (CARRY4(uVar7,uVar4) != false) {
    uVar3 = uVar3 + 1;
  }
  uVar4 = uVar3 + uVar2;
  if (CARRY4(uVar3,uVar2) != false) {
    uVar8 = uVar8 + 1;
  }
  uVar3 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[7]);
  uVar5 = (uint)((ulonglong)param_2[6] * (ulonglong)param_3[7] >> 0x20);
  uVar2 = uVar4 + uVar3;
  if (CARRY4(uVar4,uVar3) != false) {
    uVar5 = uVar5 + 1;
  }
  uVar6 = (uint)(CARRY4(uVar5,uVar8) != false);
  uVar4 = (uint)((ulonglong)param_2[7] * (ulonglong)param_3[6]);
  uVar3 = (uint)((ulonglong)param_2[7] * (ulonglong)param_3[6] >> 0x20);
  param_1[0xd] = uVar2 + uVar4;
  if (CARRY4(uVar2,uVar4) != false) {
    uVar3 = uVar3 + 1;
  }
  uVar2 = uVar3 + uVar5 + uVar8;
  uVar4 = (uint)((ulonglong)param_2[7] * (ulonglong)param_3[7]);
  iVar1 = (int)((ulonglong)param_2[7] * (ulonglong)param_3[7] >> 0x20);
  if (CARRY4(uVar3,uVar5 + uVar8) != false) {
    uVar6 = uVar6 + 1;
  }
  param_1[0xe] = uVar2 + uVar4;
  if (CARRY4(uVar2,uVar4) != false) {
    iVar1 = iVar1 + 1;
  }
  param_1[0xf] = iVar1 + uVar6;
  return;
}

