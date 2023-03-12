
int CRYPTO_memcmp(void *a,void *b,size_t len)

{
  byte *pbVar1;
  byte *pbVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  size_t sVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  if (len == 0) {
    return 0;
  }
  sVar6 = (size_t)((((uint)a | (uint)b) & 3) == 0);
  if (len < 9) {
    sVar6 = 0;
  }
  uVar9 = sVar6;
  if (sVar6 == 0) {
    do {
      pbVar1 = (byte *)((int)a + sVar6);
      pbVar2 = (byte *)((int)b + sVar6);
      sVar6 = sVar6 + 1;
      uVar9 = uVar9 | *pbVar2 ^ *pbVar1;
    } while (sVar6 != len);
    return uVar9;
  }
  iVar5 = 0;
  uVar8 = 0;
  uVar7 = 0;
  uVar9 = len & 0xfffffffc;
  do {
    puVar3 = (uint *)((int)b + iVar5);
    uVar8 = uVar8 + 1;
    puVar4 = (uint *)((int)a + iVar5);
    iVar5 = iVar5 + 4;
    uVar7 = *puVar3 ^ *puVar4 | uVar7;
  } while (uVar8 < len >> 2);
  uVar7 = (uVar7 | uVar7 >> 8 | uVar7 >> 0x10) & 0xff | uVar7 >> 0x18;
  if (len != uVar9) {
    uVar8 = uVar9 + 1;
    uVar7 = uVar7 | *(byte *)((int)a + (len & 0xfffffffc)) ^ *(byte *)((int)b + (len & 0xfffffffc));
    if (uVar8 < len) {
      uVar9 = uVar9 + 2;
      uVar7 = uVar7 | *(byte *)((int)a + uVar8) ^ *(byte *)((int)b + uVar8);
      if (uVar9 < len) {
        uVar7 = uVar7 | *(byte *)((int)a + uVar9) ^ *(byte *)((int)b + uVar9);
      }
    }
  }
  return uVar7;
}

