
int gost_imit_update(int param_1,undefined *param_2,size_t param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  undefined *__src;
  uint uVar6;
  int in_GS_OFFSET;
  undefined local_28 [8];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = *(int *)(param_1 + 0xc);
  iVar3 = *(int *)(iVar2 + 0x103c);
  if (iVar3 == 0) {
    ERR_GOST_error(0x73,0x74,"gost_crypt.c",0x21b);
    goto LAB_081daf59;
  }
  uVar6 = *(uint *)(iVar2 + 0x1038);
  __src = param_2;
  if (uVar6 == 0) {
LAB_081dae90:
    puVar5 = __src;
    uVar6 = param_3;
    if (param_3 < 9) {
      uVar4 = param_3;
      if (param_3 == 0) goto LAB_081daf4e;
    }
    else {
      do {
        if ((*(int *)(iVar2 + 0x1034) != 0) && (*(int *)(iVar2 + 0x1030) == 0x400)) {
          cryptopro_key_meshing(iVar2,local_28);
        }
        uVar6 = uVar6 - 8;
        mac_block(iVar2,iVar2 + 0x1020,puVar5);
        *(uint *)(iVar2 + 0x1030) = (*(uint *)(iVar2 + 0x1030) & 0x3ff) + 8;
        puVar5 = puVar5 + 8;
      } while (8 < uVar6);
      __src = __src + (param_3 - 9 & 0xfffffff8) + 8;
      param_3 = (param_3 - 8) - (param_3 - 9 & 0xfffffff8);
    }
    memcpy((void *)(iVar2 + 0x1028),__src,param_3);
    uVar4 = param_3;
  }
  else {
    uVar4 = uVar6;
    uVar1 = param_3;
    if ((param_3 != 0) && (uVar6 < 8)) {
      __src = param_2 + 1;
      *(undefined *)(iVar2 + 0x1028 + uVar6) = *param_2;
      uVar1 = param_3 - 1;
      uVar4 = uVar6 + 1;
      if ((7 < uVar4) || (uVar1 == 0)) goto LAB_081daf74;
      __src = param_2 + 2;
      *(undefined *)(iVar2 + 0x1028 + uVar4) = param_2[1];
      uVar1 = param_3 - 2;
      uVar4 = uVar6 + 2;
      if ((7 < uVar4) || (uVar1 == 0)) goto LAB_081daf74;
      __src = param_2 + 3;
      *(undefined *)(iVar2 + 0x1028 + uVar4) = param_2[2];
      uVar1 = param_3 - 3;
      uVar4 = uVar6 + 3;
      if ((7 < uVar4) || (uVar1 == 0)) goto LAB_081daf74;
      __src = param_2 + 4;
      *(undefined *)(iVar2 + 0x1028 + uVar4) = param_2[3];
      uVar1 = param_3 - 4;
      uVar4 = uVar6 + 4;
      if ((7 < uVar4) || (uVar1 == 0)) goto LAB_081daf74;
      __src = param_2 + 5;
      *(undefined *)(iVar2 + 0x1028 + uVar4) = param_2[4];
      uVar1 = param_3 - 5;
      uVar4 = uVar6 + 5;
      if ((7 < uVar4) || (uVar1 == 0)) goto LAB_081daf74;
      __src = param_2 + 6;
      *(undefined *)(iVar2 + 0x1028 + uVar4) = param_2[5];
      uVar1 = param_3 - 6;
      uVar4 = uVar6 + 6;
      if ((7 < uVar4) || (uVar1 == 0)) goto LAB_081daf74;
      param_3 = param_3 - 7;
      __src = param_2 + 7;
      *(undefined *)(iVar2 + 0x102f) = param_2[6];
LAB_081dae38:
      if ((*(int *)(iVar2 + 0x1034) != 0) && (*(int *)(iVar2 + 0x1030) == 0x400)) {
        cryptopro_key_meshing(iVar2,local_28);
      }
      mac_block(iVar2,iVar2 + 0x1020,iVar2 + 0x1028);
      *(uint *)(iVar2 + 0x1030) = (*(uint *)(iVar2 + 0x1030) & 0x3ff) + 8;
      goto LAB_081dae90;
    }
LAB_081daf74:
    param_3 = uVar1;
    if (uVar4 == 8) goto LAB_081dae38;
  }
LAB_081daf4e:
  *(uint *)(iVar2 + 0x1038) = uVar4;
  iVar3 = 1;
LAB_081daf59:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

