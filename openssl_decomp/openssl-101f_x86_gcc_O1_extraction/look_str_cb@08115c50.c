
void look_str_cb(undefined4 param_1,_STACK *param_2,undefined4 param_3,void **param_4)

{
  char *__s;
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  void *__n;
  int iVar4;
  int in_GS_OFFSET;
  void *local_24;
  int local_20;
  
  iVar4 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_4[1] == (void *)0x0) {
    while( true ) {
      iVar2 = sk_num(param_2);
      if (iVar2 <= iVar4) break;
      pvVar3 = sk_value(param_2,iVar4);
      (**(code **)((int)pvVar3 + 0x30))(pvVar3,&local_24,0,param_1);
      pvVar1 = local_24;
      __s = *(char **)((int)local_24 + 0xc);
      __n = (void *)strlen(__s);
      if (__n == param_4[3]) {
        iVar2 = strncasecmp(__s,(char *)param_4[2],(size_t)__n);
        if (iVar2 == 0) {
          *param_4 = pvVar3;
          param_4[1] = pvVar1;
          break;
        }
      }
      iVar4 = iVar4 + 1;
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

