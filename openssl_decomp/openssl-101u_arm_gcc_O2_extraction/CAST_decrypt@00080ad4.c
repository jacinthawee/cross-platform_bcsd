
void CAST_decrypt(uint *data,CAST_KEY *key)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = *data;
  uVar6 = data[1];
  if (key->short_key == 0) {
    uVar2 = key->data[0x1e] + uVar6;
    uVar4 = 0x20 - key->data[0x1f] & 0x1f;
    uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
    uVar5 = (*(int *)(CAST_S_table3 + ((uVar4 << 8) >> 0x18) * 4) -
            *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) +
            (*(uint *)(&CAST_S_table0 + ((uVar4 << 0x10) >> 0x18) * 4) ^
            *(uint *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) ^ uVar5;
    uVar2 = key->data[0x1c] - uVar5;
    uVar4 = 0x20 - key->data[0x1d] & 0x1f;
    uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
    uVar6 = (*(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4) +
             *(int *)(&CAST_S_table0 + ((uVar4 << 0x10) >> 0x18) * 4) ^
            *(uint *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) -
            *(int *)(CAST_S_table3 + ((uVar4 << 8) >> 0x18) * 4) ^ uVar6;
    uVar2 = key->data[0x1a] ^ uVar6;
    uVar4 = 0x20 - key->data[0x1b] & 0x1f;
    uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
    uVar5 = uVar5 ^ *(uint *)(CAST_S_table3 + ((uVar4 << 8) >> 0x18) * 4) ^
            (*(int *)(&CAST_S_table0 + ((uVar4 << 0x10) >> 0x18) * 4) -
            *(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) +
            *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4);
    uVar2 = key->data[0x18] + uVar5;
    uVar4 = 0x20 - key->data[0x19] & 0x1f;
    uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
    uVar6 = (*(int *)(CAST_S_table3 + ((uVar4 << 8) >> 0x18) * 4) -
            *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) +
            (*(uint *)(CAST_S_table1 + (uVar4 & 0xff) * 4) ^
            *(uint *)(&CAST_S_table0 + ((uVar4 << 0x10) >> 0x18) * 4)) ^ uVar6;
  }
  uVar2 = key->data[0x16] - uVar6;
  uVar4 = 0x20 - key->data[0x17] & 0x1f;
  uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
  uVar5 = (*(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4) +
           *(int *)(&CAST_S_table0 + ((uVar4 << 0x10) >> 0x18) * 4) ^
          *(uint *)(CAST_S_table2 + (uVar4 >> 0x18) * 4)) -
          *(int *)(CAST_S_table3 + ((uVar4 << 8) >> 0x18) * 4) ^ uVar5;
  uVar2 = uVar5 ^ key->data[0x14];
  uVar4 = 0x20 - key->data[0x15] & 0x1f;
  uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
  uVar4 = uVar6 ^ *(uint *)(CAST_S_table3 + ((uVar4 << 8) >> 0x18) * 4) ^
          (*(int *)(&CAST_S_table0 + ((uVar4 << 0x10) >> 0x18) * 4) -
          *(int *)(CAST_S_table1 + (uVar4 & 0xff) * 4)) +
          *(int *)(CAST_S_table2 + (uVar4 >> 0x18) * 4);
  uVar2 = key->data[0x12] + uVar4;
  uVar6 = 0x20 - key->data[0x13] & 0x1f;
  uVar6 = uVar2 >> uVar6 | uVar2 << 0x20 - uVar6;
  uVar5 = (*(int *)(CAST_S_table3 + ((uVar6 << 8) >> 0x18) * 4) -
          *(int *)(CAST_S_table2 + (uVar6 >> 0x18) * 4)) +
          (*(uint *)(&CAST_S_table0 + ((uVar6 << 0x10) >> 0x18) * 4) ^
          *(uint *)(CAST_S_table1 + (uVar6 & 0xff) * 4)) ^ uVar5;
  uVar2 = key->data[0x10] - uVar5;
  uVar6 = 0x20 - key->data[0x11] & 0x1f;
  uVar6 = uVar2 >> uVar6 | uVar2 << 0x20 - uVar6;
  uVar4 = (*(int *)(&CAST_S_table0 + ((uVar6 << 0x10) >> 0x18) * 4) +
           *(int *)(CAST_S_table1 + (uVar6 & 0xff) * 4) ^
          *(uint *)(CAST_S_table2 + (uVar6 >> 0x18) * 4)) -
          *(int *)(CAST_S_table3 + ((uVar6 << 8) >> 0x18) * 4) ^ uVar4;
  uVar2 = uVar4 ^ key->data[0xe];
  uVar6 = 0x20 - key->data[0xf] & 0x1f;
  uVar6 = uVar2 >> uVar6 | uVar2 << 0x20 - uVar6;
  uVar2 = uVar5 ^ *(uint *)(CAST_S_table3 + ((uVar6 << 8) >> 0x18) * 4) ^
          (*(int *)(&CAST_S_table0 + ((uVar6 << 0x10) >> 0x18) * 4) -
          *(int *)(CAST_S_table1 + (uVar6 & 0xff) * 4)) +
          *(int *)(CAST_S_table2 + (uVar6 >> 0x18) * 4);
  uVar5 = key->data[0xc] + uVar2;
  uVar6 = 0x20 - key->data[0xd] & 0x1f;
  uVar6 = uVar5 >> uVar6 | uVar5 << 0x20 - uVar6;
  uVar4 = (*(int *)(CAST_S_table3 + ((uVar6 << 8) >> 0x18) * 4) -
          *(int *)(CAST_S_table2 + (uVar6 >> 0x18) * 4)) +
          (*(uint *)(&CAST_S_table0 + ((uVar6 << 0x10) >> 0x18) * 4) ^
          *(uint *)(CAST_S_table1 + (uVar6 & 0xff) * 4)) ^ uVar4;
  uVar5 = key->data[10] - uVar4;
  uVar6 = 0x20 - key->data[0xb] & 0x1f;
  uVar6 = uVar5 >> uVar6 | uVar5 << 0x20 - uVar6;
  uVar2 = (*(int *)(&CAST_S_table0 + ((uVar6 << 0x10) >> 0x18) * 4) +
           *(int *)(CAST_S_table1 + (uVar6 & 0xff) * 4) ^
          *(uint *)(CAST_S_table2 + (uVar6 >> 0x18) * 4)) -
          *(int *)(CAST_S_table3 + ((uVar6 << 8) >> 0x18) * 4) ^ uVar2;
  uVar5 = uVar2 ^ key->data[8];
  uVar6 = 0x20 - key->data[9] & 0x1f;
  uVar6 = uVar5 >> uVar6 | uVar5 << 0x20 - uVar6;
  uVar4 = uVar4 ^ *(uint *)(CAST_S_table3 + ((uVar6 << 8) >> 0x18) * 4) ^
          (*(int *)(&CAST_S_table0 + ((uVar6 << 0x10) >> 0x18) * 4) -
          *(int *)(CAST_S_table1 + (uVar6 & 0xff) * 4)) +
          *(int *)(CAST_S_table2 + (uVar6 >> 0x18) * 4);
  uVar5 = key->data[6] + uVar4;
  uVar6 = 0x20 - key->data[7] & 0x1f;
  uVar6 = uVar5 >> uVar6 | uVar5 << 0x20 - uVar6;
  uVar2 = (*(int *)(CAST_S_table3 + ((uVar6 << 8) >> 0x18) * 4) -
          *(int *)(CAST_S_table2 + (uVar6 >> 0x18) * 4)) +
          (*(uint *)(&CAST_S_table0 + ((uVar6 << 0x10) >> 0x18) * 4) ^
          *(uint *)(CAST_S_table1 + (uVar6 & 0xff) * 4)) ^ uVar2;
  uVar5 = key->data[4] - uVar2;
  uVar6 = 0x20 - key->data[5] & 0x1f;
  uVar6 = uVar5 >> uVar6 | uVar5 << 0x20 - uVar6;
  uVar4 = (*(int *)(&CAST_S_table0 + ((uVar6 << 0x10) >> 0x18) * 4) +
           *(int *)(CAST_S_table1 + (uVar6 & 0xff) * 4) ^
          *(uint *)(CAST_S_table2 + (uVar6 >> 0x18) * 4)) -
          *(int *)(CAST_S_table3 + ((uVar6 << 8) >> 0x18) * 4) ^ uVar4;
  uVar5 = uVar4 ^ key->data[2];
  uVar6 = 0x20 - key->data[3] & 0x1f;
  uVar6 = uVar5 >> uVar6 | uVar5 << 0x20 - uVar6;
  uVar2 = uVar2 ^ *(uint *)(CAST_S_table3 + ((uVar6 << 8) >> 0x18) * 4) ^
          *(int *)(CAST_S_table2 + (uVar6 >> 0x18) * 4) +
          (*(int *)(&CAST_S_table0 + ((uVar6 << 0x10) >> 0x18) * 4) -
          *(int *)(CAST_S_table1 + (uVar6 & 0xff) * 4));
  uVar5 = key->data[0] + uVar2;
  uVar6 = 0x20 - key->data[1] & 0x1f;
  uVar6 = uVar5 >> uVar6 | uVar5 << 0x20 - uVar6;
  iVar3 = *(int *)(CAST_S_table3 + ((uVar6 << 8) >> 0x18) * 4);
  uVar5 = *(uint *)(CAST_S_table1 + (uVar6 & 0xff) * 4);
  iVar1 = *(int *)(CAST_S_table2 + (uVar6 >> 0x18) * 4);
  uVar6 = *(uint *)(&CAST_S_table0 + ((uVar6 << 0x10) >> 0x18) * 4);
  data[1] = uVar2;
  *data = uVar4 ^ (uVar6 ^ uVar5) + (iVar3 - iVar1);
  return;
}

