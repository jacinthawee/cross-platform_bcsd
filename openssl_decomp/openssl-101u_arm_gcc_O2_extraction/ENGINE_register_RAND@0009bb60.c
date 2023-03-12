
int ENGINE_register_RAND(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x1c) != 0) {
    iVar1 = engine_table_register(&rand_table,0x9bb45,e,&dummy_nid,1,0);
    return iVar1;
  }
  return 1;
}

