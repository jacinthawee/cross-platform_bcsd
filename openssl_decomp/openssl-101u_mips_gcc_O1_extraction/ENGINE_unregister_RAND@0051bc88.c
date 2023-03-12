
void ENGINE_unregister_RAND(ENGINE *e)

{
                    /* WARNING: Could not recover jumptable at 0x0051bc9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_unregister_006a885c)(&rand_table,e);
  return;
}

