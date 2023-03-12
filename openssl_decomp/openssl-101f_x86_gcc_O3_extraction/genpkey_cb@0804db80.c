
undefined4 genpkey_cb(EVP_PKEY_CTX *param_1)

{
  BIO *b;
  int iVar1;
  int in_GS_OFFSET;
  undefined local_11;
  int local_10;
  
  local_11 = 0x2a;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  b = (BIO *)EVP_PKEY_CTX_get_app_data(param_1);
  iVar1 = EVP_PKEY_CTX_get_keygen_info(param_1,0);
  if (iVar1 == 0) {
    local_11 = 0x2e;
  }
  else if (iVar1 == 1) {
    local_11 = 0x2b;
  }
  else if (iVar1 == 2) {
    local_11 = 0x2a;
  }
  else if (iVar1 == 3) {
    local_11 = 10;
  }
  BIO_write(b,&local_11,1);
  BIO_ctrl(b,0xb,0,(void *)0x0);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

