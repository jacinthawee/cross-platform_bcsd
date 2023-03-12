
void SRP_user_pwd_set_sv_isra_4(BIGNUM **param_1,BIGNUM **param_2,char *param_3,char *param_4)

{
  size_t sVar1;
  int iVar2;
  BIGNUM *pBVar3;
  uchar auStack_9e8 [2500];
  int local_24;
  
  local_24 = __TMC_END__;
  sVar1 = strlen(param_3);
  if ((sVar1 < 0x9c5) && (sVar1 = strlen(param_4), sVar1 < 0x9c5)) {
    iVar2 = t_fromb64(auStack_9e8,param_4);
    pBVar3 = BN_bin2bn(auStack_9e8,iVar2,(BIGNUM *)0x0);
    *param_2 = pBVar3;
    if (pBVar3 != (BIGNUM *)0x0) {
      iVar2 = t_fromb64(auStack_9e8,param_3);
      pBVar3 = BN_bin2bn(auStack_9e8,iVar2,(BIGNUM *)0x0);
      *param_1 = pBVar3;
      if (pBVar3 != (BIGNUM *)0x0) {
        pBVar3 = (BIGNUM *)0x1;
      }
      goto LAB_000ee534;
    }
  }
  pBVar3 = (BIGNUM *)0x0;
LAB_000ee534:
  if (local_24 != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pBVar3);
  }
  return;
}

