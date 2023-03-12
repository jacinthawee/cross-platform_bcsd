
bool __regparm3
SRP_user_pwd_set_sv_isra_4(BIGNUM **param_1_00,BIGNUM **param_2,char *param_3,char *param_1)

{
  size_t sVar1;
  int iVar2;
  BIGNUM *pBVar3;
  int in_GS_OFFSET;
  bool bVar4;
  uchar local_9e4 [2500];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  sVar1 = strlen(param_3);
  if (sVar1 < 0x9c5) {
    sVar1 = strlen(param_1);
    if (sVar1 < 0x9c5) {
      iVar2 = t_fromb64();
      pBVar3 = BN_bin2bn(local_9e4,iVar2,(BIGNUM *)0x0);
      *param_2 = pBVar3;
      if (pBVar3 != (BIGNUM *)0x0) {
        iVar2 = t_fromb64();
        pBVar3 = BN_bin2bn(local_9e4,iVar2,(BIGNUM *)0x0);
        bVar4 = pBVar3 != (BIGNUM *)0x0;
        *param_1_00 = pBVar3;
        goto LAB_0819b37b;
      }
    }
  }
  bVar4 = false;
LAB_0819b37b:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

