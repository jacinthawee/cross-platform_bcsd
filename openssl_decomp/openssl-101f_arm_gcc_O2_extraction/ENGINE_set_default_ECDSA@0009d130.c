
int ENGINE_set_default_ECDSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x18) != 0) {
    iVar1 = engine_table_register(&ecdsa_table,0x9d095,e,&dummy_nid,1,1);
    return iVar1;
  }
  return 1;
}

