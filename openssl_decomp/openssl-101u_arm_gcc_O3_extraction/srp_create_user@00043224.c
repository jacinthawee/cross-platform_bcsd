
void srp_create_user(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,BIO *param_7,int param_8)

{
  int iVar1;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined auStack_42c [1024];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  local_434 = param_6;
  local_438 = 0;
  local_430 = param_1;
  iVar1 = password_callback(auStack_42c,0x400,1,&local_434);
  if (iVar1 < 1) {
    iVar1 = 0;
  }
  else {
    if (param_8 != 0) {
      BIO_printf(param_7,"Creating\n user=\"%s\"\n g=\"%s\"\n N=\"%s\"\n",param_1,param_4,param_5);
    }
    iVar1 = SRP_create_verifier(param_1,auStack_42c,&local_438,param_2,param_5,param_4);
    if (iVar1 == 0) {
      BIO_printf(param_7,"Internal error creating SRP verifier\n");
    }
    else {
      *param_3 = local_438;
    }
    if (1 < param_8) {
      BIO_printf(param_7,"gNid=%s salt =\"%s\"\n verifier =\"%s\"\n",iVar1,local_438,*param_2);
    }
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar1);
}

