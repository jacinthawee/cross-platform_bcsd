
int ENGINE_register_ECDSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x18) != 0) {
    iVar1 = engine_table_register(&ecdsa_table,engine_unregister_all_ECDSA,e,&dummy_nid,1,0);
    return iVar1;
  }
  return 1;
}
