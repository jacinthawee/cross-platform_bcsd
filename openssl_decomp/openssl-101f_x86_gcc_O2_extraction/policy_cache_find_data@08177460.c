
void * policy_cache_find_data(int param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  int in_GS_OFFSET;
  undefined local_20 [4];
  undefined4 local_1c;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_1c = param_2;
  iVar1 = sk_find(*(_STACK **)(param_1 + 4),local_20);
  if (iVar1 == -1) {
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = sk_value(*(_STACK **)(param_1 + 4),iVar1);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pvVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

