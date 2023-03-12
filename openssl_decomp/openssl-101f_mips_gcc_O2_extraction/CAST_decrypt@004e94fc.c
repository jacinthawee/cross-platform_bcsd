
void CAST_decrypt(uint *data,CAST_KEY *key)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  puVar4 = PTR_CAST_S_table1_006a9620;
  puVar3 = PTR_CAST_S_table0_006a961c;
  puVar2 = PTR_CAST_S_table2_006a9618;
  puVar1 = PTR_CAST_S_table3_006a9614;
  uVar9 = data[1];
  uVar7 = *data;
  if (key->short_key == 0) {
    uVar5 = uVar9 + key->data[0x1e];
    uVar6 = -key->data[0x1f] & 0x1f;
    uVar6 = (uVar5 >> uVar6) + (uVar5 << 0x20 - uVar6);
    uVar7 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar6 * 0x10000 >> 0x18) * 4) ^
            *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar6 & 0xff) * 4)) +
            (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar6 * 0x100 >> 0x18) * 4) -
            *(int *)(PTR_CAST_S_table2_006a9618 + (uVar6 >> 0x18) * 4)) ^ uVar7;
    uVar5 = key->data[0x1c] - uVar7;
    uVar6 = -key->data[0x1d] & 0x1f;
    uVar6 = (uVar5 >> uVar6) + (uVar5 << 0x20 - uVar6);
    uVar9 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar6 * 0x10000 >> 0x18) * 4) +
             *(int *)(PTR_CAST_S_table1_006a9620 + (uVar6 & 0xff) * 4) ^
            *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar6 >> 0x18) * 4)) -
            *(int *)(PTR_CAST_S_table3_006a9614 + (uVar6 * 0x100 >> 0x18) * 4) ^ uVar9;
    uVar5 = uVar9 ^ key->data[0x1a];
    uVar6 = -key->data[0x1b] & 0x1f;
    uVar6 = (uVar5 >> uVar6) + (uVar5 << 0x20 - uVar6);
    uVar7 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar6 * 0x10000 >> 0x18) * 4) -
            *(int *)(PTR_CAST_S_table1_006a9620 + (uVar6 & 0xff) * 4)) +
            *(int *)(PTR_CAST_S_table2_006a9618 + (uVar6 >> 0x18) * 4) ^
            uVar7 ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar6 * 0x100 >> 0x18) * 4);
    uVar5 = uVar7 + key->data[0x18];
    uVar6 = -key->data[0x19] & 0x1f;
    uVar6 = (uVar5 >> uVar6) + (uVar5 << 0x20 - uVar6);
    uVar9 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar6 * 0x10000 >> 0x18) * 4) ^
            *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar6 & 0xff) * 4)) +
            (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar6 * 0x100 >> 0x18) * 4) -
            *(int *)(PTR_CAST_S_table2_006a9618 + (uVar6 >> 0x18) * 4)) ^ uVar9;
  }
  uVar5 = key->data[0x16] - uVar9;
  uVar6 = -key->data[0x17] & 0x1f;
  uVar6 = (uVar5 >> uVar6) + (uVar5 << 0x20 - uVar6);
  uVar7 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar6 * 0x10000 >> 0x18) * 4) +
           *(int *)(PTR_CAST_S_table1_006a9620 + (uVar6 & 0xff) * 4) ^
          *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar6 >> 0x18) * 4)) -
          *(int *)(PTR_CAST_S_table3_006a9614 + (uVar6 * 0x100 >> 0x18) * 4) ^ uVar7;
  uVar5 = uVar7 ^ key->data[0x14];
  uVar6 = -key->data[0x15] & 0x1f;
  uVar6 = (uVar5 >> uVar6) + (uVar5 << 0x20 - uVar6);
  uVar5 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar6 * 0x10000 >> 0x18) * 4) -
          *(int *)(PTR_CAST_S_table1_006a9620 + (uVar6 & 0xff) * 4)) +
          *(int *)(PTR_CAST_S_table2_006a9618 + (uVar6 >> 0x18) * 4) ^
          uVar9 ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar6 * 0x100 >> 0x18) * 4);
  uVar6 = uVar5 + key->data[0x12];
  uVar9 = -key->data[0x13] & 0x1f;
  uVar9 = (uVar6 >> uVar9) + (uVar6 << 0x20 - uVar9);
  uVar7 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar9 * 0x10000 >> 0x18) * 4) ^
          *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar9 & 0xff) * 4)) +
          (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar9 * 0x100 >> 0x18) * 4) -
          *(int *)(PTR_CAST_S_table2_006a9618 + (uVar9 >> 0x18) * 4)) ^ uVar7;
  uVar6 = key->data[0x10] - uVar7;
  uVar9 = -key->data[0x11] & 0x1f;
  uVar9 = (uVar6 >> uVar9) + (uVar6 << 0x20 - uVar9);
  uVar5 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar9 * 0x10000 >> 0x18) * 4) +
           *(int *)(PTR_CAST_S_table1_006a9620 + (uVar9 & 0xff) * 4) ^
          *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar9 >> 0x18) * 4)) -
          *(int *)(PTR_CAST_S_table3_006a9614 + (uVar9 * 0x100 >> 0x18) * 4) ^ uVar5;
  uVar6 = uVar5 ^ key->data[0xe];
  uVar9 = -key->data[0xf] & 0x1f;
  uVar9 = (uVar6 >> uVar9) + (uVar6 << 0x20 - uVar9);
  uVar8 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar9 * 0x10000 >> 0x18) * 4) -
          *(int *)(PTR_CAST_S_table1_006a9620 + (uVar9 & 0xff) * 4)) +
          *(int *)(PTR_CAST_S_table2_006a9618 + (uVar9 >> 0x18) * 4) ^
          uVar7 ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar9 * 0x100 >> 0x18) * 4);
  uVar9 = uVar8 + key->data[0xc];
  uVar7 = -key->data[0xd] & 0x1f;
  uVar7 = (uVar9 >> uVar7) + (uVar9 << 0x20 - uVar7);
  uVar5 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar7 * 0x10000 >> 0x18) * 4) ^
          *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar7 & 0xff) * 4)) +
          (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar7 * 0x100 >> 0x18) * 4) -
          *(int *)(PTR_CAST_S_table2_006a9618 + (uVar7 >> 0x18) * 4)) ^ uVar5;
  uVar9 = key->data[10] - uVar5;
  uVar7 = -key->data[0xb] & 0x1f;
  uVar7 = (uVar9 >> uVar7) + (uVar9 << 0x20 - uVar7);
  uVar8 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar7 * 0x10000 >> 0x18) * 4) +
           *(int *)(PTR_CAST_S_table1_006a9620 + (uVar7 & 0xff) * 4) ^
          *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar7 >> 0x18) * 4)) -
          *(int *)(PTR_CAST_S_table3_006a9614 + (uVar7 * 0x100 >> 0x18) * 4) ^ uVar8;
  uVar9 = uVar8 ^ key->data[8];
  uVar7 = -key->data[9] & 0x1f;
  uVar7 = (uVar9 >> uVar7) + (uVar9 << 0x20 - uVar7);
  uVar6 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar7 * 0x10000 >> 0x18) * 4) -
          *(int *)(PTR_CAST_S_table1_006a9620 + (uVar7 & 0xff) * 4)) +
          *(int *)(PTR_CAST_S_table2_006a9618 + (uVar7 >> 0x18) * 4) ^
          uVar5 ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar7 * 0x100 >> 0x18) * 4);
  uVar9 = uVar6 + key->data[6];
  uVar7 = -key->data[7] & 0x1f;
  uVar7 = (uVar9 >> uVar7) + (uVar9 << 0x20 - uVar7);
  uVar8 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar7 * 0x10000 >> 0x18) * 4) ^
          *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar7 & 0xff) * 4)) +
          (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar7 * 0x100 >> 0x18) * 4) -
          *(int *)(PTR_CAST_S_table2_006a9618 + (uVar7 >> 0x18) * 4)) ^ uVar8;
  uVar9 = key->data[4] - uVar8;
  uVar7 = -key->data[5] & 0x1f;
  uVar7 = (uVar9 >> uVar7) + (uVar9 << 0x20 - uVar7);
  uVar6 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar7 * 0x10000 >> 0x18) * 4) +
           *(int *)(PTR_CAST_S_table1_006a9620 + (uVar7 & 0xff) * 4) ^
          *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar7 >> 0x18) * 4)) -
          *(int *)(PTR_CAST_S_table3_006a9614 + (uVar7 * 0x100 >> 0x18) * 4) ^ uVar6;
  uVar9 = uVar6 ^ key->data[2];
  uVar7 = -key->data[3] & 0x1f;
  uVar7 = (uVar9 >> uVar7) + (uVar9 << 0x20 - uVar7);
  uVar5 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar7 * 0x10000 >> 0x18) * 4) -
          *(int *)(PTR_CAST_S_table1_006a9620 + (uVar7 & 0xff) * 4)) +
          *(int *)(PTR_CAST_S_table2_006a9618 + (uVar7 >> 0x18) * 4) ^
          uVar8 ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar7 * 0x100 >> 0x18) * 4);
  uVar9 = uVar5 + key->data[0];
  uVar7 = -key->data[1] & 0x1f;
  uVar7 = (uVar9 >> uVar7) + (uVar9 << 0x20 - uVar7);
  data[1] = uVar5;
  *data = (*(uint *)(puVar3 + (uVar7 * 0x10000 >> 0x18) * 4) ^
          *(uint *)(puVar4 + (uVar7 & 0xff) * 4)) +
          (*(int *)(puVar1 + (uVar7 * 0x100 >> 0x18) * 4) - *(int *)(puVar2 + (uVar7 >> 0x18) * 4))
          ^ uVar6;
  return;
}

