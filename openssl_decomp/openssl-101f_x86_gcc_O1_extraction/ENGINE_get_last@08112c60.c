
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ENGINE * ENGINE_get_last(void)

{
  ENGINE *pEVar1;
  int in_EAX;
  
  CRYPTO_lock(in_EAX,9,(char *)0x1e,(int)"eng_list.c");
  pEVar1 = engine_list_tail;
  if (engine_list_tail != (ENGINE *)0x0) {
    *(int *)(engine_list_tail + 0x58) = *(int *)(engine_list_tail + 0x58) + 1;
  }
  CRYPTO_lock(in_EAX,10,(char *)0x1e,(int)"eng_list.c");
  return pEVar1;
}

