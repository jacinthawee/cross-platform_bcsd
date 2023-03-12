
void dtls1_get_message_header(undefined *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  
  *param_2 = 0;
  param_2[10] = 0;
  puVar2 = (undefined4 *)((uint)(param_2 + 1) & 0xfffffffc);
  for (uVar1 = (uint)((int)param_2 + (0x2c - (int)(undefined4 *)((uint)(param_2 + 1) & 0xfffffffc)))
               >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined *)param_2 = *param_1;
  param_2[1] = (uint)(byte)param_1[2] << 8 | (uint)(byte)param_1[1] << 0x10 | (uint)(byte)param_1[3]
  ;
  *(ushort *)(param_2 + 2) = *(ushort *)(param_1 + 4) << 8 | *(ushort *)(param_1 + 4) >> 8;
  param_2[3] = (uint)(byte)param_1[7] << 8 | (uint)(byte)param_1[6] << 0x10 | (uint)(byte)param_1[8]
  ;
  param_2[4] = (uint)(byte)param_1[10] << 8 | (uint)(byte)param_1[9] << 0x10 |
               (uint)(byte)param_1[0xb];
  return;
}

