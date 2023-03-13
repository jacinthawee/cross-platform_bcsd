
size_t x509_name_ex_i2d(int *param_1,void **param_2)

{
  _STACK **pp_Var1;
  void *data;
  int iVar2;
  size_t len;
  _STACK *st;
  int iVar3;
  _STACK *st_00;
  int in_GS_OFFSET;
  int local_34;
  _STACK *local_28;
  char **local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pp_Var1 = (_STACK **)*param_1;
  if (pp_Var1[1] == (_STACK *)0x0) {
LAB_0813eeb8:
    len = pp_Var1[2]->num;
    if (param_2 != (void **)0x0) {
      memcpy(*param_2,pp_Var1[2]->data,len);
      *param_2 = (void *)((int)*param_2 + len);
    }
  }
  else {
    local_28 = (_STACK *)0x0;
    local_28 = sk_new_null();
    if (local_28 == (_STACK *)0x0) {
      st = (_STACK *)0x0;
    }
    else {
      local_34 = -1;
      st_00 = (_STACK *)0x0;
      for (iVar3 = 0; iVar2 = sk_num(*pp_Var1), iVar3 < iVar2; iVar3 = iVar3 + 1) {
        data = sk_value(*pp_Var1,iVar3);
        if (*(int *)((int)data + 8) != local_34) {
          st_00 = sk_new_null();
          st = local_28;
          if ((st_00 == (_STACK *)0x0) ||
             (iVar2 = sk_push(local_28,st_00), st = local_28, iVar2 == 0)) goto LAB_0813f044;
          local_34 = *(int *)((int)data + 8);
        }
        iVar2 = sk_push(st_00,data);
        st = local_28;
        if (iVar2 == 0) goto LAB_0813f044;
      }
      len = ASN1_item_ex_i2d((ASN1_VALUE **)&local_28,(uchar **)0x0,
                             (ASN1_ITEM *)X509_NAME_INTERNAL_it,-1,-1);
      iVar3 = BUF_MEM_grow((BUF_MEM *)pp_Var1[2],len);
      st = local_28;
      if (iVar3 != 0) {
        local_24 = pp_Var1[2]->data;
        ASN1_item_ex_i2d((ASN1_VALUE **)&local_28,(uchar **)&local_24,
                         (ASN1_ITEM *)X509_NAME_INTERNAL_it,-1,-1);
        sk_pop_free(local_28,local_sk_X509_NAME_ENTRY_free);
        pp_Var1[1] = (_STACK *)0x0;
        if ((int)len < 0) goto LAB_0813eed8;
        if (pp_Var1[3] != (_STACK *)0x0) {
          CRYPTO_free(pp_Var1[3]);
          pp_Var1[3] = (_STACK *)0x0;
        }
        iVar3 = sk_num(*pp_Var1);
        if (iVar3 == 0) {
          pp_Var1[4] = (_STACK *)0x0;
        }
        else {
          len = x509_name_canon_part_0();
          if ((int)len < 0) goto LAB_0813eed8;
        }
        goto LAB_0813eeb8;
      }
    }
LAB_0813f044:
    len = 0xffffffff;
    sk_pop_free(st,local_sk_X509_NAME_ENTRY_free);
    ERR_put_error(0xd,0xcb,0x41,"x_name.c",0x143);
  }
LAB_0813eed8:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return len;
}

