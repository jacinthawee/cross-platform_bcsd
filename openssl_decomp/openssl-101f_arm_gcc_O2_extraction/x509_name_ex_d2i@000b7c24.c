
int x509_name_ex_d2i(ASN1_VALUE **param_1,uchar **param_2,long param_3,undefined4 param_4,
                    int param_5,int param_6,char param_7,ASN1_TLC *param_8)

{
  int iVar1;
  _STACK *p_Var2;
  int iVar3;
  void *data;
  int iVar4;
  _STACK **pp_Var5;
  uchar *__src;
  uchar *local_28;
  _STACK *local_24 [2];
  
  __src = *param_2;
  local_24[0] = (_STACK *)0x0;
  local_28 = __src;
  iVar1 = ASN1_item_ex_d2i((ASN1_VALUE **)local_24,&local_28,param_3,
                           (ASN1_ITEM *)PTR_X509_NAME_INTERNAL_it_000b7d9c,param_5,param_6,param_7,
                           param_8);
  if (iVar1 < 1) {
    return iVar1;
  }
  pp_Var5 = (_STACK **)*param_1;
  if (pp_Var5 != (_STACK **)0x0) {
    BUF_MEM_free((BUF_MEM *)pp_Var5[2]);
    sk_pop_free(*pp_Var5,X509_NAME_ENTRY_free + 1);
    if (pp_Var5[3] != (_STACK *)0x0) {
      CRYPTO_free(pp_Var5[3]);
    }
    CRYPTO_free(pp_Var5);
    *param_1 = (ASN1_VALUE *)0x0;
  }
  pp_Var5 = (_STACK **)CRYPTO_malloc(0x14,"x_name.c",0x87);
  if (pp_Var5 == (_STACK **)0x0) {
    ERR_put_error(0xd,0xab,0x41,"x_name.c",0x93);
  }
  else {
    p_Var2 = sk_new_null();
    *pp_Var5 = p_Var2;
    if (p_Var2 != (_STACK *)0x0) {
      p_Var2 = (_STACK *)BUF_MEM_new();
      pp_Var5[2] = p_Var2;
      if (p_Var2 != (_STACK *)0x0) {
        pp_Var5[3] = (_STACK *)0x0;
        pp_Var5[4] = (_STACK *)0x0;
        pp_Var5[1] = (_STACK *)0x1;
        iVar1 = BUF_MEM_grow((BUF_MEM *)p_Var2,(int)local_28 - (int)__src);
        if (iVar1 != 0) {
          memcpy(pp_Var5[2]->data,__src,(int)local_28 - (int)__src);
          for (iVar1 = 0; iVar3 = sk_num(local_24[0]), iVar1 < iVar3; iVar1 = iVar1 + 1) {
            p_Var2 = (_STACK *)sk_value(local_24[0],iVar1);
            iVar3 = 0;
            while( true ) {
              iVar4 = sk_num(p_Var2);
              if (iVar4 <= iVar3) break;
              data = sk_value(p_Var2,iVar3);
              *(int *)((int)data + 8) = iVar1;
              iVar4 = sk_push(*pp_Var5,data);
              iVar3 = iVar3 + 1;
              if (iVar4 == 0) goto LAB_000b7cc6;
            }
            sk_free(p_Var2);
          }
          sk_free(local_24[0]);
          iVar1 = x509_name_canon(pp_Var5);
          if (iVar1 != 0) {
            pp_Var5[1] = (_STACK *)0x0;
            *param_1 = (ASN1_VALUE *)pp_Var5;
            *param_2 = local_28;
            return iVar1;
          }
        }
LAB_000b7cc6:
        ASN1_item_free((ASN1_VALUE *)pp_Var5,(ASN1_ITEM *)PTR_X509_NAME_it_000b7da0);
        goto LAB_000b7cce;
      }
    }
    ERR_put_error(0xd,0xab,0x41,"x_name.c",0x93);
    if (*pp_Var5 != (_STACK *)0x0) {
      sk_free(*pp_Var5);
    }
    CRYPTO_free(pp_Var5);
  }
LAB_000b7cce:
  ERR_put_error(0xd,0x9e,0x3a,"x_name.c",0xdc);
  return 0;
}

