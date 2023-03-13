
/* WARNING: Could not reconcile some variable overlaps */

void gost_dec_cfb(undefined4 param_1,undefined4 *param_2,byte *param_3,byte *param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int in_GS_OFFSET;
  undefined4 local_30;
  undefined4 local_2c;
  byte local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  byte local_24;
  byte local_23;
  byte local_22;
  byte local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = param_2[1];
  local_30 = *param_2;
  if (0 < param_5) {
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      gostcrypt(param_1,&local_30,&local_28);
      bVar1 = *param_3;
      *param_4 = bVar1 ^ local_28;
      bVar2 = param_3[1];
      param_4[1] = bVar2 ^ local_27;
      bVar3 = param_3[2];
      param_4[2] = bVar3 ^ local_26;
      local_30 = CONCAT13(param_3[3],CONCAT12(bVar3,CONCAT11(bVar2,bVar1)));
      param_4[3] = param_3[3] ^ local_25;
      bVar1 = param_3[4];
      param_4[4] = bVar1 ^ local_24;
      bVar2 = param_3[5];
      param_4[5] = bVar2 ^ local_23;
      bVar3 = param_3[6];
      param_4[6] = bVar3 ^ local_22;
      local_2c = CONCAT13(param_3[7],CONCAT12(bVar3,CONCAT11(bVar2,bVar1)));
      param_4[7] = param_3[7] ^ local_21;
      param_4 = param_4 + 8;
      param_3 = param_3 + 8;
    } while (param_5 != iVar4);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

