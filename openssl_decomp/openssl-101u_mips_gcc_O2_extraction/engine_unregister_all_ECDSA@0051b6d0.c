
void engine_unregister_all_ECDSA(void)

{
                    /* WARNING: Could not recover jumptable at 0x0051b6e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_cleanup_006a8858)(&ecdsa_table);
  return;
}
