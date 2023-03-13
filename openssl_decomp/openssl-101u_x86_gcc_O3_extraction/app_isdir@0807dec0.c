
uint app_isdir(char *param_1)

{
  int iVar1;
  uint uVar2;
  int in_GS_OFFSET;
  stat local_68;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = __xstat(3,param_1,&local_68);
  if (iVar1 == 0) {
    uVar2 = (uint)((local_68.st_mode & 0xf000) == 0x4000);
  }
  else {
    uVar2 = 0xffffffff;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

