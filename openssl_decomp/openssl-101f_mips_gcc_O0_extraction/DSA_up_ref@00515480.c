
int DSA_up_ref(DSA *r)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a9080)(&r->references,1,8,"dsa_lib.c",0xeb);
  return iVar1 < 2 ^ 1;
}

