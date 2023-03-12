
int __regparm3
srp_create_user(undefined4 param_1_00,undefined4 *param_2_00,undefined4 *param_3_00,
               undefined4 param_1,undefined4 param_2,undefined4 param_3,BIO *param_4,int param_5)

{
  int iVar1;
  int in_GS_OFFSET;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined local_420 [1024];
  int local_20;
  
  local_42c = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_428 = param_3;
  local_424 = param_1_00;
  iVar1 = password_callback(local_420,0x400,1,&local_428);
  if (iVar1 < 1) {
    iVar1 = 0;
  }
  else {
    if (param_5 != 0) {
      BIO_printf(param_4,"Creating\n user=\"%s\"\n g=\"%s\"\n N=\"%s\"\n",param_1_00,param_1,param_2
                );
    }
    iVar1 = SRP_create_verifier(param_1_00,local_420,&local_42c,param_2_00,param_2,param_1);
    if (iVar1 == 0) {
      BIO_printf(param_4,"Internal error creating SRP verifier\n");
    }
    else {
      *param_3_00 = local_42c;
    }
    if (1 < param_5) {
      BIO_printf(param_4,"gNid=%s salt =\"%s\"\n verifier =\"%s\"\n",iVar1,local_42c,*param_2_00);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

