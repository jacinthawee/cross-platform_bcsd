
ulong bn_add_words(ulong *rp,ulong *ap,ulong *bp,int num)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulong *puVar5;
  ulong *puVar6;
  ulong *puVar7;
  uint uVar8;
  uint uVar9;
  
  uVar1 = 0;
  if (0 < num) {
    if ((num & 0xfffffffcU) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
      puVar5 = rp;
      puVar6 = ap;
      puVar7 = bp;
      do {
        uVar8 = *puVar6;
        rp = puVar5 + 4;
        ap = puVar6 + 4;
        bp = puVar7 + 4;
        num = num - 4;
        uVar3 = uVar8 + *puVar7;
        *puVar5 = uVar3 + uVar1;
        uVar4 = puVar6[1];
        uVar2 = uVar4 + puVar7[1];
        uVar8 = uVar2 + (uint)(uVar3 + uVar1 < uVar3) + (uint)(uVar3 < uVar8);
        puVar5[1] = uVar8;
        uVar9 = puVar6[2];
        uVar3 = uVar9 + puVar7[2];
        uVar4 = uVar3 + (uint)(uVar8 < uVar2) + (uint)(uVar2 < uVar4);
        puVar5[2] = uVar4;
        uVar2 = puVar6[3];
        uVar8 = uVar2 + puVar7[3];
        uVar3 = uVar8 + (uint)(uVar4 < uVar3) + (uint)(uVar3 < uVar9);
        puVar5[3] = uVar3;
        uVar1 = (uint)(uVar3 < uVar8) + (uint)(uVar8 < uVar2);
        puVar5 = rp;
        puVar6 = ap;
        puVar7 = bp;
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return uVar1;
      }
    }
    uVar2 = *bp;
    uVar3 = uVar2 + *ap;
    *rp = uVar3 + uVar1;
    uVar1 = (uint)(uVar3 + uVar1 < uVar3) + (uint)(uVar3 < uVar2);
    if (num != 1) {
      uVar2 = bp[1];
      uVar3 = uVar2 + ap[1];
      rp[1] = uVar3 + uVar1;
      uVar1 = (uint)(uVar3 + uVar1 < uVar3) + (uint)(uVar3 < uVar2);
      if (num != 2) {
        uVar2 = ap[2];
        uVar3 = uVar2 + bp[2];
        rp[2] = uVar3 + uVar1;
        return (uint)(uVar3 + uVar1 < uVar3) + (uint)(uVar3 < uVar2);
      }
    }
  }
  return uVar1;
}

