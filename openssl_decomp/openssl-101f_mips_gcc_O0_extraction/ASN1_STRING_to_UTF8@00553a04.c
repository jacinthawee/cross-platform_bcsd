
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
  int local_14;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_28 = local_24;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = -1;
  if (in != (ASN1_STRING *)0x0) {
    piVar4 = &in->type;
    if (((uint)*piVar4 < 0x1f) && ((int)(char)tag2nbyte[*piVar4] != 0xffffffff)) {
      piVar1 = &in->length;
      in = (ASN1_STRING *)in->data;
      local_1c = (uchar *)0x0;
      local_24[0] = 0;
      iVar3 = (*(code *)PTR_ASN1_mbstring_copy_006a9df8)
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
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar4 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar5 = (uint)X509_ALGOR_it[0];
  if (X509_ALGOR_it._16_4_ == 0) {
    if (uVar5 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar3 = (*(code *)(&switchD_00565630::switchdataD_0066aba0)[uVar5])();
      return iVar3;
    }
  }
  else if (uVar5 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*(code *)(&switchD_005651a0::switchdataD_0066ab84)[uVar5])();
    return iVar3;
  }
  if (piVar4 == *(int **)PTR___stack_chk_guard_006aabf0) {
    return 0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(int *)(*piVar4 + in->type);
}

