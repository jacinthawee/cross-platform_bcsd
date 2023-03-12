
dsa_st * EVP_PKEY_get1_DSA(EVP_PKEY *pkey)

{
  if (pkey->type == 0x74) {
    DSA_up_ref((DSA *)(pkey->pkey).rsa);
    return (dsa_st *)(pkey->pkey).ptr;
  }
  ERR_put_error(6,0x78,0x81,"p_lib.c",299);
  return (dsa_st *)0x0;
}

