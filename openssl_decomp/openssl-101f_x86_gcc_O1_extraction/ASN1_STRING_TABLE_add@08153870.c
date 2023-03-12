
int ASN1_STRING_TABLE_add(int param_1,long param_2,long param_3,ulong param_4,ulong param_5)

{
  bool bVar1;
  int *data;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  int local_34 [5];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (stable == (_STACK *)0x0) {
    stable = sk_new(sk_table_cmp);
    if (stable != (_STACK *)0x0) goto LAB_0815389f;
    iVar2 = 0xdd;
LAB_081539b5:
    iVar3 = 0;
    ERR_put_error(0xd,0x81,0x41,"a_strnid.c",iVar2);
  }
  else {
LAB_0815389f:
    local_34[0] = param_1;
    data = (int *)OBJ_bsearch_(local_34,tbl_standard,0x13,0x14,table_cmp_BSEARCH_CMP_FN);
    if (data == (int *)0x0) {
      if (stable != (_STACK *)0x0) {
        iVar2 = sk_find(stable,local_34);
        if (-1 < iVar2) {
          data = (int *)sk_value(stable,iVar2);
          if (data != (int *)0x0) goto LAB_081538c9;
        }
      }
      data = (int *)CRYPTO_malloc(0x14,"a_strnid.c",0xe1);
      if (data == (int *)0x0) {
        iVar2 = 0xe4;
        goto LAB_081539b5;
      }
      bVar1 = true;
      data[4] = param_5 & 0xfffffffe | 1;
      *data = param_1;
    }
    else {
LAB_081538c9:
      bVar1 = false;
      data[4] = param_5 & 0xfffffffe | data[4] & 1U;
    }
    if (param_2 != -1) {
      data[1] = param_2;
    }
    if (param_3 != -1) {
      data[2] = param_3;
    }
    iVar3 = 1;
    data[3] = param_4;
    if (bVar1) {
      sk_push(stable,data);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

