
int ENGINE_register_DH(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x10) != 0) {
    iVar1 = (*(code *)PTR_engine_table_register_006a9980)
                      (&dh_table,engine_unregister_all_DH,e,&dummy_nid,1,0,&_gp);
    return iVar1;
  }
  return 1;
}
