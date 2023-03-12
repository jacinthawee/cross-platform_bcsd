
bool TS_CONF_set_clock_precision_digits(CONF *param_1,char *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int in_GS_OFFSET;
  bool bVar3;
  uint local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = 0;
  uVar1 = NCONF_get_number_e(param_1,param_2,"clock_precision_digits",(long *)&local_14);
  if (uVar1 == 0) {
    local_14 = 0;
  }
  else {
    uVar1 = local_14;
    if (6 < local_14) {
      __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"clock_precision_digits")
      ;
      bVar3 = false;
      goto LAB_081996d9;
    }
  }
  iVar2 = TS_RESP_CTX_set_clock_precision_digits(param_3,uVar1);
  bVar3 = iVar2 != 0;
LAB_081996d9:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

