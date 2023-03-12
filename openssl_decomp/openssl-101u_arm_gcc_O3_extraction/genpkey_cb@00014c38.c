
undefined4 genpkey_cb(EVP_PKEY_CTX *param_1)

{
  BIO *b;
  int iVar1;
  undefined local_18 [8];
  
  local_18[0] = 0x2a;
  b = (BIO *)EVP_PKEY_CTX_get_app_data(param_1);
  iVar1 = EVP_PKEY_CTX_get_keygen_info(param_1,0);
  if (iVar1 == 0) {
    local_18[0] = 0x2e;
  }
  else if (iVar1 == 1) {
    local_18[0] = 0x2b;
  }
  else if (iVar1 == 2) {
    local_18[0] = 0x2a;
  }
  else if (iVar1 == 3) {
    local_18[0] = 10;
  }
  BIO_write(b,local_18,1);
  BIO_ctrl(b,0xb,0,(void *)0x0);
  return 1;
}

