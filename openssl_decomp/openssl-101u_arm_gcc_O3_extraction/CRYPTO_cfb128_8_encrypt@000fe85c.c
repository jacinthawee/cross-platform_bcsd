
void CRYPTO_cfb128_8_encrypt
               (int param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5,
               undefined4 param_6,int param_7,code *param_8)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bVar5;
  undefined4 uVar6;
  int iVar7;
  undefined3 uStack_4f;
  undefined uStack_4c;
  undefined3 local_4b;
  undefined uStack_48;
  undefined3 local_47;
  undefined uStack_44;
  undefined3 local_43;
  
  iVar1 = __stack_chk_guard;
  if (param_3 != 0) {
    if (param_7 == 0) {
      do {
        uVar2 = *param_5;
        uVar3 = param_5[1];
        uVar4 = param_5[2];
        uVar6 = param_5[3];
        (*param_8)(param_5,param_5,param_4);
        bVar5 = *(byte *)(param_1 + param_7);
        local_4b = (undefined3)((uint)uVar3 >> 8);
        uStack_48 = (undefined)uVar4;
        *(byte *)(param_2 + param_7) = bVar5 ^ *(byte *)param_5;
        param_7 = param_7 + 1;
        uStack_4f = (undefined3)((uint)uVar2 >> 8);
        uStack_4c = (undefined)uVar3;
        param_5[1] = CONCAT13(uStack_48,local_4b);
        local_47 = (undefined3)((uint)uVar4 >> 8);
        uStack_44 = (undefined)uVar6;
        local_43 = (undefined3)((uint)uVar6 >> 8);
        *param_5 = CONCAT13(uStack_4c,uStack_4f);
        param_5[2] = CONCAT13(uStack_44,local_47);
        param_5[3] = CONCAT13(bVar5,local_43);
      } while (param_7 != param_3);
    }
    else {
      iVar7 = 0;
      do {
        uVar2 = *param_5;
        uVar3 = param_5[1];
        uVar4 = param_5[2];
        uVar6 = param_5[3];
        (*param_8)(param_5,param_5,param_4);
        bVar5 = *(byte *)param_5 ^ *(byte *)(param_1 + iVar7);
        local_47 = (undefined3)((uint)uVar4 >> 8);
        uStack_44 = (undefined)uVar6;
        *(byte *)(param_2 + iVar7) = bVar5;
        iVar7 = iVar7 + 1;
        uStack_4f = (undefined3)((uint)uVar2 >> 8);
        uStack_4c = (undefined)uVar3;
        param_5[2] = CONCAT13(uStack_44,local_47);
        local_4b = (undefined3)((uint)uVar3 >> 8);
        uStack_48 = (undefined)uVar4;
        local_43 = (undefined3)((uint)uVar6 >> 8);
        *param_5 = CONCAT13(uStack_4c,uStack_4f);
        param_5[1] = CONCAT13(uStack_48,local_4b);
        param_5[3] = CONCAT13(bVar5,local_43);
      } while (iVar7 != param_3);
    }
  }
  if (iVar1 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

