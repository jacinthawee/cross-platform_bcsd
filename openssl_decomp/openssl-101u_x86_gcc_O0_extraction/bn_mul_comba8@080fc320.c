
void bn_mul_comba8(undefined4 *param_1,uint *param_2,uint *param_3)

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
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  
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
  uVar12 = uVar9 + uVar4;
  uVar3 = (ulonglong)param_3[1] * (ulonglong)param_2[2] + (uVar3 & 0xffffffff);
  uVar5 = (uint)(uVar3 >> 0x20);
  uVar13 = uVar12 + uVar5;
  lVar1 = (ulonglong)*param_3 * (ulonglong)param_2[3] + (uVar3 & 0xffffffff);
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  param_1[3] = (int)lVar1;
  uVar9 = (uint)CARRY4(uVar8,uVar6) + (uint)CARRY4(uVar9,uVar4) + (uint)CARRY4(uVar12,uVar5) +
          (uint)CARRY4(uVar13,uVar7);
  uVar3 = (ulonglong)*param_3 * (ulonglong)param_2[4] + (ulonglong)(uVar13 + uVar7);
  uVar6 = (uint)(uVar3 >> 0x20);
  uVar12 = uVar9 + uVar6;
  uVar3 = (ulonglong)param_3[1] * (ulonglong)param_2[3] + (uVar3 & 0xffffffff);
  uVar4 = (uint)(uVar3 >> 0x20);
  uVar13 = uVar12 + uVar4;
  uVar3 = (ulonglong)param_3[2] * (ulonglong)param_2[2] + (uVar3 & 0xffffffff);
  uVar5 = (uint)(uVar3 >> 0x20);
  uVar16 = uVar13 + uVar5;
  uVar3 = (ulonglong)param_3[3] * (ulonglong)param_2[1] + (uVar3 & 0xffffffff);
  uVar7 = (uint)(uVar3 >> 0x20);
  uVar17 = uVar16 + uVar7;
  lVar1 = (ulonglong)param_3[4] * (ulonglong)*param_2 + (uVar3 & 0xffffffff);
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  param_1[4] = (int)lVar1;
  uVar12 = (uint)CARRY4(uVar9,uVar6) + (uint)CARRY4(uVar12,uVar4) + (uint)CARRY4(uVar13,uVar5) +
           (uint)CARRY4(uVar16,uVar7) + (uint)CARRY4(uVar17,uVar8);
  uVar3 = (ulonglong)param_3[5] * (ulonglong)*param_2 + (ulonglong)(uVar17 + uVar8);
  uVar6 = (uint)(uVar3 >> 0x20);
  uVar13 = uVar12 + uVar6;
  uVar3 = (ulonglong)param_3[4] * (ulonglong)param_2[1] + (uVar3 & 0xffffffff);
  uVar4 = (uint)(uVar3 >> 0x20);
  uVar16 = uVar13 + uVar4;
  uVar3 = (ulonglong)param_3[3] * (ulonglong)param_2[2] + (uVar3 & 0xffffffff);
  uVar5 = (uint)(uVar3 >> 0x20);
  uVar17 = uVar16 + uVar5;
  uVar3 = (ulonglong)param_3[2] * (ulonglong)param_2[3] + (uVar3 & 0xffffffff);
  uVar7 = (uint)(uVar3 >> 0x20);
  uVar10 = uVar17 + uVar7;
  uVar3 = (ulonglong)param_3[1] * (ulonglong)param_2[4] + (uVar3 & 0xffffffff);
  uVar8 = (uint)(uVar3 >> 0x20);
  uVar11 = uVar10 + uVar8;
  lVar1 = (ulonglong)*param_3 * (ulonglong)param_2[5] + (uVar3 & 0xffffffff);
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar12 = (uint)CARRY4(uVar12,uVar6) + (uint)CARRY4(uVar13,uVar4) + (uint)CARRY4(uVar16,uVar5) +
           (uint)CARRY4(uVar17,uVar7) + (uint)CARRY4(uVar10,uVar8) + (uint)CARRY4(uVar11,uVar9);
  param_1[5] = (int)lVar1;
  uVar3 = (ulonglong)*param_3 * (ulonglong)param_2[6] + (ulonglong)(uVar11 + uVar9);
  uVar13 = (uint)(uVar3 >> 0x20);
  uVar16 = uVar13 + uVar12;
  uVar3 = (ulonglong)param_3[1] * (ulonglong)param_2[5] + (uVar3 & 0xffffffff);
  uVar6 = (uint)(uVar3 >> 0x20);
  uVar17 = uVar16 + uVar6;
  uVar3 = (ulonglong)param_3[2] * (ulonglong)param_2[4] + (uVar3 & 0xffffffff);
  uVar4 = (uint)(uVar3 >> 0x20);
  uVar10 = uVar17 + uVar4;
  uVar3 = (ulonglong)param_3[3] * (ulonglong)param_2[3] + (uVar3 & 0xffffffff);
  uVar5 = (uint)(uVar3 >> 0x20);
  uVar11 = uVar10 + uVar5;
  uVar3 = (ulonglong)param_3[4] * (ulonglong)param_2[2] + (uVar3 & 0xffffffff);
  uVar7 = (uint)(uVar3 >> 0x20);
  uVar18 = uVar11 + uVar7;
  uVar3 = (ulonglong)param_3[5] * (ulonglong)param_2[1] + (uVar3 & 0xffffffff);
  uVar8 = (uint)(uVar3 >> 0x20);
  uVar19 = uVar18 + uVar8;
  lVar1 = (ulonglong)param_3[6] * (ulonglong)*param_2 + (uVar3 & 0xffffffff);
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  param_1[6] = (int)lVar1;
  uVar16 = (uint)CARRY4(uVar13,uVar12) + (uint)CARRY4(uVar16,uVar6) + (uint)CARRY4(uVar17,uVar4) +
           (uint)CARRY4(uVar10,uVar5) + (uint)CARRY4(uVar11,uVar7) + (uint)CARRY4(uVar18,uVar8) +
           (uint)CARRY4(uVar19,uVar9);
  uVar3 = (ulonglong)param_3[7] * (ulonglong)*param_2 + (ulonglong)(uVar19 + uVar9);
  uVar6 = (uint)(uVar3 >> 0x20);
  uVar17 = uVar16 + uVar6;
  uVar3 = (ulonglong)param_3[6] * (ulonglong)param_2[1] + (uVar3 & 0xffffffff);
  uVar4 = (uint)(uVar3 >> 0x20);
  uVar10 = uVar17 + uVar4;
  uVar3 = (ulonglong)param_3[5] * (ulonglong)param_2[2] + (uVar3 & 0xffffffff);
  uVar5 = (uint)(uVar3 >> 0x20);
  uVar11 = uVar10 + uVar5;
  uVar3 = (ulonglong)param_3[4] * (ulonglong)param_2[3] + (uVar3 & 0xffffffff);
  uVar7 = (uint)(uVar3 >> 0x20);
  uVar18 = uVar11 + uVar7;
  uVar3 = (ulonglong)param_3[3] * (ulonglong)param_2[4] + (uVar3 & 0xffffffff);
  uVar8 = (uint)(uVar3 >> 0x20);
  uVar19 = uVar18 + uVar8;
  uVar3 = (ulonglong)param_3[2] * (ulonglong)param_2[5] + (uVar3 & 0xffffffff);
  uVar9 = (uint)(uVar3 >> 0x20);
  uVar14 = uVar19 + uVar9;
  uVar3 = (ulonglong)param_3[1] * (ulonglong)param_2[6] + (uVar3 & 0xffffffff);
  uVar12 = (uint)(uVar3 >> 0x20);
  uVar15 = uVar14 + uVar12;
  lVar1 = (ulonglong)*param_3 * (ulonglong)param_2[7] + (uVar3 & 0xffffffff);
  uVar13 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar16 = (uint)CARRY4(uVar16,uVar6) + (uint)CARRY4(uVar17,uVar4) + (uint)CARRY4(uVar10,uVar5) +
           (uint)CARRY4(uVar11,uVar7) + (uint)CARRY4(uVar18,uVar8) + (uint)CARRY4(uVar19,uVar9) +
           (uint)CARRY4(uVar14,uVar12) + (uint)CARRY4(uVar15,uVar13);
  param_1[7] = (int)lVar1;
  uVar3 = (ulonglong)param_3[1] * (ulonglong)param_2[7] + (ulonglong)(uVar15 + uVar13);
  uVar6 = (uint)(uVar3 >> 0x20);
  uVar13 = uVar16 + uVar6;
  uVar3 = (ulonglong)param_3[2] * (ulonglong)param_2[6] + (uVar3 & 0xffffffff);
  uVar4 = (uint)(uVar3 >> 0x20);
  uVar17 = uVar13 + uVar4;
  uVar3 = (ulonglong)param_3[3] * (ulonglong)param_2[5] + (uVar3 & 0xffffffff);
  uVar5 = (uint)(uVar3 >> 0x20);
  uVar10 = uVar17 + uVar5;
  uVar3 = (ulonglong)param_3[4] * (ulonglong)param_2[4] + (uVar3 & 0xffffffff);
  uVar7 = (uint)(uVar3 >> 0x20);
  uVar11 = uVar10 + uVar7;
  uVar3 = (ulonglong)param_3[5] * (ulonglong)param_2[3] + (uVar3 & 0xffffffff);
  uVar8 = (uint)(uVar3 >> 0x20);
  uVar18 = uVar11 + uVar8;
  uVar3 = (ulonglong)param_3[6] * (ulonglong)param_2[2] + (uVar3 & 0xffffffff);
  uVar9 = (uint)(uVar3 >> 0x20);
  uVar19 = uVar18 + uVar9;
  lVar1 = (ulonglong)param_3[7] * (ulonglong)param_2[1] + (uVar3 & 0xffffffff);
  uVar12 = (uint)((ulonglong)lVar1 >> 0x20);
  param_1[8] = (int)lVar1;
  uVar13 = (uint)CARRY4(uVar16,uVar6) + (uint)CARRY4(uVar13,uVar4) + (uint)CARRY4(uVar17,uVar5) +
           (uint)CARRY4(uVar10,uVar7) + (uint)CARRY4(uVar11,uVar8) + (uint)CARRY4(uVar18,uVar9) +
           (uint)CARRY4(uVar19,uVar12);
  uVar3 = (ulonglong)param_3[7] * (ulonglong)param_2[2] + (ulonglong)(uVar19 + uVar12);
  uVar6 = (uint)(uVar3 >> 0x20);
  uVar12 = uVar13 + uVar6;
  uVar3 = (ulonglong)param_3[6] * (ulonglong)param_2[3] + (uVar3 & 0xffffffff);
  uVar4 = (uint)(uVar3 >> 0x20);
  uVar16 = uVar12 + uVar4;
  uVar3 = (ulonglong)param_3[5] * (ulonglong)param_2[4] + (uVar3 & 0xffffffff);
  uVar5 = (uint)(uVar3 >> 0x20);
  uVar17 = uVar16 + uVar5;
  uVar3 = (ulonglong)param_3[4] * (ulonglong)param_2[5] + (uVar3 & 0xffffffff);
  uVar7 = (uint)(uVar3 >> 0x20);
  uVar10 = uVar17 + uVar7;
  uVar3 = (ulonglong)param_3[3] * (ulonglong)param_2[6] + (uVar3 & 0xffffffff);
  uVar8 = (uint)(uVar3 >> 0x20);
  uVar11 = uVar10 + uVar8;
  lVar1 = (ulonglong)param_3[2] * (ulonglong)param_2[7] + (uVar3 & 0xffffffff);
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  param_1[9] = (int)lVar1;
  uVar12 = (uint)CARRY4(uVar13,uVar6) + (uint)CARRY4(uVar12,uVar4) + (uint)CARRY4(uVar16,uVar5) +
           (uint)CARRY4(uVar17,uVar7) + (uint)CARRY4(uVar10,uVar8) + (uint)CARRY4(uVar11,uVar9);
  uVar3 = (ulonglong)param_3[3] * (ulonglong)param_2[7] + (ulonglong)(uVar11 + uVar9);
  uVar6 = (uint)(uVar3 >> 0x20);
  uVar9 = uVar12 + uVar6;
  uVar3 = (ulonglong)param_3[4] * (ulonglong)param_2[6] + (uVar3 & 0xffffffff);
  uVar4 = (uint)(uVar3 >> 0x20);
  uVar13 = uVar9 + uVar4;
  uVar3 = (ulonglong)param_3[5] * (ulonglong)param_2[5] + (uVar3 & 0xffffffff);
  uVar5 = (uint)(uVar3 >> 0x20);
  uVar16 = uVar13 + uVar5;
  uVar3 = (ulonglong)param_3[6] * (ulonglong)param_2[4] + (uVar3 & 0xffffffff);
  uVar7 = (uint)(uVar3 >> 0x20);
  uVar17 = uVar16 + uVar7;
  lVar1 = (ulonglong)param_3[7] * (ulonglong)param_2[3] + (uVar3 & 0xffffffff);
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  param_1[10] = (int)lVar1;
  uVar9 = (uint)CARRY4(uVar12,uVar6) + (uint)CARRY4(uVar9,uVar4) + (uint)CARRY4(uVar13,uVar5) +
          (uint)CARRY4(uVar16,uVar7) + (uint)CARRY4(uVar17,uVar8);
  uVar3 = (ulonglong)param_3[7] * (ulonglong)param_2[4] + (ulonglong)(uVar17 + uVar8);
  uVar6 = (uint)(uVar3 >> 0x20);
  uVar8 = uVar9 + uVar6;
  uVar3 = (ulonglong)param_3[6] * (ulonglong)param_2[5] + (uVar3 & 0xffffffff);
  uVar4 = (uint)(uVar3 >> 0x20);
  uVar12 = uVar8 + uVar4;
  uVar3 = (ulonglong)param_3[5] * (ulonglong)param_2[6] + (uVar3 & 0xffffffff);
  uVar5 = (uint)(uVar3 >> 0x20);
  uVar13 = uVar12 + uVar5;
  lVar1 = (ulonglong)param_3[4] * (ulonglong)param_2[7] + (uVar3 & 0xffffffff);
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  param_1[0xb] = (int)lVar1;
  uVar8 = (uint)CARRY4(uVar9,uVar6) + (uint)CARRY4(uVar8,uVar4) + (uint)CARRY4(uVar12,uVar5) +
          (uint)CARRY4(uVar13,uVar7);
  uVar3 = (ulonglong)param_3[5] * (ulonglong)param_2[7] + (ulonglong)(uVar13 + uVar7);
  uVar6 = (uint)(uVar3 >> 0x20);
  uVar7 = uVar8 + uVar6;
  uVar3 = (ulonglong)param_3[6] * (ulonglong)param_2[6] + (uVar3 & 0xffffffff);
  uVar4 = (uint)(uVar3 >> 0x20);
  uVar9 = uVar7 + uVar4;
  lVar1 = (ulonglong)param_3[7] * (ulonglong)param_2[5] + (uVar3 & 0xffffffff);
  uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
  param_1[0xc] = (int)lVar1;
  uVar7 = (uint)CARRY4(uVar8,uVar6) + (uint)CARRY4(uVar7,uVar4) + (uint)CARRY4(uVar9,uVar5);
  uVar3 = (ulonglong)param_3[7] * (ulonglong)param_2[6] + (ulonglong)(uVar9 + uVar5);
  uVar6 = (uint)(uVar3 >> 0x20);
  uVar5 = uVar7 + uVar6;
  lVar1 = (ulonglong)param_3[6] * (ulonglong)param_2[7] + (uVar3 & 0xffffffff);
  uVar4 = (uint)((ulonglong)lVar1 >> 0x20);
  param_1[0xd] = (int)lVar1;
  *(ulonglong *)(param_1 + 0xe) =
       (ulonglong)param_3[7] * (ulonglong)param_2[7] +
       CONCAT44((uint)CARRY4(uVar7,uVar6) + (uint)CARRY4(uVar5,uVar4),uVar5 + uVar4);
  return;
}
