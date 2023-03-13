
ASN1_TIME * X509_time_adj(ASN1_TIME *s,long adj,time_t *t)

{
  ASN1_TIME *pAVar1;
  int in_GS_OFFSET;
  time_t local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (t == (time_t *)0x0) {
    time(&local_14);
  }
  else {
    local_14 = *t;
  }
  if ((s != (ASN1_TIME *)0x0) && ((*(byte *)&s->flags & 0x40) == 0)) {
    if (s->type == 0x17) {
      pAVar1 = ASN1_UTCTIME_adj(s,local_14,0,adj);
      goto LAB_0815e1cd;
    }
    if (s->type == 0x18) {
      pAVar1 = ASN1_GENERALIZEDTIME_adj(s,local_14,0,adj);
      goto LAB_0815e1cd;
    }
  }
  pAVar1 = ASN1_TIME_adj(s,local_14,0,adj);
LAB_0815e1cd:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

