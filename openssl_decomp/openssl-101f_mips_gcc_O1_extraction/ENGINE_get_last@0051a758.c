
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ENGINE * ENGINE_get_last(void)

{
  ENGINE *pEVar1;
  
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_list.c",0xd3);
  pEVar1 = engine_list_tail;
  if (engine_list_tail != (ENGINE *)0x0) {
    *(int *)(engine_list_tail + 0x58) = *(int *)(engine_list_tail + 0x58) + 1;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_list.c",0xda);
  return pEVar1;
}
