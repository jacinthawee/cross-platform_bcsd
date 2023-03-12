
int OCSP_check_validity(ASN1_GENERALIZEDTIME *thisupd,ASN1_GENERALIZEDTIME *nextupd,long sec,
                       long maxsec)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int local_2c;
  int local_28;
  int *local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_time_006aabe4)(&local_2c);
  iVar2 = (*(code *)PTR_ASN1_GENERALIZEDTIME_check_006a9dd4)(thisupd);
  if (iVar2 == 0) {
    uVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x73,0x7b,"ocsp_cl.c",0x140);
  }
  else {
    local_28 = local_2c + sec;
    iVar2 = (*(code *)PTR_X509_cmp_time_006a880c)(thisupd,&local_28);
    if (iVar2 >= 1) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x73,0x7e,"ocsp_cl.c",0x148);
    }
    uVar4 = (uint)(iVar2 < 1);
    if (-1 < maxsec) {
      local_28 = local_2c - maxsec;
      iVar2 = (*(code *)PTR_X509_cmp_time_006a880c)(thisupd,&local_28);
      if (iVar2 < 0) {
        uVar4 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x73,0x7f,"ocsp_cl.c",0x152);
      }
    }
  }
  if (nextupd != (ASN1_GENERALIZEDTIME *)0x0) {
    iVar2 = (*(code *)PTR_ASN1_GENERALIZEDTIME_check_006a9dd4)(nextupd);
    if (iVar2 == 0) {
      uVar4 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x73,0x7a,"ocsp_cl.c",0x15e);
      iVar2 = (*(code *)PTR_ASN1_STRING_cmp_006a8248)(nextupd,thisupd);
    }
    else {
      local_28 = local_2c - sec;
      iVar2 = (*(code *)PTR_X509_cmp_time_006a880c)(nextupd,&local_28);
      if (iVar2 < 0) {
        uVar4 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x73,0x7d,"ocsp_cl.c",0x166);
      }
      iVar2 = (*(code *)PTR_ASN1_STRING_cmp_006a8248)(nextupd,thisupd);
    }
    if (iVar2 < 0) {
      uVar4 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x73,0x7c,"ocsp_cl.c",0x16e);
    }
  }
  if (local_24 == *(int **)puVar1) {
    return uVar4;
  }
  piVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x005b10a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*piVar3 + 8));
  return iVar2;
}

