
ulong bn_sub_words(ulong *rp,ulong *ap,ulong *bp,int num)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  
  if (num < 1) {
    uVar7 = 0;
  }
  else {
    uVar7 = num & 0xfffffffc;
    if (uVar7 != 0) {
      uVar7 = 0;
      puVar1 = rp;
      puVar2 = ap;
      puVar3 = bp;
      do {
        uVar8 = *puVar2;
        num = num - 4;
        uVar4 = *puVar3;
        ap = puVar2 + 4;
        bp = puVar3 + 4;
        rp = puVar1 + 4;
        uVar10 = uVar8 - uVar4;
        *puVar1 = uVar10 - uVar7;
        uVar9 = puVar2[1];
        if (uVar8 < uVar4) {
          uVar10 = 1;
        }
        uVar5 = puVar3[1];
        if (uVar8 >= uVar4) {
          uVar10 = 0;
        }
        if (uVar8 != uVar4) {
          uVar7 = uVar10;
        }
        uVar10 = uVar9 - uVar5;
        puVar1[1] = uVar10 - uVar7;
        uVar4 = puVar2[2];
        if (uVar9 < uVar5) {
          uVar10 = 1;
        }
        uVar8 = puVar3[2];
        if (uVar9 >= uVar5) {
          uVar10 = 0;
        }
        if (uVar9 != uVar5) {
          uVar7 = uVar10;
        }
        uVar10 = uVar4 - uVar8;
        puVar1[2] = uVar10 - uVar7;
        uVar9 = puVar2[3];
        if (uVar4 < uVar8) {
          uVar10 = 1;
        }
        uVar5 = puVar3[3];
        if (uVar4 >= uVar8) {
          uVar10 = 0;
        }
        if (uVar4 != uVar8) {
          uVar7 = uVar10;
        }
        puVar1[3] = (uVar9 - uVar5) - uVar7;
        if (uVar9 != uVar5) {
          uVar7 = (uint)(uVar9 < uVar5);
        }
        puVar1 = rp;
        puVar2 = ap;
        puVar3 = bp;
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return uVar7;
      }
    }
    iVar6 = 0;
    do {
      uVar8 = *(uint *)((int)ap + iVar6);
      uVar4 = *(uint *)((int)bp + iVar6);
      *(uint *)((int)rp + iVar6) = (uVar8 - uVar4) - uVar7;
      if (uVar8 != uVar4) {
        uVar7 = (uint)(uVar8 < uVar4);
      }
      num = num - 1;
      iVar6 = iVar6 + 4;
    } while (num != 0);
  }
  return uVar7;
}

