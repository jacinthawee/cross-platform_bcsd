
void ENGINE_unregister_DSA(ENGINE *e)

{
                    /* WARNING: Could not recover jumptable at 0x0051d3fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_unregister_006a997c)(&dsa_table,e);
  return;
}

