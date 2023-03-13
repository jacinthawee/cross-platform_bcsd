
int __regparm3 x509_object_idx_cnt(_STACK *param_1_00,int param_2,X509_ALGOR *param_3,int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_GS_OFFSET;
  int local_138;
  X509 *local_134;
  undefined local_130 [60];
  X509_ALGOR *local_f4;
  undefined local_d4 [180];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_138 = param_2;
  if (param_2 == 1) {
    local_134 = (X509 *)(local_d4 + 0x4c);
    local_d4._76_4_ = (NAME_CONSTRAINTS *)(local_130 + 0x28);
    local_f4 = param_3;
  }
  else {
    if (param_2 != 2) {
      iVar1 = -1;
      goto LAB_081630a8;
    }
    local_134 = (X509 *)local_d4;
    local_d4._0_4_ = (X509_CINF *)local_130;
    local_130._8_4_ = param_3;
  }
  iVar1 = sk_find(param_1_00,&local_138);
  if ((-1 < iVar1) && (param_1 != (int *)0x0)) {
    *param_1 = 1;
    iVar4 = iVar1;
    while( true ) {
      iVar4 = iVar4 + 1;
      iVar2 = sk_num(param_1_00);
      if (iVar2 <= iVar4) break;
      piVar3 = (int *)sk_value(param_1_00,iVar4);
      iVar2 = *piVar3;
      if (iVar2 != local_138) break;
      if (iVar2 == 1) {
        iVar2 = X509_subject_name_cmp((X509 *)piVar3[1],local_134);
LAB_08163064:
        if (iVar2 != 0) break;
      }
      else if (iVar2 == 2) {
        iVar2 = X509_CRL_cmp((X509_CRL *)piVar3[1],(X509_CRL *)local_134);
        goto LAB_08163064;
      }
      *param_1 = *param_1 + 1;
    }
  }
LAB_081630a8:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

