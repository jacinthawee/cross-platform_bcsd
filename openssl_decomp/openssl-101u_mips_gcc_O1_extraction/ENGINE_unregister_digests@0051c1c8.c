
void ENGINE_unregister_digests(ENGINE *e)

{
                    /* WARNING: Could not recover jumptable at 0x0051c1dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_unregister_006a885c)(&digest_table,e);
  return;
}

