
void CRYPTO_cfb128_1_encrypt
               (int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 *param_5,
               undefined4 param_6,int param_7,code *param_8)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char local_50;
  byte bStack_4f;
  byte bStack_4e;
  byte bStack_4d;
  char local_4c;
  byte local_4b;
  byte local_4a;
  byte local_49;
  char local_48;
  byte local_47;
  byte local_46;
  byte local_45;
  byte local_43;
  byte local_42;
  byte local_41;
  
  iVar1 = __stack_chk_guard;
  if (param_3 != 0) {
    uVar6 = 0;
    do {
      uVar7 = uVar6 >> 3;
      uVar2 = *param_5;
      uVar3 = param_5[1];
      uVar4 = param_5[2];
      uVar5 = param_5[3];
      if (((int)(uint)*(byte *)(param_1 + uVar7) >> (~uVar6 & 7) & 1U) == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = 0x80;
      }
      (*param_8)(param_5,param_5,param_4);
      if (param_7 == 0) {
        uVar9 = uVar8 ^ *(byte *)param_5;
      }
      else {
        uVar8 = uVar8 ^ *(byte *)param_5;
        uVar9 = uVar8;
      }
      bStack_4f = (byte)((uint)uVar2 >> 8);
      bStack_4e = (byte)((uint)uVar2 >> 0x10);
      local_50 = (char)uVar2;
      bStack_4d = (byte)((uint)uVar2 >> 0x18);
      local_4c = (char)uVar3;
      *(byte *)param_5 = (byte)((int)(uint)bStack_4f >> 7) | local_50 << 1;
      local_4b = (byte)(uVar3 >> 8);
      *(byte *)((int)param_5 + 1) = (byte)((int)(uint)bStack_4e >> 7) | bStack_4f << 1;
      local_4a = (byte)(uVar3 >> 0x10);
      *(byte *)((int)param_5 + 2) = (byte)((int)(uint)bStack_4d >> 7) | bStack_4e << 1;
      local_49 = (byte)(uVar3 >> 0x18);
      *(byte *)((int)param_5 + 3) = (byte)((int)(uVar3 & 0xff) >> 7) | bStack_4d << 1;
      local_48 = (char)uVar4;
      *(byte *)(param_5 + 1) = (byte)((int)(uint)local_4b >> 7) | local_4c << 1;
      local_47 = (byte)(uVar4 >> 8);
      *(byte *)((int)param_5 + 5) = (byte)((int)(uint)local_4a >> 7) | local_4b << 1;
      local_46 = (byte)(uVar4 >> 0x10);
      *(byte *)((int)param_5 + 6) = (byte)((int)(uint)local_49 >> 7) | local_4a << 1;
      local_45 = (byte)(uVar4 >> 0x18);
      *(byte *)((int)param_5 + 9) = (byte)((int)(uint)local_46 >> 7) | local_47 << 1;
      local_42 = (byte)(uVar5 >> 0x10);
      *(byte *)((int)param_5 + 10) = (byte)((int)(uint)local_45 >> 7) | local_46 << 1;
      local_41 = (byte)(uVar5 >> 0x18);
      *(byte *)((int)param_5 + 7) = (byte)((int)(uVar4 & 0xff) >> 7) | local_49 << 1;
      *(byte *)(param_5 + 2) = (byte)((int)(uint)local_47 >> 7) | local_48 << 1;
      local_43 = (byte)(uVar5 >> 8);
      *(byte *)((int)param_5 + 0xe) = (byte)((int)(uint)local_41 >> 7) | local_42 << 1;
      *(byte *)((int)param_5 + 0xd) = (byte)((int)(uint)local_42 >> 7) | local_43 << 1;
      *(byte *)(param_5 + 3) = (byte)((int)(uint)local_43 >> 7) | (byte)((uVar5 & 0xff) << 1);
      *(byte *)((int)param_5 + 0xf) = (byte)(uVar8 >> 7) | local_41 << 1;
      *(byte *)((int)param_5 + 0xb) = (byte)((int)(uVar5 & 0xff) >> 7) | local_45 << 1;
      *(byte *)(param_2 + uVar7) =
           (byte)((int)(uVar9 & 0xffffff80) >> (uVar6 & 7)) |
           *(byte *)(param_2 + uVar7) & ~(byte)(1 << (~uVar6 & 7));
      uVar6 = uVar6 + 1;
    } while (uVar6 != param_3);
  }
  if (iVar1 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

