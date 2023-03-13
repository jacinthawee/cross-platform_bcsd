
int ENGINE_register_ECDSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x18) != 0) {
    iVar1 = (*(code *)PTR_engine_table_register_006a8860)
                      (&ecdsa_table,engine_unregister_all_ECDSA,e,&dummy_nid,1,0,&_gp);
    return iVar1;
  }
  return 1;
}

