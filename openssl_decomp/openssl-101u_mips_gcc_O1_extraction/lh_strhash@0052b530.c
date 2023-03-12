
ulong lh_strhash(char *c)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (c == (char *)0x0) {
    return 0;
  }
  uVar4 = (uint)*c;
  uVar2 = 0;
  if (uVar4 != 0) {
    uVar5 = 0x100;
    do {
      uVar3 = uVar4 | uVar5;
      uVar4 = (uint)c[1];
      c = c + 1;
      uVar1 = -((uVar3 >> 2 ^ uVar3) & 0xf) & 0x1f;
      uVar5 = uVar5 + 0x100;
      uVar2 = uVar3 * uVar3 ^ (uVar2 >> uVar1) + (uVar2 << 0x20 - uVar1);
    } while (uVar4 != 0);
    return uVar2 >> 0x10 ^ uVar2;
  }
  return uVar2;
}

