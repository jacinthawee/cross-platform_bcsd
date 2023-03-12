
rsa_st * EVP_PKEY_get1_RSA(EVP_PKEY *pkey)

{
  if (pkey->type == 6) {
    RSA_up_ref((pkey->pkey).rsa);
    return (rsa_st *)(pkey->pkey).ptr;
  }
  ERR_put_error(6,0x79,0x7f,"p_lib.c",0x120);
  return (rsa_st *)0x0;
}

