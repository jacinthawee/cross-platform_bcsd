
void ENGINE_unregister_ECDH(ENGINE *e)

{
                    /* WARNING: Could not recover jumptable at 0x0051babc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_unregister_006a885c)(&ecdh_table,e);
  return;
}

