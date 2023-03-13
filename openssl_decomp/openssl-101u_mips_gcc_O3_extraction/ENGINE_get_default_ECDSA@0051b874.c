
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ENGINE * ENGINE_get_default_ECDSA(void)

{
  ENGINE *pEVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0051b888. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (ENGINE *)(*(code *)PTR_engine_table_select_006a8864)(&ecdsa_table,1);
  return pEVar1;
}

