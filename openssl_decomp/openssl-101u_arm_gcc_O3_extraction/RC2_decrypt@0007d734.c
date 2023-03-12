
void RC2_decrypt(ulong *data,RC2_KEY *key)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  puVar7 = key->data + 0x3f;
  iVar9 = 3;
  iVar10 = 5;
  uVar1 = *data & 0xffff;
  uVar4 = *data >> 0x10;
  uVar6 = data[1] & 0xffff;
  uVar3 = data[1] >> 0x10;
  do {
    iVar10 = iVar10 + -1;
    uVar3 = ((((uVar3 & 0x1f) << 0xb | uVar3 >> 5) - (uVar1 & ~uVar6)) - (uVar6 & uVar4)) - *puVar7
            & 0xffff;
    uVar8 = ((((uVar6 & 7) << 0xd | uVar6 >> 3) - (uVar3 & ~uVar4)) - (uVar4 & uVar1)) - puVar7[-1];
    uVar6 = uVar8 & 0xffff;
    uVar5 = ((((uVar4 & 3) << 0xe | uVar4 >> 2) - (uVar6 & ~uVar1)) - (uVar3 & uVar1)) - puVar7[-2];
    uVar4 = uVar5 & 0xffff;
    uVar2 = ((((uVar1 & 1) << 0xf | uVar1 >> 1) - (uVar4 & ~uVar3)) - (uVar8 & uVar3)) - puVar7[-3];
    uVar1 = uVar2 & 0xffff;
    if (iVar10 == 0) {
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) {
        *data = uVar1 | uVar4 << 0x10;
        data[1] = uVar6 | uVar3 << 0x10;
        return;
      }
      if (iVar9 == 2) {
        iVar10 = 6;
      }
      else {
        iVar10 = 5;
      }
      uVar8 = uVar3 - key->data[uVar8 & 0x3f];
      uVar3 = uVar8 & 0xffff;
      uVar6 = uVar6 - key->data[uVar5 & 0x3f] & 0xffff;
      uVar4 = uVar4 - key->data[uVar2 & 0x3f] & 0xffff;
      uVar1 = uVar1 - key->data[uVar8 & 0x3f] & 0xffff;
    }
    puVar7 = puVar7 + -4;
  } while( true );
}

