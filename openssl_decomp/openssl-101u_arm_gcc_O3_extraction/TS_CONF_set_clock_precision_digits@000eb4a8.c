
int TS_CONF_set_clock_precision_digits(CONF *param_1,char *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint local_1c [2];
  
  local_1c[0] = 0;
  uVar1 = NCONF_get_number_e(param_1,param_2,"clock_precision_digits",(long *)local_1c);
  if ((uVar1 != 0) && (uVar1 = local_1c[0], 6 < local_1c[0])) {
    __fprintf_chk(stderr,1,"invalid variable value for %s::%s\n",param_2,"clock_precision_digits");
    return 0;
  }
  local_1c[0] = uVar1;
  iVar2 = TS_RESP_CTX_set_clock_precision_digits(param_3,local_1c[0]);
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

