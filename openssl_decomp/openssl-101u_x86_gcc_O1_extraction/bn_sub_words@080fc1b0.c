
ulong bn_sub_words(ulong *rp,ulong *ap,ulong *bp,int num)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (num < 1) {
    return 0;
  }
  uVar4 = 0;
  if ((num & 0xfffffffcU) != 0) {
    do {
      uVar1 = *ap;
      uVar5 = *bp;
      *rp = (uVar1 - uVar5) - uVar4;
      if (uVar1 != uVar5) {
        uVar4 = (uint)(uVar1 < uVar5);
      }
      uVar1 = ap[1];
      uVar5 = bp[1];
      rp[1] = (uVar1 - uVar5) - uVar4;
      uVar3 = ap[2];
      if (uVar1 != uVar5) {
        uVar4 = (uint)(uVar1 < uVar5);
      }
      uVar1 = bp[2];
      rp[2] = (uVar3 - uVar1) - uVar4;
      uVar2 = (uint)(uVar3 < uVar1);
      uVar5 = ap[3];
      if (uVar3 == uVar1) {
        uVar2 = uVar4;
      }
      uVar1 = bp[3];
      rp[3] = (uVar5 - uVar1) - uVar2;
      uVar4 = uVar2;
      if (uVar5 != uVar1) {
        uVar4 = (uint)(uVar5 < uVar1);
      }
      num = num - 4;
      ap = ap + 4;
      bp = bp + 4;
      rp = rp + 4;
    } while ((num & 0xfffffffcU) != 0);
    if (num == 0) {
      return uVar4;
    }
  }
  uVar1 = *ap;
  uVar5 = *bp;
  *rp = (uVar1 - uVar5) - uVar4;
  uVar3 = (uint)(uVar1 < uVar5);
  if (uVar5 == uVar1) {
    uVar3 = uVar4;
  }
  if (num != 1) {
    uVar4 = ap[1];
    uVar1 = bp[1];
    rp[1] = (uVar4 - uVar1) - uVar3;
    uVar5 = (uint)(uVar4 < uVar1);
    if (uVar4 == uVar1) {
      uVar5 = uVar3;
    }
    uVar3 = uVar5;
    if (num != 2) {
      uVar4 = ap[2];
      uVar1 = bp[2];
      rp[2] = (uVar4 - uVar1) - uVar5;
      uVar3 = (uint)(uVar4 < uVar1);
      if (uVar4 == uVar1) {
        uVar3 = uVar5;
      }
    }
  }
  return uVar3;
}

