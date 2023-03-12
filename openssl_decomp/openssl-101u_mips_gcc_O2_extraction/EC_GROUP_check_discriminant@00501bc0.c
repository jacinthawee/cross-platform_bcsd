
int EC_GROUP_check_discriminant(EC_GROUP *group,BN_CTX *ctx)

{
  int iVar1;
  
  if (*(code **)(*(int *)group + 0x24) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00501bd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)group + 0x24))();
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xab,0x42,"ec_lib.c",0x1b9);
  return 0;
}

