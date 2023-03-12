
int OCSP_check_validity(ASN1_GENERALIZEDTIME *thisupd,ASN1_GENERALIZEDTIME *nextupd,long sec,
                       long maxsec)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int local_28;
  int local_24 [2];
  
  time(&local_28);
  uVar1 = ASN1_GENERALIZEDTIME_check(thisupd);
  if (uVar1 == 0) {
    ERR_put_error(0x27,0x73,0x7b,"ocsp_cl.c",0x152);
  }
  else {
    local_24[0] = local_28 + sec;
    iVar3 = X509_cmp_time(thisupd,local_24);
    if (iVar3 >= 1) {
      ERR_put_error(0x27,0x73,0x7e,"ocsp_cl.c",0x157);
    }
    uVar1 = (uint)(iVar3 < 1);
    if (-1 < maxsec) {
      local_24[0] = local_28 - maxsec;
      iVar3 = X509_cmp_time(thisupd,local_24);
      if (iVar3 < 0) {
        uVar1 = 0;
        ERR_put_error(0x27,0x73,0x7f,"ocsp_cl.c",0x162);
      }
    }
  }
  if (nextupd != (ASN1_GENERALIZEDTIME *)0x0) {
    uVar2 = ASN1_GENERALIZEDTIME_check(nextupd);
    if (uVar2 == 0) {
      ERR_put_error(0x27,0x73,0x7a,"ocsp_cl.c",0x16d);
      iVar3 = ASN1_STRING_cmp(nextupd,thisupd);
      uVar1 = uVar2;
    }
    else {
      local_24[0] = local_28 - sec;
      iVar3 = X509_cmp_time(nextupd,local_24);
      if (iVar3 < 0) {
        uVar1 = 0;
        ERR_put_error(0x27,0x73,0x7d,"ocsp_cl.c",0x172);
      }
      iVar3 = ASN1_STRING_cmp(nextupd,thisupd);
    }
    if (iVar3 < 0) {
      ERR_put_error(0x27,0x73,0x7c,"ocsp_cl.c",0x17a);
      return 0;
    }
  }
  return uVar1;
}

