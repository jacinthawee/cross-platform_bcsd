
int x509_name_ex_d2i(void **param_1,uchar **param_2,long param_3,undefined4 param_4,int param_5,
                    int param_6,char param_7,ASN1_TLC *param_8)

{
  uchar *__src;
  int iVar1;
  _STACK **pp_Var2;
  _STACK *p_Var3;
  void *data;
  int iVar4;
  int in_GS_OFFSET;
  int local_34;
  uchar *local_28;
  _STACK *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (_STACK *)0x0;
  __src = *param_2;
  if (0x100000 < param_3) {
    param_3 = 0x100000;
  }
  local_28 = __src;
  iVar1 = ASN1_item_ex_d2i((ASN1_VALUE **)&local_24,&local_28,param_3,
                           (ASN1_ITEM *)X509_NAME_INTERNAL_it,param_5,param_6,param_7,param_8);
  if (iVar1 < 1) goto LAB_0813f1fd;
  pp_Var2 = (_STACK **)*param_1;
  if (pp_Var2 != (_STACK **)0x0) {
    BUF_MEM_free((BUF_MEM *)pp_Var2[2]);
    sk_pop_free(*pp_Var2,X509_NAME_ENTRY_free);
    if (pp_Var2[3] != (_STACK *)0x0) {
      CRYPTO_free(pp_Var2[3]);
    }
    CRYPTO_free(pp_Var2);
    *param_1 = (void *)0x0;
  }
  pp_Var2 = (_STACK **)CRYPTO_malloc(0x14,"x_name.c",0x8f);
  if (pp_Var2 == (_STACK **)0x0) {
    ERR_put_error(0xd,0xab,0x41,"x_name.c",0x9d);
  }
  else {
    p_Var3 = sk_new_null();
    *pp_Var2 = p_Var3;
    if (p_Var3 != (_STACK *)0x0) {
      p_Var3 = (_STACK *)BUF_MEM_new();
      pp_Var2[2] = p_Var3;
      if (p_Var3 != (_STACK *)0x0) {
        pp_Var2[3] = (_STACK *)0x0;
        pp_Var2[4] = (_STACK *)0x0;
        pp_Var2[1] = (_STACK *)0x1;
        iVar1 = BUF_MEM_grow((BUF_MEM *)p_Var3,(int)local_28 - (int)__src);
        if (iVar1 != 0) {
          memcpy(pp_Var2[2]->data,__src,(int)local_28 - (int)__src);
          for (local_34 = 0; iVar1 = sk_num(local_24), local_34 < iVar1; local_34 = local_34 + 1) {
            p_Var3 = (_STACK *)sk_value(local_24,local_34);
            for (iVar1 = 0; iVar4 = sk_num(p_Var3), iVar1 < iVar4; iVar1 = iVar1 + 1) {
              data = sk_value(p_Var3,iVar1);
              *(int *)((int)data + 8) = local_34;
              iVar4 = sk_push(*pp_Var2,data);
              if (iVar4 == 0) goto LAB_0813f1cc;
            }
            sk_free(p_Var3);
          }
          sk_free(local_24);
          if (pp_Var2[3] != (_STACK *)0x0) {
            CRYPTO_free(pp_Var2[3]);
            pp_Var2[3] = (_STACK *)0x0;
          }
          iVar1 = sk_num(*pp_Var2);
          if (iVar1 == 0) {
            pp_Var2[4] = (_STACK *)0x0;
            iVar1 = 1;
          }
          else {
            iVar1 = x509_name_canon_part_0();
            if (iVar1 == 0) goto LAB_0813f1cc;
          }
          pp_Var2[1] = (_STACK *)0x0;
          *param_1 = pp_Var2;
          *param_2 = local_28;
          goto LAB_0813f1fd;
        }
LAB_0813f1cc:
        ASN1_item_free((ASN1_VALUE *)pp_Var2,(ASN1_ITEM *)X509_NAME_it);
        goto LAB_0813f1dd;
      }
    }
    ERR_put_error(0xd,0xab,0x41,"x_name.c",0x9d);
    if (*pp_Var2 != (_STACK *)0x0) {
      sk_free(*pp_Var2);
    }
    CRYPTO_free(pp_Var2);
  }
LAB_0813f1dd:
  ERR_put_error(0xd,0x9e,0x3a,"x_name.c",0xf5);
  iVar1 = 0;
LAB_0813f1fd:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

