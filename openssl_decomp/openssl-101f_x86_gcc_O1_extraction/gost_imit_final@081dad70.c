
int gost_imit_final(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = *(int *)(iVar1 + 0x103c);
  if (iVar2 == 0) {
    ERR_GOST_error(0x8c,0x74,"gost_crypt.c",0x240);
    goto LAB_081dadca;
  }
  if (*(int *)(iVar1 + 0x1030) == 0) {
    if (*(int *)(iVar1 + 0x1038) != 0) {
      local_28 = 0;
      local_24 = 0;
      gost_imit_update(param_1,&local_28,8);
      goto LAB_081dae0b;
    }
  }
  else {
LAB_081dae0b:
    iVar2 = *(int *)(iVar1 + 0x1038);
    if (iVar2 != 0) {
      if (iVar2 < 8) {
        memset((void *)(iVar1 + 0x1028 + iVar2),0,8 - iVar2);
      }
      if ((*(int *)(iVar1 + 0x1034) != 0) && (*(int *)(iVar1 + 0x1030) == 0x400)) {
        cryptopro_key_meshing(iVar1,&local_28);
      }
      mac_block(iVar1,iVar1 + 0x1020,iVar1 + 0x1028);
      *(uint *)(iVar1 + 0x1030) = (*(uint *)(iVar1 + 0x1030) & 0x3ff) + 8;
    }
  }
  get_mac(iVar1 + 0x1020,0x20,param_2);
  iVar2 = 1;
LAB_081dadca:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

