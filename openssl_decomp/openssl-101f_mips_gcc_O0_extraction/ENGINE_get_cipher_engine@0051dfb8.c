
ENGINE * ENGINE_get_cipher_engine(int nid)

{
  ENGINE *pEVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0051dfcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (ENGINE *)(*(code *)PTR_engine_table_select_006a9984)(&cipher_table,nid);
  return pEVar1;
}
