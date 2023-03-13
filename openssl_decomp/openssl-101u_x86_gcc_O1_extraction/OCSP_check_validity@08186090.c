
int OCSP_check_validity(ASN1_GENERALIZEDTIME *thisupd,ASN1_GENERALIZEDTIME *nextupd,long sec,
                       long maxsec)

{
  int iVar1;
  uint uVar2;
  int in_GS_OFFSET;
  int iVar3;
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  time(&local_28);
  iVar1 = ASN1_GENERALIZEDTIME_check(thisupd);
  if (iVar1 == 0) {
    iVar3 = 0x152;
    iVar1 = 0x7b;
LAB_081860d7:
    uVar2 = 0;
    ERR_put_error(0x27,0x73,iVar1,"ocsp_cl.c",iVar3);
  }
  else {
    local_24 = sec + local_28;
    iVar1 = X509_cmp_time(thisupd,&local_24);
    if (iVar1 >= 1) {
      ERR_put_error(0x27,0x73,0x7e,"ocsp_cl.c",0x157);
    }
    uVar2 = (uint)(iVar1 < 1);
    if (-1 < maxsec) {
      local_24 = local_28 - maxsec;
      iVar1 = X509_cmp_time(thisupd,&local_24);
      if (iVar1 < 0) {
        iVar3 = 0x162;
        iVar1 = 0x7f;
        goto LAB_081860d7;
      }
    }
  }
  if (nextupd == (ASN1_GENERALIZEDTIME *)0x0) goto LAB_08186178;
  iVar1 = ASN1_GENERALIZEDTIME_check(nextupd);
  if (iVar1 == 0) {
    iVar3 = 0x16d;
    iVar1 = 0x7a;
LAB_0818610c:
    uVar2 = 0;
    ERR_put_error(0x27,0x73,iVar1,"ocsp_cl.c",iVar3);
  }
  else {
    local_24 = local_28 - sec;
    iVar1 = X509_cmp_time(nextupd,&local_24);
    if (iVar1 < 0) {
      iVar3 = 0x172;
      iVar1 = 0x7d;
      goto LAB_0818610c;
    }
  }
  iVar1 = ASN1_STRING_cmp(nextupd,thisupd);
  if (iVar1 < 0) {
    uVar2 = 0;
    ERR_put_error(0x27,0x73,0x7c,"ocsp_cl.c",0x17a);
  }
LAB_08186178:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

