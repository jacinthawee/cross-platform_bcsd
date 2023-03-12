
ulong bn_sub_words(ulong *rp,ulong *ap,ulong *bp,int num)

{
  uint uVar1;
  ulong *puVar2;
  ulong *puVar3;
  ulong *puVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if (num < 1) {
    return 0;
  }
  uVar1 = 0;
  puVar2 = rp;
  puVar3 = ap;
  puVar4 = bp;
  if ((num & 0xfffffffcU) != 0) {
    do {
      uVar5 = *puVar3;
      rp = puVar2 + 4;
      uVar10 = *puVar4;
      ap = puVar3 + 4;
      bp = puVar4 + 4;
      num = num - 4;
      *puVar2 = (uVar5 - uVar10) - uVar1;
      uVar8 = puVar4[1];
      uVar6 = puVar3[1];
      if (uVar5 != uVar10) {
        uVar1 = (uint)(uVar5 < uVar10);
      }
      uVar5 = uVar1;
      if ((uVar6 ^ uVar8) != 0) {
        uVar5 = (uint)(uVar6 < uVar8);
      }
      puVar2[1] = (uVar6 - uVar8) - uVar1;
      uVar9 = puVar4[2];
      uVar10 = puVar3[2];
      if ((uVar6 ^ uVar8) != 0) {
        uVar1 = (uint)(uVar6 < uVar8);
      }
      uVar8 = (uint)(uVar10 < uVar9);
      uVar6 = uVar8;
      if (uVar10 == uVar9) {
        uVar8 = uVar1;
        uVar6 = uVar5;
      }
      puVar2[2] = (uVar10 - uVar9) - uVar5;
      uVar10 = puVar4[3];
      uVar5 = puVar3[3];
      uVar1 = uVar8;
      if ((uVar5 ^ uVar10) != 0) {
        uVar1 = (uint)(uVar5 < uVar10);
      }
      uVar8 = (uint)(uVar5 < uVar10);
      if ((uVar5 ^ uVar10) == 0) {
        uVar8 = uVar6;
      }
      puVar2[3] = (uVar5 - uVar10) - uVar6;
      puVar2 = rp;
      puVar3 = ap;
      puVar4 = bp;
    } while ((num & 0xfffffffcU) != 0);
    if (num == 0) {
      return uVar8;
    }
  }
  uVar8 = *ap;
  uVar6 = *bp;
  uVar5 = (uint)(uVar8 < uVar6);
  if (uVar6 == uVar8) {
    uVar5 = uVar1;
  }
  *rp = (uVar8 - uVar6) - uVar1;
  if (num != 1) {
    uVar8 = ap[1];
    uVar6 = bp[1];
    uVar7 = (uVar8 - uVar6) - uVar5;
    uVar1 = (uint)(uVar8 < uVar6);
    if (uVar8 == uVar6) {
      uVar1 = uVar5;
    }
    uVar5 = uVar1;
    rp[1] = uVar7;
    if (num != 2) {
      uVar1 = ap[2];
      uVar6 = bp[2];
      uVar7 = (uVar1 - uVar6) - uVar5;
      if (uVar1 != uVar6) {
        uVar5 = (uint)(uVar1 < uVar6);
      }
      rp[2] = uVar7;
    }
  }
  return uVar5;
}

