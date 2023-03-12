
void mdc2_body(int param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  DES_key_schedule DStack_a8;
  
  if (param_3 != 0) {
    bVar10 = *(byte *)(param_1 + 0xc);
    bVar1 = *(byte *)(param_1 + 0x14);
    pbVar11 = param_2;
    do {
      bVar2 = pbVar11[2];
      bVar3 = pbVar11[6];
      bVar4 = pbVar11[1];
      bVar5 = pbVar11[5];
      bVar6 = *pbVar11;
      bVar7 = pbVar11[4];
      bVar8 = pbVar11[3];
      bVar9 = pbVar11[7];
      *(byte *)(param_1 + 0xc) = bVar10 & 0x9f | 0x40;
      *(byte *)(param_1 + 0x14) = bVar1 & 0x9f | 0x20;
      uVar13 = (uint)bVar2 << 0x10 | (uint)bVar4 << 8 | (uint)bVar6 | (uint)bVar8 << 0x18;
      uVar12 = (uint)bVar3 << 0x10 | (uint)bVar5 << 8 | (uint)bVar7 | (uint)bVar9 << 0x18;
      pbVar11 = pbVar11 + 8;
      local_b8 = uVar13;
      local_b4 = uVar12;
      local_b0 = uVar13;
      local_ac = uVar12;
      DES_set_odd_parity((DES_cblock *)(param_1 + 0xc));
      DES_set_key_unchecked((DES_cblock *)(param_1 + 0xc),&DStack_a8);
      DES_encrypt1(&local_b8,&DStack_a8,1);
      DES_set_odd_parity((DES_cblock *)(param_1 + 0x14));
      DES_set_key_unchecked((DES_cblock *)(param_1 + 0x14),&DStack_a8);
      DES_encrypt1(&local_b0,&DStack_a8,1);
      local_b0 = local_b0 ^ uVar13;
      uVar13 = uVar13 ^ local_b8;
      local_ac = local_ac ^ uVar12;
      bVar10 = (byte)uVar13;
      *(char *)(param_1 + 0x10) = (char)local_ac;
      uVar12 = uVar12 ^ local_b4;
      *(byte *)(param_1 + 0xc) = bVar10;
      *(char *)(param_1 + 0x18) = (char)uVar12;
      *(char *)(param_1 + 0xd) = (char)(uVar13 >> 8);
      *(char *)(param_1 + 0xe) = (char)(uVar13 >> 0x10);
      *(char *)(param_1 + 0xf) = (char)(uVar13 >> 0x18);
      bVar1 = (byte)local_b0;
      *(byte *)(param_1 + 0x14) = bVar1;
      *(char *)(param_1 + 0x15) = (char)(local_b0 >> 8);
      *(char *)(param_1 + 0x16) = (char)(local_b0 >> 0x10);
      *(char *)(param_1 + 0x17) = (char)(local_b0 >> 0x18);
      *(char *)(param_1 + 0x11) = (char)(local_ac >> 8);
      *(char *)(param_1 + 0x12) = (char)(local_ac >> 0x10);
      *(char *)(param_1 + 0x13) = (char)(local_ac >> 0x18);
      *(char *)(param_1 + 0x19) = (char)(uVar12 >> 8);
      *(char *)(param_1 + 0x1a) = (char)(uVar12 >> 0x10);
      *(char *)(param_1 + 0x1b) = (char)(uVar12 >> 0x18);
    } while ((uint)((int)pbVar11 - (int)param_2) < param_3);
  }
  return;
}

