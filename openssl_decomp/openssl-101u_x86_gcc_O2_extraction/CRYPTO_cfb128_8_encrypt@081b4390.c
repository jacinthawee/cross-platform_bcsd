
void CRYPTO_cfb128_8_encrypt
               (byte *param_1,byte *param_2,int param_3,undefined4 param_4,undefined4 *param_5,
               undefined4 param_6,int param_7,code *param_8)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  byte *pbVar8;
  byte *pbVar9;
  int in_GS_OFFSET;
  undefined3 uStack_40;
  undefined local_3d;
  undefined3 uStack_3c;
  undefined local_39;
  undefined3 uStack_38;
  undefined local_35;
  undefined3 uStack_34;
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_3 != 0) {
    uVar4 = *param_5;
    uVar6 = param_5[1];
    uVar5 = param_5[2];
    uVar7 = param_5[3];
    pbVar9 = param_1;
    if (param_7 == 0) {
      do {
        pbVar8 = pbVar9 + 1;
        (*param_8)(param_5,param_5,param_4);
        uStack_38 = (undefined3)((uint)uVar5 >> 8);
        local_35 = (undefined)uVar7;
        uStack_40 = (undefined3)((uint)uVar4 >> 8);
        local_3d = (undefined)uVar6;
        uVar4 = CONCAT13(local_3d,uStack_40);
        uStack_34 = (undefined3)((uint)uVar7 >> 8);
        uVar7 = CONCAT13(*pbVar9,uStack_34);
        *param_2 = *pbVar9 ^ *(byte *)param_5;
        uStack_3c = (undefined3)((uint)uVar6 >> 8);
        local_39 = (undefined)uVar5;
        uVar6 = CONCAT13(local_39,uStack_3c);
        *param_5 = uVar4;
        param_5[2] = CONCAT13(local_35,uStack_38);
        param_5[3] = uVar7;
        param_5[1] = uVar6;
        uVar5 = CONCAT13(local_35,uStack_38);
        param_2 = param_2 + 1;
        pbVar9 = pbVar8;
      } while (param_1 + param_3 != pbVar8);
    }
    else {
      do {
        pbVar8 = pbVar9 + 1;
        (*param_8)(param_5,param_5,param_4);
        bVar3 = *pbVar9;
        uStack_3c = (undefined3)((uint)uVar6 >> 8);
        local_39 = (undefined)uVar5;
        bVar2 = *(byte *)param_5;
        uStack_38 = (undefined3)((uint)uVar5 >> 8);
        local_35 = (undefined)uVar7;
        uVar5 = CONCAT13(local_35,uStack_38);
        *param_2 = bVar3 ^ bVar2;
        uStack_40 = (undefined3)((uint)uVar4 >> 8);
        local_3d = (undefined)uVar6;
        uVar4 = CONCAT13(local_3d,uStack_40);
        uStack_34 = (undefined3)((uint)uVar7 >> 8);
        uVar7 = CONCAT13(bVar3 ^ bVar2,uStack_34);
        param_5[1] = CONCAT13(local_39,uStack_3c);
        param_5[2] = uVar5;
        *param_5 = uVar4;
        param_5[3] = uVar7;
        uVar6 = CONCAT13(local_39,uStack_3c);
        param_2 = param_2 + 1;
        pbVar9 = pbVar8;
      } while (param_1 + param_3 != pbVar8);
    }
  }
  if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

