
ASN1_TIME * ASN1_TIME_adj(ASN1_TIME *s,time_t t,int offset_day,long offset_sec)

{
  int offset_day_00;
  long offset_sec_00;
  int iVar1;
  ASN1_TIME *pAVar2;
  int iVar3;
  int in_GS_OFFSET;
  undefined local_4c [44];
  int local_20;
  
  offset_sec_00 = offset_sec;
  offset_day_00 = offset_day;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = OPENSSL_gmtime(&t,local_4c);
  if (iVar1 == 0) {
    ERR_put_error(0xd,0xd9,0xad,"a_time.c",0x73);
    pAVar2 = (ASN1_TIME *)0x0;
  }
  else {
    if ((offset_day_00 != 0) || (offset_sec_00 != 0)) {
      iVar3 = OPENSSL_gmtime_adj(iVar1,offset_day_00,offset_sec_00);
      if (iVar3 == 0) {
        pAVar2 = (ASN1_TIME *)0x0;
        goto LAB_0813a429;
      }
    }
    if (*(int *)(iVar1 + 0x14) - 0x32U < 100) {
      pAVar2 = ASN1_UTCTIME_adj(s,t,offset_day_00,offset_sec_00);
    }
    else {
      pAVar2 = ASN1_GENERALIZEDTIME_adj(s,t,offset_day_00,offset_sec_00);
    }
  }
LAB_0813a429:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

