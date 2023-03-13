
int DSA_up_ref(DSA *r)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(&r->references,1,8,"dsa_lib.c",0xed);
  return iVar1 < 2 ^ 1;
}

