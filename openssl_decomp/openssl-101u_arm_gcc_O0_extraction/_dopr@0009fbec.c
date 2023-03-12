
/* WARNING: Removing unreachable block (ram,0x000a0582) */
/* WARNING: Removing unreachable block (ram,0x000a0588) */
/* WARNING: Removing unreachable block (ram,0x0009fd7c) */
/* WARNING: Removing unreachable block (ram,0x0009ff72) */

void _dopr(undefined4 param_1,int param_2,int *param_3,int *param_4,undefined4 *param_5,
          char *param_6)

{
  int iVar1;
  int local_58 [11];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if ((*param_6 != '\0') && ((param_2 != 0 || (*param_3 != 0)))) {
                    /* WARNING: Could not recover jumptable at 0x0009fc62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_0009fc62::switchdataD_0009fc66 + switchD_0009fc62::switchdataD_0009fc66))();
    return;
  }
  *param_5 = 0;
  local_58[0] = 0;
  iVar1 = doapr_outch(param_1,param_2,local_58,param_3,0);
  if (iVar1 != 0) {
    *param_4 = local_58[0] + -1;
  }
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1 != 0);
  }
  return;
}

