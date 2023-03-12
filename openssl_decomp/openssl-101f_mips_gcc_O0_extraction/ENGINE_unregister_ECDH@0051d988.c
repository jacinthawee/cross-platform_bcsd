
void ENGINE_unregister_ECDH(ENGINE *e)

{
                    /* WARNING: Could not recover jumptable at 0x0051d99c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_unregister_006a997c)(&ecdh_table,e);
  return;
}

