
undefined4
bn_mul_mont(undefined4 param_1,uint *param_2,uint *param_3,uint *param_4,undefined4 param_5,
           int param_6)

{
  bool bVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined4 uVar4;
  uint **ppuVar5;
  uint *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint **ppuVar11;
  uint **ppuVar12;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  int iVar17;
  uint *puVar18;
  uint *puVar19;
  uint *puVar20;
  uint *puVar21;
  uint uVar22;
  uint *in_lr;
  bool bVar23;
  uint *apuStack_38 [2];
  uint **ppuVar13;
  
  if (param_6 < 2) {
    uVar4 = 0;
  }
  else {
    uVar8 = *param_3;
    uVar14 = *param_2;
    uVar15 = *param_4;
    puVar20 = (uint *)*apuStack_38[0xe];
    apuStack_38[0xf] = param_3 + param_6 + -1;
    uVar2 = (ulonglong)uVar8 * (ulonglong)uVar14;
    uVar22 = (uint)(uVar2 >> 0x20);
    apuStack_38[0xe] = puVar20;
    uVar14 = (int)uVar2 * (int)puVar20;
    uVar15 = (uint)((ulonglong)uVar14 * (ulonglong)uVar15 + (uVar2 & 0xffffffff) >> 0x20);
    puVar20 = param_2 + 1;
    puVar21 = param_4 + 1;
    ppuVar11 = apuStack_38 + (1 - param_6);
    do {
      puVar16 = puVar20 + 1;
      puVar19 = puVar21 + 1;
      uVar2 = (ulonglong)uVar8 * (ulonglong)*puVar20 + (ulonglong)uVar22;
      uVar22 = (uint)(uVar2 >> 0x20);
      lVar3 = (ulonglong)uVar14 * (ulonglong)*puVar21 + (ulonglong)uVar15 + (uVar2 & 0xffffffff);
      ppuVar12 = ppuVar11 + 1;
      *ppuVar11 = (uint *)lVar3;
      uVar15 = (uint)((ulonglong)lVar3 >> 0x20);
      puVar20 = puVar16;
      puVar21 = puVar19;
      ppuVar11 = ppuVar12;
    } while (ppuVar12 != apuStack_38);
    puVar20 = apuStack_38[0xd];
    puVar21 = apuStack_38[0xe];
    apuStack_38[0] = (uint *)(uVar15 + uVar22);
    apuStack_38[1] = (uint *)(uint)CARRY4(uVar15,uVar22);
    do {
      iVar17 = (int)apuStack_38 - (int)(apuStack_38 + (1 - param_6));
      puVar6 = (uint *)((int)puVar16 - iVar17);
      uVar8 = puVar20[1];
      puVar10 = (uint *)((int)puVar19 - iVar17);
      uVar14 = puVar10[-1];
      puVar18 = *(uint **)(&stack0xffffffd0 + param_6 * -4);
      uVar2 = (ulonglong)uVar8 * (ulonglong)puVar6[-1] + ZEXT48(apuStack_38[1 - param_6]);
      uVar22 = (uint)(uVar2 >> 0x20);
      apuStack_38[0xd] = puVar20 + 1;
      uVar15 = (int)uVar2 * (int)puVar21;
      uVar14 = (uint)((ulonglong)uVar15 * (ulonglong)uVar14 + (uVar2 & 0xffffffff) >> 0x20);
      ppuVar11 = apuStack_38 + (1 - param_6);
      do {
        puVar16 = puVar6 + 1;
        puVar19 = puVar10 + 1;
        uVar2 = (ulonglong)uVar8 * (ulonglong)*puVar6 + (ulonglong)(uVar22 + (int)puVar18);
        uVar22 = (int)(uVar2 >> 0x20) + (uint)CARRY4(uVar22,(uint)puVar18);
        puVar18 = ppuVar11[2];
        lVar3 = (ulonglong)uVar15 * (ulonglong)*puVar10 + (ulonglong)uVar14 + (uVar2 & 0xffffffff);
        ppuVar12 = ppuVar11 + 1;
        *ppuVar11 = (uint *)lVar3;
        uVar14 = (uint)((ulonglong)lVar3 >> 0x20);
        puVar6 = puVar16;
        puVar10 = puVar19;
        ppuVar11 = ppuVar12;
      } while (ppuVar12 != apuStack_38);
      puVar20 = apuStack_38[0xd];
      puVar21 = apuStack_38[0xe];
      puVar6 = (uint *)((uint)CARRY4(uVar14,uVar22) + (uint)CARRY4(uVar14 + uVar22,(uint)puVar18));
      apuStack_38[0] = (uint *)(uVar14 + uVar22 + (int)puVar18);
      apuStack_38[1] = puVar6;
    } while (puVar20 != apuStack_38[0xf]);
    ppuVar5 = apuStack_38 + 1;
    puVar20 = apuStack_38[0xc];
    ppuVar11 = (uint **)((int)puVar19 - ((int)ppuVar5 - (int)(apuStack_38 + (1 - param_6))));
    ppuVar12 = apuStack_38 + (1 - param_6);
    bVar23 = true;
    do {
      ppuVar13 = ppuVar12 + 1;
      puVar19 = *ppuVar12;
      puVar16 = *ppuVar11;
      bVar1 = (uint)((int)puVar19 - (int)puVar16) < (uint)bVar23;
      puVar21 = puVar20 + 1;
      *puVar20 = (int)puVar19 - ((int)puVar16 + (uint)!bVar23);
      puVar20 = puVar21;
      ppuVar11 = ppuVar11 + 1;
      ppuVar12 = ppuVar13;
      bVar23 = puVar16 < puVar19 || bVar1;
    } while (ppuVar13 != ppuVar5);
    uVar8 = (int)puVar6 - (uint)(puVar16 >= puVar19 && !bVar1);
    puVar9 = (undefined4 *)((int)puVar21 - ((int)ppuVar5 - (int)(apuStack_38 + (1 - param_6))));
    puVar7 = (undefined4 *)((uint)(apuStack_38 + (1 - param_6)) & uVar8 | (uint)puVar9 & ~uVar8);
    ppuVar11 = apuStack_38 + (1 - param_6);
    do {
      uVar4 = *puVar7;
      ppuVar12 = ppuVar11 + 1;
      *ppuVar11 = (uint *)(apuStack_38 + (1 - param_6));
      *puVar9 = uVar4;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
      ppuVar11 = ppuVar12;
    } while (ppuVar12 != ppuVar5);
    in_lr = apuStack_38[0xb];
    uVar4 = 1;
  }
  if (((uint)in_lr & 1) != 0) {
    return uVar4;
  }
  return uVar4;
}

