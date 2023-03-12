
undefined4 ipv6_cb(byte *param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  int in_GS_OFFSET;
  int local_40;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = *(int *)(param_3 + 0x10);
  if (iVar2 != 0x10) {
    if (param_2 == 0) {
      if (*(int *)(param_3 + 0x14) == -1) {
        *(int *)(param_3 + 0x14) = iVar2;
      }
      else {
        uVar3 = 0;
        if (iVar2 != *(int *)(param_3 + 0x14)) goto LAB_0816b9c9;
      }
      *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
      uVar3 = 1;
      goto LAB_0816b9c9;
    }
    if (param_2 < 5) {
      local_40 = param_2;
      uVar5 = 0;
      do {
        bVar1 = *param_1;
        uVar6 = (uint)bVar1;
        uVar5 = uVar5 << 4;
        if ((byte)(bVar1 - 0x30) < 10) {
          uVar5 = uVar5 | uVar6 - 0x30;
        }
        else if ((byte)(bVar1 + 0xbf) < 6) {
          uVar5 = uVar5 | uVar6 - 0x37;
        }
        else {
          if (5 < (byte)(bVar1 + 0x9f)) goto LAB_0816ba30;
          uVar5 = uVar5 | uVar6 - 0x57;
        }
        local_40 = local_40 + -1;
        param_1 = param_1 + 1;
      } while (local_40 != 0);
      ((undefined *)(iVar2 + param_3))[1] = (char)uVar5;
      uVar3 = 1;
      *(undefined *)(iVar2 + param_3) = (char)(uVar5 >> 8);
      *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 2;
      goto LAB_0816b9c9;
    }
    uVar3 = 0;
    if ((0xc < iVar2) || (param_1[param_2] != 0)) goto LAB_0816b9c9;
    iVar4 = __isoc99_sscanf(param_1,"%d.%d.%d.%d",&local_30,&local_2c,&local_28,&local_24);
    if (((iVar4 == 4) && (((local_30 < 0x100 && (local_2c < 0x100)) && (local_28 < 0x100)))) &&
       (local_24 < 0x100)) {
      puVar7 = (undefined *)(iVar2 + param_3);
      *puVar7 = (char)local_30;
      puVar7[1] = (char)local_2c;
      puVar7[3] = (char)local_24;
      puVar7[2] = (char)local_28;
      uVar3 = 1;
      *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 4;
      goto LAB_0816b9c9;
    }
  }
LAB_0816ba30:
  uVar3 = 0;
LAB_0816b9c9:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

