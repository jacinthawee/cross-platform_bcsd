
void RC2_decrypt(ulong *data,RC2_KEY *key)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  puVar6 = key->data + 0x3f;
  iVar8 = 3;
  uVar9 = key->data[0x3f];
  uVar2 = *data & 0xffff;
  iVar7 = 5;
  uVar3 = *data >> 0x10;
  uVar10 = data[1] >> 0x10;
  uVar5 = data[1] & 0xffff;
  do {
    uVar10 = ((((uVar10 & 0x1f) << 0xb | uVar10 >> 5) - (~uVar5 & uVar2)) - (uVar3 & uVar5)) - uVar9
             & 0xffff;
    uVar9 = ((((uVar5 & 7) << 0xd | uVar5 >> 3) - (~uVar3 & uVar10)) - (uVar2 & uVar3)) - puVar6[-1]
    ;
    uVar5 = uVar9 & 0xffff;
    uVar4 = ((((uVar3 & 3) << 0xe | uVar3 >> 2) - (~uVar2 & uVar5)) - (uVar2 & uVar10)) - puVar6[-2]
    ;
    uVar3 = uVar4 & 0xffff;
    uVar1 = ((((uVar2 & 1) << 0xf | uVar2 >> 1) - (~uVar10 & uVar3)) - (uVar10 & uVar9)) -
            puVar6[-3];
    iVar7 = iVar7 + -1;
    puVar6 = puVar6 + -4;
    uVar2 = uVar1 & 0xffff;
    if (iVar7 == 0) {
      iVar8 = iVar8 + -1;
      if (iVar8 == 0) {
        *data = uVar3 << 0x10 | uVar2;
        data[1] = uVar10 << 0x10 | uVar5;
        return;
      }
      uVar9 = uVar10 - key->data[uVar9 & 0x3f];
      iVar7 = 6;
      if (iVar8 != 2) {
        iVar7 = 5;
      }
      uVar10 = uVar9 & 0xffff;
      uVar5 = uVar5 - key->data[uVar4 & 0x3f] & 0xffff;
      uVar3 = uVar3 - key->data[uVar1 & 0x3f] & 0xffff;
      uVar2 = uVar2 - key->data[uVar9 & 0x3f] & 0xffff;
    }
    uVar9 = *puVar6;
  } while( true );
}

