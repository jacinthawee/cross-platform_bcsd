
void CAST_encrypt(uint *data,CAST_KEY *key)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_14;
  
  uVar2 = key->data[0] + data[1];
  bVar1 = (byte)key->data[1] & 0x1f;
  uVar2 = uVar2 << bVar1 | uVar2 >> 0x20 - bVar1;
  uVar2 = ((*(uint *)(CAST_S_table0 + (uVar2 >> 8 & 0xff) * 4) ^
           *(uint *)(CAST_S_table1 + (uVar2 & 0xff) * 4)) -
          *(int *)(CAST_S_table2 + (uVar2 >> 0x18) * 4)) +
          *(int *)(CAST_S_table3 + (uVar2 >> 0x10 & 0xff) * 4) ^ *data;
  uVar4 = key->data[2] ^ uVar2;
  bVar1 = (byte)key->data[3] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  uVar3 = *(uint *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4) ^ data[1] ^
          (*(int *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) -
          *(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) +
          *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4);
  uVar4 = key->data[4] - uVar3;
  bVar1 = (byte)key->data[5] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  uVar2 = uVar2 ^ (*(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4) +
                   *(int *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) ^
                  *(uint *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) -
                  *(int *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4);
  uVar4 = key->data[6] + uVar2;
  bVar1 = (byte)key->data[7] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  uVar3 = uVar3 ^ ((*(uint *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) ^
                   *(uint *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) -
                  *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) +
                  *(int *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4);
  uVar4 = key->data[8] ^ uVar3;
  bVar1 = (byte)key->data[9] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  uVar2 = uVar2 ^ *(uint *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4) ^
          (*(int *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) -
          *(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) +
          *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4);
  uVar4 = key->data[10] - uVar2;
  bVar1 = (byte)key->data[0xb] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  uVar3 = uVar3 ^ (*(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4) +
                   *(int *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) ^
                  *(uint *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) -
                  *(int *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4);
  uVar4 = key->data[0xc] + uVar3;
  bVar1 = (byte)key->data[0xd] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  uVar2 = ((*(uint *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) ^
           *(uint *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) -
          *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) +
          *(int *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4) ^ uVar2;
  uVar4 = key->data[0xe] ^ uVar2;
  bVar1 = (byte)key->data[0xf] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  local_14 = (*(int *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) -
             *(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) +
             *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4) ^
             uVar3 ^ *(uint *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4);
  uVar4 = key->data[0x10] - local_14;
  bVar1 = (byte)key->data[0x11] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  uVar2 = uVar2 ^ (*(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4) +
                   *(int *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) ^
                  *(uint *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) -
                  *(int *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4);
  uVar4 = key->data[0x12] + uVar2;
  bVar1 = (byte)key->data[0x13] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  local_14 = ((*(uint *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) ^
              *(uint *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) -
             *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) +
             *(int *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4) ^ local_14;
  uVar4 = key->data[0x14] ^ local_14;
  bVar1 = (byte)key->data[0x15] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  uVar2 = (*(int *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) -
          *(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) +
          *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4) ^
          uVar2 ^ *(uint *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4);
  uVar4 = key->data[0x16] - uVar2;
  bVar1 = (byte)key->data[0x17] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  local_14 = local_14 ^
             (*(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4) +
              *(int *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) ^
             *(uint *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) -
             *(int *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4);
  if (key->short_key == 0) {
    uVar4 = key->data[0x18] + local_14;
    bVar1 = (byte)key->data[0x19] & 0x1f;
    uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
    uVar2 = uVar2 ^ ((*(uint *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) ^
                     *(uint *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) -
                    *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) +
                    *(int *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4);
    uVar4 = key->data[0x1a] ^ uVar2;
    bVar1 = (byte)key->data[0x1b] & 0x1f;
    uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
    local_14 = local_14 ^ *(uint *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4) ^
               (*(int *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) -
               *(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) +
               *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4);
    uVar4 = key->data[0x1c] - local_14;
    bVar1 = (byte)key->data[0x1d] & 0x1f;
    uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
    uVar2 = uVar2 ^ (*(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4) +
                     *(int *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) ^
                    *(uint *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) -
                    *(int *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4);
    uVar4 = key->data[0x1e] + uVar2;
    bVar1 = (byte)key->data[0x1f] & 0x1f;
    uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
    local_14 = local_14 ^
               *(int *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4) +
               ((*(uint *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) ^
                *(uint *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) -
               *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4));
  }
  data[1] = uVar2;
  *data = local_14;
  return;
}

