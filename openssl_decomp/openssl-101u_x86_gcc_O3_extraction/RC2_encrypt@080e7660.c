
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
  uint uVar10;
  uint *puVar11;
  int local_18;
  int local_14;
  
  local_18 = 3;
  local_14 = 5;
  uVar6 = key->data[0];
  uVar9 = *data & 0xffff;
  uVar3 = data[1] & 0xffff;
  uVar4 = *data >> 0x10;
  uVar2 = data[1] >> 0x10;
  puVar11 = key->data;
  do {
    uVar5 = uVar6 + (uVar3 & uVar2) + (~uVar2 & uVar4) + uVar9 & 0xffff;
    uVar1 = uVar5 * 2;
    uVar5 = uVar5 >> 0xf;
    uVar9 = uVar1 | uVar5;
    uVar6 = (~uVar9 & uVar3) + uVar4 + puVar11[1] + (uVar2 & uVar9) & 0xffff;
    uVar4 = uVar6 >> 0xe | uVar6 * 4;
    uVar7 = (~uVar4 & uVar2) + uVar3 + puVar11[2] + (uVar9 & uVar4) & 0xffff;
    uVar6 = uVar7 * 8;
    uVar7 = uVar7 >> 0xd;
    uVar3 = uVar7 | uVar6;
    uVar8 = (~uVar3 & uVar9) + uVar2 + puVar11[3] + (uVar4 & uVar3) & 0xffff;
    uVar10 = uVar8 << 5;
    uVar8 = uVar8 >> 0xb;
    uVar2 = uVar8 | uVar10;
    local_14 = local_14 + -1;
    if (local_14 == 0) {
      local_18 = local_18 + -1;
      if (local_18 == 0) {
        *data = uVar4 << 0x10 | uVar1 & 0xffff | uVar5;
        data[1] = uVar2 << 0x10 | uVar7 | uVar6 & 0xffff;
        return;
      }
      local_14 = (local_18 == 2) + 5;
      uVar9 = uVar9 + key->data[uVar8 | uVar10 & 0x3f];
      uVar4 = uVar4 + key->data[uVar9 & 0x3f];
      uVar3 = uVar3 + key->data[uVar4 & 0x3f];
      uVar2 = uVar2 + key->data[uVar3 & 0x3f];
    }
    uVar6 = puVar11[4];
    puVar11 = puVar11 + 4;
  } while( true );
}

