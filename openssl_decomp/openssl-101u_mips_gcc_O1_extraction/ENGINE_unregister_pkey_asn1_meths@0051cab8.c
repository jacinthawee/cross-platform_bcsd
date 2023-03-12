
void ENGINE_unregister_pkey_asn1_meths(ENGINE *e)

{
                    /* WARNING: Could not recover jumptable at 0x0051cacc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_unregister_006a885c)(&pkey_asn1_meth_table,e);
  return;
}

