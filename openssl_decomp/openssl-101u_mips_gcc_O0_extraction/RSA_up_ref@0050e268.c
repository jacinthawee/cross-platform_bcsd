
int RSA_up_ref(RSA *r)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(&r->references,1,9,"rsa_lib.c",0x108);
  return iVar1 < 2 ^ 1;
}

