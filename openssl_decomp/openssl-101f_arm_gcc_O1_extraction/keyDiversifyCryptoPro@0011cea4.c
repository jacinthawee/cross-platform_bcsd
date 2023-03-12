
void keyDiversifyCryptoPro(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined local_38;
  undefined local_37;
  undefined local_36;
  undefined local_35;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  int local_2c;
  
  uVar6 = *param_2;
  uVar4 = param_2[2];
  uVar2 = param_2[3];
  param_4[1] = param_2[1];
  param_4[2] = uVar4;
  iVar12 = 0;
  param_4[3] = uVar2;
  local_2c = __TMC_END__;
  *param_4 = uVar6;
  uVar6 = param_2[5];
  uVar4 = param_2[6];
  uVar2 = param_2[7];
  param_4[4] = param_2[4];
  param_4[5] = uVar6;
  param_4[6] = uVar4;
  param_4[7] = uVar2;
  do {
    iVar9 = 0;
    iVar10 = 0;
    uVar11 = 1;
    puVar7 = param_4;
    do {
      uVar3 = uVar11 & *(byte *)(param_3 + iVar12);
      puVar8 = puVar7 + 1;
      uVar11 = uVar11 << 1;
      uVar5 = (uint)*(byte *)((int)puVar7 + 2) << 0x10 | (uint)*(byte *)((int)puVar7 + 1) << 8 |
              (uint)*(byte *)puVar7 | (uint)*(byte *)((int)puVar7 + 3) << 0x18;
      iVar1 = uVar5 + iVar10;
      if (uVar3 == 0) {
        iVar9 = uVar5 + iVar9;
        iVar1 = iVar10;
      }
      iVar10 = iVar1;
      puVar7 = puVar8;
    } while (puVar8 != param_4 + 8);
    local_38 = (undefined)iVar10;
    iVar12 = iVar12 + 1;
    local_34 = (undefined)iVar9;
    local_37 = (undefined)((uint)iVar10 >> 8);
    local_33 = (undefined)((uint)iVar9 >> 8);
    local_36 = (undefined)((uint)iVar10 >> 0x10);
    local_35 = (undefined)((uint)iVar10 >> 0x18);
    local_32 = (undefined)((uint)iVar9 >> 0x10);
    local_31 = (undefined)((uint)iVar9 >> 0x18);
    gost_key(param_1,param_4);
    gost_enc_cfb(param_1,&local_38,param_4,param_4,4);
  } while (iVar12 != 8);
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

