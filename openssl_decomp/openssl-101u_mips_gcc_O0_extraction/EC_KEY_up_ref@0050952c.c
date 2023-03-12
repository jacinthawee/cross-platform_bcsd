
int EC_KEY_up_ref(EC_KEY *key)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(key + 0x18,1,0x21,"ec_key.c",0xd9);
  return iVar1 < 2 ^ 1;
}

