
void ENGINE_unregister_RSA(ENGINE *e)

{
                    /* WARNING: Could not recover jumptable at 0x0051b33c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_unregister_006a885c)(&rsa_table,e);
  return;
}

