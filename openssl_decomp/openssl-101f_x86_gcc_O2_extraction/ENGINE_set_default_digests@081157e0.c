
int ENGINE_set_default_digests(ENGINE *e)

{
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  undefined4 local_14;
  int local_10;
  
  iVar2 = 1;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(code **)(e + 0x28) != (code *)0x0) {
    iVar1 = (**(code **)(e + 0x28))(e,0,&local_14,0);
    if (0 < iVar1) {
      iVar2 = engine_table_register(&digest_table,engine_unregister_all_digests,e,local_14,iVar1,1);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

