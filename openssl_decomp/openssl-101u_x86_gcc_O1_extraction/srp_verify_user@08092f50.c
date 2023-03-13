
int __regparm3
srp_verify_user(undefined4 param_1_00,char *param_2_00,undefined4 param_3_00,undefined4 param_1,
               undefined4 param_2,undefined4 param_3,BIO *param_4,int param_5)

{
  char *ptr;
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  undefined *puVar3;
  undefined4 local_430;
  char *local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined local_420 [1024];
  int local_20;
  
  local_42c = (char *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_428 = param_3;
  local_430 = param_3_00;
  local_424 = param_1_00;
  iVar1 = password_callback(local_420,0x400,0,&local_428);
  if (iVar1 < 1) {
    iVar1 = 0;
  }
  else {
    if (param_5 != 0) {
      BIO_printf(param_4,
                 "Validating\n   user=\"%s\"\n srp_verifier=\"%s\"\n srp_usersalt=\"%s\"\n g=\"%s\"\n N=\"%s\"\n"
                 ,param_1_00,param_2_00,local_430,param_1,param_2);
    }
    puVar3 = local_420;
    BIO_printf(param_4,"Pass %s\n",local_420);
    iVar1 = SRP_create_verifier(param_1_00,local_420,&local_430,&local_42c,param_2,param_1);
    ptr = local_42c;
    if (iVar1 == 0) {
      BIO_printf(param_4,"Internal error validating SRP verifier\n",puVar3);
    }
    else {
      iVar2 = strcmp(local_42c,param_2_00);
      if (iVar2 != 0) {
        iVar1 = 0;
      }
      CRYPTO_free(ptr);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

