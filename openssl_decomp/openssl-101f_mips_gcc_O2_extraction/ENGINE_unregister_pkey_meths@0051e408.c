
void ENGINE_unregister_pkey_meths(ENGINE *e)

{
                    /* WARNING: Could not recover jumptable at 0x0051e41c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_unregister_006a997c)(&pkey_meth_table,e);
  return;
}

