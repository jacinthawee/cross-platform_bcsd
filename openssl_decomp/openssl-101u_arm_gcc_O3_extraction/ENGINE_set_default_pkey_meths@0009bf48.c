
int ENGINE_set_default_pkey_meths(ENGINE *e)

{
  int iVar1;
  undefined4 local_14 [2];
  
  if ((*(code **)(e + 0x2c) != (code *)0x0) &&
     (iVar1 = (**(code **)(e + 0x2c))(e,0,local_14,0), 0 < iVar1)) {
    iVar1 = engine_table_register(&pkey_meth_table,0x9bea1,e,local_14[0],iVar1,1);
    return iVar1;
  }
  return 1;
}

