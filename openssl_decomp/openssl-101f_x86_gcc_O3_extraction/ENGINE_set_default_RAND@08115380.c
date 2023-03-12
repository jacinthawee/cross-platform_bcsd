
int ENGINE_set_default_RAND(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x1c) != 0) {
    iVar1 = engine_table_register(&rand_table,engine_unregister_all_RAND,e,&dummy_nid,1,1);
    return iVar1;
  }
  return 1;
}

