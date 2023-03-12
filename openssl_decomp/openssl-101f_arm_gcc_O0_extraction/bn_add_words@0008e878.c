
ulong bn_add_words(ulong *rp,ulong *ap,ulong *bp,int num)

{
  ulong *puVar1;
  int iVar2;
  ulong *puVar3;
  ulong *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  ulong uVar11;
  
  if (num < 1) {
    return 0;
  }
  uVar11 = 0;
  puVar1 = rp;
  puVar3 = ap;
  puVar4 = bp;
  if ((num & 0xfffffffcU) != 0) {
    do {
      uVar5 = *puVar4;
      uVar6 = *puVar3;
      uVar7 = uVar6 + uVar5;
      *puVar1 = uVar7 + uVar11;
      uVar9 = (uint)CARRY4(uVar6,uVar5) + (uint)CARRY4(uVar7,uVar11);
      uVar7 = puVar4[1];
      num = num - 4;
      uVar5 = puVar3[1];
      bp = puVar4 + 4;
      ap = puVar3 + 4;
      rp = puVar1 + 4;
      uVar6 = uVar5 + uVar7;
      puVar1[1] = uVar6 + uVar9;
      uVar7 = (uint)CARRY4(uVar5,uVar7) + (uint)CARRY4(uVar6,uVar9);
      uVar9 = puVar4[2];
      uVar5 = puVar3[2];
      uVar6 = uVar5 + uVar9;
      puVar1[2] = uVar7 + uVar6;
      uVar8 = puVar4[3];
      uVar7 = (uint)CARRY4(uVar5,uVar9) + (uint)CARRY4(uVar7,uVar6);
      uVar5 = puVar3[3];
      uVar6 = uVar5 + uVar8;
      puVar1[3] = uVar6 + uVar7;
      uVar11 = (uint)CARRY4(uVar5,uVar8) + (uint)CARRY4(uVar6,uVar7);
      puVar1 = rp;
      puVar3 = ap;
      puVar4 = bp;
    } while ((num & 0xfffffffcU) != 0);
    if (num == 0) {
      return uVar11;
    }
  }
  iVar10 = 0;
  do {
    uVar5 = *(uint *)((int)ap + iVar10) + *(uint *)((int)bp + iVar10);
    iVar2 = uVar5 + uVar11;
    uVar11 = (uint)CARRY4(*(uint *)((int)ap + iVar10),*(uint *)((int)bp + iVar10)) +
             (uint)CARRY4(uVar5,uVar11);
    num = num - 1;
    *(int *)((int)rp + iVar10) = iVar2;
    iVar10 = iVar10 + 4;
  } while (num != 0);
  return uVar11;
}

