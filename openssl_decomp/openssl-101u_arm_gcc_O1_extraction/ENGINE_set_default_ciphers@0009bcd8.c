
int ENGINE_set_default_ciphers(ENGINE *e)

{
  int iVar1;
  undefined4 local_14 [2];
  
  if ((*(code **)(e + 0x24) != (code *)0x0) &&
     (iVar1 = (**(code **)(e + 0x24))(e,0,local_14,0), 0 < iVar1)) {
    iVar1 = engine_table_register(&cipher_table,0x9bc31,e,local_14[0],iVar1,1);
    return iVar1;
  }
  return 1;
}

