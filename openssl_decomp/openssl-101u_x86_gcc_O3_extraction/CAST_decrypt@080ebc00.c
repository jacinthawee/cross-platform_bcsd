
void CAST_decrypt(uint *data,CAST_KEY *key)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = *data;
  uVar4 = data[1];
  if (key->short_key == 0) {
    uVar3 = key->data[0x1e] + uVar4;
    bVar1 = (byte)key->data[0x1f] & 0x1f;
    uVar3 = uVar3 << bVar1 | uVar3 >> 0x20 - bVar1;
    uVar2 = uVar2 ^ ((*(uint *)(CAST_S_table0 + (uVar3 >> 8 & 0xff) * 4) ^
                     *(uint *)(CAST_S_table1 + (uVar3 & 0xff) * 4)) -
                    *(int *)(CAST_S_table2 + (uVar3 >> 0x18) * 4)) +
                    *(int *)(CAST_S_table3 + (uVar3 >> 0x10 & 0xff) * 4);
    uVar3 = key->data[0x1c] - uVar2;
    bVar1 = (byte)key->data[0x1d] & 0x1f;
    uVar3 = uVar3 << bVar1 | uVar3 >> 0x20 - bVar1;
    uVar4 = uVar4 ^ (*(int *)(CAST_S_table1 + (uVar3 & 0xff) * 4) +
                     *(int *)(CAST_S_table0 + (uVar3 >> 8 & 0xff) * 4) ^
                    *(uint *)(CAST_S_table2 + (uVar3 >> 0x18) * 4)) -
                    *(int *)(CAST_S_table3 + (uVar3 >> 0x10 & 0xff) * 4);
    uVar3 = key->data[0x1a] ^ uVar4;
    bVar1 = (byte)key->data[0x1b] & 0x1f;
    uVar3 = uVar3 << bVar1 | uVar3 >> 0x20 - bVar1;
    uVar2 = uVar2 ^ *(uint *)(CAST_S_table3 + (uVar3 >> 0x10 & 0xff) * 4) ^
            (*(int *)(CAST_S_table0 + (uVar3 >> 8 & 0xff) * 4) -
            *(int *)(CAST_S_table1 + (uVar3 & 0xff) * 4)) +
            *(int *)(CAST_S_table2 + (uVar3 >> 0x18) * 4);
    uVar3 = key->data[0x18] + uVar2;
    bVar1 = (byte)key->data[0x19] & 0x1f;
    uVar3 = uVar3 << bVar1 | uVar3 >> 0x20 - bVar1;
    uVar4 = uVar4 ^ ((*(uint *)(CAST_S_table0 + (uVar3 >> 8 & 0xff) * 4) ^
                     *(uint *)(CAST_S_table1 + (uVar3 & 0xff) * 4)) -
                    *(int *)(CAST_S_table2 + (uVar3 >> 0x18) * 4)) +
                    *(int *)(CAST_S_table3 + (uVar3 >> 0x10 & 0xff) * 4);
  }
  uVar3 = key->data[0x16] - uVar4;
  bVar1 = (byte)key->data[0x17] & 0x1f;
  uVar3 = uVar3 << bVar1 | uVar3 >> 0x20 - bVar1;
  uVar2 = uVar2 ^ (*(int *)(CAST_S_table1 + (uVar3 & 0xff) * 4) +
                   *(int *)(CAST_S_table0 + (uVar3 >> 8 & 0xff) * 4) ^
                  *(uint *)(CAST_S_table2 + (uVar3 >> 0x18) * 4)) -
                  *(int *)(CAST_S_table3 + (uVar3 >> 0x10 & 0xff) * 4);
  uVar3 = key->data[0x14] ^ uVar2;
  bVar1 = (byte)key->data[0x15] & 0x1f;
  uVar3 = uVar3 << bVar1 | uVar3 >> 0x20 - bVar1;
  uVar3 = uVar4 ^ *(uint *)(CAST_S_table3 + (uVar3 >> 0x10 & 0xff) * 4) ^
          (*(int *)(CAST_S_table0 + (uVar3 >> 8 & 0xff) * 4) -
          *(int *)(CAST_S_table1 + (uVar3 & 0xff) * 4)) +
          *(int *)(CAST_S_table2 + (uVar3 >> 0x18) * 4);
  uVar4 = key->data[0x12] + uVar3;
  bVar1 = (byte)key->data[0x13] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  uVar2 = ((*(uint *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) ^
           *(uint *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) -
          *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) +
          *(int *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4) ^ uVar2;
  uVar4 = key->data[0x10] - uVar2;
  bVar1 = (byte)key->data[0x11] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  uVar3 = uVar3 ^ (*(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4) +
                   *(int *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) ^
                  *(uint *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) -
                  *(int *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4);
  uVar4 = key->data[0xe] ^ uVar3;
  bVar1 = (byte)key->data[0xf] & 0x1f;
  uVar4 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  uVar4 = uVar2 ^ *(uint *)(CAST_S_table3 + (uVar4 >> 0x10 & 0xff) * 4) ^
          (*(int *)(CAST_S_table0 + (uVar4 >> 8 & 0xff) * 4) -
          *(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) +
          *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4);
  uVar2 = key->data[0xc] + uVar4;
  bVar1 = (byte)key->data[0xd] & 0x1f;
  uVar2 = uVar2 << bVar1 | uVar2 >> 0x20 - bVar1;
  uVar3 = ((*(uint *)(CAST_S_table0 + (uVar2 >> 8 & 0xff) * 4) ^
           *(uint *)(CAST_S_table1 + (uVar2 & 0xff) * 4)) -
          *(int *)(CAST_S_table2 + (uVar2 >> 0x18) * 4)) +
          *(int *)(CAST_S_table3 + (uVar2 >> 0x10 & 0xff) * 4) ^ uVar3;
  uVar2 = key->data[10] - uVar3;
  bVar1 = (byte)key->data[0xb] & 0x1f;
  uVar2 = uVar2 << bVar1 | uVar2 >> 0x20 - bVar1;
  uVar4 = uVar4 ^ (*(int *)(CAST_S_table1 + (uVar2 & 0xff) * 4) +
                   *(int *)(CAST_S_table0 + (uVar2 >> 8 & 0xff) * 4) ^
                  *(uint *)(CAST_S_table2 + (uVar2 >> 0x18) * 4)) -
                  *(int *)(CAST_S_table3 + (uVar2 >> 0x10 & 0xff) * 4);
  uVar2 = key->data[8] ^ uVar4;
  bVar1 = (byte)key->data[9] & 0x1f;
  uVar2 = uVar2 << bVar1 | uVar2 >> 0x20 - bVar1;
  uVar3 = uVar3 ^ *(uint *)(CAST_S_table3 + (uVar2 >> 0x10 & 0xff) * 4) ^
          (*(int *)(CAST_S_table0 + (uVar2 >> 8 & 0xff) * 4) -
          *(int *)(CAST_S_table1 + (uVar2 & 0xff) * 4)) +
          *(int *)(CAST_S_table2 + (uVar2 >> 0x18) * 4);
  uVar2 = key->data[6] + uVar3;
  bVar1 = (byte)key->data[7] & 0x1f;
  uVar2 = uVar2 << bVar1 | uVar2 >> 0x20 - bVar1;
  uVar4 = ((*(uint *)(CAST_S_table0 + (uVar2 >> 8 & 0xff) * 4) ^
           *(uint *)(CAST_S_table1 + (uVar2 & 0xff) * 4)) -
          *(int *)(CAST_S_table2 + (uVar2 >> 0x18) * 4)) +
          *(int *)(CAST_S_table3 + (uVar2 >> 0x10 & 0xff) * 4) ^ uVar4;
  uVar2 = key->data[4] - uVar4;
  bVar1 = (byte)key->data[5] & 0x1f;
  uVar2 = uVar2 << bVar1 | uVar2 >> 0x20 - bVar1;
  uVar3 = (*(int *)(CAST_S_table1 + (uVar2 & 0xff) * 4) +
           *(int *)(CAST_S_table0 + (uVar2 >> 8 & 0xff) * 4) ^
          *(uint *)(CAST_S_table2 + (uVar2 >> 0x18) * 4)) -
          *(int *)(CAST_S_table3 + (uVar2 >> 0x10 & 0xff) * 4) ^ uVar3;
  uVar2 = key->data[2] ^ uVar3;
  bVar1 = (byte)key->data[3] & 0x1f;
  uVar5 = uVar2 << bVar1 | uVar2 >> 0x20 - bVar1;
  uVar2 = key->data[1];
  uVar5 = uVar4 ^ *(uint *)(CAST_S_table3 + (uVar5 >> 0x10 & 0xff) * 4) ^
          (*(int *)(CAST_S_table0 + (uVar5 >> 8 & 0xff) * 4) -
          *(int *)(CAST_S_table1 + (uVar5 & 0xff) * 4)) +
          *(int *)(CAST_S_table2 + (uVar5 >> 0x18) * 4);
  uVar4 = key->data[0];
  data[1] = uVar5;
  uVar4 = uVar4 + uVar5;
  bVar1 = (byte)uVar2 & 0x1f;
  uVar2 = uVar4 << bVar1 | uVar4 >> 0x20 - bVar1;
  *data = uVar3 ^ ((*(uint *)(CAST_S_table0 + (uVar2 >> 8 & 0xff) * 4) ^
                   *(uint *)(CAST_S_table1 + (uVar2 & 0xff) * 4)) -
                  *(int *)(CAST_S_table2 + (uVar2 >> 0x18) * 4)) +
                  *(int *)(CAST_S_table3 + (uVar2 >> 0x10 & 0xff) * 4);
  return;
}

