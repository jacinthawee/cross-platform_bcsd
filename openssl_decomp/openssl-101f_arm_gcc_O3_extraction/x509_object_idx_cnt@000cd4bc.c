
void x509_object_idx_cnt(_STACK *param_1,int param_2,undefined4 param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int local_134;
  X509 *local_130;
  undefined auStack_12c [60];
  undefined4 local_f0;
  X509 local_d0;
  int local_1c;
  
  local_1c = __TMC_END__;
  local_134 = param_2;
  if (param_2 == 1) {
    local_d0.nc = (NAME_CONSTRAINTS *)(auStack_12c + 0x28);
    local_130 = (X509 *)&local_d0.nc;
    local_f0 = param_3;
  }
  else {
    if (param_2 != 2) {
      uVar1 = 0xffffffff;
      goto LAB_000cd54c;
    }
    local_d0.cert_info = (X509_CINF *)auStack_12c;
    local_130 = &local_d0;
    auStack_12c._8_4_ = param_3;
  }
  uVar1 = sk_find(param_1,&local_134);
  uVar4 = ~uVar1 >> 0x1f;
  if (param_4 == (int *)0x0) {
    uVar4 = 0;
  }
  if (uVar4 != 0) {
    iVar5 = uVar1 + 1;
    *param_4 = 1;
    iVar2 = sk_num(param_1);
    if (iVar5 < iVar2) {
      do {
        piVar3 = (int *)sk_value(param_1,iVar5);
        iVar2 = *piVar3;
        if (iVar2 != local_134) break;
        if (iVar2 == 1) {
          iVar2 = X509_subject_name_cmp((X509 *)piVar3[1],local_130);
LAB_000cd530:
          if (iVar2 != 0) break;
        }
        else if (iVar2 == 2) {
          iVar2 = X509_CRL_cmp((X509_CRL *)piVar3[1],(X509_CRL *)local_130);
          goto LAB_000cd530;
        }
        iVar5 = iVar5 + 1;
        *param_4 = *param_4 + 1;
        iVar2 = sk_num(param_1);
      } while (iVar5 < iVar2);
    }
  }
LAB_000cd54c:
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}

