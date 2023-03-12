
void * tree_find_sk(_STACK *param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  int in_GS_OFFSET;
  undefined *local_2c [3];
  undefined local_20 [4];
  undefined4 local_1c;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_1c = param_2;
  local_2c[0] = local_20;
  iVar1 = sk_find(param_1,local_2c);
  if (iVar1 == -1) {
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = sk_value(param_1,iVar1);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pvVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

