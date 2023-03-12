
void gost_imit_final(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int local_24;
  int local_20;
  int local_1c;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(iVar2 + 0x103c);
  local_1c = __TMC_END__;
  if (iVar1 == 0) {
    ERR_GOST_error(0x8c,0x74,"gost_crypt.c",0x240);
    goto LAB_0011be70;
  }
  iVar1 = *(int *)(iVar2 + 0x1030);
  if (iVar1 == 0) {
    if (*(int *)(iVar2 + 0x1038) != 0) {
      local_24 = iVar1;
      local_20 = iVar1;
      gost_imit_update(param_1,&local_24,8);
      goto LAB_0011be8c;
    }
  }
  else {
LAB_0011be8c:
    iVar1 = *(int *)(iVar2 + 0x1038);
    if (iVar1 != 0) {
      if (iVar1 < 8) {
        memset((void *)(iVar1 + 0x1028 + iVar2),0,8 - iVar1);
      }
      if ((*(int *)(iVar2 + 0x1034) != 0) && (*(int *)(iVar2 + 0x1030) == 0x400)) {
        cryptopro_key_meshing(iVar2,&local_24);
      }
      mac_block(iVar2,iVar2 + 0x1020,iVar2 + 0x1028);
      *(uint *)(iVar2 + 0x1030) = (*(uint *)(iVar2 + 0x1030) & 0x3ff) + 8;
    }
  }
  iVar1 = 1;
  get_mac(iVar2 + 0x1020,0x20,param_2);
LAB_0011be70:
  if (local_1c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar1);
}

