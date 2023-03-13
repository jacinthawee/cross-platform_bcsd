
int CRYPTO_memcmp(void *a,void *b,size_t len)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  byte bVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  
  if (len == 0) {
    uVar5 = 0;
  }
  else if (((((uint)b | (uint)a) & 3) == 0) && (8 < len)) {
    uVar5 = 0;
    uVar8 = 0;
    uVar9 = (len - 4 >> 2) + 1;
    sVar3 = uVar9 * 4;
    do {
      iVar1 = uVar5 * 4;
      iVar2 = uVar5 * 4;
      uVar5 = uVar5 + 1;
      uVar8 = uVar8 | *(uint *)((int)b + iVar1) ^ *(uint *)((int)a + iVar2);
    } while (uVar5 < uVar9);
    uVar5 = (uint)(byte)((byte)(uVar8 >> 0x10) | (byte)(uVar8 >> 8) | (byte)uVar8) | uVar8 >> 0x18;
    if (((len != sVar3) &&
        (uVar5 = uVar5 | *(byte *)((int)b + uVar9 * 4) ^ *(byte *)((int)a + uVar9 * 4),
        sVar3 + 1 < len)) &&
       (uVar5 = uVar5 | *(byte *)((int)a + sVar3 + 1) ^ *(byte *)((int)b + sVar3 + 1),
       sVar3 + 2 < len)) {
      uVar5 = uVar5 | *(byte *)((int)a + sVar3 + 2) ^ *(byte *)((int)b + sVar3 + 2);
    }
  }
  else {
    uVar5 = 0;
    pbVar6 = (byte *)a;
    do {
                    /* WARNING: Load size is inaccurate */
      bVar4 = *b;
      pbVar7 = pbVar6 + 1;
      b = (void *)((int)b + 1);
      uVar5 = uVar5 | bVar4 ^ *pbVar6;
      pbVar6 = pbVar7;
    } while (pbVar7 != (byte *)((int)a + len));
  }
  return uVar5;
}

