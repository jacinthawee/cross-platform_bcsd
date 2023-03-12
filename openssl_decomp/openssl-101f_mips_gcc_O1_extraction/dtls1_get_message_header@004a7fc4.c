
void dtls1_get_message_header
               (undefined *param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

{
  (*(code *)PTR_memset_006aab00)(param_2,0,0x2c,param_4,&_gp);
  *param_2 = *param_1;
  *(uint *)(param_2 + 4) =
       (uint)(byte)param_1[1] << 0x10 | (uint)(byte)param_1[2] << 8 | (uint)(byte)param_1[3];
  *(undefined2 *)(param_2 + 8) = *(undefined2 *)(param_1 + 4);
  *(uint *)(param_2 + 0xc) =
       (uint)(byte)param_1[6] << 0x10 | (uint)(byte)param_1[7] << 8 | (uint)(byte)param_1[8];
  *(uint *)(param_2 + 0x10) =
       (uint)(byte)param_1[9] << 0x10 | (uint)(byte)param_1[10] << 8 | (uint)(byte)param_1[0xb];
  return;
}

