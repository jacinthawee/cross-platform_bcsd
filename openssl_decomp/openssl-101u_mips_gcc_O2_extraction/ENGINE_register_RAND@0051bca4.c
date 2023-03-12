
int ENGINE_register_RAND(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x1c) != 0) {
    iVar1 = (*(code *)PTR_engine_table_register_006a8860)
                      (&rand_table,engine_unregister_all_RAND,e,&dummy_nid,1,0,&_gp);
    return iVar1;
  }
  return 1;
}

