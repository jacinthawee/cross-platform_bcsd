
int EC_POINT_mul(EC_GROUP *group,EC_POINT *r,BIGNUM *n,EC_POINT *q,BIGNUM *m,BN_CTX *ctx)

{
  bool bVar1;
  int iVar2;
  int in_GS_OFFSET;
  EC_POINT *local_28;
  BIGNUM *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = q;
  local_24 = m;
  bVar1 = q != (EC_POINT *)0x0 && m != (BIGNUM *)0x0;
  if (*(code **)(*(int *)group + 0x78) == (code *)0x0) {
    iVar2 = ec_wNAF_mul(group,r,n,bVar1,&local_28,&local_24,ctx);
  }
  else {
    iVar2 = (**(code **)(*(int *)group + 0x78))(group,r,n,bVar1,&local_28,&local_24,ctx);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

