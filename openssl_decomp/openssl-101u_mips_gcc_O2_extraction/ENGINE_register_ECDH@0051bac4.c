
int ENGINE_register_ECDH(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x14) != 0) {
    iVar1 = (*(code *)PTR_engine_table_register_006a8860)
                      (&ecdh_table,engine_unregister_all_ECDH,e,&dummy_nid,1,0,&_gp);
    return iVar1;
  }
  return 1;
}

