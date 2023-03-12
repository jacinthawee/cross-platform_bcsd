
void srp_verify_user(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,BIO *param_7,int param_8)

{
  char *ptr;
  int iVar1;
  int iVar2;
  undefined4 local_434;
  char *local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined auStack_424 [1024];
  int local_24;
  
  iVar2 = 0;
  local_42c = param_6;
  local_24 = __TMC_END__;
  local_430 = (char *)0x0;
  local_434 = param_3;
  local_428 = param_1;
  iVar1 = password_callback(auStack_424,0x400,0,&local_42c);
  if (0 < iVar1) {
    if (param_8 != 0) {
      BIO_printf(param_7,
                 "Validating\n   user=\"%s\"\n srp_verifier=\"%s\"\n srp_usersalt=\"%s\"\n g=\"%s\"\n N=\"%s\"\n"
                 ,param_1,param_2,local_434,param_4,param_5);
    }
    BIO_printf(param_7,"Pass %s\n",auStack_424);
    iVar2 = SRP_create_verifier(param_1,auStack_424,&local_434,&local_430,param_5,param_4);
    ptr = local_430;
    if (iVar2 == 0) {
      BIO_printf(param_7,"Internal error validating SRP verifier\n");
    }
    else {
      iVar1 = strcmp(local_430,param_2);
      if (iVar1 != 0) {
        iVar2 = 0;
      }
      CRYPTO_free(ptr);
    }
  }
  if (local_24 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar2);
}

