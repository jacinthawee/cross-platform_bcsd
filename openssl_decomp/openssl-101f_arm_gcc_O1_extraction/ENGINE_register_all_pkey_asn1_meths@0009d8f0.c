
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_register_all_pkey_asn1_meths(void)

{
  ENGINE *e;
  int iVar1;
  undefined4 local_14;
  
  for (e = ENGINE_get_first(); e != (ENGINE *)0x0; e = ENGINE_get_next(e)) {
    if ((*(code **)(e + 0x30) != (code *)0x0) &&
       (iVar1 = (**(code **)(e + 0x30))(e,0,&local_14,0), 0 < iVar1)) {
      engine_table_register(&pkey_asn1_meth_table,0x9d831,e,local_14,iVar1,0);
    }
  }
  return;
}

