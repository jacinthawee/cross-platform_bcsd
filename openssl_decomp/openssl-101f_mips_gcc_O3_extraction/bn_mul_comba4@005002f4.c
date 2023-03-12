
void bn_mul_comba4(undefined4 *param_1,uint *param_2,uint *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar4 = *param_2;
  uVar5 = *param_3;
  *param_1 = (int)((ulonglong)uVar4 * (ulonglong)uVar5);
  uVar6 = *param_2;
  uVar7 = param_3[1];
  uVar13 = (uint)((ulonglong)uVar6 * (ulonglong)uVar7);
  uVar4 = (int)((ulonglong)uVar4 * (ulonglong)uVar5 >> 0x20) + uVar13;
  lVar1 = (ulonglong)param_2[1] * (ulonglong)*param_3 + (ulonglong)uVar4;
  param_1[1] = (int)lVar1;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar4 = (uint)(uVar4 < uVar13) + (int)((ulonglong)uVar6 * (ulonglong)uVar7 >> 0x20) + uVar8;
  uVar2 = (ulonglong)param_2[2] * (ulonglong)*param_3 + (ulonglong)uVar4;
  uVar3 = (ulonglong)param_2[1] * (ulonglong)param_3[1] + (uVar2 & 0xffffffff);
  uVar5 = (uint)(uVar2 >> 0x20);
  uVar7 = (uint)(uVar3 >> 0x20);
  lVar1 = (ulonglong)*param_2 * (ulonglong)param_3[2] + (uVar3 & 0xffffffff);
  uVar4 = uVar5 + (uVar4 < uVar8);
  param_1[2] = (int)lVar1;
  uVar6 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar12 = uVar7 + uVar4;
  uVar8 = uVar6 + uVar12;
  uVar2 = (ulonglong)*param_2 * (ulonglong)param_3[3] + (ulonglong)uVar8;
  uVar3 = (ulonglong)param_2[1] * (ulonglong)param_3[2] + (uVar2 & 0xffffffff);
  uVar13 = (uint)(uVar2 >> 0x20);
  uVar2 = (ulonglong)param_2[2] * (ulonglong)param_3[1] + (uVar3 & 0xffffffff);
  uVar11 = (uint)(uVar3 >> 0x20);
  uVar6 = uVar13 + (uint)(uVar4 < uVar5) + (uint)(uVar12 < uVar7) + (uint)(uVar8 < uVar6);
  lVar1 = (ulonglong)param_2[3] * (ulonglong)*param_3 + (uVar2 & 0xffffffff);
  uVar8 = (uint)(uVar2 >> 0x20);
  param_1[3] = (int)lVar1;
  uVar10 = uVar11 + uVar6;
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar4 = uVar8 + uVar10;
  uVar12 = uVar7 + uVar4;
  uVar2 = (ulonglong)param_2[3] * (ulonglong)param_3[1] + (ulonglong)uVar12;
  uVar3 = (ulonglong)param_2[2] * (ulonglong)param_3[2] + (uVar2 & 0xffffffff);
  uVar5 = (uint)(uVar2 >> 0x20);
  uVar4 = uVar5 + (uint)(uVar6 < uVar13) + (uint)(uVar10 < uVar11) + (uint)(uVar4 < uVar8) +
                  (uint)(uVar12 < uVar7);
  lVar1 = (ulonglong)param_2[1] * (ulonglong)param_3[3] + (uVar3 & 0xffffffff);
  uVar13 = (uint)(uVar3 >> 0x20);
  param_1[4] = (int)lVar1;
  uVar9 = uVar13 + uVar4;
  uVar12 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar11 = uVar12 + uVar9;
  uVar2 = (ulonglong)param_2[2] * (ulonglong)param_3[3] + (ulonglong)uVar11;
  lVar1 = (ulonglong)param_2[3] * (ulonglong)param_3[2] + (uVar2 & 0xffffffff);
  param_1[5] = (int)lVar1;
  uVar6 = param_2[3];
  uVar7 = (uint)(uVar2 >> 0x20);
  uVar10 = param_3[3];
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar4 = uVar7 + (uint)(uVar4 < uVar5) + (uint)(uVar9 < uVar13) + (uint)(uVar11 < uVar12);
  uVar12 = (uint)((ulonglong)uVar6 * (ulonglong)uVar10);
  uVar5 = uVar8 + uVar4;
  uVar13 = uVar5 + uVar12;
  param_1[6] = uVar13;
  param_1[7] = (uint)(uVar13 < uVar12) + (int)((ulonglong)uVar6 * (ulonglong)uVar10 >> 0x20) +
               (uint)(uVar4 < uVar7) + (uint)(uVar5 < uVar8);
  return;
}

