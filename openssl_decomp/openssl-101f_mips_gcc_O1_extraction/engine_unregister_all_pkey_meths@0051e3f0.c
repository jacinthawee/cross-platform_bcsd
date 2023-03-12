
void engine_unregister_all_pkey_meths(void)

{
                    /* WARNING: Could not recover jumptable at 0x0051e400. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_cleanup_006a9978)(&pkey_meth_table);
  return;
}

