
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ENGINE * ENGINE_get_first(void)

{
  ENGINE *pEVar1;
  
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_list.c",0xbc);
  pEVar1 = engine_list_head;
  if (engine_list_head != (ENGINE *)0x0) {
    *(int *)(engine_list_head + 0x58) = *(int *)(engine_list_head + 0x58) + 1;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_list.c",0xc2);
  return pEVar1;
}

