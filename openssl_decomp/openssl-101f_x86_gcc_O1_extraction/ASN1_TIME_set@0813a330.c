
ASN1_TIME * ASN1_TIME_set(ASN1_TIME *s,time_t t)

{
  int iVar1;
  ASN1_TIME *pAVar2;
  int in_GS_OFFSET;
  time_t local_40;
  undefined local_3c [44];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_40 = t;
  iVar1 = OPENSSL_gmtime(&local_40,local_3c);
  if (iVar1 == 0) {
    ERR_put_error(0xd,0xd9,0xad,"a_time.c",0x73);
    pAVar2 = (ASN1_TIME *)0x0;
  }
  else if (*(int *)(iVar1 + 0x14) - 0x32U < 100) {
    pAVar2 = ASN1_UTCTIME_adj(s,local_40,0,0);
  }
  else {
    pAVar2 = ASN1_GENERALIZEDTIME_adj(s,local_40,0,0);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

