
int EC_GROUP_get_degree(EC_GROUP *group)

{
  int iVar1;
  
  if (*(code **)(*(int *)group + 0x20) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00503ed4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)group + 0x20))();
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xad,0x42,"ec_lib.c",0x1c7);
  return 0;
}

