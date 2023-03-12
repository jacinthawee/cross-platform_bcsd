
int EC_GROUP_check_discriminant(EC_GROUP *group,BN_CTX *ctx)

{
  int iVar1;
  
  if (*(code **)(*(int *)group + 0x24) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00503f30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)group + 0x24))();
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xab,0x42,"ec_lib.c",0x1d2);
  return 0;
}

