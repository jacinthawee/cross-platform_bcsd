
int CRYPTO_memcmp(void *a,void *b,size_t len)

{
  byte bVar1;
  uint uVar2;
  size_t sVar3;
  byte *pbVar4;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar5;
  
  uVar2 = 0;
  if (len != 0) {
    if (((((uint)b | (uint)a) & 3) != 0) || (len < 9)) {
      uVar2 = 0;
      pbVar5 = (byte *)a;
      do {
        pbVar4 = pbVar5 + 1;
                    /* WARNING: Load size is inaccurate */
        bVar1 = *b;
        b = (void *)((int)b + 1);
        uVar2 = uVar2 | bVar1 ^ *pbVar5;
        pbVar5 = pbVar4;
      } while (pbVar4 != (byte *)((int)a + len));
      return uVar2;
    }
    uVar10 = 0;
    uVar2 = 0;
    uVar6 = (len - 4 >> 2) + 1;
    sVar3 = uVar6 * 4;
    puVar8 = (uint *)b;
    puVar9 = (uint *)a;
    do {
      uVar7 = *puVar8;
      uVar10 = uVar10 + 1;
      uVar11 = *puVar9;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
      uVar2 = uVar2 | uVar7 ^ uVar11;
    } while (uVar10 < uVar6);
    uVar2 = (uVar2 | uVar2 << 8 | uVar2 << 0x10) >> 0x18 | uVar2 & 0xff;
    if (len != sVar3) {
      uVar6 = sVar3 + 1;
      uVar2 = uVar2 | *(byte *)((int)b + sVar3) ^ *(byte *)((int)a + sVar3);
      if (uVar6 < len) {
        uVar10 = sVar3 + 2;
        uVar2 = uVar2 | *(byte *)((int)a + uVar6) ^ *(byte *)((int)b + uVar6);
        if (uVar10 < len) {
          return uVar2 | *(byte *)((int)a + uVar10) ^ *(byte *)((int)b + uVar10);
        }
      }
    }
  }
  return uVar2;
}

