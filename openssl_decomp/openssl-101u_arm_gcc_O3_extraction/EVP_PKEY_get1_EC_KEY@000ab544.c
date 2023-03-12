
ec_key_st * EVP_PKEY_get1_EC_KEY(EVP_PKEY *pkey)

{
  if (pkey->type == 0x198) {
    EC_KEY_up_ref((EC_KEY *)(pkey->pkey).rsa);
    return (ec_key_st *)(pkey->pkey).ptr;
  }
  ERR_put_error(6,0x83,0x8e,"p_lib.c",0x140);
  return (ec_key_st *)0x0;
}

