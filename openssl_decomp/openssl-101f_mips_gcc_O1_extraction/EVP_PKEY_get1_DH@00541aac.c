
dh_st * EVP_PKEY_get1_DH(EVP_PKEY *pkey)

{
  if (pkey->type == 0x1c) {
    (*(code *)PTR_DH_up_ref_006a9bfc)((pkey->pkey).ptr);
    return (dh_st *)(pkey->pkey).ptr;
  }
  ERR_put_error(6,0x77,0x80,"p_lib.c",0x160);
  return (dh_st *)0x0;
}

