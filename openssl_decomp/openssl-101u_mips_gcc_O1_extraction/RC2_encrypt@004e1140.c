
void RC2_encrypt(ulong *data,RC2_KEY *key)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  
  iVar11 = 3;
  iVar10 = 5;
  uVar16 = key->data[0];
  uVar4 = *data & 0xffff;
  uVar12 = data[1] >> 0x10;
  uVar6 = *data >> 0x10;
  uVar14 = data[1] & 0xffff;
  puVar9 = key->data;
  do {
    puVar1 = puVar9 + 1;
    puVar2 = puVar9 + 2;
    puVar3 = puVar9 + 3;
    uVar16 = (~uVar12 & uVar6) + (uVar14 & uVar12) + uVar4 + uVar16 & 0xffff;
    uVar5 = uVar16 << 1;
    uVar16 = uVar16 >> 0xf;
    iVar10 = iVar10 + -1;
    uVar4 = uVar5 | uVar16;
    puVar9 = puVar9 + 4;
    uVar6 = uVar6 + *puVar1 + (uVar12 & uVar4) + (~uVar4 & uVar14) & 0xffff;
    uVar6 = uVar6 << 2 | uVar6 >> 0xe;
    uVar7 = uVar14 + *puVar2 + (uVar4 & uVar6) + (~uVar6 & uVar12) & 0xffff;
    uVar15 = uVar7 << 3;
    uVar7 = uVar7 >> 0xd;
    uVar14 = uVar15 | uVar7;
    uVar8 = uVar12 + *puVar3 + (uVar6 & uVar14) + (~uVar14 & uVar4) & 0xffff;
    uVar13 = uVar8 << 5;
    uVar8 = uVar8 >> 0xb;
    uVar12 = uVar13 | uVar8;
    if (iVar10 == 0) {
      iVar11 = iVar11 + -1;
      if (iVar11 == 0) {
        *data = uVar5 & 0xffff | uVar16 | uVar6 << 0x10;
        data[1] = uVar15 & 0xffff | uVar7 | uVar12 << 0x10;
        return;
      }
      iVar10 = 6;
      if (iVar11 != 2) {
        iVar10 = 5;
      }
      uVar4 = uVar4 + key->data[uVar13 & 0x3f | uVar8];
      uVar6 = uVar6 + key->data[uVar4 & 0x3f];
      uVar14 = uVar14 + key->data[uVar6 & 0x3f];
      uVar12 = uVar12 + key->data[uVar14 & 0x3f];
    }
    uVar16 = *puVar9;
  } while( true );
}

