
void RC2_encrypt(ulong *data,RC2_KEY *key)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  
  uVar8 = *data & 0xffff;
  uVar6 = data[1] & 0xffff;
  iVar13 = 3;
  iVar11 = 5;
  uVar1 = *data >> 0x10;
  uVar3 = data[1] >> 0x10;
  puVar10 = key->data;
  do {
    iVar11 = iVar11 + -1;
    uVar9 = uVar8 + (uVar1 & ~uVar3) + *puVar10 + (uVar3 & uVar6) & 0xffff;
    uVar2 = uVar9 << 1;
    uVar9 = uVar9 >> 0xf;
    uVar8 = uVar2 | uVar9;
    uVar1 = (uVar8 & uVar3) + puVar10[1] + uVar1 + (uVar6 & ~uVar8) & 0xffff;
    uVar1 = uVar1 << 2 | uVar1 >> 0xe;
    uVar7 = (uVar1 & uVar8) + puVar10[2] + uVar6 + (uVar3 & ~uVar1) & 0xffff;
    uVar4 = uVar7 << 3;
    uVar7 = uVar7 >> 0xd;
    uVar6 = uVar4 | uVar7;
    uVar5 = (uVar6 & uVar1) + puVar10[3] + uVar3 + (uVar8 & ~uVar6) & 0xffff;
    uVar12 = uVar5 << 5;
    uVar5 = uVar5 >> 0xb;
    uVar3 = uVar12 | uVar5;
    if (iVar11 == 0) {
      iVar13 = iVar13 + -1;
      if (iVar13 == 0) {
        *data = uVar2 & 0xffff | uVar9 | uVar1 << 0x10;
        data[1] = uVar4 & 0xffff | uVar7 | uVar3 << 0x10;
        return;
      }
      if (iVar13 == 2) {
        iVar11 = 6;
      }
      else {
        iVar11 = 5;
      }
      uVar8 = uVar8 + key->data[uVar12 & 0x3f | uVar5];
      uVar1 = uVar1 + key->data[uVar8 & 0x3f];
      uVar6 = uVar6 + key->data[uVar1 & 0x3f];
      uVar3 = uVar3 + key->data[uVar6 & 0x3f];
    }
    puVar10 = puVar10 + 4;
  } while( true );
}

