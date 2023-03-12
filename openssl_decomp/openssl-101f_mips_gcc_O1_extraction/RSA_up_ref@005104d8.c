
int RSA_up_ref(RSA *r)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a9080)(&r->references,1,9,"rsa_lib.c",0x103);
  return iVar1 < 2 ^ 1;
}

