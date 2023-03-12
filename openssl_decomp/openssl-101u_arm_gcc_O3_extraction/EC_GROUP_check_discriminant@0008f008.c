
int EC_GROUP_check_discriminant(EC_GROUP *group,BN_CTX *ctx)

{
  int iVar1;
  
  if (*(code **)(*(int *)group + 0x24) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0008f01a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)group + 0x24))();
    return iVar1;
  }
  ERR_put_error(0x10,0xab,0x42,"ec_lib.c",0x1b9);
  return 0;
}
