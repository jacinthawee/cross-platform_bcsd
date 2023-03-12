
ulong bn_add_words(ulong *rp,ulong *ap,ulong *bp,int num)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  
  if (num < 1) {
    return 0;
  }
  uVar2 = 0;
  if ((num & 0xfffffffcU) != 0) {
    do {
      uVar1 = *bp + *ap;
      uVar3 = (uint)CARRY4(*bp,*ap) + (uint)CARRY4(uVar1,uVar2);
      *rp = uVar1 + uVar2;
      uVar2 = bp[1] + ap[1];
      uVar1 = (uint)CARRY4(bp[1],ap[1]) + (uint)CARRY4(uVar3,uVar2);
      rp[1] = uVar3 + uVar2;
      uVar2 = bp[2] + ap[2];
      uVar3 = (uint)CARRY4(bp[2],ap[2]) + (uint)CARRY4(uVar2,uVar1);
      rp[2] = uVar2 + uVar1;
      uVar1 = bp[3] + ap[3];
      uVar2 = (uint)CARRY4(bp[3],ap[3]) + (uint)CARRY4(uVar1,uVar3);
      num = num - 4;
      ap = ap + 4;
      bp = bp + 4;
      rp[3] = uVar1 + uVar3;
      rp = rp + 4;
    } while ((num & 0xfffffffcU) != 0);
    if (num == 0) {
      return uVar2;
    }
  }
  uVar1 = *ap + *bp;
  uVar5 = (uint)CARRY4(*ap,*bp) + (uint)CARRY4(uVar1,uVar2);
  *rp = uVar1 + uVar2;
  if (num != 1) {
    uVar2 = ap[1] + bp[1];
    uVar4 = uVar2 + uVar5;
    uVar5 = (uint)CARRY4(ap[1],bp[1]) + (uint)CARRY4(uVar2,uVar5);
    rp[1] = uVar4;
    if (num != 2) {
      uVar2 = bp[2] + ap[2];
      uVar4 = uVar2 + uVar5;
      uVar5 = (uint)CARRY4(bp[2],ap[2]) + (uint)CARRY4(uVar2,uVar5);
      rp[2] = uVar4;
    }
  }
  return uVar5;
}

