
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_register_all_RSA(void)

{
  ENGINE *e;
  
  for (e = ENGINE_get_first(); e != (ENGINE *)0x0; e = ENGINE_get_next(e)) {
    if (*(int *)(e + 8) != 0) {
      (*(code *)PTR_engine_table_register_006a8860)
                (&rsa_table,engine_unregister_all_RSA,e,&dummy_nid,1,0);
    }
  }
  return;
}

