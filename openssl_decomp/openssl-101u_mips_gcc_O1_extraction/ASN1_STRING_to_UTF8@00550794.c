
int ASN1_STRING_to_UTF8(uchar **out,ASN1_STRING *in)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *local_28;
  int local_24 [2];
  uchar *local_1c;
  undefined4 local_18;
  int local_14;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_28 = local_24;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = -1;
  if (in != (ASN1_STRING *)0x0) {
    piVar4 = &in->type;
    if (((uint)*piVar4 < 0x1f) && ((int)(char)tag2nbyte[*piVar4] != 0xffffffff)) {
      piVar1 = &in->length;
      in = (ASN1_STRING *)in->data;
      local_1c = (uchar *)0x0;
      local_24[0] = 0;
      local_18 = 0;
      iVar3 = (*(code *)PTR_ASN1_mbstring_copy_006a8cd4)
                        (&local_28,in,*piVar1,(int)(char)tag2nbyte[*piVar4] | 0x1000,0x2000);
      if (-1 < iVar3) {
        *out = local_1c;
        iVar3 = local_24[0];
      }
    }
    else {
      iVar3 = -1;
    }
  }
  if (local_14 == *(int *)puVar2) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar4 = *(int **)PTR___stack_chk_guard_006a9ae8;
  uVar5 = (uint)X509_ALGOR_it[0];
  if (X509_ALGOR_it._16_4_ == 0) {
    if (uVar5 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005619f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar3 = (*(code *)(&switchD_005619f8::switchdataD_0066a17c)[uVar5])();
      return iVar3;
    }
  }
  else if (uVar5 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00561550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*(code *)(&switchD_00561550::switchdataD_0066a160)[uVar5])();
    return iVar3;
  }
  if (piVar4 == *(int **)PTR___stack_chk_guard_006a9ae8) {
    return 0;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return *(int *)(*piVar4 + in->type);
}

