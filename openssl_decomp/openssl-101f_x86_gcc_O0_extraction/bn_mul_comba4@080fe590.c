
void bn_mul_comba4(undefined4 *param_1,uint *param_2,uint *param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar6 = *param_3;
  uVar4 = *param_2;
  *param_1 = (int)((ulonglong)uVar6 * (ulonglong)uVar4);
  lVar2 = (ulonglong)param_3[1] * (ulonglong)*param_2 +
          ((ulonglong)uVar6 * (ulonglong)uVar4 >> 0x20);
  lVar1 = (ulonglong)*param_3 * (ulonglong)param_2[1];
  uVar6 = (uint)CARRY4((int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4((uint)lVar2,(uint)lVar1),
                       (uint)((ulonglong)lVar2 >> 0x20));
  param_1[1] = (int)(lVar2 + lVar1);
  uVar3 = (ulonglong)*param_3 * (ulonglong)param_2[2] + ((ulonglong)(lVar2 + lVar1) >> 0x20);
  uVar7 = (uint)(uVar3 >> 0x20);
  uVar8 = uVar7 + uVar6;
  uVar3 = (ulonglong)param_3[1] * (ulonglong)param_2[1] + (uVar3 & 0xffffffff);
  uVar4 = (uint)(uVar3 >> 0x20);
  uVar9 = uVar8 + uVar4;
  lVar1 = (ulonglong)param_3[2] * (ulonglong)*param_2 + (uVar3 & 0xffffffff);
  uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
  param_1[2] = (int)lVar1;
  uVar8 = (uint)CARRY4(uVar7,uVar6) + (uint)CARRY4(uVar8,uVar4) + (uint)CARRY4(uVar9,uVar5);
  uVar3 = (ulonglong)param_3[3] * (ulonglong)*param_2 + (ulonglong)(uVar9 + uVar5);
  uVar6 = (uint)(uVar3 >> 0x20);
  uVar9 = uVar8 + uVar6;
  uVar3 = (ulonglong)param_3[2] * (ulonglong)param_2[1] + (uVar3 & 0xffffffff);
  uVar4 = (uint)(uVar3 >> 0x20);
  uVar10 = uVar9 + uVar4;
  uVar3 = (ulonglong)param_3[1] * (ulonglong)param_2[2] + (uVar3 & 0xffffffff);
  uVar5 = (uint)(uVar3 >> 0x20);
  uVar11 = uVar10 + uVar5;
  lVar1 = (ulonglong)*param_3 * (ulonglong)param_2[3] + (uVar3 & 0xffffffff);
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  param_1[3] = (int)lVar1;
  uVar8 = (uint)CARRY4(uVar8,uVar6) + (uint)CARRY4(uVar9,uVar4) + (uint)CARRY4(uVar10,uVar5) +
          (uint)CARRY4(uVar11,uVar7);
  uVar3 = (ulonglong)param_3[1] * (ulonglong)param_2[3] + (ulonglong)(uVar11 + uVar7);
  uVar6 = (uint)(uVar3 >> 0x20);
  uVar7 = uVar8 + uVar6;
  uVar3 = (ulonglong)param_3[2] * (ulonglong)param_2[2] + (uVar3 & 0xffffffff);
  uVar4 = (uint)(uVar3 >> 0x20);
  uVar9 = uVar7 + uVar4;
  lVar1 = (ulonglong)param_3[3] * (ulonglong)param_2[1] + (uVar3 & 0xffffffff);
  uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
  param_1[4] = (int)lVar1;
  uVar7 = (uint)CARRY4(uVar8,uVar6) + (uint)CARRY4(uVar7,uVar4) + (uint)CARRY4(uVar9,uVar5);
  uVar3 = (ulonglong)param_3[3] * (ulonglong)param_2[2] + (ulonglong)(uVar9 + uVar5);
  uVar6 = (uint)(uVar3 >> 0x20);
  uVar5 = uVar7 + uVar6;
  lVar1 = (ulonglong)param_3[2] * (ulonglong)param_2[3] + (uVar3 & 0xffffffff);
  uVar4 = (uint)((ulonglong)lVar1 >> 0x20);
  param_1[5] = (int)lVar1;
  *(ulonglong *)(param_1 + 6) =
       (ulonglong)param_3[3] * (ulonglong)param_2[3] +
       CONCAT44((uint)CARRY4(uVar7,uVar6) + (uint)CARRY4(uVar5,uVar4),uVar5 + uVar4);
  return;
}

