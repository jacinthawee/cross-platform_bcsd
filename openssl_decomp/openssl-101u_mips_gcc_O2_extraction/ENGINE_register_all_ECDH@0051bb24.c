
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_register_all_ECDH(void)

{
  ENGINE *e;
  
  for (e = ENGINE_get_first(); e != (ENGINE *)0x0; e = ENGINE_get_next(e)) {
    if (*(int *)(e + 0x14) != 0) {
      (*(code *)PTR_engine_table_register_006a8860)
                (&ecdh_table,engine_unregister_all_ECDH,e,&dummy_nid,1,0);
    }
  }
  return;
}

