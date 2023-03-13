
void * ssl_give_srp_client_pwd_cb(undefined4 param_1,undefined4 *param_2)

{
  void *ptr;
  int iVar1;
  int in_GS_OFFSET;
  undefined4 local_18;
  char *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  ptr = CRYPTO_malloc(0x401,"s_client.c",0x224);
  if (ptr == (void *)0x0) {
    BIO_printf(bio_err,"Malloc failure\n");
    ptr = (void *)0x0;
  }
  else {
    local_18 = *param_2;
    local_14 = "SRP user";
    iVar1 = password_callback(ptr,0x400,0,&local_18);
    if (iVar1 < 0) {
      BIO_printf(bio_err,"Can\'t read Password\n");
      CRYPTO_free(ptr);
      ptr = (void *)0x0;
    }
    else {
      *(undefined *)((int)ptr + iVar1) = 0;
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return ptr;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

