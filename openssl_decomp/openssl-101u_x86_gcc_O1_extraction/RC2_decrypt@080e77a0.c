
void RC2_decrypt(ulong *data,RC2_KEY *key)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *local_20;
  int local_18;
  int local_14;
  
  local_18 = 3;
  local_14 = 5;
  uVar1 = *data & 0xffff;
  uVar5 = *data >> 0x10;
  uVar2 = key->data[0x3f];
  uVar7 = data[1] & 0xffff;
  uVar3 = data[1] >> 0x10;
  local_20 = key->data + 0x3f;
  do {
    uVar3 = (((uVar3 >> 5 | (uVar3 & 0x1f) << 0xb) - (~uVar7 & uVar1)) - (uVar5 & uVar7)) - uVar2 &
            0xffff;
    uVar4 = (((uVar7 >> 3 | (uVar7 & 7) << 0xd) - (~uVar5 & uVar3)) - (uVar1 & uVar5)) -
            local_20[-1];
    uVar7 = uVar4 & 0xffff;
    uVar6 = (((uVar5 >> 2 | (uVar5 & 3) << 0xe) - (~uVar1 & uVar7)) - (uVar1 & uVar3)) -
            local_20[-2];
    uVar5 = uVar6 & 0xffff;
    uVar2 = (((uVar1 >> 1 | (uVar1 & 1) << 0xf) - (~uVar3 & uVar5)) - (uVar4 & uVar3)) -
            local_20[-3];
    local_14 = local_14 + -1;
    uVar1 = uVar2 & 0xffff;
    if (local_14 == 0) {
      local_18 = local_18 + -1;
      if (local_18 == 0) {
        *data = uVar1 | uVar5 << 0x10;
        data[1] = uVar3 << 0x10 | uVar7;
        return;
      }
      local_14 = (local_18 == 2) + 5;
      uVar7 = uVar7 - key->data[uVar6 & 0x3f] & 0xffff;
      uVar4 = uVar3 - key->data[uVar4 & 0x3f];
      uVar3 = uVar4 & 0xffff;
      uVar5 = uVar5 - key->data[uVar2 & 0x3f] & 0xffff;
      uVar1 = uVar1 - key->data[uVar4 & 0x3f] & 0xffff;
    }
    uVar2 = local_20[-4];
    local_20 = local_20 + -4;
  } while( true );
}

