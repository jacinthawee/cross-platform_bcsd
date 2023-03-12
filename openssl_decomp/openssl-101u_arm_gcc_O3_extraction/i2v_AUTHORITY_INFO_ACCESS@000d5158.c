
void i2v_AUTHORITY_INFO_ACCESS(X509V3_EXT_METHOD *param_1,_STACK *param_2,_STACK *param_3)

{
  ASN1_OBJECT **ppAVar1;
  _STACK *p_Var2;
  void *pvVar3;
  size_t sVar4;
  size_t sVar5;
  int iVar6;
  int iVar7;
  char acStack_7c [80];
  int local_2c;
  
  iVar7 = 0;
  local_2c = __stack_chk_guard;
  do {
    iVar6 = sk_num(param_2);
    if (iVar6 <= iVar7) {
      if (param_3 == (_STACK *)0x0) {
LAB_000d5216:
        param_3 = sk_new_null();
      }
LAB_000d5206:
      if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(param_3);
      }
      return;
    }
    ppAVar1 = (ASN1_OBJECT **)sk_value(param_2,iVar7);
    p_Var2 = (_STACK *)
             i2v_GENERAL_NAME(param_1,(GENERAL_NAME *)ppAVar1[1],(stack_st_CONF_VALUE *)param_3);
    if (p_Var2 == (_STACK *)0x0) goto LAB_000d5216;
    pvVar3 = sk_value(p_Var2,iVar7);
    i2t_ASN1_OBJECT(acStack_7c,0x50,*ppAVar1);
    sVar4 = strlen(acStack_7c);
    sVar5 = strlen(*(char **)((int)pvVar3 + 4));
    sVar4 = sVar5 + sVar4 + 5;
    param_3 = (_STACK *)CRYPTO_malloc(sVar4,"v3_info.c",0x7f);
    if (param_3 == (_STACK *)0x0) {
      ERR_put_error(0x22,0x8a,0x41,"v3_info.c",0x82);
      goto LAB_000d5206;
    }
    BUF_strlcpy((char *)param_3,acStack_7c,sVar4);
    iVar7 = iVar7 + 1;
    BUF_strlcat((char *)param_3," - ",sVar4);
    BUF_strlcat((char *)param_3,*(char **)((int)pvVar3 + 4),sVar4);
    CRYPTO_free(*(void **)((int)pvVar3 + 4));
    *(_STACK **)((int)pvVar3 + 4) = param_3;
    param_3 = p_Var2;
  } while( true );
}

