
void * ssl_give_srp_client_pwd_cb(undefined4 param_1,undefined4 *param_2)

{
  void *ptr;
  void *pvVar1;
  void *pvVar2;
  undefined uVar3;
  undefined4 local_18;
  char *local_14;
  
  ptr = CRYPTO_malloc(0x401,"s_client.c",0x224);
  if (ptr == (void *)0x0) {
    BIO_printf(bio_err,"Malloc failure\n");
  }
  else {
    local_18 = *param_2;
    uVar3 = 0;
    local_14 = "SRP user";
    pvVar1 = (void *)password_callback(ptr,0x400,0,&local_18);
    pvVar2 = pvVar1;
    if (-1 < (int)pvVar1) {
      uVar3 = 0;
      pvVar2 = ptr;
    }
    if (-1 < (int)pvVar1) {
      *(undefined *)((int)ptr + (int)pvVar1) = uVar3;
      ptr = pvVar2;
    }
    else {
      BIO_printf(bio_err,"Can\'t read Password\n");
      CRYPTO_free(ptr);
      ptr = (void *)0x0;
    }
  }
  return ptr;
}

