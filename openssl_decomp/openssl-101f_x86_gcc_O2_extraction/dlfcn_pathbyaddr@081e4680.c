
int dlfcn_pathbyaddr(code *param_1,void *param_2,int param_3)

{
  int iVar1;
  size_t __n;
  undefined4 uVar2;
  int in_GS_OFFSET;
  char *local_30 [4];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1 == (code *)0x0) {
    param_1 = dlfcn_pathbyaddr;
  }
  iVar1 = dladdr(param_1,local_30);
  if (iVar1 == 0) {
    uVar2 = dlerror();
    ERR_add_error_data(4,"dlfcn_pathbyaddr(): ",uVar2);
    iVar1 = -1;
  }
  else {
    __n = strlen(local_30[0]);
    if (param_3 < 1) {
      iVar1 = __n + 1;
    }
    else {
      if (param_3 <= (int)__n) {
        __n = param_3 - 1;
      }
      memcpy(param_2,local_30[0],__n);
      iVar1 = __n + 1;
      *(undefined *)((int)param_2 + __n) = 0;
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

