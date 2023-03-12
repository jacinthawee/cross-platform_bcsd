
void ENGINE_unregister_RAND(ENGINE *e)

{
                    /* WARNING: Could not recover jumptable at 0x0051db7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_unregister_006a997c)(&rand_table,e);
  return;
}

