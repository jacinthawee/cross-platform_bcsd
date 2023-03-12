
rsa_st * EVP_PKEY_get1_RSA(EVP_PKEY *pkey)

{
  if (pkey->type == 6) {
    (*(code *)PTR_RSA_up_ref_006a7f98)((pkey->pkey).ptr);
    return (rsa_st *)(pkey->pkey).ptr;
  }
  ERR_put_error(6,0x79,0x7f,"p_lib.c",0x117);
  return (rsa_st *)0x0;
}

