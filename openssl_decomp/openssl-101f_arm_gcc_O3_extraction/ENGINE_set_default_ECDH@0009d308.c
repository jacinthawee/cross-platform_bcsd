
int ENGINE_set_default_ECDH(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x14) != 0) {
    iVar1 = engine_table_register(&ecdh_table,0x9d26d,e,&dummy_nid,1,1);
    return iVar1;
  }
  return 1;
}

