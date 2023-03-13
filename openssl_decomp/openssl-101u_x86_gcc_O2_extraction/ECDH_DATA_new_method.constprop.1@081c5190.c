
undefined4 * ECDH_DATA_new_method_constprop_1(void)

{
  undefined4 *ptr;
  ENGINE *e;
  ECDH_METHOD *e_00;
  
  ptr = (undefined4 *)CRYPTO_malloc(0x18,"ech_lib.c",0x8c);
  if (ptr == (undefined4 *)0x0) {
    ERR_put_error(0x2b,0x65,0x41,"ech_lib.c",0x8e);
    ptr = (undefined4 *)0x0;
  }
  else {
    *ptr = 0;
    if (default_ECDH_method == (ECDH_METHOD *)0x0) {
      default_ECDH_method = ECDH_OpenSSL();
    }
    ptr[3] = default_ECDH_method;
    ptr[1] = 0;
    e = ENGINE_get_default_ECDH();
    ptr[1] = e;
    if (e == (ENGINE *)0x0) {
      e_00 = (ECDH_METHOD *)ptr[3];
    }
    else {
      e_00 = ENGINE_get_ECDH(e);
      ptr[3] = e_00;
      if (e_00 == (ECDH_METHOD *)0x0) {
        ERR_put_error(0x2b,0x65,0x26,"ech_lib.c",0x9c);
        ENGINE_finish((ENGINE *)e_00);
        CRYPTO_free(ptr);
        return (undefined4 *)0x0;
      }
    }
    ptr[2] = *(undefined4 *)(e_00 + 8);
    CRYPTO_new_ex_data(0xd,ptr,(CRYPTO_EX_DATA *)(ptr + 4));
  }
  return ptr;
}

