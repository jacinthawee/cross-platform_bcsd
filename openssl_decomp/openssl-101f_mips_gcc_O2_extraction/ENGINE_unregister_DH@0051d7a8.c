
void ENGINE_unregister_DH(ENGINE *e)

{
                    /* WARNING: Could not recover jumptable at 0x0051d7bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_unregister_006a997c)(&dh_table,e);
  return;
}

