
ulong lh_strhash(char *c)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  
  if (c != (char *)0x0) {
    bVar2 = *c;
    uVar1 = 0;
    if (bVar2 != 0) {
      uVar5 = 0x100;
      do {
        c = (char *)((byte *)c + 1);
        uVar4 = (int)(char)bVar2 | uVar5;
        uVar5 = uVar5 + 0x100;
        bVar3 = ((byte)(uVar4 >> 2) ^ bVar2) & 0xf;
        bVar2 = *c;
        uVar1 = (uVar1 << bVar3 | uVar1 >> 0x20 - bVar3) ^ uVar4 * uVar4;
      } while (bVar2 != 0);
      uVar1 = uVar1 ^ uVar1 >> 0x10;
    }
    return uVar1;
  }
  return 0;
}

