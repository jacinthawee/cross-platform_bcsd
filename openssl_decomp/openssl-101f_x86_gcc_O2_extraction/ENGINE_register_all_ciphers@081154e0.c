
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_register_all_ciphers(void)

{
  ENGINE *pEVar1;
  ENGINE *e;
  int in_GS_OFFSET;
  undefined4 local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  pEVar1 = ENGINE_get_first();
  if (pEVar1 != (ENGINE *)0x0) {
    do {
      e = *(ENGINE **)(pEVar1 + 0x24);
      if (e != (ENGINE *)0x0) {
        e = (ENGINE *)(*(code *)e)(pEVar1,0,&local_14,0);
        if (0 < (int)e) {
          e = (ENGINE *)
              engine_table_register(&cipher_table,engine_unregister_all_ciphers,pEVar1,local_14,e,0)
          ;
        }
      }
      pEVar1 = ENGINE_get_next(e);
    } while (pEVar1 != (ENGINE *)0x0);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

