
int ENGINE_set_default_ECDH(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x14) != 0) {
    iVar1 = engine_table_register(&ecdh_table,engine_unregister_all_ECDH,e,&dummy_nid,1,1);
    return iVar1;
  }
  return 1;
}

