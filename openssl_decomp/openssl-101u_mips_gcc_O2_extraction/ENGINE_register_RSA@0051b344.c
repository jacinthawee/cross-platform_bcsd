
int ENGINE_register_RSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 8) != 0) {
    iVar1 = (*(code *)PTR_engine_table_register_006a8860)
                      (&rsa_table,engine_unregister_all_RSA,e,&dummy_nid,1,0,&_gp);
    return iVar1;
  }
  return 1;
}

