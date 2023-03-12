
dsa_st * EVP_PKEY_get1_DSA(EVP_PKEY *pkey)

{
  if (pkey->type == 0x74) {
    (*(code *)PTR_DSA_up_ref_006a8adc)((pkey->pkey).ptr);
    return (dsa_st *)(pkey->pkey).ptr;
  }
  ERR_put_error(6,0x78,0x81,"p_lib.c",299);
  return (dsa_st *)0x0;
}

