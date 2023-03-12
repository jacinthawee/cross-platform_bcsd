
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ENGINE * ENGINE_new(void)

{
  ENGINE *pEVar1;
  
  pEVar1 = (ENGINE *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x70,"eng_lib.c",0x44);
  if (pEVar1 == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x7a,0x41,"eng_lib.c",0x47);
    pEVar1 = (ENGINE *)0x0;
  }
  else {
    (*(code *)PTR_memset_006aab00)(pEVar1,0,0x70);
    *(undefined4 *)(pEVar1 + 0x58) = 1;
    (*(code *)PTR_CRYPTO_new_ex_data_006a9430)(9,pEVar1,pEVar1 + 0x60);
  }
  return pEVar1;
}

