
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_register_all_ECDSA(void)

{
  ENGINE *pEVar1;
  ENGINE *e;
  
  pEVar1 = ENGINE_get_first();
  while (pEVar1 != (ENGINE *)0x0) {
    e = *(ENGINE **)(pEVar1 + 0x18);
    if (e != (ENGINE *)0x0) {
      e = (ENGINE *)
          engine_table_register(&ecdsa_table,engine_unregister_all_ECDSA,pEVar1,&dummy_nid,1,0);
    }
    pEVar1 = ENGINE_get_next(e);
  }
  return;
}

