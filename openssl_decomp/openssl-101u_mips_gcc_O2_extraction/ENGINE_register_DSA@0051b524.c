
int ENGINE_register_DSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0xc) != 0) {
    iVar1 = (*(code *)PTR_engine_table_register_006a8860)
                      (&dsa_table,engine_unregister_all_DSA,e,&dummy_nid,1,0,&_gp);
    return iVar1;
  }
  return 1;
}

