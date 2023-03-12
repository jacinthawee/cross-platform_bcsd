
/* WARNING: Could not reconcile some variable overlaps */

void CRYPTO_cfb128_1_encrypt
               (int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 *param_5,
               undefined4 param_6,int param_7,code *param_8)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  byte bVar9;
  byte *pbVar10;
  int in_GS_OFFSET;
  uint local_6c;
  char local_41;
  byte bStack_40;
  byte bStack_3f;
  byte bStack_3e;
  char local_3d;
  byte bStack_3c;
  byte bStack_3b;
  byte bStack_3a;
  char local_39;
  byte bStack_38;
  byte bStack_37;
  byte bStack_36;
  char local_35;
  byte bStack_34;
  byte bStack_33;
  byte bStack_32;
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_3 != 0) {
    uVar8 = 0;
    do {
      uVar2 = *param_5;
      bVar6 = (byte)uVar8;
      uVar3 = param_5[1];
      bVar7 = ~bVar6 & 7;
      uVar4 = param_5[2];
      bVar9 = (byte)((int)(uint)*(byte *)(param_1 + (uVar8 >> 3)) >> bVar7) & 1;
      uVar5 = param_5[3];
      local_6c._0_1_ = -bVar9 & 0x80;
      (*param_8)(param_5,param_5,param_4);
      if (param_7 == 0) {
        local_6c._0_1_ = (byte)local_6c ^ *(byte *)param_5;
      }
      else {
        local_6c._0_1_ = (byte)local_6c ^ *(byte *)param_5;
        bVar9 = (byte)local_6c >> 7;
      }
      local_6c = (uint)(byte)local_6c;
      bStack_40 = (byte)((uint)uVar2 >> 8);
      local_41 = (char)uVar2;
      *(byte *)param_5 = (byte)((int)(uint)bStack_40 >> 7) | local_41 * '\x02';
      bStack_3f = (byte)((uint)uVar2 >> 0x10);
      *(byte *)((int)param_5 + 1) = bStack_40 * '\x02' | (byte)((int)(uint)bStack_3f >> 7);
      bStack_3e = (byte)((uint)uVar2 >> 0x18);
      *(byte *)((int)param_5 + 2) = bStack_3f * '\x02' | (byte)((int)(uint)bStack_3e >> 7);
      local_3d = (char)uVar3;
      *(byte *)((int)param_5 + 3) = bStack_3e * '\x02' | (byte)((int)(uVar3 & 0xff) >> 7);
      bStack_3c = (byte)(uVar3 >> 8);
      *(byte *)(param_5 + 1) = local_3d * '\x02' | (byte)((int)(uint)bStack_3c >> 7);
      bStack_3b = (byte)(uVar3 >> 0x10);
      *(byte *)((int)param_5 + 5) = bStack_3c * '\x02' | (byte)((int)(uint)bStack_3b >> 7);
      bStack_3a = (byte)(uVar3 >> 0x18);
      *(byte *)((int)param_5 + 6) = bStack_3b * '\x02' | (byte)((int)(uint)bStack_3a >> 7);
      local_39 = (char)uVar4;
      *(byte *)((int)param_5 + 7) = bStack_3a * '\x02' | (byte)((int)(uVar4 & 0xff) >> 7);
      bStack_38 = (byte)(uVar4 >> 8);
      *(byte *)(param_5 + 2) = local_39 * '\x02' | (byte)((int)(uint)bStack_38 >> 7);
      bStack_37 = (byte)(uVar4 >> 0x10);
      *(byte *)((int)param_5 + 9) = bStack_38 * '\x02' | (byte)((int)(uint)bStack_37 >> 7);
      bStack_36 = (byte)(uVar4 >> 0x18);
      *(byte *)((int)param_5 + 10) = bStack_37 * '\x02' | (byte)((int)(uint)bStack_36 >> 7);
      local_35 = (char)uVar5;
      *(byte *)((int)param_5 + 0xb) = bStack_36 * '\x02' | (byte)((int)(uVar5 & 0xff) >> 7);
      bStack_34 = (byte)(uVar5 >> 8);
      *(byte *)(param_5 + 3) = local_35 * '\x02' | (byte)((int)(uint)bStack_34 >> 7);
      bStack_33 = (byte)(uVar5 >> 0x10);
      *(byte *)((int)param_5 + 0xd) = bStack_34 * '\x02' | (byte)((int)(uint)bStack_33 >> 7);
      bStack_32 = (byte)(uVar5 >> 0x18);
      *(byte *)((int)param_5 + 0xf) = bStack_32 * '\x02' | bVar9;
      *(byte *)((int)param_5 + 0xe) = bStack_33 * '\x02' | (byte)((int)(uint)bStack_32 >> 7);
      pbVar10 = (byte *)((uVar8 >> 3) + param_2);
      uVar8 = uVar8 + 1;
      *pbVar10 = ~(byte)(1 << bVar7) & *pbVar10 | (byte)((int)(local_6c & 0x80) >> (bVar6 & 7));
    } while (param_3 != uVar8);
  }
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

