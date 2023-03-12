
ENGINE * ENGINE_get_pkey_meth_engine(int nid)

{
  ENGINE *pEVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0051e68c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (ENGINE *)(*(code *)PTR_engine_table_select_006a9984)(&pkey_meth_table,nid);
  return pEVar1;
}

