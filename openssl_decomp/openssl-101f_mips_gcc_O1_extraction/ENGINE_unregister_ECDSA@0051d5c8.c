
void ENGINE_unregister_ECDSA(ENGINE *e)

{
                    /* WARNING: Could not recover jumptable at 0x0051d5dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_unregister_006a997c)(&ecdsa_table,e);
  return;
}
